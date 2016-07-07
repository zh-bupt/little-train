#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include"trainrun.h" 
#include"control.h"
#include "egg.h"
#include "drawtrain.h"
#include<math.h>
int commontrack1=0;//公共轨道1的状态，0表示空闲，1表示占用 
int commontrack2=0;//公共轨道2的状态，0表示空闲，1表示占用 
int istrain1=0;//火车1进入监测点的标志，1表示进入监测点，当火车使出对应监测点时变为0 
int istrain31=0;//火车3进入监测点的标志，1表示进入监测点1，当火车使出对应监测点时变为0  
int istrain33=0;//火车3进入监测点的标志，1表示进入监测点2，当火车使出对应监测点时变为0  
int istrain2=0;//火车2进入监测点的标志，1表示进入监测点 ，当火车使出对应监测点时变为0 
extern clock_t begin1,begin31,begin2,begin32,end; 

extern HEGG hEggs[3];
extern TRAIN train1,train2,train3;//声明外部变量 
extern int controlstrategy;//声明外部变量 

/*火车运行函数(顺时针运行)*/ 
void TrainRun(TRAIN *train)
{
	Monitor1(train);//监测火车位置 
	while(1){
		Sleep(1000/train->speed);//时间控制，让火车以一定速度运行 
		Monitor2(train);//检测火车位置 
		if(train->state){//控制火车运行 
		if(fabs(train->xcoordinate-train->bend[0][0])<0.01&&fabs(train->ycoordinate-train->bend[0][1])<0.01){//弯道转弯，并移动 
			train->direction=EAST;
			train->xcoordinate=train->xcoordinate+0.1;
		}
		else if(fabs(train->xcoordinate-train->bend[1][0])<0.01&&fabs(train->ycoordinate-train->bend[1][1])<0.01){//弯道转弯，并移动 
			train->direction=SOUTH;
			train->ycoordinate=train->ycoordinate-0.1;
		}
		else if(fabs(train->xcoordinate-train->bend[2][0])<0.01&&fabs(train->ycoordinate-train->bend[2][1])<0.01){//弯道转弯，并移动 
			train->direction=WEST;
			train->xcoordinate=train->xcoordinate-0.1;
		}
		else if(fabs(train->xcoordinate-train->bend[3][0])<0.01&&fabs(train->ycoordinate-train->bend[3][1])<0.01){//弯道转弯，并移动 
			train->direction=NORTH;
			train->ycoordinate=train->ycoordinate+0.1;
		}
		else{//直道处直接移动 
			if(train->direction==EAST)
			{
			  train->xcoordinate=train->xcoordinate+0.1;
			}   
			else if(train->direction==SOUTH)
			{
			  train->ycoordinate=train->ycoordinate-0.1;
		    }
			else if(train->direction==WEST)
		    {
			  train->xcoordinate=train->xcoordinate-0.1;

			} 
			else if(train->direction==NORTH)
			{
			  train->ycoordinate=train->ycoordinate+0.1;

			}
			  
		}
	}
		Monitor1(train);//监测火车位置
	}
}

/*火车运行函数(逆时针运行)*/ 
void TrainRun2(TRAIN *train)
{
	Monitor1(train);//监测火车位置
	while(1){
		Sleep(1000/train->speed);
		Monitor2(train);//监测火车位置
		if(train->state){
		if(fabs(train->xcoordinate-train->bend[0][0])<0.01&&fabs(train->ycoordinate-train->bend[0][1])<0.01){//弯道转弯，并移动 
			train->direction=SOUTH;
			train->ycoordinate=train->ycoordinate-0.1;

		}
		else if(fabs(train->xcoordinate-train->bend[1][0])<0.01&&fabs(train->ycoordinate-train->bend[1][1])<0.01){//弯道转弯，并移动 
			train->direction=WEST;
			train->xcoordinate=train->xcoordinate-0.1;

		}
		else if(fabs(train->xcoordinate-train->bend[2][0])<0.01&&fabs(train->ycoordinate-train->bend[2][1])<0.01){//弯道转弯，并移动 
			train->direction=NORTH;
			train->ycoordinate=train->ycoordinate+0.1;

		}
		else if(fabs(train->xcoordinate-train->bend[3][0])<0.01&&fabs(train->ycoordinate-train->bend[3][1])<0.01){//弯道转弯，并移动 
			train->direction=EAST;
			train->xcoordinate=train->xcoordinate+0.1;

		}
		else{//直道处直接移动 
			if(train->direction==EAST)
			{
			  train->xcoordinate=train->xcoordinate+0.1;

			}   
			else if(train->direction==SOUTH)
			{
			  train->ycoordinate=train->ycoordinate-0.1;

		    }
			else if(train->direction==WEST)
		    {
			  train->xcoordinate=train->xcoordinate-0.1;

			} 
			else if(train->direction==NORTH)
			{
			  train->ycoordinate=train->ycoordinate+0.1;

			}
			  
		}
	}
		Monitor1(train);//监测火车位置
	}
}

/*对火车进入监测点时进行检测及参数改变*/ 
void Monitor1(TRAIN *train)
{
	switch(train->number){
		case 1:
			if(fabs(train->xcoordinate-train->checkpoint[0][0])<0.01&&fabs(train->ycoordinate-train->checkpoint[0][1])<0.01){
				istrain1=1;
				train->state=0;
			}
			break;
		case 2:
			if(fabs(train->xcoordinate-train->checkpoint[0][0])<0.01&&fabs(train->ycoordinate-train->checkpoint[0][1])<0.01){
				istrain2 = 1;
				train->state=0;
			}
			break;
		case 3:
			if(fabs(train->xcoordinate-train->checkpoint[0][0])<0.01&&fabs(train->ycoordinate-train->checkpoint[0][1])<0.01){
				istrain31=1;
				train->state=0;
			}
			else if(fabs(train->xcoordinate-train->checkpoint[2][0])<0.01&&fabs(train->ycoordinate-train->checkpoint[2][1])<0.01){
				istrain33=1;
				train->state=0;
			}
			break;
	}
}

/*对火车驶出监测点进行检测及参数改变*/ 
void Monitor2(TRAIN *train)
{
	switch(train->number){
		case 1:
			if(fabs(train->xcoordinate-train->checkpoint[0][0])<0.01&&fabs(train->ycoordinate-train->checkpoint[0][1])<0.01){
				if(commontrack1==0&&istrain33==1){
					commontrack1=1;
					Control(&train1, &train3, controlstrategy);
				}
				else if(commontrack1==0&&istrain33==0){
					train->state=1;
					commontrack1=1;
				}
			}
			else if(fabs(train->xcoordinate-train->checkpoint[1][0])<0.01&&fabs(train->ycoordinate-train->checkpoint[1][1])<0.01){
				commontrack1 = 0;
				istrain1 = 0;
			}
			else if(train->stoptime!=0&&fabs(train->xcoordinate-(train->checkpoint[0][0]+train->checkpoint[1][0])/2)<0.01&&fabs(train->ycoordinate-(train->checkpoint[0][1]+train->checkpoint[1][1])/2)<0.01){
				printf("火车%d在公共轨道1停靠.\n",train->number);
				train->state=0;
				begin1=clock();
				TimeControl(train->stoptime);
				train->state=1;
				printf("火车%d停靠时间结束.\n",train->number);
			} 
			break;
		case 2:
			if(fabs(train->xcoordinate-train->checkpoint[0][0])<0.01&&fabs(train->ycoordinate-train->checkpoint[0][1])<0.01){
				if(commontrack2==0&&istrain31==1){
					commontrack2=1;
					Control(&train2, &train3, controlstrategy);
				}
				else if(commontrack2==0&&istrain31==0){
					train->state = 1;
					commontrack2=1;
				}
			}
			else if(fabs(train->xcoordinate-train->checkpoint[1][0])<0.01&&fabs(train->ycoordinate-train->checkpoint[1][1])<0.01){
				commontrack2=0;
				istrain2=0;
			}
			else if(train->stoptime!=0&&fabs(train->xcoordinate-(train->checkpoint[0][0]+train->checkpoint[1][0])/2)<0.01&&fabs(train->ycoordinate-(train->checkpoint[0][1]+train->checkpoint[1][1])/2)<0.01){
				printf("火车%d在公共轨道2停靠.\n",train->number);
				train->state=0;
				begin2=clock();
				TimeControl(train->stoptime);
				train->state=1;
				printf("火车%d停靠时间结束.\n",train->number);
			} 
			break;
		case 3:
			if(fabs(train->xcoordinate-train->checkpoint[0][0])<0.01&&fabs(train->ycoordinate-train->checkpoint[0][1])<0.01){
				if(commontrack2==0&&istrain2==1){
					commontrack2=1;
					Control(&train2, &train3, controlstrategy);
				}
				else if(commontrack2==0&&istrain2==0){
					train->state=1;
					commontrack2=1;
				}
			}
			else if(fabs(train->xcoordinate-train->checkpoint[1][0])<0.01&&fabs(train->ycoordinate-train->checkpoint[1][1])<0.01){
				commontrack2=0;
				istrain31=0;
			}
			else if(fabs(train->xcoordinate-train->checkpoint[2][0])<0.01&&fabs(train->ycoordinate-train->checkpoint[2][1])<0.01){
				if(commontrack1==0&&istrain1==1){
					commontrack1=1;
					Control(&train1, &train3, controlstrategy);
				}
				else if (commontrack1 == 0 && istrain1==0) {
					train->state=1;
					commontrack1 = 1;
				}
			}
			else if(fabs(train->xcoordinate-train->checkpoint[3][0])<0.01&&fabs(train->ycoordinate-train->checkpoint[3][1])<0.01){
				commontrack1=0;
				istrain33=0;
			}
			else if(train->stoptime!=0&&fabs(train->xcoordinate-(train->checkpoint[0][0]+train->checkpoint[1][0])/2)<0.01&&fabs(train->ycoordinate-(train->checkpoint[0][1]+train->checkpoint[1][1])/2)<0.01){
				printf("火车%d在公共轨道2停靠.\n",train->number);
				train->state=0;
				begin32=clock();
				TimeControl(train->stoptime);
				train->state=1;
				printf("火车%d停靠时间结束.\n",train->number); 
			} 
			else if(train->stoptime!=0&&fabs(train->xcoordinate-(train->checkpoint[2][0]+train->checkpoint[3][0])/2)<0.01&&fabs(train->ycoordinate-(train->checkpoint[2][1]+train->checkpoint[3][1])/2)<0.01){
				printf("火车%d在公共轨道1停靠.\n",train->number);
				train->state=0;
				begin31=clock();
				TimeControl(train->stoptime);
				train->state=1;
				printf("火车%d停靠时间结束.\n",train->number);
			} 
			break;
	}
}

/*计时函数，该函数运行t时间后结束*/
void TimeControl(double t)
{
	clock_t begin,end;
	begin=clock();
	double duration=0;
	while(duration<t){
    	end = clock();
    	duration = (double)(end - begin) / CLOCKS_PER_SEC; 
    }
}
