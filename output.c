#include<stdlib.h>
#include<stdio.h> 
#include"output.h"
#include"trainrun.h"

extern int controlstrategy;
extern int commontrack1,commontrack2;//�����ⲿ���� 
extern TRAIN train1,train2,train3;//�����ⲿ���� 
extern int istrain1,istrain31,istrain33,istrain2;//�����ⲿ���� 

/*��ӡ������Ϣ*/ 
void PrintInfo(void)
{
	int time = 1;
	FILE* fptr;
	fptr = fopen("file\\report.txt", "w");
	if (fptr == NULL)
		printf("�ļ���ʧ��\n");
	else {
		fclose(fptr);
		while (1) {
			fptr = fopen("file\\report.txt", "a+");
			if (fptr == NULL)
				printf("�ļ���ʧ��\n");
			else {
				TimeControl(1);
				system("cls"); 
				printf("������Ҫִ�еĲ���\n");
				printf("1.�޸Ļ��ٶ�\n");
				printf("2.�ı���Ʋ���\n");
				printf("3.��������(��ͣ\\����)\n"); 
				printf("4.�޸Ļ�ͣ��ʱ��\n");
				printf("����������%d��\n", time);
				fprintf(fptr, "����������%d��\n", time);
				switch (controlstrategy) {
				case 1:
					printf("��ǰ�Ŀ��Ʋ���Ϊ�쳵����\n");
					fprintf(fptr, "��ǰ�Ŀ��Ʋ���Ϊ�쳵����\n");
					break;
				case 2:
					printf("��ǰ�Ŀ��Ʋ���Ϊ��������\n");
					fprintf(fptr, "��ǰ�Ŀ��Ʋ���Ϊ��������\n");
					break;
				case 3:
					printf("��ǰ�Ŀ��Ʋ���Ϊ�˹�����\n");
					fprintf(fptr, "��ǰ�Ŀ��Ʋ���Ϊ�˹�����\n");
					break;
				}
				switch (commontrack1) {//����������1��״̬ 
				case 1:
					if (train1.state == 1 && istrain1 == 1) {
						printf("�������1����1ռ��\n");
						fprintf(fptr, "1�Ź��������1�ų�ռ��\n");
					}
					else if (train3.state == 1 && istrain33 == 1) {
						printf("�������1����3ռ��\n");
						fprintf(fptr, "1�Ź��������3�ų�ռ��\n");
					}
					else if(train1.state==0&&train1.xcoordinate==(train1.checkpoint[0][0]+train1.checkpoint[1][0])/2&&train1.ycoordinate==(train1.checkpoint[0][1]+train1.checkpoint[1][1])/2){
						printf("��1�ڹ������1�м�ͣ��\n");
						fprintf(fptr,"��1�ڹ������1�м�ͣ��\n");
					} 
					else if(train3.state==0&&train3.xcoordinate==(train3.checkpoint[2][0]+train3.checkpoint[3][0])/2&&train3.ycoordinate==(train3.checkpoint[2][1]+train3.checkpoint[3][1])/2){
						printf("��3�ڹ������1�м�ͣ��\n");
						fprintf(fptr,"��3�ڹ������1�м�ͣ��\n");
					} 
					else {
						printf("�������1δ��ռ��\n");
						fprintf(fptr, "�������1δ��ռ��\n");
					}
					break;
				case 0:
					printf("�������1δ��ռ��\n");
					fprintf(fptr, "�������1δ��ռ��\n");
					break;
				}
				switch (commontrack2) {//����������2��״̬ 
				case 1:
					if (train2.state == 1 && istrain2 == 1) {
						printf("�������2����2ռ��\n");
						fprintf(fptr, "2�Ź��������2�ų�ռ��\n");
					}

					else if (train3.state == 1 && istrain31 == 1) {
						printf("�������2����3ռ��\n");
						fprintf(fptr, "2�Ź��������3�ų�ռ��\n");
					}
					else if(train2.state==0&&train2.xcoordinate==(train2.checkpoint[0][0]+train2.checkpoint[1][0])/2&&train2.ycoordinate==(train2.checkpoint[0][1]+train2.checkpoint[1][1])/2){
						printf("��2�ڹ������2�м�ͣ��\n");
						fprintf(fptr,"��2�ڹ������2�м�ͣ��\n");
					} 
					else if(train3.state==0&&train3.xcoordinate==(train3.checkpoint[0][0]+train3.checkpoint[1][0])/2&&train3.ycoordinate==(train3.checkpoint[0][1]+train3.checkpoint[1][1])/2){
						printf("��3�ڹ������2�м�ͣ��\n");
						fprintf(fptr,"��3�ڹ������2�м�ͣ��\n");
					} 
					else {
						printf("�������2δ��ռ��\n");
						fprintf(fptr, "�������2δ��ռ��\n");
					}
					break;
				case 0:
					printf("�������2δ��ռ��\n");
					fprintf(fptr, "�������2δ��ռ��\n");
					break;
				}
				time++;
				fprintf(fptr, "train1:\nx:%f y:%f state:%d direction:%d istrain1:%d\n", train1.xcoordinate, train1.ycoordinate, train1.state, train1.direction, istrain1);
				printf("train1:\nx:%f y:%f state:%d direction:%d\n", train1.xcoordinate, train1.ycoordinate, train1.state, train1.direction, istrain1);
				fprintf(fptr, "train2:\nx:%f y:%f state:%d direction:%d istrain2:%d\n", train2.xcoordinate, train2.ycoordinate, train2.state, train2.direction, istrain2);
				printf("train2:\nx:%f y:%f state:%d direction:%d\n", train2.xcoordinate, train2.ycoordinate, train2.state, train2.direction, istrain2);
				fprintf(fptr, "train3:\nx:%f y:%f state:%d direction:%d istrain31:%d istrain33:%d\n", train3.xcoordinate, train3.ycoordinate, train3.state, train3.direction, istrain31, istrain33);
				printf("train3:\nx:%f y:%f state:%d direction:%d\n", train3.xcoordinate, train3.ycoordinate, train3.state, train3.direction, istrain31, istrain33);
				fputc('\n', fptr);
				putchar('\n');
				fclose(fptr);
				printf("===============================================\n"); 
			}
		}
	}
}
void PrintSpaInfo(void)
{
	FILE* fptr;
	fptr = fopen("file\\report.txt", "a+");
	if (fptr == NULL)
		printf("�ļ���ʧ��\n");
	else{
		fprintf(fptr,"����λ�����\n");
		fprintf(fptr, "train1:\nx:%f y:%f state:%d direction:%d speed:%d istrain1:%d\n", train1.xcoordinate, train1.ycoordinate, train1.state, train1.direction, train1.speed,istrain1);
		fprintf(fptr, "train2:\nx:%f y:%f state:%d direction:%d speed:%d istrain2:%d\n", train2.xcoordinate, train2.ycoordinate, train2.state, train2.direction, train2.speed,istrain2);
		fprintf(fptr, "train3:\nx:%f y:%f state:%d direction:%d speed:%d istrain31:%d istrain33:%d\n", train3.xcoordinate, train3.ycoordinate, train3.state, train3.direction, train3.speed,istrain31, istrain33);
		fputc('\n', fptr);
		fclose(fptr);		
	}
}
