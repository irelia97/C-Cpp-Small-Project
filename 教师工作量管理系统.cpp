#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100

int num  = 0;
int flag = 1;
struct teachar
{
	char  tno[32];	//��ʦ��� 
	char  name[32];	//���� 
	char  rank[32];	//ְ��
	char  cno[32];	//�γ̱��
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
	if(strcmp(rank,"����")  ==0 || strcmp(rank,"��ʦ")==0 ||
	   strcmp(rank,"������")==0 || strcmp(rank,"����")==0)
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
	if(strcmp(rank,"����") == 0){
		return 20.0*work;
	}else if(strcmp(rank,"��ʦ") == 0){
		return 24.0*work;
	}else if(strcmp(rank,"������")==0){
		return 28.0*work;
	}else if(strcmp(rank,"����")==0){
		return 32.0*work;
	}
}

void Menu()
{
	int t, index = 0;
	
	do{
		system("cls");
		puts("--------------------------��ʦ����������ϵͳ--------------------------");
		puts("1. ��Ϣ¼��ͱ���\n2. ��ʾ��Ϣ\n3. ��ѯ��Ϣ(���)\n4. ��ѯ��Ϣ(����)");
		puts("5. �޸���Ϣ\n6. ɾ����Ϣ\n7. ׷����Ϣ\n8. ͳ��\n9. �˳�\n");
		printf("��ǰ����%d����Ϣ\n", num); 
		puts("----------------------------------------------------------------------"); 
		
		printf("�����빦����ţ�");
		t = scanf("%d", &index);
		if(t==0 || index<=0 || index>9){
			Error("���������������룡");
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
				Error("��������ϵͳ���´��ټ���");
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
		Error("�����������ޣ�");
		return;
	}
	
	while(1)
	{
		system("cls");
		printf("------------��%d����Ϣ����------------\n\n", num+1);
		printf("�������ʦ��ţ�");
		scanf("%s",teac[i].tno);
		printf("�������ʦ������"); 
		scanf("%s",teac[i].name);	
		
		printf("�������ʦְ��(���̡���ʦ�������ڻ����)��");
		scanf("%s",teac[i].rank);
		if( CheckRank(teac[i].rank) != 1){
			Error("������������ְ�ƣ�");
			continue;
		}
		if( CheckTeac(teac[i].tno, teac[i].name, teac[i].rank) != 1 ){
			Error("�˽�ʦ��֮ǰ¼�����Ϣ��һ�£�");
			continue;
		}
		
		printf("������γ̱�ţ�");
		scanf("%s",teac[i].cno);		
		printf("������γ�ѧʱ��");
		t = scanf("%f", &n);
		if(t==0 || n<=0 || n!=(int)n){
			Error("�������������������룡");
			continue;
		}
		printf("������༶��(1~3)��"); 
		t = scanf("%f", &m);
		if(t==0 || m<=0 || m>3 || m!=(int)m){
			Error("�������������������룡");
			continue;
		}
		break;
	}
	teac[i].cnum = (int)m;
	teac[i].work   = GetWork( (int)m, (int)n );
	teac[i].salary = GetSalary(teac[i].work, teac[i].rank);
	num++;
	puts("\n\n¼����ɣ�\n\n"); 
}
	
void Input()
{
	int i, n, t;
	if(flag == 0){
		Error("�Ѿ����й���Ϣ¼�룡");
		return;
	}
	
	printf("������Ҫ¼�����Ϣ����(1~100)��"); 
	t = scanf("%d", &n);
	if(t==0 || n<=0 || n>100){
		Error("�������������������룡");
		return;
	}
	getchar();
	
	for(i = 0; i < n; ++i)
	{
		printf("����׼��¼��%d����������Ϣ�������ǵ�%d����\n", n, i+1);
		system("pause");				
		Add();
	}
	puts("��Ϣ¼��ɹ�����\n"); 
	flag = 0;
}

void Show()
{
	int i;
	if(num == 0){
		puts("��ǰû����Ϣ�ɹ�������");
		return;
	}	
	puts("���    ����    ְ��    �γ̱��    �༶��    ������    ���η�");
	
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
		puts("��ǰû����Ϣ�ɹ�������");
		return;
	}
	
	printf("�������ѯ�Ľ�ʦ���(ģ����ѯ)��");
	scanf("%s",tno); 
	for(i = 0, j = 0; i < num; ++i)
	{
		if(strstr(teac[i].tno, tno) != NULL )
			index[j++] = i;
	}
	if(j == 0){
		Error("���޴��ˣ�");
		return;
	}else{
		puts("���    ����    ְ��    �γ̱��    �༶��    ������    ���η�");		
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
		puts("��ǰû����Ϣ�ɹ�������");
		return;
	}
	
	printf("�������ѯ�Ľ�ʦ����(ģ����ѯ)��");
	scanf("%s",name); 
	for(i = 0, j = 0; i < num; ++i)
	{
		if(strstr(teac[i].name, name) != NULL )
			index[j++] = i;
	}
	if(j == 0){
		Error("���޴��ˣ�");
		return;
	}else{
		puts("���    ����    ְ��    �γ̱��    �༶��    ������    ���η�");		
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
		puts("��ǰû����Ϣ�ɹ�������");
		return;
	}	
	printf("������Ҫ�޸���Ϣ�Ľ�ʦ��ţ�");
	scanf("%s",tno); 
	for(i = 0, j = 0; i < num; ++i)
		if(strcmp(tno, teac[i].tno) == 0)
			index[j++] = i;
	if(j == 0){
		Error("���޴���");
		return;
	}else{
		puts("���    ����    ְ��    �γ̱��    �༶��    ������    ���η�    ���");				
		for(i = 0; i < j; ++i)
		{
			k = index[i];
			printf("%s\t%s\t%s\t%s\t\t%d\t%.2f\t%.2f\t%d\n", teac[k].tno, teac[k].name, 
			teac[k].rank, teac[k].cno, teac[k].cnum, teac[k].work, teac[k].salary, i+1);
		}
		printf("��ѡ��Ҫ�޸ĵ���Ϣ���(1~%d)��", j);
		t = scanf("%d", &i);
		if(t==0 || i<=0 || i>j){
			Error("���������������룡");
			return;
		}
		
		i = index[i-1];	
		printf("�������µĿγ̱�ţ�");
		scanf("%s",teac[i].cno);
		
		printf("�������µĿγ�ѧʱ��");
		t = scanf("%f", &n);
		if(t==0 || n<=0 || n!=(int)n){
			Error("�������������������룡");
			return;
		}
		printf("�������µİ༶��(1~3)��"); 
		t = scanf("%f", &m);
		if(t==0 || m<=0 || m>3 || m!=(int)m){
			Error("�������������������룡");
			return;
		}
		teac[i].cnum = (int)m;
		teac[i].work   = GetWork( (int)m, (int)n );
		teac[i].salary = GetSalary(teac[i].work, teac[i].rank);
	}
	puts("�޸ĳɹ���"); 
}

void Delete()
{
	int   i, j, n;
	int   index[N];
	char  tno[32];
	
	if(num == 0){
		puts("��ǰû����Ϣ�ɹ�������");
		return;
	}		
	printf("������Ҫɾ����Ϣ�Ľ�ʦ��ţ�");
	scanf("%s",tno); 
	for(i = 0, j = 0; i < num; ++i)
		if(strcmp(tno, teac[i].tno) == 0)
			index[j++] = i;
	if(j == 0){
		Error("���޴���");
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
	puts("ɾ����ɣ�");
}

void Statistics()
{
	int   i, t;
	char  tno[32];
	char  ranks[4][8] = {"����", "��ʦ", "������", "����"}; 
	float sum_work[4] = {0.0};
	int   nums[4] = {0};
	float work = 0.0, salary = 0.0;

	if(num == 0){
		puts("��ǰû����Ϣ�ɹ�������");
		return;
	}	
	puts("1. �����ţ�����ý�ʦ�ܵĹ��������ܴ��η�\n2. ����ְ��ͳ�ƣ�����ְ�Ƶ�ƽ��������\n0. �˳�\n");
	printf("�����빦����ţ�");   
	t = scanf("%d", &i);
	if(t==0 || t<0 || t>2){
		Error("���������������룡");
		return;
	}

	switch(i)
	{
		case 0:
			return;
		case 1:
			printf("������Ҫͳ�ƵĽ�ʦ��ţ�");
			scanf("%s",tno);
			for(i = 0; i < num; ++i)
			{
				if(strcmp(tno, teac[i].tno) == 0){
					work   += teac[i].work;
					salary += teac[i].salary;
				}
			}
			if(work < 1e-6){
				Error("���޴��ˣ�");
				return;
			}else{
				printf("�ܹ�������%5.2f���ܴ��ηѣ�%5.2f\n", work, salary);
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
			puts("ְ��\t\tƽ��������\n"); 
			for(i = 0; i < 4; ++i)
				printf("%s��\t\t%5.2f\n", ranks[i], sum_work[i]/nums[i]);
	}				
}
