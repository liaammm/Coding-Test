#include<iostream>  //map,tolower,toupper,ctype.h;
#include<algorithm>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<map>
using namespace std;

int Max_Num;
char A[1100000];
char Ans[20],Wod[20];  //ʹ��string�������ַ�������ȷ�������;
map<string,int> MP;

void Input(){
	int i,j,t;
	gets(A);
	for(i=0;A[i]!='\0';i++)
		A[i]=tolower(A[i]);
	i=0;
	Max_Num=0;
	while(A[i]!='\0'){
		if((A[i]<='z'&&A[i]>='a')||(A[i]<='9'&&A[i]>='0')){
			j=0;
			for(;(A[i]<='z'&&A[i]>='a')||(A[i]<='9'&&A[i]>='0');i++)
				Wod[j++]=A[i];
			Wod[j]='\0';
			t=++MP[Wod];
			if(t>Max_Num){  //��������;
				Max_Num=t;
				strcpy(Ans,Wod);
			}
			else if(t==Max_Num&&Wod<Ans)  //���ѡ���ֵ����С��;
				strcpy(Ans,Wod);
		}
		else
			i++;
	}
}

void Process(){

}

void Display(){
	printf("%s %d\n",Ans,Max_Num);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
