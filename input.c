#include "input.h"
#include<stdio.h>

/*��ʼ���������Ϣ*/
void initialize(TRAIN *train) 
{
	int choose;
	    printf("���%d�Ż�ѡ������������(1)���ļ�����(2):",train->number);
	    scanf("%d",&choose);
	    if(choose==1){
			printf("������%d�Ż��ٶȡ�����ʱ�䡢���з���(0��ʾ˳ʱ��,1��ʾ��ʱ��)���������ͣ��ʱ�䡢x���ꡢy����:", train->number);
			scanf("%d %d %d %d %f %f", &train->speed, &train->starttime, &train->rounddirection, &train->stoptime, &train->xcoordinate, &train->ycoordinate);
			printf("�������ĸ������λ��:");
			scanf("%f %f %f %f %f %f %f %f", &train->bend[0][0], &train->bend[0][1], &train->bend[1][0], &train->bend[1][1], &train->bend[2][0], &train->bend[2][1], &train->bend[3][0], &train->bend[3][1]);
			printf("�������ʼ����(1:EAST 2:SOUTH 3:WEST 4:NORTH):");
			scanf("%d", &train->direction);
			if(train->number==3)
			{
			  printf("�������ĸ�����λ��:");
			  scanf("%f %f %f %f %f %f %f %f", &train->checkpoint[0][0], &train->checkpoint[0][1], &train->checkpoint[1][0], &train->checkpoint[1][1],&train->checkpoint[2][0], &train->checkpoint[2][1], &train->checkpoint[3][0], &train->checkpoint[3][1]);
			}
			else
			{
			  printf("��������������λ��:");
			  scanf("%f %f %f %f", &train->checkpoint[0][0], &train->checkpoint[0][1], &train->checkpoint[1][0], &train->checkpoint[1][1]);
	        }
		}
		else{
			FILE *fptr = NULL;
			switch (train->number) {
			case 1:
				fopen_s(&fptr, "file\\train1.txt", "r");
				if (fptr == NULL)
					printf("�����ļ���ʧ��!\n");
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
					printf("�����ļ���ʧ��!\n");
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
					printf("�����ļ���ʧ��!\n");
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
