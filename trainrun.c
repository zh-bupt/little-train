#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include"trainrun.h" 
#include"control.h"
#include "egg.h"
#include "drawtrain.h"
#include<math.h>
int commontrack1=0;//�������1��״̬��0��ʾ���У�1��ʾռ�� 
int commontrack2=0;//�������2��״̬��0��ʾ���У�1��ʾռ�� 
int istrain1=0;//��1�������ı�־��1��ʾ������㣬����ʹ����Ӧ����ʱ��Ϊ0 
int istrain31=0;//��3�������ı�־��1��ʾ�������1������ʹ����Ӧ����ʱ��Ϊ0  
int istrain33=0;//��3�������ı�־��1��ʾ�������2������ʹ����Ӧ����ʱ��Ϊ0  
int istrain2=0;//��2�������ı�־��1��ʾ������� ������ʹ����Ӧ����ʱ��Ϊ0 
extern clock_t begin1,begin31,begin2,begin32,end; 

extern HEGG hEggs[3];
extern TRAIN train1,train2,train3;//�����ⲿ���� 
extern int controlstrategy;//�����ⲿ���� 

/*�����к���(˳ʱ������)*/ 
void TrainRun(TRAIN *train)
{
	Monitor1(train);//����λ�� 
	while(1){
		Sleep(1000/train->speed);//ʱ����ƣ��û���һ���ٶ����� 
		Monitor2(train);//����λ�� 
		if(train->state){//���ƻ����� 
		if(fabs(train->xcoordinate-train->bend[0][0])<0.01&&fabs(train->ycoordinate-train->bend[0][1])<0.01){//���ת�䣬���ƶ� 
			train->direction=EAST;
			train->xcoordinate=train->xcoordinate+0.1;
		}
		else if(fabs(train->xcoordinate-train->bend[1][0])<0.01&&fabs(train->ycoordinate-train->bend[1][1])<0.01){//���ת�䣬���ƶ� 
			train->direction=SOUTH;
			train->ycoordinate=train->ycoordinate-0.1;
		}
		else if(fabs(train->xcoordinate-train->bend[2][0])<0.01&&fabs(train->ycoordinate-train->bend[2][1])<0.01){//���ת�䣬���ƶ� 
			train->direction=WEST;
			train->xcoordinate=train->xcoordinate-0.1;
		}
		else if(fabs(train->xcoordinate-train->bend[3][0])<0.01&&fabs(train->ycoordinate-train->bend[3][1])<0.01){//���ת�䣬���ƶ� 
			train->direction=NORTH;
			train->ycoordinate=train->ycoordinate+0.1;
		}
		else{//ֱ����ֱ���ƶ� 
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
		Monitor1(train);//����λ��
	}
}

/*�����к���(��ʱ������)*/ 
void TrainRun2(TRAIN *train)
{
	Monitor1(train);//����λ��
	while(1){
		Sleep(1000/train->speed);
		Monitor2(train);//����λ��
		if(train->state){
		if(fabs(train->xcoordinate-train->bend[0][0])<0.01&&fabs(train->ycoordinate-train->bend[0][1])<0.01){//���ת�䣬���ƶ� 
			train->direction=SOUTH;
			train->ycoordinate=train->ycoordinate-0.1;

		}
		else if(fabs(train->xcoordinate-train->bend[1][0])<0.01&&fabs(train->ycoordinate-train->bend[1][1])<0.01){//���ת�䣬���ƶ� 
			train->direction=WEST;
			train->xcoordinate=train->xcoordinate-0.1;

		}
		else if(fabs(train->xcoordinate-train->bend[2][0])<0.01&&fabs(train->ycoordinate-train->bend[2][1])<0.01){//���ת�䣬���ƶ� 
			train->direction=NORTH;
			train->ycoordinate=train->ycoordinate+0.1;

		}
		else if(fabs(train->xcoordinate-train->bend[3][0])<0.01&&fabs(train->ycoordinate-train->bend[3][1])<0.01){//���ת�䣬���ƶ� 
			train->direction=EAST;
			train->xcoordinate=train->xcoordinate+0.1;

		}
		else{//ֱ����ֱ���ƶ� 
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
		Monitor1(train);//����λ��
	}
}

/*�Ի𳵽������ʱ���м�⼰�����ı�*/ 
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

/*�Ի�ʻ��������м�⼰�����ı�*/ 
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
				printf("��%d�ڹ������1ͣ��.\n",train->number);
				train->state=0;
				begin1=clock();
				TimeControl(train->stoptime);
				train->state=1;
				printf("��%dͣ��ʱ�����.\n",train->number);
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
				printf("��%d�ڹ������2ͣ��.\n",train->number);
				train->state=0;
				begin2=clock();
				TimeControl(train->stoptime);
				train->state=1;
				printf("��%dͣ��ʱ�����.\n",train->number);
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
				printf("��%d�ڹ������2ͣ��.\n",train->number);
				train->state=0;
				begin32=clock();
				TimeControl(train->stoptime);
				train->state=1;
				printf("��%dͣ��ʱ�����.\n",train->number); 
			} 
			else if(train->stoptime!=0&&fabs(train->xcoordinate-(train->checkpoint[2][0]+train->checkpoint[3][0])/2)<0.01&&fabs(train->ycoordinate-(train->checkpoint[2][1]+train->checkpoint[3][1])/2)<0.01){
				printf("��%d�ڹ������1ͣ��.\n",train->number);
				train->state=0;
				begin31=clock();
				TimeControl(train->stoptime);
				train->state=1;
				printf("��%dͣ��ʱ�����.\n",train->number);
			} 
			break;
	}
}

/*��ʱ�������ú�������tʱ������*/
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
