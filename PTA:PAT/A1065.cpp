#include<iostream>  //�ڴ���һЩ������ʱ,�����ź����ַֿ�������һ�ֱȽϺõ�����,���Ű���������,С����ȵ�;
#include<algorithm>  //ͳһ�������浽�ַ����ĵ�λ,������Ƚ�;
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<map>
using namespace std;

struct biginteger{
	bool sign;  //true��,false��;
	char Num[25];
}A,B,C,S;

int T;
char As[25],Bs[25],Cs[25];

void Input(){
	scanf("%d",&T);
}

void InitStr(){
	int i,j;
	if(As[0]=='-'){
		A.sign=false;
		A.Num[24]='\0';
		i=strlen(As)-1,j=23;
		for(;i>=1;i--)
			A.Num[j--]=As[i];
		for(;j>=0;j--)
			A.Num[j]='0';
	}
	else{
		A.sign=true;
		A.Num[24]='\0';
		i=strlen(As)-1,j=23;
		for(;i>=0;i--)
			A.Num[j--]=As[i];
		for(;j>=0;j--)
			A.Num[j]='0';
	}
	if(Bs[0]=='-'){
		B.sign=false;
		B.Num[24]='\0';
		i=strlen(Bs)-1,j=23;
		for(;i>=1;i--)
			B.Num[j--]=Bs[i];
		for(;j>=0;j--)
			B.Num[j]='0';
	}
	else{
		B.sign=true;
		B.Num[24]='\0';
		i=strlen(Bs)-1,j=23;
		for(;i>=0;i--)
			B.Num[j--]=Bs[i];
		for(;j>=0;j--)
			B.Num[j]='0';
	}
	if(Cs[0]=='-'){
		C.sign=false;
		C.Num[24]='\0';
		i=strlen(Cs)-1,j=23;
		for(;i>=1;i--)
			C.Num[j--]=Cs[i];
		for(;j>=0;j--)
			C.Num[j]='0';
	}
	else{
		C.sign=true;
		C.Num[24]='\0';
		i=strlen(Cs)-1,j=23;
		for(;i>=0;i--)
			C.Num[j--]=Cs[i];
		for(;j>=0;j--)
			C.Num[j]='0';
	}
}

void ADD(){  //ͬ��;
	S.sign=A.sign;
	S.Num[24]='\0';
	int i,temp=0;
	for(i=23;i>=0;i--){
		temp+=A.Num[i]-'0'+B.Num[i]-'0';
		S.Num[i]=temp%10+'0';
		temp/=10;
	}
}

void SUB(){  //���;	
	if(strcmp(A.Num,B.Num)==0){
		S.sign=true;
		S.Num[24]='\0';
		int i;
		for(i=23;i>=0;i--)
			S.Num[0]='0';
	}
	else{
	S.sign=B.sign;
	S.Num[24]='\0';
	int i;
	for(i=23;i>=0;i--){
		if(B.Num[i]>=A.Num[i])
			S.Num[i]=B.Num[i]-A.Num[i]+'0';
		else{
			S.Num[i]=B.Num[i]-A.Num[i]+10+'0';
			A.Num[i-1]+=1;
		}
	}
	}
}

void Process(){
	int i;
	for(i=1;i<=T;i++){
		scanf("%s%s%s",As,Bs,Cs);
		InitStr();
		if(A.sign==B.sign)
			ADD();
		else{
			if(strcmp(A.Num,B.Num)>0){  //ע�⵽�ṹ���ǿ���ֱ�Ӹ�ֵ��,���Դ��򻯴���;
				S=A;
				A=B;
				B=S;
			}
			SUB();
		}
		if(S.sign&&!C.sign)
			printf("Case #%d: true\n",i);
		else if(!S.sign&&C.sign)
			printf("Case #%d: false\n",i);
		else{
			if(S.sign){
				if(strcmp(S.Num,C.Num)>0)
					printf("Case #%d: true\n",i);
				else
					printf("Case #%d: false\n",i);
			}
			else{
				if(strcmp(S.Num,C.Num)<0)
					printf("Case #%d: true\n",i);
				else
					printf("Case #%d: false\n",i);
			}
		}
	}
}

void Display(){

}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}