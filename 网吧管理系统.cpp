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
		//	同一卡号的人不可能在同一时间操纵2台计算机
		if( (x->card==fee[i].card) &&
		  ( (GetMin(x->begin)>=GetMin(fee[i].begin) && GetMin(x->begin)< GetMin(fee[i].end) ) || 
		    (GetMin(x->end)>GetMin(fee[i].begin) && GetMin(x->end)<= GetMin(fee[i].end) )     ||
			(GetMin(x->begin)<=GetMin(fee[i].begin) && GetMin(x->end)>=GetMin(fee[i].end) ) ) )
			return 0;
		//	同一编号的计算机不可能在同一时间有2个计费 
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
		puts("-------------------网吧管理系统-------------------\n");
		printf("1. 录入费用信息\n2. 显示费用信息\n3. 查询上机费用信息\n4. 修改费用信息\n");
		printf("5. 删除费用信息\n6. 追加费用信息\n7. 统计\n8. 退出系统\n\n");
		printf("信息录入时注意：同一卡号的人不可能在同一时间操纵2台计算机\n");
		printf("信息录入时注意：同一编号的计算机不可能在同一时间有2个计费\n");
		printf("上机时间不足一小时的按一小时计算\n"); 
		printf("\n\n当前共有信息%d条\n\n", total);
		puts("--------------------------------------------------");
		printf("请输入功能序号：");
		
		t = scanf("%d", &index);
		if(t==0 || (index<1||index>8)){
			ErrorInput("输入有误！请检查输入！");		
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
	
	printf("请输入录入信息的条数：");
	t = scanf("%d", &n);
	if(t==0 || n<=0 || n>100){
		ErrorInput("输入有误！请检查输入！");
		return;
	}
	
	for(i = 0; i < n; ++i)
	{
		system("cls");
		printf("共要录入%d条信息，当前准备录入第%d条\n\n", n, i+1);
		system("pause");
		Add();
	}
	puts("录入成功！");
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
		printf("请输入卡号(1~1000)：");
		t = scanf("%d", &fee[i].card);
		if(t==0 || fee[i].card<=0 || fee[i].card>1000){
			ErrorInput("请输入正确的卡号！");
			continue;
		}
		
		printf("请输入计算机编号(1~100)："); 
		t = scanf("%d", &fee[i].num);
		if(t==0 || fee[i].num<=0 || fee[i].num>100){
			ErrorInput("请输入正确的计算机编号！");
			continue;
		}
		
		printf("请输入上机时间(如14:52)：");
		t = scanf("%d:%d", &fee[i].begin[0], &fee[i].begin[1]);
		if(t==0 || (fee[i].begin[0]<0||fee[i].begin[0]>=24) 
		||(fee[i].begin[1]<0||fee[i].begin[1]>=60) )
		{
			ErrorInput("请输入正确的上机时间！");
			continue;
		}
		
		printf("请输入下机时间(如21:46)：");
		t = scanf("%d:%d", &fee[i].end[0], &fee[i].end[1]);
		
		hour = GetHour(&fee[i]);
		if(t==0 || ((fee[i].begin[0]<0||fee[i].begin[0]>=24) 
		||(fee[i].begin[1]<0||fee[i].begin[1]>=60)) || (hour<=0) )
		{
			ErrorInput("请输入正确的下机时间！");
			continue;
		}
		
		if(CheckTime(&fee[i]) == 0){
			ErrorInput("该时间段与已有数据冲突！");
			continue;
		}
		break;
	}
	
	fee[i].fee = hour*2;
	cpt_fee[fee[i].num] += fee[i].fee;
	total++;
	puts("录入成功！");
	system("pause");
	system("cls");
}

void PrintData()
{
	int i;
	
	puts("卡号    计算机编号    上机时间    下机时间    费用"); 
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
	
	puts("1. 卡号查询\n2. 计算机编号查询\n0. 退出"); 
	printf("请输入查询方式：");
	t = scanf("%d", &x);
	if(t==0 || (x!=0&&x!=1&&x!=2)){
		ErrorInput("输入有误！请检查输入！");
		return;
	}
	
	if(x == 0){
		return;
	}else if(x == 1){
		printf("请输入卡号："); 
		t = scanf("%d", &x);
		if(t==0 || x<=0 || x>1000){
			ErrorInput("输入有误！请检查输入！");
			return;
		}
		
		puts("卡号    计算机编号    上机时间    下机时间    费用");		
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
			ErrorInput("查无此人！");
			return;
		}
	}else if(x == 2){
		printf("请输入计算机编号："); 
		t = scanf("%d", &x);
		if(t==0 || x<=0 || x>1000){
			ErrorInput("输入有误！请检查输入！");
			return;
		}
		 
		puts("卡号    计算机编号    上机时间    下机时间    费用");		
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
			ErrorInput("查无此人！");
			return;
		}
	}
	system("pause");
}
	
void Find(int index[], int *n)
{
	int i, j, t;
	int x;
	
	printf("请输入卡号查找："); 
	t = scanf("%d", &x);
	if(t==0 || x<=0 || x>1000){
		ErrorInput("输入有误！请检查输入！");
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
		puts("查无此人！"); 
		system("pause");
	}
}
	
void Modify()
{
	int i, t, hour;
	int psw, n = 0;
	int index[N];
	
	printf("Tips：管理员密码是123456\n\n");
	Find(index, &n);
	if(n == 0)
		return;
	
	puts("序号    卡号    计算机编号    上机时间    下机时间    费用");	
	for(i = 0; i < n; ++i)
	{
		t = index[i];
		printf("%d      %4d      %4d          %02d:%02d        %02d:%02d       %d\n",
		i+1, fee[t].card, fee[t].num, fee[t].begin[0], 
		fee[t].begin[1], fee[t].end[0], fee[t].end[1], fee[t].fee);
	}
	
	printf("\n请输入操作密码：");
	t = scanf("%d", &psw);
	if(t==0 || psw!=123456){
		ErrorInput("输入错误！");
		return;
	}
		
	puts("\n请输入要修改的序号："); 
	t = scanf("%d", &i);
	if(t==0 || i<=0 || i>n){
		ErrorInput("输入错误！请检查输入！");
		return;
	}
	
	i = index[i-1];
	cpt_fee[fee[i].num] -= fee[i].fee;
	while(1)
	{
		printf("请输入计算机编号(1~100)："); 
		t = scanf("%d", &fee[i].num);
		if(t==0 || fee[i].num<=0 || fee[i].num>100){
			ErrorInput("请输入正确的计算机编号！");
			continue;
		}
		
		printf("请输入上机时间(如14:52)：");
		t = scanf("%d:%d", &fee[i].begin[0], &fee[i].begin[1]);
		if(t==0 || (fee[i].begin[0]<0||fee[i].begin[0]>=24) 
		||(fee[i].begin[1]<0||fee[i].begin[1]>=60))
		{
			ErrorInput("请输入正确的上机时间！");
			continue;
		}
		
		printf("请输入下机时间(如21:46)：");
		t = scanf("%d:%d", &fee[i].end[0], &fee[i].end[1]);
		
		hour = GetHour(&fee[i]);
		if(t==0 || ((fee[i].begin[0]<0||fee[i].begin[0]>=24) 
		||(fee[i].begin[1]<0||fee[i].begin[1]>=60)) || (hour<=0) )
		{
			ErrorInput("请输入正确的下机时间！");
			continue;
		}
		if(CheckTime(&fee[i], i) == 0){
			ErrorInput("该时间段与已有数据冲突！");
			continue;
		}
		break;
	}	
	fee[i].fee = hour*2;
	cpt_fee[fee[i].num] += fee[i].fee;
	puts("修改成功！");
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
	
	puts("序号    卡号    计算机编号    上机时间    下机时间    费用");	
	for(i = 0; i < n; ++i)
	{
		t = index[i];
		printf("%d    %4d    %4d    %02d:%02d        %02d:%02d       %d\n",
		i+1, fee[t].card, fee[t].num, fee[t].begin[0], 
		fee[t].begin[1], fee[t].end[0], fee[t].end[1], fee[t].fee);
	}	
	puts("\n请输入要删除的序号："); 
	t = scanf("%d", &i);
	if(t==0 || t<=0 || t>n){
		ErrorInput("输入错误！请检查输入！");
		return;
	}
	
	n = index[i-1];
	cpt_fee[fee[n].num] -= fee[n].fee;
	for(i = n+1; i < total; ++i)
		fee[i-1] = fee[i];			
	total--;
	
	puts("删除成功！");
	system("pause");
}
	
void Statistics()
{
	int i, fee_sum = 0;
	for(i = 0; i < total; ++i)
		fee_sum += fee[i].fee;
	printf("所有用户上机费用之和：%d\n\n", fee_sum);
	
	puts("每台电脑的所有费用之和");
	puts("\n编号    费用\n"); 
	for(i = 0; i < N; ++i)
		if(cpt_fee[i] != 0)
			printf("%d\t%d\n", i, cpt_fee[i]);
					
	system("pause");
}
