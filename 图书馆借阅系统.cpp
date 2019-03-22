/* ͼ��ݽ���ϵͳ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 500

int num = 0;

struct library
{
	char  bor_num[20];
	char  book_num[20];
	int   bor_day[3];
	int   ret_day[3];
	int   flag;
	float bill;
}book[N+1];

void Menu();
void PrintList();
void GetTime(struct library* x);
int  GetDay(struct library* x);
void Borrow();
int  Find(const char* no);
void Return();
void FindByNum();
void PrintByDay();
void DeleteByNum();
void DeleteOld();
void Statistics();

int main()
{
	Menu();
	return 0;
}

void Menu()
{
	int index;
	do{
		puts("-----------------------ͼ��ݽ���ϵͳ-----------------------\n");
		printf("1. ����\n2. ����\n3. ��ѯ������Ϣ\n4. ��ѯĳ�ս������\n");
		printf("5. ɾ����Ϣ\n6. ɾ����������\n7. ͳ�Ƽ���\n8. ������Ϣ�б�\n9. �˳�\n");
		printf("\n��ǰ����%d�������¼\n", num); 
		puts("\n------------------------------------------------------------\n"); 	
		
		printf("�����빦����ţ�");	
		scanf("%d", &index);
		
		system("cls");
		switch(index){
			case 1:
				Borrow();
				break;
			case 2:
				Return();
				break;
			case 3:
				FindByNum();
				break;
			case 4:
				PrintByDay();
				break;
			case 5:
				DeleteByNum();
				break;
			case 6:
				DeleteOld();
				break;
			case 7:
				Statistics();
				break;
			case 8:
				PrintList();
				break;
			case 9:
				;																 
		}
		system("pause");
		system("cls");
	}while(index != 9);
}

void PrintList()
{
	int i;
	
	puts("����֤��        ͼ��֤��        ��������        ��������        ����"); 	
	for(i = 0; i < num; ++i)
	{
		printf("%s\t%s\t\t%04d-%02d-%02d\t%04d-%02d-%02d\t%.2f\n", book[i].bor_num, book[i].book_num,
		book[i].bor_day[0], book[i].bor_day[1], book[i].bor_day[2], book[i].ret_day[0], 
		book[i].ret_day[1], book[i].ret_day[2], book[i].bill);
	}
}

void GetTime(struct library* x)
{
    time_t t;
    struct tm * lt;
    
    time(&t);				//��ȡUnixʱ�����
    lt = localtime(&t);		//תΪʱ��ṹ
    x->bor_day[0] = lt->tm_year+1900;
    x->bor_day[1] = lt->tm_mon+1;
    x->bor_day[2] = lt->tm_mday;
}

int GetDay(struct library* x)
{
	tm ptr1, ptr2;
	time_t st1, st2;
	
	ptr1.tm_sec = ptr1.tm_min = ptr1.tm_hour = 0;	
	ptr1.tm_year = x->bor_day[0]-1900;
	ptr1.tm_mon  = x->bor_day[1]-1;
	ptr1.tm_mday = x->bor_day[2];
	ptr2.tm_sec = ptr2.tm_min = ptr2.tm_hour = 0;	
	ptr2.tm_year = x->ret_day[0]-1900;
	ptr2.tm_mon  = x->ret_day[1]-1;
	ptr2.tm_mday = x->ret_day[2];
	
	st1 = mktime(&ptr1);
	st2 = mktime(&ptr2);
	return (int)( (st2-st1)/3600/24 );
}

void Borrow()
{
	int i = num;
 
	puts("--------------------------������Ϣ¼��--------------------------\n");	
	printf("���������֤�ţ�");
	scanf("%s", book[i].bor_num);
	printf("������ͼ���ţ�");
	scanf("%s", book[i].book_num);
	if( Find(book[i].book_num) != -1 ){
		puts("û���Ȿ�������ѱ������");
		system("pause");
		return;
	}	
	GetTime(&book[i]); 
	
	book[i].ret_day[0] = book[i].ret_day[1] = book[i].ret_day[2] = 0;
	book[i].bill = 0;
	book[i].flag = 1;
	num++;
	puts("������Ϣ¼��ɹ���"); 
}

int Find(const char* no)
{
	int i;
	for(i = 0; i < num; ++i)
		if(strcmp(no,book[i].book_num)==0 && book[i].flag==1)	//���ұ���� 
			return i;
	return -1;
}

void Return()
{
	int  i, day;
	char book_no[20];
	
	puts("--------------------------������Ϣ�Ǽ�--------------------------\n");	
	printf("������Ҫ�黹����ı�ţ�");
	scanf("%s", book_no);
	
	i = Find(book_no);
	if(i == -1){
		puts("�޴˽�����Ϣ��");
		system("pause");
		return;
	}
	printf("�����뻹��ʱ��(��2018-09-12)��");
	scanf("%d-%d-%d", &book[i].ret_day[0], &book[i].ret_day[1], &book[i].ret_day[2]); 
	day = GetDay(&book[i]);
	if(day < 0){
		puts("���ܱȽ���ʱ���磡");
		system("pause");
		return;
	}
	if(day > 30){
		book[i].bill = 0.2*(day-30);
	}
	book[i].flag = 0;
}

void FindByNum()
{
	int  i;
	char no[20];
	puts("--------------------------������֤���ҽ�����Ϣ--------------------------\n");
	printf("���������֤�ţ�");
	scanf("%s", no);
	
	puts("����֤��        ͼ��֤��        ��������"); 
	for(i = 0; i < num; ++i)
	{
		if( strstr(book[i].bor_num, no) != NULL )
			printf("%s\t%s\t\t%04d-%02d-%02d\n", book[i].bor_num, book[i].book_num,
			book[i].bor_day[0], book[i].bor_day[1], book[i].bor_day[2]); 
	}
}		

void PrintByDay()
{
	int i, year, month, day;
	puts("--------------------------�����ڲ��ҽ�����Ϣ--------------------------\n");
	printf("����������(�� 2018-06-12)��");
	scanf("%d-%d-%d", &year, &month, &day);
	
	puts("����֤��        ͼ��֤��        ��������"); 
	for(i = 0; i < num; ++i)
	{
		if(year==book[i].bor_day[0] && month==book[i].bor_day[1]
		&& day ==book[i].bor_day[2])
			printf("%s\t%s\t\t%04d-%02d-%02d\n", book[i].bor_num, book[i].book_num,
			book[i].bor_day[0], book[i].bor_day[1], book[i].bor_day[2]); 
	}
}

void DeleteByNum()
{
	int  i, j;
	char no[20];
	
	puts("--------------------------��ͼ����ɾ��������Ϣ--------------------------\n");
	printf("������ͼ���ţ�");
	scanf("%s", no);
	
	for(i = 0; i < num; ++i)
	{
		if(strstr(book[i].book_num, no) != NULL){
			for(j = i+1; j < num; ++j)
				book[j-1] = book[j];
			num--;
		}
	}
}

void DeleteOld()
{
	int i, j, year;
	struct library x;
	GetTime(&x);
	
	year = x.bor_day[0]-1;		//��һ�� 
	for(i = 0; i < num; ++i)
	{
		if(year == book[i].bor_day[0]){
			for(j = i+1; j < num; ++j)
				book[j-1] = book[j];
			num--;
		}
	}
}
	
void Statistics()
{
	int i, cnt = 0;
	float  sum = 0;
	
	for(i = 0; i < num; ++i)
	{
		if(book[i].bill > 0){
			cnt++;
			sum += book[i].bill;
		}
	}
	printf("����%d�����ڽ����¼���ܼƷ���Ϊ%fԪ��\n", cnt, sum);
}	
