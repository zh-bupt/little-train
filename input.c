#include "input.h"
#include<stdio.h>

/*初始化定义火车信息*/
void initialize(TRAIN *train) 
{
	int choose;
	    printf("请对%d号火车选择命令行配置(1)或文件配置(2):",train->number);
	    scanf("%d",&choose);
	    if(choose==1){
			printf("请输入%d号火车速度、发车时间、绕行方向(0表示顺时针,1表示逆时针)、公共轨道停靠时间、x坐标、y坐标:", train->number);
			scanf("%d %d %d %d %f %f", &train->speed, &train->starttime, &train->rounddirection, &train->stoptime, &train->xcoordinate, &train->ycoordinate);
			printf("请输入四个弯道的位置:");
			scanf("%f %f %f %f %f %f %f %f", &train->bend[0][0], &train->bend[0][1], &train->bend[1][0], &train->bend[1][1], &train->bend[2][0], &train->bend[2][1], &train->bend[3][0], &train->bend[3][1]);
			printf("请输入初始方向(1:EAST 2:SOUTH 3:WEST 4:NORTH):");
			scanf("%d", &train->direction);
			if(train->number==3)
			{
			  printf("请输入四个监测点位置:");
			  scanf("%f %f %f %f %f %f %f %f", &train->checkpoint[0][0], &train->checkpoint[0][1], &train->checkpoint[1][0], &train->checkpoint[1][1],&train->checkpoint[2][0], &train->checkpoint[2][1], &train->checkpoint[3][0], &train->checkpoint[3][1]);
			}
			else
			{
			  printf("请输入两个监测点位置:");
			  scanf("%f %f %f %f", &train->checkpoint[0][0], &train->checkpoint[0][1], &train->checkpoint[1][0], &train->checkpoint[1][1]);
	        }
		}
		else{
			FILE *fptr = NULL;
			switch (train->number) {
			case 1:
				fopen_s(&fptr, "file\\train1.txt", "r");
				if (fptr == NULL)
					printf("配置文件打开失败!\n");
				else {
					fscanf_s(fptr, "%d %d %d %d %d %f %f", &train->speed, &train->rounddirection, &train->state, &train->starttime, &train->stoptime, &train->xcoordinate, &train->ycoordinate);
					fscanf_s(fptr, "%f %f %f %f %f %f %f %f", &train->bend[0][0], &train->bend[0][1], &train->bend[1][0], &train->bend[1][1], &train->bend[2][0], &train->bend[2][1], &train->bend[3][0], &train->bend[3][1]);
					fscanf_s(fptr, "%d", &train->direction);
					fscanf_s(fptr, "%f %f %f %f", &train->checkpoint[0][0], &train->checkpoint[0][1], &train->checkpoint[1][0], &train->checkpoint[1][1]);
				}
				fclose(fptr);
				break;
			case 2:
				fopen_s(&fptr, "file\\train2.txt", "r");
				if (fptr == NULL)
					printf("配置文件打开失败!\n");
				else {
					fscanf_s(fptr, "%d %d %d %d %d %f %f", &train->speed, &train->rounddirection, &train->state, &train->starttime, &train->stoptime, &train->xcoordinate, &train->ycoordinate);
					fscanf_s(fptr, "%f %f %f %f %f %f %f %f", &train->bend[0][0], &train->bend[0][1], &train->bend[1][0], &train->bend[1][1], &train->bend[2][0], &train->bend[2][1], &train->bend[3][0], &train->bend[3][1]);
					fscanf_s(fptr, "%d", &train->direction);
					fscanf_s(fptr, "%f %f %f %f", &train->checkpoint[0][0], &train->checkpoint[0][1], &train->checkpoint[1][0], &train->checkpoint[1][1]);
				}
				fclose(fptr);
				break;
			case 3:
				fopen_s(&fptr, "file\\train3.txt", "r");
				if (fptr == NULL)
					printf("配置文件打开失败!\n");
				else {
					fscanf_s(fptr, "%d %d %d %d %d %f %f", &train->speed, &train->rounddirection, &train->state, &train->starttime, &train->stoptime, &train->xcoordinate, &train->ycoordinate);
					fscanf_s(fptr, "%f %f %f %f %f %f %f %f", &train->bend[0][0], &train->bend[0][1], &train->bend[1][0], &train->bend[1][1], &train->bend[2][0], &train->bend[2][1], &train->bend[3][0], &train->bend[3][1]);
					fscanf_s(fptr, "%d", &train->direction);
					fscanf_s(fptr, "%f %f %f %f %f %f %f %f", &train->checkpoint[0][0], &train->checkpoint[0][1], &train->checkpoint[1][0], &train->checkpoint[1][1], &train->checkpoint[2][0], &train->checkpoint[2][1], &train->checkpoint[3][0], &train->checkpoint[3][1]);
				}
				fclose(fptr);
				break;
			}
	}
}
