#include<stdio.h>
#include<stdlib.h> 
main()
{
	FILE *fptr=NULL;
	int num,speed,x,y,starttime,stoptime,direction,rounddirection;
	int bend[4][2];
	int checkpoint[4][2];
	while (1) {
		printf("��������Ҫ�޸ĵĻ𳵱��:");
		scanf("%d", &num);
		switch (num) {
		case 1:
			fopen_s(&fptr, "train1.txt", "w");
			if (fptr == NULL)
				printf("�ļ���ʧ��!\n");
			else {
				printf("��������ٶȡ�����ʱ�䡢���з���(0��ʾ˳ʱ��,1��ʾ��ʱ��)���������ͣ��ʱ�䡢x���ꡢy����:");
				scanf("%d %d %d %d %d %d", &speed, &starttime, &rounddirection, &stoptime, &x, &y);
				fprintf(fptr, "%d %d %d %d %d %d %d\n", speed, rounddirection, 0, starttime, stoptime, x, y);
				printf("�������ĸ������λ��:");
				scanf("%d %d %d %d %d %d %d %d", &bend[0][0], &bend[0][1], &bend[1][0], &bend[1][1], &bend[2][0], &bend[2][1], &bend[3][0], &bend[3][1]);
				fprintf(fptr, "%d %d %d %d %d %d %d %d\n", bend[0][0], bend[0][1], bend[1][0], bend[1][1], bend[2][0], bend[2][1], bend[3][0], bend[3][1]);
				printf("�������ʼ����(1:EAST 2:SOUTH 3:WEST 4:NORTH):");
				scanf("%d", &direction);
				fprintf(fptr, "%d\n", direction);
				printf("��������������λ��:");
				scanf("%d %d %d %d", &checkpoint[0][0], &checkpoint[0][1], &checkpoint[1][0], &checkpoint[1][1]);
				fprintf(fptr, "%d %d %d %d\n", checkpoint[0][0], checkpoint[0][1], checkpoint[1][0], checkpoint[1][1]);
			}
			fclose(fptr); 
			break;
		case 2:
			fopen_s(&fptr, "train2.txt", "w");
			if (fptr == NULL)
				printf("�ļ���ʧ��!\n");
			else {
				printf("��������ٶȡ�����ʱ�䡢���з���(0��ʾ˳ʱ��,1��ʾ��ʱ��)���������ͣ��ʱ�䡢x���ꡢy����:");
				scanf("%d %d %d %d %d %d", &speed, &starttime, &rounddirection, &stoptime, &x, &y);
				fprintf(fptr, "%d %d %d %d %d %d %d\n", speed, rounddirection, 0, starttime, stoptime, x, y);
				printf("�������ĸ������λ��:");
				scanf("%d %d %d %d %d %d %d %d", &bend[0][0], &bend[0][1], &bend[1][0], &bend[1][1], &bend[2][0], &bend[2][1], &bend[3][0], &bend[3][1]);
				fprintf(fptr, "%d %d %d %d %d %d %d %d\n", bend[0][0], bend[0][1], bend[1][0], bend[1][1], bend[2][0], bend[2][1], bend[3][0], bend[3][1]);
				printf("�������ʼ����(1:EAST 2:SOUTH 3:WEST 4:NORTH):");
				scanf("%d", &direction);
				fprintf(fptr, "%d\n", direction);
				printf("��������������λ��:");
				scanf("%d %d %d %d", &checkpoint[0][0], &checkpoint[0][1], &checkpoint[1][0], &checkpoint[1][1]);
				fprintf(fptr, "%d %d %d %d\n", checkpoint[0][0], checkpoint[0][1], checkpoint[1][0], checkpoint[1][1]);
			}
			fclose(fptr);
			break;
		case 3:
			fopen_s(&fptr, "train3.txt", "w");
			if (fptr == NULL)
				printf("�ļ���ʧ��!\n");
			else {
				printf("��������ٶȡ�����ʱ�䡢���з���(0��ʾ˳ʱ��,1��ʾ��ʱ��)���������ͣ��ʱ�䡢x���ꡢy����:");
				scanf("%d %d %d %d %d %d", &speed, &starttime, &rounddirection, &stoptime, &x, &y);
				fprintf(fptr, "%d %d %d %d %d %d %d\n", speed, rounddirection, 0, starttime, stoptime, x, y);
				printf("�������ĸ������λ��:");
				scanf("%d %d %d %d %d %d %d %d", &bend[0][0], &bend[0][1], &bend[1][0], &bend[1][1], &bend[2][0], &bend[2][1], &bend[3][0], &bend[3][1]);
				fprintf(fptr, "%d %d %d %d %d %d %d %d\n", bend[0][0], bend[0][1], bend[1][0], bend[1][1], bend[2][0], bend[2][1], bend[3][0], bend[3][1]);
				printf("�������ʼ����(1:EAST 2:SOUTH 3:WEST 4:NORTH):");
				scanf("%d", &direction);
				fprintf(fptr, "%d\n", direction);
				printf("�������ĸ�����λ��:");
				scanf("%d %d %d %d %d %d %d %d", &checkpoint[0][0], &checkpoint[0][1], &checkpoint[1][0], &checkpoint[1][1], &checkpoint[2][0], &checkpoint[2][1], &checkpoint[3][0], &checkpoint[3][1]);
				fprintf(fptr, "%d %d %d %d %d %d %d %d\n", checkpoint[0][0], checkpoint[0][1], checkpoint[1][0], checkpoint[1][1], checkpoint[2][0], checkpoint[2][1], checkpoint[3][0], checkpoint[3][1]);
			}
			fclose(fptr);
			break;
		}
	 }
	}
	
