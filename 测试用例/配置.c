#include<stdio.h>
#include<stdlib.h> 
main()
{
	FILE *fptr=NULL;
	int num,speed,x,y,starttime,stoptime,direction,rounddirection;
	int bend[4][2];
	int checkpoint[4][2];
	while (1) {
		printf("请输入你要修改的火车编号:");
		scanf("%d", &num);
		switch (num) {
		case 1:
			fopen_s(&fptr, "train1.txt", "w");
			if (fptr == NULL)
				printf("文件打开失败!\n");
			else {
				printf("请输入火车速度、发车时间、绕行方向(0表示顺时针,1表示逆时针)、公共轨道停靠时间、x坐标、y坐标:");
				scanf("%d %d %d %d %d %d", &speed, &starttime, &rounddirection, &stoptime, &x, &y);
				fprintf(fptr, "%d %d %d %d %d %d %d\n", speed, rounddirection, 0, starttime, stoptime, x, y);
				printf("请输入四个弯道的位置:");
				scanf("%d %d %d %d %d %d %d %d", &bend[0][0], &bend[0][1], &bend[1][0], &bend[1][1], &bend[2][0], &bend[2][1], &bend[3][0], &bend[3][1]);
				fprintf(fptr, "%d %d %d %d %d %d %d %d\n", bend[0][0], bend[0][1], bend[1][0], bend[1][1], bend[2][0], bend[2][1], bend[3][0], bend[3][1]);
				printf("请输入初始方向(1:EAST 2:SOUTH 3:WEST 4:NORTH):");
				scanf("%d", &direction);
				fprintf(fptr, "%d\n", direction);
				printf("请输入两个监测点位置:");
				scanf("%d %d %d %d", &checkpoint[0][0], &checkpoint[0][1], &checkpoint[1][0], &checkpoint[1][1]);
				fprintf(fptr, "%d %d %d %d\n", checkpoint[0][0], checkpoint[0][1], checkpoint[1][0], checkpoint[1][1]);
			}
			fclose(fptr); 
			break;
		case 2:
			fopen_s(&fptr, "train2.txt", "w");
			if (fptr == NULL)
				printf("文件打开失败!\n");
			else {
				printf("请输入火车速度、发车时间、绕行方向(0表示顺时针,1表示逆时针)、公共轨道停靠时间、x坐标、y坐标:");
				scanf("%d %d %d %d %d %d", &speed, &starttime, &rounddirection, &stoptime, &x, &y);
				fprintf(fptr, "%d %d %d %d %d %d %d\n", speed, rounddirection, 0, starttime, stoptime, x, y);
				printf("请输入四个弯道的位置:");
				scanf("%d %d %d %d %d %d %d %d", &bend[0][0], &bend[0][1], &bend[1][0], &bend[1][1], &bend[2][0], &bend[2][1], &bend[3][0], &bend[3][1]);
				fprintf(fptr, "%d %d %d %d %d %d %d %d\n", bend[0][0], bend[0][1], bend[1][0], bend[1][1], bend[2][0], bend[2][1], bend[3][0], bend[3][1]);
				printf("请输入初始方向(1:EAST 2:SOUTH 3:WEST 4:NORTH):");
				scanf("%d", &direction);
				fprintf(fptr, "%d\n", direction);
				printf("请输入两个监测点位置:");
				scanf("%d %d %d %d", &checkpoint[0][0], &checkpoint[0][1], &checkpoint[1][0], &checkpoint[1][1]);
				fprintf(fptr, "%d %d %d %d\n", checkpoint[0][0], checkpoint[0][1], checkpoint[1][0], checkpoint[1][1]);
			}
			fclose(fptr);
			break;
		case 3:
			fopen_s(&fptr, "train3.txt", "w");
			if (fptr == NULL)
				printf("文件打开失败!\n");
			else {
				printf("请输入火车速度、发车时间、绕行方向(0表示顺时针,1表示逆时针)、公共轨道停靠时间、x坐标、y坐标:");
				scanf("%d %d %d %d %d %d", &speed, &starttime, &rounddirection, &stoptime, &x, &y);
				fprintf(fptr, "%d %d %d %d %d %d %d\n", speed, rounddirection, 0, starttime, stoptime, x, y);
				printf("请输入四个弯道的位置:");
				scanf("%d %d %d %d %d %d %d %d", &bend[0][0], &bend[0][1], &bend[1][0], &bend[1][1], &bend[2][0], &bend[2][1], &bend[3][0], &bend[3][1]);
				fprintf(fptr, "%d %d %d %d %d %d %d %d\n", bend[0][0], bend[0][1], bend[1][0], bend[1][1], bend[2][0], bend[2][1], bend[3][0], bend[3][1]);
				printf("请输入初始方向(1:EAST 2:SOUTH 3:WEST 4:NORTH):");
				scanf("%d", &direction);
				fprintf(fptr, "%d\n", direction);
				printf("请输入四个监测点位置:");
				scanf("%d %d %d %d %d %d %d %d", &checkpoint[0][0], &checkpoint[0][1], &checkpoint[1][0], &checkpoint[1][1], &checkpoint[2][0], &checkpoint[2][1], &checkpoint[3][0], &checkpoint[3][1]);
				fprintf(fptr, "%d %d %d %d %d %d %d %d\n", checkpoint[0][0], checkpoint[0][1], checkpoint[1][0], checkpoint[1][1], checkpoint[2][0], checkpoint[2][1], checkpoint[3][0], checkpoint[3][1]);
			}
			fclose(fptr);
			break;
		}
	 }
	}
	
