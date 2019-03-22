#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100

int num  = 0;
int flag = 1;
struct teachar
{
	char  tno[32];	//教师编号 
	char  name[32];	//姓名 
	char  rank[32];	//职称
	char  cno[32];	//课程编号
	int   cnum; 
	float work;
	float salary;
}teac[N];

void Error(const char* msg);
int CheckTeac(const char* tno, const char* name, const char* rank);
int CheckRank(const char* rank);
float GetWork(int cnum, int snum);
float GetSalary(float work, const char* rank);
void Menu();
void Add();
void Input();
void Show();
void SelectByTno();
void SelectByName();
void Modify();
void Delete();
void Statistics();

int main()
{
	Menu();
	return 0;
}

void Error(const char* msg)
{
	puts(msg);
	system("pause");
	fflush(stdin);
}

int CheckTeac(const char* tno, const char* name, const char* rank)
{
	int i;
	for(i = 0; i < num; ++i)
		if(strcmp(tno,teac[i].tno)==0 && 
		  (strcmp(name,teac[i].name)!=0 || strcmp(rank,teac[i].rank)!=0) )
			return 0;
	return 1;
}

int CheckRank(const char* rank)
{
	if(strcmp(rank,"助教")  ==0 || strcmp(rank,"讲师")==0 ||
	   strcmp(rank,"副教授")==0 || strcmp(rank,"教授")==0)
		return 1;
	else
		return 0;
}	 

float GetWork(int cnum, int snum)
{
	if(cnum == 1){
		return 1.0*snum;
	}else if(cnum == 2){
		return 1.5*snum;
	}else if(cnum == 3){
		return 2.0*snum;
	}
}

float GetSalary(float work, const char* rank)
{
	if(strcmp(rank,"助教") == 0){
		return 20.0*work;
	}else if(strcmp(rank,"讲师") == 0){
		return 24.0*work;
	}else if(strcmp(rank,"副教授")==0){
		return 28.0*work;
	}else if(strcmp(rank,"教授")==0){
		return 32.0*work;
	}
}

void Menu()
{
	int t, index = 0;
	
	do{
		system("cls");
		puts("--------------------------教师工作量计算系统--------------------------");
		puts("1. 信息录入和保存\n2. 显示信息\n3. 查询信息(编号)\n4. 查询信息(姓名)");
		puts("5. 修改信息\n6. 删除信息\n7. 追加信息\n8. 统计\n9. 退出\n");
		printf("当前共有%d条信息\n", num); 
		puts("----------------------------------------------------------------------"); 
		
		printf("请输入功能序号：");
		t = scanf("%d", &index);
		if(t==0 || index<=0 || index>9){
			Error("输入有误！请检查输入！");
			continue;
		}
					
		system("cls");
		switch(index)
		{
			case 1:
				Input(); break;
			case 2:
				Show();  break;
			case 3:
				SelectByTno();  break;
			case 4:
				SelectByName(); break;
			case 5:
				Modify(); break;
			case 6:
				Delete(); Show(); break;
			case 7:
				Add(); Show(); break;
			case 8:
				Statistics(); break;
			case 9:
				Error("即将结束系统！下次再见！");
				break; 
		}
		system("pause");
	}while(index != 9);
}
						
void Add()
{
	int i = num;
	int t;	
	float n, m;
	if(i > N-1){
		Error("超出人数上限！");
		return;
	}
	
	while(1)
	{
		system("cls");
		printf("------------第%d条信息输入------------\n\n", num+1);
		printf("请输入教师编号：");
		scanf("%s",teac[i].tno);
		printf("请输入教师姓名："); 
		scanf("%s",teac[i].name);	
		
		printf("请输入教师职称(助教、讲师、副教授或教授)：");
		scanf("%s",teac[i].rank);
		if( CheckRank(teac[i].rank) != 1){
			Error("不存在这样的职称！");
			continue;
		}
		if( CheckTeac(teac[i].tno, teac[i].name, teac[i].rank) != 1 ){
			Error("此教师与之前录入的信息不一致！");
			continue;
		}
		
		printf("请输入课程编号：");
		scanf("%s",teac[i].cno);		
		printf("请输入课程学时：");
		t = scanf("%f", &n);
		if(t==0 || n<=0 || n!=(int)n){
			Error("数据输入有误！请检查输入！");
			continue;
		}
		printf("请输入班级数(1~3)："); 
		t = scanf("%f", &m);
		if(t==0 || m<=0 || m>3 || m!=(int)m){
			Error("数据输入有误！请检查输入！");
			continue;
		}
		break;
	}
	teac[i].cnum = (int)m;
	teac[i].work   = GetWork( (int)m, (int)n );
	teac[i].salary = GetSalary(teac[i].work, teac[i].rank);
	num++;
	puts("\n\n录入完成！\n\n"); 
}
	
void Input()
{
	int i, n, t;
	if(flag == 0){
		Error("已经进行过信息录入！");
		return;
	}
	
	printf("请输入要录入的信息条数(1~100)："); 
	t = scanf("%d", &n);
	if(t==0 || n<=0 || n>100){
		Error("数据输入有误！请检查输入！");
		return;
	}
	getchar();
	
	for(i = 0; i < n; ++i)
	{
		printf("共计准备录入%d条工作量信息！现在是第%d条！\n", n, i+1);
		system("pause");				
		Add();
	}
	puts("信息录入成功！！\n"); 
	flag = 0;
}

void Show()
{
	int i;
	if(num == 0){
		puts("当前没有信息可供操作！");
		return;
	}	
	puts("编号    姓名    职称    课程编号    班级数    工作量    代课费");
	
	for(i = 0; i < num; ++i)
	{
		printf("%s\t%s\t%s\t%s\t\t%d\t%.2f\t%.2f\n", teac[i].tno, teac[i].name, 
		teac[i].rank, teac[i].cno, teac[i].cnum, teac[i].work, teac[i].salary);
	}
}

void SelectByTno()
{
	int  i, j, k;
	int  index[N];
	char tno[32];
	if(num == 0){
		puts("当前没有信息可供操作！");
		return;
	}
	
	printf("请输入查询的教师编号(模糊查询)：");
	scanf("%s",tno); 
	for(i = 0, j = 0; i < num; ++i)
	{
		if(strstr(teac[i].tno, tno) != NULL )
			index[j++] = i;
	}
	if(j == 0){
		Error("查无此人！");
		return;
	}else{
		puts("编号    姓名    职称    课程编号    班级数    工作量    代课费");		
		for(i = 0; i < j; ++i)
		{
			k = index[i];
			printf("%s\t%s\t%s\t%s\t\t%d\t%.2f\t%.2f\n", teac[k].tno, teac[k].name, 
			teac[k].rank, teac[k].cno, teac[k].cnum, teac[k].work, teac[k].salary);
		}
	}
}
	
void SelectByName()
{
	int  i, j, k;
	int  index[N];
	char name[32];
	if(num == 0){
		puts("当前没有信息可供操作！");
		return;
	}
	
	printf("请输入查询的教师姓名(模糊查询)：");
	scanf("%s",name); 
	for(i = 0, j = 0; i < num; ++i)
	{
		if(strstr(teac[i].name, name) != NULL )
			index[j++] = i;
	}
	if(j == 0){
		Error("查无此人！");
		return;
	}else{
		puts("编号    姓名    职称    课程编号    班级数    工作量    代课费");		
		for(i = 0; i < j; ++i)
		{
			k = index[i];
			printf("%s\t%s\t%s\t%s\t\t%d\t%.2f\t%.2f\n", teac[k].tno, teac[k].name, 
			teac[k].rank, teac[k].cno, teac[k].cnum, teac[k].work, teac[k].salary);
		}
	}
}

void Modify()
{
	int   i, j, k, t;
	int   index[N];
	float n, m;
	char  tno[32];
	
	if(num == 0){
		puts("当前没有信息可供操作！");
		return;
	}	
	printf("请输入要修改信息的教师编号：");
	scanf("%s",tno); 
	for(i = 0, j = 0; i < num; ++i)
		if(strcmp(tno, teac[i].tno) == 0)
			index[j++] = i;
	if(j == 0){
		Error("查无此人");
		return;
	}else{
		puts("编号    姓名    职称    课程编号    班级数    工作量    代课费    序号");				
		for(i = 0; i < j; ++i)
		{
			k = index[i];
			printf("%s\t%s\t%s\t%s\t\t%d\t%.2f\t%.2f\t%d\n", teac[k].tno, teac[k].name, 
			teac[k].rank, teac[k].cno, teac[k].cnum, teac[k].work, teac[k].salary, i+1);
		}
		printf("请选择要修改的信息序号(1~%d)：", j);
		t = scanf("%d", &i);
		if(t==0 || i<=0 || i>j){
			Error("输入有误！请检查输入！");
			return;
		}
		
		i = index[i-1];	
		printf("请输入新的课程编号：");
		scanf("%s",teac[i].cno);
		
		printf("请输入新的课程学时：");
		t = scanf("%f", &n);
		if(t==0 || n<=0 || n!=(int)n){
			Error("数据输入有误！请检查输入！");
			return;
		}
		printf("请输入新的班级数(1~3)："); 
		t = scanf("%f", &m);
		if(t==0 || m<=0 || m>3 || m!=(int)m){
			Error("数据输入有误！请检查输入！");
			return;
		}
		teac[i].cnum = (int)m;
		teac[i].work   = GetWork( (int)m, (int)n );
		teac[i].salary = GetSalary(teac[i].work, teac[i].rank);
	}
	puts("修改成功！"); 
}

void Delete()
{
	int   i, j, n;
	int   index[N];
	char  tno[32];
	
	if(num == 0){
		puts("当前没有信息可供操作！");
		return;
	}		
	printf("请输入要删除信息的教师编号：");
	scanf("%s",tno); 
	for(i = 0, j = 0; i < num; ++i)
		if(strcmp(tno, teac[i].tno) == 0)
			index[j++] = i;
	if(j == 0){
		Error("查无此人");
		return;
	}else{
		n = j;
		j = 0;
		while(n--)
		{
			for(i = index[j]+1; i < num; ++i)
				teac[i-1] = teac[i];
			j++;
		}
	}
	num -= j;
	puts("删除完成！");
}

void Statistics()
{
	int   i, t;
	char  tno[32];
	char  ranks[4][8] = {"助教", "讲师", "副教授", "教授"}; 
	float sum_work[4] = {0.0};
	int   nums[4] = {0};
	float work = 0.0, salary = 0.0;

	if(num == 0){
		puts("当前没有信息可供操作！");
		return;
	}	
	puts("1. 输入编号，输出该教师总的工作量和总代课费\n2. 按照职称统计，各类职称的平均工作量\n0. 退出\n");
	printf("请输入功能序号：");   
	t = scanf("%d", &i);
	if(t==0 || t<0 || t>2){
		Error("输入有误！请检查输入！");
		return;
	}

	switch(i)
	{
		case 0:
			return;
		case 1:
			printf("请输入要统计的教师编号：");
			scanf("%s",tno);
			for(i = 0; i < num; ++i)
			{
				if(strcmp(tno, teac[i].tno) == 0){
					work   += teac[i].work;
					salary += teac[i].salary;
				}
			}
			if(work < 1e-6){
				Error("查无此人！");
				return;
			}else{
				printf("总工作量：%5.2f，总代课费：%5.2f\n", work, salary);
			}
			break;
		case 2:
			for(i = 0; i < num; ++i)
			{
				if(strcmp(ranks[0], teac[i].rank) == 0){
					sum_work[0] += teac[i].work;
					nums[0]++;
				}else if(strcmp(ranks[1], teac[i].rank) == 0){
					sum_work[1] += teac[i].work;
					nums[1]++;
				}else if(strcmp(ranks[2], teac[i].rank) == 0){
					sum_work[2] += teac[i].work;
					nums[2]++;
				}else if(strcmp(ranks[3], teac[i].rank) == 0){
					sum_work[3] += teac[i].work;	
					nums[3]++;
				}
			}
			puts("职称\t\t平均工作量\n"); 
			for(i = 0; i < 4; ++i)
				printf("%s：\t\t%5.2f\n", ranks[i], sum_work[i]/nums[i]);
	}				
}
