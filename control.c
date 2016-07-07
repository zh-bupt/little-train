#include "control.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

extern TRAIN train1,train2,train3;//声明外部变量 
int controlstrategy=1;//控制策略：1表示快车优先策略，2表示交替策略，3表示人工控制 
static int last1=1;//用来控制交替策略的静态全局变量 
static int last2=1;//用来控制交替策略的静态全局变量

/*当两辆火车同时到达公共轨道时判断哪辆火车进入公共轨道*/ 
void Control(TRAIN *t1,TRAIN *t2,int controlstrategy)
{
	printf("\a火车%d和火车%d申请进入公共轨道\n",t1->number,t2->number);
	switch(controlstrategy){
		case 1://当controlstrategy为1时调用快车优先策略 
			FastFirst(t1,t2);
			break;
		case 2://当controlstrategy为2时调用交替优先策略 
			Alternate(t1,t2);
			break;
		case 3://当controlstrategy为3时调用人工控制策略 
		    ManualOperation(t1,t2); 
	}
 } 
 
 /*快车优先策略*/ 
 void FastFirst(TRAIN *t1,TRAIN *t2)
 { 
 	if(t1->speed > t2->speed){//判断t1与t2的速度，速度大的进入公共轨道 
 		 t1->state=1;
		  printf("火车%d进入公共轨道.\n",t1->number);	
	 }
 	else{
 		t2->state=1;
 		printf("火车%d进入公共轨道.\n",t2->number);
	 }
 }
 
 /*交替优先策略*/ 
 void Alternate(TRAIN *t1,TRAIN *t2)
{
    if(t1->number==1&&t2->number==3){//先判断为哪两辆车调用此策略 
    	if(last1==1){//根据last的值判断哪辆车进入公共轨道 
		  last1=2;
		  t1->state=1;
		  printf("火车%d进入公共轨道.\n",t1->number);
		}
    	else{
    	  last1=1;
    	  t2->state=1;
    	  printf("火车%d进入公共轨道.\n",t2->number);
		}
	}
	else{
		if(last2==1){
		   last2=2;
		   t1->state=1;
		   printf("火车%d进入公共轨道.\n",t1->number);
		}
		else{
			last2=1;
			t2->state=1;
			printf("火车%d进入公共轨道.\n",t2->number);
		}
	}
}

/*人工控制策略*/ 
 void ManualOperation(TRAIN *t1, TRAIN *t2)
 {
	 int num=0;
	 printf("火车%d和火车%d申请公共轨道，请选择进入公共轨道的火车:\n",t1->number,t2->number);
 }
 
  void Operate(void)
 {
 	int num1/*功能选择*/,num2/*火车编号*/,num3/*火车参数*/;
 	char command;
	printf("输入你要执行的操作\n");
	printf("1.修改火车速度\n");
	printf("2.改变控制策略\n");
	printf("3.输入命令(暂停\\运行)\n"); 
	printf("4.修改火车停靠时间\n"); 
	 while(1){ 
	 	scanf("%d",&num1);
 		switch(num1){
 			case 1:
 				printf("请选择你要修改的火车\n");
 				scanf("%d",&num2);
				printf("输入修改后的火车速度\n");
				switch(num2){
					case 1:
						scanf("%d",&train1.speed); 
						break;
					case 2:
						scanf("%d",&train2.speed); 
						break;
					case 3:
						scanf("%d",&train3.speed); 
						break;
				}
				break;
 			case 2:
 				printf("请输入控制策略(1为快车优先，2为交替策略，3为人工控制)\n");
 				scanf("%d",&controlstrategy);
 				break;
 			case 3:
 				printf("请输入你的指令A,B,C分别表示让1,2,3火车停止;a,b,c分别表示让1,2,3,火车启动\n");
 				scanf("%c",&command);
 				if(command=='A')
				  train1.state=0;
				else if(command=='B')
				  train2.state=0;
				else if(command=='C')
				  train3.state=0;
				else if(command=='a')
				  train1.state=1;
				else if(command=='b')
				  train2.state=1;
				else if(command=='c')
				  train3.state=1; 
				break; 
			case 4:
				printf("请选择你要修改的火车\n");
 				scanf("%d",&num3);
				printf("输入修改后的停靠时间\n");
				switch(num3){
					case 1:
						scanf("%d",&train1.stoptime); 
						break;
					case 2:
						scanf("%d",&train2.stoptime); 
						break;
					case 3:
						scanf("%d",&train3.stoptime); 
						break;
				}
				break;
 	     }
	 }
 }
