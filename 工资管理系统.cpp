#include <stdio.h>
#include <stdlib.h>
#define N 75

int total = 0;

struct salary
{
	int   num;
	char  name[20];
	float bas_sal;
	float cut;
	float tax;
	float rel_sal;
}Salary[N];
struct salary* const p = Salary;

void Menu();
int CheckNum(const int num);
float GetTax(const float salary, const float cut);
void InputData();
void PrintData();
int Search();
void Modify();
void Delete();
void Add();
void Statistics();

int main()
{
	Menu();
	return 0;
}

void Menu()
{
	int index = 0;
	int t;
	
	while(1)
	{
		system("cls");
		puts("-------------------工资管理系统-------------------\n");
		printf("1. 信息录入\n2. 信息显示\n3. 查询（按职工编号）\n4. 修改\n");
		printf("5. 删除\n6. 追加\n7. 统计\n8. 退出系统\n\n");
		printf("当前共有职工%d人\n\n", total);
		puts("--------------------------------------------------");
		printf("请输入功能序号：");
		
		t = scanf("%d", &index);
		if(t==0 || (index<1||index>8)){
			puts("输入有误！请检查输入！");
			system("pause");
			fflush(stdin);			
			continue;
		}
		system("cls");
		switch(index)
		{
			case 1:
				InputData(); break;
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
		system("pause");
	}	
}

int CheckNum(const int num)
{
	int i;
	for(i = 0; i < total; ++i)
		if(p[i].num == num)
			return 0;
	return 1;
}

//	参考2018年应纳税所得额计算方法(不含税) 
float GetTax(const float salary, const float cut)
{
	float fast_cut;
	float money = salary-cut-3500.0;
	if(salary<=3500.0){
		return 0.0;
	}else if(money<=1455.0){
		money *= 0.03;
		fast_cut = 0.0;
	}else if(money>1455.0 && money<=4155.0){
		money *= 0.10; 
		fast_cut = 105.0;
	}else if(money>4155.0 && money<=7755.0){
		money *= 0.20;
		fast_cut = 555.0;
	}else if(money>7755.0 && money<=27255.0){
		money *= 0.25;
		fast_cut = 1005.0;
	}else if(money>27255.0 && money<=41255.0){
		money *= 0.30;
		fast_cut = 2755.0;
	}else if(money>41255.0 && money<=57505.0){
		money *= 0.35;
		fast_cut = 5505.0;
	}else{
		money *= 0.45;
		fast_cut = 13505.0;
	}
	
	return money-fast_cut;
}
	
void InputData()
{
	int i, n, t;
	
	printf("请输入职工人数（1~70）：");
	t = scanf("%d", &n);
	if( t==0 || (n+total<=0||n+total>70) ){
		puts("输入有误！请检查输入！");
		system("pause");
		fflush(stdin);		
		return;
	}
	 
	for(i = 0; i < n; ++i)
	{
		system("cls");
		printf("共要录入%d名职工，当前准备录入第%d位\n\n", n, i+1);
		system("pause");
		Add();
	}
	puts("录入成功！");
}

void PrintData()
{
	int i;
	puts("-----------------------------职工工资信息表-----------------------------");
	printf("职工编号    姓名\t基本工资\t扣款\t     税金\t     应发工资\n");
	
	
	for(i = 0; i < total; ++i)
	{
		printf("%d\t    %s\t%-8.2f\t%-8.2f    %.2f\t     %.2f\n", 
		p[i].num, p[i].name, p[i].bas_sal,
		p[i].cut, p[i].tax, p[i].rel_sal);
	}
}

int Search()
{
	int i, num;
	int flag;
	
	puts("-----------------------------职工查找-----------------------------");
	printf("请输入要查找的职工编号：");
	i = scanf("%d", &num);
	
	if( i==0 || (num<=0 || num>70) ){
		puts("输入有误！请检查输入！");
		flag = -1;
		fflush(stdin);		
	}else{
		for(i = 0; i < total; ++i)
		{
			if(p[i].num == num){
				puts("该职工信息如下：\n"); 
				puts("职工编号    姓名\t应发工资");				
				printf("%d\t    %s\t%.2f\n", p[i].num, p[i].name, p[i].rel_sal);			
				flag = i;
				break;
			}
		}
		if(i == total){
			puts("查无此人！");
			flag = -1;
		}
	}
	return flag;
}

void Modify()
{
	int i = Search();
	int t;
	
	if(i == -1)
		return;
	
	system("cls");
	puts("-----------------------------职工信息修改-----------------------------\n");
	
	puts("该职工完整信息如下：");	 
	printf("职工编号    姓名\t基本工资\t扣款\t     税金\t     应发工资\n");
		printf("%d\t    %s\t%-8.2f\t%-8.2f    %.2f\t     %.2f\n", 
	p[i].num, p[i].name, p[i].bas_sal,
	p[i].cut, p[i].tax, p[i].rel_sal);
			
	printf("\n请修改基本工资：");
	t = scanf("%f", &p[i].bas_sal);
	if(t==0 || p[i].bas_sal<=0){
		puts("输入有误！请检查输入！");
		system("pause"); 
		fflush(stdin);		
		return;
	}
	
	printf("请修改扣款：");
	t = scanf("%f", &p[i].cut);
	if(t==0 || p[i].cut<0 || p[i].cut>p[i].bas_sal){
		puts("输入有误！请检查输入！");
		system("pause");
		fflush(stdin);		
		return;
	}
	
	p[i].tax = GetTax(p[i].bas_sal, p[i].cut);
	p[i].rel_sal = p[i].bas_sal-p[i].cut-p[i].tax;
	puts("修改完成！");	
}

void Delete()
{
	int i = Search();	

	if(i == -1)
		return;
	puts("-----------------------------职工信息删除-----------------------------\n");	
	for(i = i+1; i < total; ++i)
		p[i-1] = p[i];
	
	total--;	
	puts("删除完成！");	
}

void Add()
{
	int i = total, t, num;
	if(total >= 69){
		puts("职工人数超出上限！");
		system("pause");
		return;
	}
	
	while(1)
	{
		system("cls");
		puts("-----------------------------职工工资信息录入-----------------------------"); 		
		printf("\n职工编号：");
		t = scanf("%d", &num); 
		if( CheckNum(num)==0 || t==0 || (num<=0||num>70) ){
			puts("输入有误！请重新输入！");
			system("pause");
			fflush(stdin);
			continue;
		}else
			p[i].num = num;
		
		getchar();	//接收回车 
		printf("姓名：");
		gets(p[i].name);
		
		printf("基本工资：");
		t = scanf("%f", &p[i].bas_sal);
		if(t==0 || p[i].bas_sal<=0){
			puts("输入有误！请检查输入！");
			system("pause");
			fflush(stdin);
			continue;
		}
			
		printf("扣款：");
		t = scanf("%f", &p[i].cut);
		if(t==0 || p[i].cut<0 || p[i].cut>p[i].bas_sal){
			puts("输入有误！请检查输入！");
			system("pause");
			fflush(stdin);			
			continue;
		}
		
		p[i].tax = GetTax(p[i].bas_sal, p[i].cut);
		p[i].rel_sal = p[i].bas_sal-p[i].cut-p[i].tax;
		break;
	}
	total++;
}
	
void Statistics()
{
	int i, j, n;
	float avg_sal = 0.0;
	struct salary tmp[N], t;
	
	for(i = 0; i < total; ++i)
	{
		tmp[i] = p[i];
		avg_sal += tmp[i].bas_sal;
	}
	
	n = total<5 ? total:5;
	for(i = 0; i < n-1; ++i)
	{
		for(j = i+1; j < total; ++j)
		{
			if(tmp[i].bas_sal < tmp[j].bas_sal){
				t = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = t;
			}
		}
	}
	puts("-----------------------------职工工资统计-----------------------------\n");	
	printf("平均工资为：%f\n\n", avg_sal/total);
	puts("工资最高的前五位是：");
	puts("职工编号\t姓名\t基本工资"); 
	for(i = 0; i < n; ++i)
		printf("%d\t\t%s\t%.2f\n", tmp[i].num, tmp[i].name, tmp[i].bas_sal);	
}
