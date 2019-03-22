/* 字符串处理系统 */ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Menu();
int  stringCmp(const char* a, const char* b);	//比较 
void stringRep(char* a, const char* b, int start, int n);	//替换 
int  stringSub(const char* a, const char* b);	//搜索 
void stringDel(char* a, const char* b);	//删除 
void stringIns(char* a, const char* b, int start);	//插入 
void stringNum(char *a, int num);	//数值转字符串 
void stringEnc(char *a);	//加密 
void stringDec(char *a);	//解密 

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
		puts("-----------------------字符串处理系统-----------------------\n");
		printf("1. 字符串比较\n2. 字符串替换\n3. 删除字符串\n4. 搜索字符位置\n");
		printf("5. 插入子串\n6. 整数转换为字符串\n7. 字符串加密\n8. 字符串解密\n9. 退出\n");
		puts("\n------------------------------------------------------------\n"); 	
		
		printf("请输入功能序号：");	
		scanf("%d", &index);
		switch(index){
			case 1:
				printf("字符串a：");
				scanf("%s", a);
				printf("字符串b：");
				scanf("%s", b);
				res = stringCmp(a,b);
				printf("字符差值为：%d\n", res);
				break;
			case 2:
				printf("字符串a：");
				scanf("%s", a);
				printf("字符串b：");
				scanf("%s", b);
				printf("从下标i处开始替换：", start); 
				scanf("%d", &start);
				printf("替换多少个字符：");
				scanf("%d", &n);
				stringRep(a, b, start, n);
				printf("替换后字符串a为：%s\n", a);
				break;
			case 3:
				printf("字符串a：");
				scanf("%s", a);
				printf("字符串b：");
				scanf("%s", b);
				stringDel(a, b);
				printf("删除子串b后的串a为：%s\n", a);
				break;
			case 4:
				printf("字符串a：");
				scanf("%s", a);
				printf("字符串b：");
				scanf("%s", b);
				res = stringSub(a, b);
				printf("子串b在串a首次出现位置使：%d(-1表示不是子串)\n", res);
				break;
			case 5:
				printf("字符串a：");
				scanf("%s", a);
				printf("字符串b：");
				scanf("%s", b);
				printf("从下标i开始插入子串b："); 
				scanf("%d", &start);
				stringIns(a, b, start);	
				printf("替换后的串a为：%s\n", a);
				break;
			case 6:
				printf("请输入一个整数：");
				scanf("%d", &n);
				stringNum(a, n);
				printf("转换为字符串为：%s\n", a);
				break;
			case 7:
				printf("请输入一个字符串：");
				scanf("%s", a);
				stringEnc(a);
				printf("加密后的字符串为：%s\n", a); 
				break;
			case 8:
				stringDec(a);
				printf("解密后的字符串为：%s\n", a); 	 
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
	
	while( *b!='\0' && *a==*b )	//即使 *a=='\0', 也有 *a!=*b
		++a, ++b;
	return *a-*b;
}

void stringRep(char* a, const char* b, int start, int n)
{
	if( a==NULL || b==NULL )
		return;

	if( start<0 || start>=strlen(a) ){
		puts("参数start超出上界或下界！");
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
	for(i = 0; i <= len1-len2; ++i)	//	朴素算法搜索子串 
	{
		k = i;
		for(j = 0; j < len2; ++k, ++j)
			if( a[k] != b[j] )	
				break;
		if( j == len2)
			return i;
	}
	return -1;	//	Not found，若为0可能表示在开头相等
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
		puts("参数start超出上界或下界！");
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
