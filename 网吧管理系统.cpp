#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 101

int total = 0;
int cpt_fee[N] = {0};

struct wangba
{
	int card;
	int num;
	int begin[2];
	int end[2];
	int fee;
}fee[N];

void ErrorInput(const char* str);
double GetMin(const int time[2]);
int GetHour(const wangba *x);
int CheckTime(const wangba *x, int index);
void Menu();
void Input();
void Add();
void PrintData();
void Search();
void Find(int index[], int *n);
void Modify();
void Delete();
void Statistics();

int main()
{
	Menu();
	return 0;
}

void ErrorInput(const char* str)
{
	puts(str);
	system("pause");
	fflush(stdin);
}

double GetMin(const int time[2])
{
	return (double)(time[0]*60+time[1]);
}

int GetHour(const wangba *x)
{
	double time = ( GetMin(x->end)-GetMin(x->begin) )/60.0;
	return (int)ceil(time);
}

int CheckTime(const wangba *x, int index = -1)
{
	int i;
	for(i = 0; i < total; ++i)
	{
		if(i == index)
			continue;
		//	ͬһ���ŵ��˲�������ͬһʱ�����2̨�����
		if( (x->card==fee[i].card) &&
		  ( (GetMin(x->begin)>=GetMin(fee[i].begin) && GetMin(x->begin)< GetMin(fee[i].end) ) || 
		    (GetMin(x->end)>GetMin(fee[i].begin) && GetMin(x->end)<= GetMin(fee[i].end) )     ||
			(GetMin(x->begin)<=GetMin(fee[i].begin) && GetMin(x->end)>=GetMin(fee[i].end) ) ) )
			return 0;
		//	ͬһ��ŵļ������������ͬһʱ����2���Ʒ� 
		if( (x->num==fee[i].num) &&
		  ( (GetMin(x->begin)>=GetMin(fee[i].begin) && GetMin(x->begin)< GetMin(fee[i].end) ) || 
		    (GetMin(x->end)>GetMin(fee[i].begin) && GetMin(x->end)<= GetMin(fee[i].end) )     ||
			(GetMin(x->begin)<=GetMin(fee[i].begin) && GetMin(x->end)>=GetMin(fee[i].end) ) ) )
			return 0;
	}
	return 1;
}

void Menu()
{
	int index = 0;
	int t;
	
	while(1)
	{
		system("cls");
		puts("-------------------���ɹ���ϵͳ-------------------\n");
		printf("1. ¼�������Ϣ\n2. ��ʾ������Ϣ\n3. ��ѯ�ϻ�������Ϣ\n4. �޸ķ�����Ϣ\n");
		printf("5. ɾ��������Ϣ\n6. ׷�ӷ�����Ϣ\n7. ͳ��\n8. �˳�ϵͳ\n\n");
		printf("��Ϣ¼��ʱע�⣺ͬһ���ŵ��˲�������ͬһʱ�����2̨�����\n");
		printf("��Ϣ¼��ʱע�⣺ͬһ��ŵļ������������ͬһʱ����2���Ʒ�\n");
		printf("�ϻ�ʱ�䲻��һСʱ�İ�һСʱ����\n"); 
		printf("\n\n��ǰ������Ϣ%d��\n\n", total);
		puts("--------------------------------------------------");
		printf("�����빦����ţ�");
		
		t = scanf("%d", &index);
		if(t==0 || (index<1||index>8)){
			ErrorInput("���������������룡");		
			continue;
		}
		system("cls");
		switch(index)
		{
			case 1:
				Input(); break;
			case 2:
				PrintData(); break;
			case 3:
				Search(); break;
			case 4:
				Modify(); break;
			case 5:
				Delete(); PrintData(); break;
			case 6:
				Add(); PrintData(); break;
			case 7:
				Statistics(); break;
			case 8:
				system("pause");
				exit(0);
		}
	}	
}	

void Input()
{
	int i, n, t;
	
	printf("������¼����Ϣ��������");
	t = scanf("%d", &n);
	if(t==0 || n<=0 || n>100){
		ErrorInput("���������������룡");
		return;
	}
	
	for(i = 0; i < n; ++i)
	{
		system("cls");
		printf("��Ҫ¼��%d����Ϣ����ǰ׼��¼���%d��\n\n", n, i+1);
		system("pause");
		Add();
	}
	puts("¼��ɹ���");
	system("pause");
}

void Add()
{
	int i = total;
	int t;
	int hour;
	
	while(1)
	{
		system("cls");
		printf("�����뿨��(1~1000)��");
		t = scanf("%d", &fee[i].card);
		if(t==0 || fee[i].card<=0 || fee[i].card>1000){
			ErrorInput("��������ȷ�Ŀ��ţ�");
			continue;
		}
		
		printf("�������������(1~100)��"); 
		t = scanf("%d", &fee[i].num);
		if(t==0 || fee[i].num<=0 || fee[i].num>100){
			ErrorInput("��������ȷ�ļ������ţ�");
			continue;
		}
		
		printf("�������ϻ�ʱ��(��14:52)��");
		t = scanf("%d:%d", &fee[i].begin[0], &fee[i].begin[1]);
		if(t==0 || (fee[i].begin[0]<0||fee[i].begin[0]>=24) 
		||(fee[i].begin[1]<0||fee[i].begin[1]>=60) )
		{
			ErrorInput("��������ȷ���ϻ�ʱ�䣡");
			continue;
		}
		
		printf("�������»�ʱ��(��21:46)��");
		t = scanf("%d:%d", &fee[i].end[0], &fee[i].end[1]);
		
		hour = GetHour(&fee[i]);
		if(t==0 || ((fee[i].begin[0]<0||fee[i].begin[0]>=24) 
		||(fee[i].begin[1]<0||fee[i].begin[1]>=60)) || (hour<=0) )
		{
			ErrorInput("��������ȷ���»�ʱ�䣡");
			continue;
		}
		
		if(CheckTime(&fee[i]) == 0){
			ErrorInput("��ʱ������������ݳ�ͻ��");
			continue;
		}
		break;
	}
	
	fee[i].fee = hour*2;
	cpt_fee[fee[i].num] += fee[i].fee;
	total++;
	puts("¼��ɹ���");
	system("pause");
	system("cls");
}

void PrintData()
{
	int i;
	
	puts("����    ��������    �ϻ�ʱ��    �»�ʱ��    ����"); 
	for(i = 0; i < total; ++i)
	{
		printf("%4d    %4d          %02d:%02d        %02d:%02d       %d\n",
		fee[i].card, fee[i].num, fee[i].begin[0], fee[i].begin[1],
		fee[i].end[0], fee[i].end[1], fee[i].fee);
	}
	system("pause");
}

void Search()
{
	int i, t;
	int x;
	
	puts("1. ���Ų�ѯ\n2. �������Ų�ѯ\n0. �˳�"); 
	printf("�������ѯ��ʽ��");
	t = scanf("%d", &x);
	if(t==0 || (x!=0&&x!=1&&x!=2)){
		ErrorInput("���������������룡");
		return;
	}
	
	if(x == 0){
		return;
	}else if(x == 1){
		printf("�����뿨�ţ�"); 
		t = scanf("%d", &x);
		if(t==0 || x<=0 || x>1000){
			ErrorInput("���������������룡");
			return;
		}
		
		puts("����    ��������    �ϻ�ʱ��    �»�ʱ��    ����");		
		for(i = 0; i < total; ++i)
		{
			if(x == fee[i].card){
				printf("%4d    %4d              %02d:%02d            %02d:%02d       %d\n",
				fee[i].card, fee[i].num, fee[i].begin[0], fee[i].begin[1],
				fee[i].end[0], fee[i].end[1], fee[i].fee);				
				t = 0;
			}
		}
		if(t != 0){
			ErrorInput("���޴��ˣ�");
			return;
		}
	}else if(x == 2){
		printf("������������ţ�"); 
		t = scanf("%d", &x);
		if(t==0 || x<=0 || x>1000){
			ErrorInput("���������������룡");
			return;
		}
		 
		puts("����    ��������    �ϻ�ʱ��    �»�ʱ��    ����");		
		for(i = 0; i < total; ++i)
		{
			if(x == fee[i].num){
				printf("%4d    %4d              %02d:%02d            %02d:%02d       %d\n",
				fee[i].card, fee[i].num, fee[i].begin[0], fee[i].begin[1],
				fee[i].end[0], fee[i].end[1], fee[i].fee);				
				t = 0;
			}
		}
		if(t != 0){
			ErrorInput("���޴��ˣ�");
			return;
		}
	}
	system("pause");
}
	
void Find(int index[], int *n)
{
	int i, j, t;
	int x;
	
	printf("�����뿨�Ų��ң�"); 
	t = scanf("%d", &x);
	if(t==0 || x<=0 || x>1000){
		ErrorInput("���������������룡");
		return;
	}
	
	for(i = 0, j = 0; i < total; ++i)
	{
		if(x == fee[i].card){
			index[j++] = i;
			(*n)++;
		}
	}
	if( *n == 0 ){
		puts("���޴��ˣ�"); 
		system("pause");
	}
}
	
void Modify()
{
	int i, t, hour;
	int psw, n = 0;
	int index[N];
	
	printf("Tips������Ա������123456\n\n");
	Find(index, &n);
	if(n == 0)
		return;
	
	puts("���    ����    ��������    �ϻ�ʱ��    �»�ʱ��    ����");	
	for(i = 0; i < n; ++i)
	{
		t = index[i];
		printf("%d      %4d      %4d          %02d:%02d        %02d:%02d       %d\n",
		i+1, fee[t].card, fee[t].num, fee[t].begin[0], 
		fee[t].begin[1], fee[t].end[0], fee[t].end[1], fee[t].fee);
	}
	
	printf("\n������������룺");
	t = scanf("%d", &psw);
	if(t==0 || psw!=123456){
		ErrorInput("�������");
		return;
	}
		
	puts("\n������Ҫ�޸ĵ���ţ�"); 
	t = scanf("%d", &i);
	if(t==0 || i<=0 || i>n){
		ErrorInput("��������������룡");
		return;
	}
	
	i = index[i-1];
	cpt_fee[fee[i].num] -= fee[i].fee;
	while(1)
	{
		printf("�������������(1~100)��"); 
		t = scanf("%d", &fee[i].num);
		if(t==0 || fee[i].num<=0 || fee[i].num>100){
			ErrorInput("��������ȷ�ļ������ţ�");
			continue;
		}
		
		printf("�������ϻ�ʱ��(��14:52)��");
		t = scanf("%d:%d", &fee[i].begin[0], &fee[i].begin[1]);
		if(t==0 || (fee[i].begin[0]<0||fee[i].begin[0]>=24) 
		||(fee[i].begin[1]<0||fee[i].begin[1]>=60))
		{
			ErrorInput("��������ȷ���ϻ�ʱ�䣡");
			continue;
		}
		
		printf("�������»�ʱ��(��21:46)��");
		t = scanf("%d:%d", &fee[i].end[0], &fee[i].end[1]);
		
		hour = GetHour(&fee[i]);
		if(t==0 || ((fee[i].begin[0]<0||fee[i].begin[0]>=24) 
		||(fee[i].begin[1]<0||fee[i].begin[1]>=60)) || (hour<=0) )
		{
			ErrorInput("��������ȷ���»�ʱ�䣡");
			continue;
		}
		if(CheckTime(&fee[i], i) == 0){
			ErrorInput("��ʱ������������ݳ�ͻ��");
			continue;
		}
		break;
	}	
	fee[i].fee = hour*2;
	cpt_fee[fee[i].num] += fee[i].fee;
	puts("�޸ĳɹ���");
	system("pause");
}
	
void Delete()
{
	int i, j, t;
	int n = 0;
	int index[N];
	
	Find(index, &n);
	if(n == 0)
		return;
	
	puts("���    ����    ��������    �ϻ�ʱ��    �»�ʱ��    ����");	
	for(i = 0; i < n; ++i)
	{
		t = index[i];
		printf("%d    %4d    %4d    %02d:%02d        %02d:%02d       %d\n",
		i+1, fee[t].card, fee[t].num, fee[t].begin[0], 
		fee[t].begin[1], fee[t].end[0], fee[t].end[1], fee[t].fee);
	}	
	puts("\n������Ҫɾ������ţ�"); 
	t = scanf("%d", &i);
	if(t==0 || t<=0 || t>n){
		ErrorInput("��������������룡");
		return;
	}
	
	n = index[i-1];
	cpt_fee[fee[n].num] -= fee[n].fee;
	for(i = n+1; i < total; ++i)
		fee[i-1] = fee[i];			
	total--;
	
	puts("ɾ���ɹ���");
	system("pause");
}
	
void Statistics()
{
	int i, fee_sum = 0;
	for(i = 0; i < total; ++i)
		fee_sum += fee[i].fee;
	printf("�����û��ϻ�����֮�ͣ�%d\n\n", fee_sum);
	
	puts("ÿ̨���Ե����з���֮��");
	puts("\n���    ����\n"); 
	for(i = 0; i < N; ++i)
		if(cpt_fee[i] != 0)
			printf("%d\t%d\n", i, cpt_fee[i]);
					
	system("pause");
}
