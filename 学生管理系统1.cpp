#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
	char sno[32];
	char sname[32];
	int  score[7];
	int  rank;
	float sum;
}STU;

void Screen(STU *stu);
void RecordStu(STU *stu, int num_stu, int num_cou);
void CaculateCourse(STU *stu, int num_stu, int num_cou, float *sum_cou);
void CaculateStudent(STU *stu, int num_stu, int num_cou);
void SortByScore1(STU *stu, int num_stu);
void SortByScore2(STU *stu, int num_stu);
void SortBySno(STU *stu, int num_stu, int num_cou);
void SortByName(STU *stu, int num_stu, int num_cou);
void SearchBySno(STU *stu, int num_stu, int num_cou);
void SearchByName(STU *stu, int num_stu, int num_cou);
void AnalysisCourse(STU *stu, int num_stu, int num_cou);
void ListRecord(STU *stu, int num_stu, int num_cou, float *sum_cou);
void WriteToFile(STU *stu, int num_stu, int num_cou);
void ReadFromFile();

int main()
{
	STU stu[31];	
	Screen(stu);	
	return 0; 
}


void Screen(STU *stu)
{
	int index = 0, flag = 0;
	int num_cou;
	int num_stu;
	float sum_cou[7] = {0};
	
	printf("Please input Students number : ");
	scanf("%d", &num_stu);
	printf("Please input Courses  number : ");
	scanf("%d", &num_cou);	
	while(1)
	{
		system("cls");
		printf("Student numbers : %d\n", num_stu);
		printf("Course  numbers : %d\n", num_cou);
		printf("1. Input record\n");
		printf("2. Caculate total and average score of every course\n");		
		printf("3. Caculate total and average score of every student\n");	
		printf("4. Sort in descending order by total score of every student\n");	
		printf("5. Sort in ascending order by total score of every student\n");	
		printf("6. Sort in ascending order by number\n");	
		printf("7. Sort in dictionary order by name\n");	
		printf("8. Search by number\n");	
		printf("9. Search by name\n");	
		printf("10.Statistic analysis for every course\n");	
		printf("11.List record\n");	
		printf("12.Write to a file\n");	
		printf("13.Read from a file\n");	
		printf("0. Exit\n");	
		printf("\n\nPlease enter your choice : ");
		scanf("%d", &index);
		
		system("cls");
		printf("Student numbers : %d\n", num_stu);
		printf("Course  numbers : %d\n", num_cou);		
		switch(index)
		{
			case 0:
				flag = 1;
				break;
			case 1:
				RecordStu(stu, num_stu, num_cou);
				break;
			case 2:
				CaculateCourse(stu, num_stu, num_cou, sum_cou);
				break;
			case 3:
				CaculateStudent(stu, num_stu, num_cou);	
				break;
			case 4:
				SortByScore1(stu, num_stu);
				break;
			case 5:
				SortByScore2(stu, num_stu);
				break;
			case 6:
				SortBySno(stu, num_stu, num_cou);
				break;
			case 7:
				SortByName(stu, num_stu, num_cou);
				break;
			case 8:
				SearchBySno(stu, num_stu, num_cou);
				break;
			case 9:
				SearchByName(stu, num_stu, num_cou);
				break;
			case 10:
				AnalysisCourse(stu, num_stu, num_cou);
				break;
			case 11:
				ListRecord(stu, num_stu, num_cou, sum_cou);	
				break;
			case 12:
				WriteToFile(stu, num_stu, num_cou);
				break;	
			case 13:
				ReadFromFile();
				break;
			default:
				printf("Print Error!\n");
				system("pause");
		}
		if(flag == 1)
		{
			system("cls");
			printf("Bye bye!!!\n");
			system("pause");
			break;
		}
	}			
}

void RecordStu(STU *stu, int num_stu, int num_cou)
{
	int i, j;
	printf("\n\nInput student's id, name and score:\n\n");
	
	for(i = 1; i <= num_stu; ++i)
	{
		printf("Record No.%d student's details:\n", i); 
		printf("Input student's id: ");
		scanf("%s", stu[i].sno);
		printf("Input student's name: ");
		scanf("%s", stu[i].sname);		
		
		for(j = 1; j <= num_cou; ++j)
		{
			printf("Input student's No.%d course score: ", j);
			scanf("%d", &stu[i].score[j]);
		}
		printf("\n\n");
	}
	printf("\nOK!\n");
	system("pause");				
}

void CaculateCourse(STU *stu, int num_stu, int num_cou, float *sum_cou)
{
	int i, j;
	for(i = 1; i <= num_stu; ++i)
	{
		for(j = 1; j <= num_cou; ++j)
			sum_cou[j] += stu[i].score[j];	
	}
	for(i = 1; i <= num_cou; ++i)
	{
		printf("Course %d : \n", i);		
		printf("sum score : %.2f, avg score : %.2f\n\n", sum_cou[i], sum_cou[i]/num_stu);
	}
	system("pause");
}

void CaculateStudent(STU *stu, int num_stu, int num_cou)
{
	int i, j;
	for(i = 1; i <= num_stu; ++i)
	{
		stu[i].sum = 0;
		printf("Student %d : \n", i);
		for(j = 1; j <= num_cou; ++j)
			stu[i].sum += stu[i].score[j];
		printf("sum score : %.2f, avg score : %.2f\n\n", stu[i].sum, stu[i].sum/num_cou);			
	}
	system("pause");
}

void SortByScore1(STU *stu, int num_stu)	//	学生从高到低排名 
{
	int i, j;
	STU tmp;
	
	for(i = 1; i < num_stu; ++i)
	{
		for(j = i+1; j <= num_stu; ++j)
		{
			if(stu[i].sum < stu[j].sum)
			{
				tmp = stu[i];
				stu[i] = stu[j];
				stu[j] = tmp;
			}
		}
	}
	
	printf("Rank List by Sum of score Up to Low:\n\n");
	for(i = 1; i <= num_stu; ++i)
		printf("No.%d  %-15s  %-15s  %.2f\n", i, stu[i].sno, stu[i].sname, stu[i].sum);
	system("pause");
}

void SortByScore2(STU *stu, int num_stu)	//	学生从低到高排名 
{
	int i, j;
	STU tmp;
	
	for(i = 1; i < num_stu; ++i)
	{
		for(j = i+1; j <= num_stu; ++j)
		{
			if(stu[i].sum > stu[j].sum)
			{
				tmp = stu[i];
				stu[i] = stu[j];
				stu[j] = tmp;
			}
		}
	}
	
	printf("Rank List by Sum of score Low to Up:\n\n");
	for(i = 1; i <= num_stu; ++i)
	{
		stu[i].rank = i;
		printf("No.%d  %-15s  %-15s  %.2f\n", i, stu[i].sno, stu[i].sname, stu[i].sum);
	}
	system("pause");
}
		
void SortBySno(STU *stu, int num_stu, int num_cou)
{
	int i, j;
	STU tmp;
	for(i = 1; i < num_stu; ++i)
	{
		for(j = i+1; j <= num_stu; ++j)
		{
			if(strcmp(stu[i].sno, stu[j].sno) > 0)
			{
				tmp = stu[i];
				stu[i] = stu[j];
				stu[j] = tmp;
			}
		}
	}
	
	printf("Rank List by Id Low to Up:\n\n");
	for(i = 1; i <= num_stu; ++i)
	{
		printf("No.%d  %-10s  %-10s", i, stu[i].sno, stu[i].sname);
		for(j = 1; j <= num_cou; ++j)
			printf("%d    ", stu[i].score[j]);
		putchar('\n');	
	}
	system("pause");
}
			
void SortByName(STU *stu, int num_stu, int num_cou)
{
	int i, j;
	STU tmp;
	for(i = 1; i < num_stu; ++i)
	{
		for(j = i+1; j <= num_stu; ++j)
		{
			if(strcmp(stu[i].sname, stu[j].sname) > 0)
			{
				tmp = stu[i];
				stu[i] = stu[j];
				stu[j] = tmp;
			}
		}
	}
	
	printf("Rank List by Name Low to Up:\n\n");
	for(i = 1; i <= num_stu; ++i)
	{
		printf("No.%d  %-10s  %-10s", i, stu[i].sno, stu[i].sname);
		for(j = 1; j <= num_cou; ++j)
			printf("%d    ", stu[i].score[j]);
		putchar('\n');	
	}
	system("pause");
}

void SearchBySno(STU *stu, int num_stu, int num_cou)
{
	int i, j;
	char id[32];
	
	printf("Please enter student id which you want search : ");
	scanf("%s", id);
	
	for(i = 1; i <= num_stu; ++i)
		if(strcmp(id, stu[i].sno) == 0)
			break;
	
	if(i <= num_stu)
	{
		printf("No.%d  %-10s  %-10s", stu[i].rank, stu[i].sno, stu[i].sname);	
		for(j = 1; j <= num_cou; ++j)
			printf("%d    ", stu[i].score[j]);
		putchar('\n');
	}
	else
		printf("Not found this student!\n");
	
	system("pause");	
}

void SearchByName(STU *stu, int num_stu, int num_cou)
{
	int i, j;
	char name[32];
	
	printf("Please enter student name which you want search : ");
	scanf("%s", name);
	
	for(i = 1; i <= num_stu; ++i)
		if(strcmp(name, stu[i].sname) == 0)
			break;
	
	if(i <= num_stu)
	{
		printf("No.%d  %-10s  %-10s", stu[i].rank, stu[i].sno, stu[i].sname);	
		for(j = 1; j <= num_cou; ++j)
			printf("%d    ", stu[i].score[j]);
		putchar('\n');
	}
	else
		printf("Not found this student!\n");
	
	system("pause");	
}

void AnalysisCourse(STU *stu, int num_stu, int num_cou)
{
	int i, j;
	int level[7][6] = {0};
	
	for(i = 1; i <= num_stu; ++i)
	{	
		for(j = 1; j <= num_cou; ++j)
		{
			if(stu[i].score[j] < 60)
				++level[j][5];
			else if(stu[i].score[j] < 70)
				++level[j][4];
			else if(stu[i].score[j] < 80)
				++level[j][3];	
			else if(stu[i].score[j] < 90)
				++level[j][2];			
			else
				++level[j][1];	
		}
	}
	
	for(i = 1; i <= num_cou; ++i)
	{
		printf("Course %d:\n", i);
		printf("90~100 : %d,  %.2f%%\n", level[i][1], (float)(level[i][1])/(float)(num_stu)*100);
		printf("80~89  : %d,  %.2f%%\n", level[i][2], (float)(level[i][2])/(float)(num_stu)*100);
		printf("70~79  : %d,  %.2f%%\n", level[i][3], (float)(level[i][3])/(float)(num_stu)*100);
		printf("60~69  : %d,  %.2f%%\n", level[i][4], (float)(level[i][4])/(float)(num_stu)*100);
		printf("0~59   : %d,  %.2f%%\n", level[i][5], (float)(level[i][5])/(float)(num_stu)*100);
	}
	system("pause");
}

void ListRecord(STU *stu, int num_stu, int num_cou, float *sum_cou)
{
	int i, j;
	printf("List Record:\n\n");
	
	for(i = 1; i <= num_stu; ++i)
	{
		printf("No.%d  %-10s  %-10s  %.0f  %.2f    ", i, stu[i].sno, stu[i].sname, stu[i].sum, stu[i].sum/num_cou);
		for(j = 1; j <= num_cou; ++j)
			printf("%d    ", stu[i].score[j]);
		putchar('\n');	
	}
	printf("\n\n\n");
	for(i = 1; i <= num_cou; ++i)
	{
		printf("Course %d : \n", i);		
		printf("sum score : %.2f, avg score : %.2f\n\n", sum_cou[i], sum_cou[i]/num_stu);
	}		
	system("pause");
}

void WriteToFile(STU *stu, int num_stu, int num_cou)
{
	int i, j;
	FILE *fp = fopen("./data.txt", "w");
	if(NULL == fp)
	{
		printf("Open file error!\n");
		return;
	}
	
	for(i = 1; i <= num_stu; ++i)
	{
		fprintf(fp, "%s %s %d %.0f ", stu[i].sno, stu[i].sname, stu[i].rank, stu[i].sum);
		for(j = 1; j <= num_cou; ++j)
		{
			fprintf(fp, "%d ", stu[i].score[j]);
		}
		fprintf(fp, "\n");
	}
	printf("Write in txt OK!\n");
	fclose(fp);
	system("pause");
}

void ReadFromFile()
{
	char buf[256];
	FILE *fp = fopen("./data.txt", "r");
	if(NULL == fp)
	{
		printf("No data file!\n");
		return;
	}
	
	printf("File data:\n");
	while(!feof(fp))
	{
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), fp);
		puts(buf);
	}
	printf("Read from txt OK!\n");
	fclose(fp);
	system("pause");	
}
