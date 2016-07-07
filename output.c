#include<stdlib.h>
#include<stdio.h> 
#include"output.h"
#include"trainrun.h"

extern int controlstrategy;
extern int commontrack1,commontrack2;//声明外部变量 
extern TRAIN train1,train2,train3;//声明外部变量 
extern int istrain1,istrain31,istrain33,istrain2;//声明外部变量 

/*打印各种信息*/ 
void PrintInfo(void)
{
	int time = 1;
	FILE* fptr;
	fptr = fopen("file\\report.txt", "w");
	if (fptr == NULL)
		printf("文件打开失败\n");
	else {
		fclose(fptr);
		while (1) {
			fptr = fopen("file\\report.txt", "a+");
			if (fptr == NULL)
				printf("文件打开失败\n");
			else {
				TimeControl(1);
				system("cls"); 
				printf("输入你要执行的操作\n");
				printf("1.修改火车速度\n");
				printf("2.改变控制策略\n");
				printf("3.输入命令(暂停\\运行)\n"); 
				printf("4.修改火车停靠时间\n");
				printf("程序已运行%d秒\n", time);
				fprintf(fptr, "程序已运行%d秒\n", time);
				switch (controlstrategy) {
				case 1:
					printf("当前的控制策略为快车优先\n");
					fprintf(fptr, "当前的控制策略为快车优先\n");
					break;
				case 2:
					printf("当前的控制策略为交替优先\n");
					fprintf(fptr, "当前的控制策略为交替优先\n");
					break;
				case 3:
					printf("当前的控制策略为人工控制\n");
					fprintf(fptr, "当前的控制策略为人工控制\n");
					break;
				}
				switch (commontrack1) {//输出公共轨道1的状态 
				case 1:
					if (train1.state == 1 && istrain1 == 1) {
						printf("公共轨道1被火车1占用\n");
						fprintf(fptr, "1号公共轨道被1号车占用\n");
					}
					else if (train3.state == 1 && istrain33 == 1) {
						printf("公共轨道1被火车3占用\n");
						fprintf(fptr, "1号公共轨道被3号车占用\n");
					}
					else if(train1.state==0&&train1.xcoordinate==(train1.checkpoint[0][0]+train1.checkpoint[1][0])/2&&train1.ycoordinate==(train1.checkpoint[0][1]+train1.checkpoint[1][1])/2){
						printf("火车1在公共轨道1中间停靠\n");
						fprintf(fptr,"火车1在公共轨道1中间停靠\n");
					} 
					else if(train3.state==0&&train3.xcoordinate==(train3.checkpoint[2][0]+train3.checkpoint[3][0])/2&&train3.ycoordinate==(train3.checkpoint[2][1]+train3.checkpoint[3][1])/2){
						printf("火车3在公共轨道1中间停靠\n");
						fprintf(fptr,"火车3在公共轨道1中间停靠\n");
					} 
					else {
						printf("公共轨道1未被占用\n");
						fprintf(fptr, "公共轨道1未被占用\n");
					}
					break;
				case 0:
					printf("公共轨道1未被占用\n");
					fprintf(fptr, "公共轨道1未被占用\n");
					break;
				}
				switch (commontrack2) {//输出公共轨道2的状态 
				case 1:
					if (train2.state == 1 && istrain2 == 1) {
						printf("公共轨道2被火车2占用\n");
						fprintf(fptr, "2号公共轨道被2号车占用\n");
					}

					else if (train3.state == 1 && istrain31 == 1) {
						printf("公共轨道2被火车3占用\n");
						fprintf(fptr, "2号公共轨道被3号车占用\n");
					}
					else if(train2.state==0&&train2.xcoordinate==(train2.checkpoint[0][0]+train2.checkpoint[1][0])/2&&train2.ycoordinate==(train2.checkpoint[0][1]+train2.checkpoint[1][1])/2){
						printf("火车2在公共轨道2中间停靠\n");
						fprintf(fptr,"火车2在公共轨道2中间停靠\n");
					} 
					else if(train3.state==0&&train3.xcoordinate==(train3.checkpoint[0][0]+train3.checkpoint[1][0])/2&&train3.ycoordinate==(train3.checkpoint[0][1]+train3.checkpoint[1][1])/2){
						printf("火车3在公共轨道2中间停靠\n");
						fprintf(fptr,"火车3在公共轨道2中间停靠\n");
					} 
					else {
						printf("公共轨道2未被占用\n");
						fprintf(fptr, "公共轨道2未被占用\n");
					}
					break;
				case 0:
					printf("公共轨道2未被占用\n");
					fprintf(fptr, "公共轨道2未被占用\n");
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
		printf("文件打开失败\n");
	else{
		fprintf(fptr,"特殊位置输出\n");
		fprintf(fptr, "train1:\nx:%f y:%f state:%d direction:%d speed:%d istrain1:%d\n", train1.xcoordinate, train1.ycoordinate, train1.state, train1.direction, train1.speed,istrain1);
		fprintf(fptr, "train2:\nx:%f y:%f state:%d direction:%d speed:%d istrain2:%d\n", train2.xcoordinate, train2.ycoordinate, train2.state, train2.direction, train2.speed,istrain2);
		fprintf(fptr, "train3:\nx:%f y:%f state:%d direction:%d speed:%d istrain31:%d istrain33:%d\n", train3.xcoordinate, train3.ycoordinate, train3.state, train3.direction, train3.speed,istrain31, istrain33);
		fputc('\n', fptr);
		fclose(fptr);		
	}
}
