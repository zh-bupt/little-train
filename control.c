#include "control.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

extern TRAIN train1,train2,train3;//�����ⲿ���� 
int controlstrategy=1;//���Ʋ��ԣ�1��ʾ�쳵���Ȳ��ԣ�2��ʾ������ԣ�3��ʾ�˹����� 
static int last1=1;//�������ƽ�����Եľ�̬ȫ�ֱ��� 
static int last2=1;//�������ƽ�����Եľ�̬ȫ�ֱ���

/*��������ͬʱ���﹫�����ʱ�ж������𳵽��빫�����*/ 
void Control(TRAIN *t1,TRAIN *t2,int controlstrategy)
{
	printf("\a��%d�ͻ�%d������빫�����\n",t1->number,t2->number);
	switch(controlstrategy){
		case 1://��controlstrategyΪ1ʱ���ÿ쳵���Ȳ��� 
			FastFirst(t1,t2);
			break;
		case 2://��controlstrategyΪ2ʱ���ý������Ȳ��� 
			Alternate(t1,t2);
			break;
		case 3://��controlstrategyΪ3ʱ�����˹����Ʋ��� 
		    ManualOperation(t1,t2); 
	}
 } 
 
 /*�쳵���Ȳ���*/ 
 void FastFirst(TRAIN *t1,TRAIN *t2)
 { 
 	if(t1->speed > t2->speed){//�ж�t1��t2���ٶȣ��ٶȴ�Ľ��빫����� 
 		 t1->state=1;
		  printf("��%d���빫�����.\n",t1->number);	
	 }
 	else{
 		t2->state=1;
 		printf("��%d���빫�����.\n",t2->number);
	 }
 }
 
 /*�������Ȳ���*/ 
 void Alternate(TRAIN *t1,TRAIN *t2)
{
    if(t1->number==1&&t2->number==3){//���ж�Ϊ�����������ô˲��� 
    	if(last1==1){//����last��ֵ�ж����������빫����� 
		  last1=2;
		  t1->state=1;
		  printf("��%d���빫�����.\n",t1->number);
		}
    	else{
    	  last1=1;
    	  t2->state=1;
    	  printf("��%d���빫�����.\n",t2->number);
		}
	}
	else{
		if(last2==1){
		   last2=2;
		   t1->state=1;
		   printf("��%d���빫�����.\n",t1->number);
		}
		else{
			last2=1;
			t2->state=1;
			printf("��%d���빫�����.\n",t2->number);
		}
	}
}

/*�˹����Ʋ���*/ 
 void ManualOperation(TRAIN *t1, TRAIN *t2)
 {
	 int num=0;
	 printf("��%d�ͻ�%d���빫���������ѡ����빫������Ļ�:\n",t1->number,t2->number);
 }
 
  void Operate(void)
 {
 	int num1/*����ѡ��*/,num2/*�𳵱��*/,num3/*�𳵲���*/;
 	char command;
	printf("������Ҫִ�еĲ���\n");
	printf("1.�޸Ļ��ٶ�\n");
	printf("2.�ı���Ʋ���\n");
	printf("3.��������(��ͣ\\����)\n"); 
	printf("4.�޸Ļ�ͣ��ʱ��\n"); 
	 while(1){ 
	 	scanf("%d",&num1);
 		switch(num1){
 			case 1:
 				printf("��ѡ����Ҫ�޸ĵĻ�\n");
 				scanf("%d",&num2);
				printf("�����޸ĺ�Ļ��ٶ�\n");
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
 				printf("��������Ʋ���(1Ϊ�쳵���ȣ�2Ϊ������ԣ�3Ϊ�˹�����)\n");
 				scanf("%d",&controlstrategy);
 				break;
 			case 3:
 				printf("���������ָ��A,B,C�ֱ��ʾ��1,2,3��ֹͣ;a,b,c�ֱ��ʾ��1,2,3,������\n");
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
				printf("��ѡ����Ҫ�޸ĵĻ�\n");
 				scanf("%d",&num3);
				printf("�����޸ĺ��ͣ��ʱ��\n");
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
