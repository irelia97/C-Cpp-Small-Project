/* �ַ�������ϵͳ */ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Menu();
int  stringCmp(const char* a, const char* b);	//�Ƚ� 
void stringRep(char* a, const char* b, int start, int n);	//�滻 
int  stringSub(const char* a, const char* b);	//���� 
void stringDel(char* a, const char* b);	//ɾ�� 
void stringIns(char* a, const char* b, int start);	//���� 
void stringNum(char *a, int num);	//��ֵת�ַ��� 
void stringEnc(char *a);	//���� 
void stringDec(char *a);	//���� 

int main()
{
	Menu();
	
	return 0;
}

void Menu()
{
	char a[128], b[128];
	int  index, res;
	int  start, n;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	
	do{
		system("cls");
		puts("-----------------------�ַ�������ϵͳ-----------------------\n");
		printf("1. �ַ����Ƚ�\n2. �ַ����滻\n3. ɾ���ַ���\n4. �����ַ�λ��\n");
		printf("5. �����Ӵ�\n6. ����ת��Ϊ�ַ���\n7. �ַ�������\n8. �ַ�������\n9. �˳�\n");
		puts("\n------------------------------------------------------------\n"); 	
		
		printf("�����빦����ţ�");	
		scanf("%d", &index);
		switch(index){
			case 1:
				printf("�ַ���a��");
				scanf("%s", a);
				printf("�ַ���b��");
				scanf("%s", b);
				res = stringCmp(a,b);
				printf("�ַ���ֵΪ��%d\n", res);
				break;
			case 2:
				printf("�ַ���a��");
				scanf("%s", a);
				printf("�ַ���b��");
				scanf("%s", b);
				printf("���±�i����ʼ�滻��", start); 
				scanf("%d", &start);
				printf("�滻���ٸ��ַ���");
				scanf("%d", &n);
				stringRep(a, b, start, n);
				printf("�滻���ַ���aΪ��%s\n", a);
				break;
			case 3:
				printf("�ַ���a��");
				scanf("%s", a);
				printf("�ַ���b��");
				scanf("%s", b);
				stringDel(a, b);
				printf("ɾ���Ӵ�b��Ĵ�aΪ��%s\n", a);
				break;
			case 4:
				printf("�ַ���a��");
				scanf("%s", a);
				printf("�ַ���b��");
				scanf("%s", b);
				res = stringSub(a, b);
				printf("�Ӵ�b�ڴ�a�״γ���λ��ʹ��%d(-1��ʾ�����Ӵ�)\n", res);
				break;
			case 5:
				printf("�ַ���a��");
				scanf("%s", a);
				printf("�ַ���b��");
				scanf("%s", b);
				printf("���±�i��ʼ�����Ӵ�b��"); 
				scanf("%d", &start);
				stringIns(a, b, start);	
				printf("�滻��Ĵ�aΪ��%s\n", a);
				break;
			case 6:
				printf("������һ��������");
				scanf("%d", &n);
				stringNum(a, n);
				printf("ת��Ϊ�ַ���Ϊ��%s\n", a);
				break;
			case 7:
				printf("������һ���ַ�����");
				scanf("%s", a);
				stringEnc(a);
				printf("���ܺ���ַ���Ϊ��%s\n", a); 
				break;
			case 8:
				stringDec(a);
				printf("���ܺ���ַ���Ϊ��%s\n", a); 	 
				break;
			case 9:
				;															 
		}
		system("pause");
	}while(index != 9);
}

int stringCmp(const char* a, const char* b)
{
	if( a==NULL || b==NULL )
		return 0;
	
	while( *b!='\0' && *a==*b )	//��ʹ *a=='\0', Ҳ�� *a!=*b
		++a, ++b;
	return *a-*b;
}

void stringRep(char* a, const char* b, int start, int n)
{
	if( a==NULL || b==NULL )
		return;

	if( start<0 || start>=strlen(a) ){
		puts("����start�����Ͻ���½磡");
		return;
	}
	
	int i = 0, j = start;
	for( ; i<n && a[j]!='\0'; ++i, ++j)
		a[j] = b[i];
}
	
int stringSub(const char* a, const char* b)
{
	int len1 = strlen(a);
	int len2 = strlen(b);
	if( a==NULL || b==NULL || len1<len2 )
		return -1;	
	
	int i, j, k;
	for(i = 0; i <= len1-len2; ++i)	//	�����㷨�����Ӵ� 
	{
		k = i;
		for(j = 0; j < len2; ++k, ++j)
			if( a[k] != b[j] )	
				break;
		if( j == len2)
			return i;
	}
	return -1;	//	Not found����Ϊ0���ܱ�ʾ�ڿ�ͷ���
}

void stringDel(char* a, const char* b)
{
	int len1 = strlen(a);
	int len2 = strlen(b);
	if( a==NULL || b==NULL || len1<len2 )
		return;
	
	int i = 0, j = 0;	
	while(i != -1)
	{
		i = stringSub(a, b);		
		if(i != -1){
			j = i + len2;
			while(a[j] != '\0')
				a[i++] = a[j++];
			a[i] = '\0';				
		}
	}		
}

void stringIns(char* a, const char* b, int start)
{
	int len1 = strlen(a);
	int len2 = strlen(b);
	if( a==NULL || b==NULL )
		return;
	if( start<0 || start>=len1 ){
		puts("����start�����Ͻ���½磡");
		return;
	}
	
	int i, j;
	for(i = len1+len2-1; i > start; --i)
		a[i] = a[i-len2]; 
	for(i = start+1, j = 0; j < len2; ++i,++j)
		a[i] = b[j];
	a[len1+len2] = '\0';
}
	
void stringNum(char *a, int num)
{
	if( a == NULL )
		return;	
	if( num < 0 ){
		a[0] = '-';
		num *= -1;
	}
	
	int i = -1, j = (a[0]=='-') ? 1:0;
	int stack[10];
	do{
		stack[++i] = num%10;
		num /= 10;
	}while(num != 0);
	
	while(i >= 0)
		a[j++] = (stack[i--]+'0');
	a[j] = '\0';	
}

void stringEnc(char *a)
{
	int i, t;
	const int key[] = {5,7,8,6,4,3,9,2};
	
	for(i = 0; i < strlen(a); ++i)
	{
		t = (int)a[i] + key[i%8];
		if(t > 122)
			a[i] = (char)(t%91);
		else
			a[i] = (char)(t);
	}
}

void stringDec(char *a)
{
	int i, t;
	const int key[] = {5,7,8,6,4,3,9,2};
	
	for(i = 0; i < strlen(a); ++i)
	{
		t = (int)a[i] - key[i%8];
		if(t < 32)
			a[i] = (char)(t+91);
		else
			a[i] = (char)(t);
	}
}		
