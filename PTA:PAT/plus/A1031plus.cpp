#include<iostream>  //��ģ�⻭ͼ;
#include<algorithm>  //�������ֵ�˼��,�Ի�ͼ���ӵ�H��W�Ĵ�С����Ҫ��,��Ҫ�����ͼ������;
#include<string.h>  //������õ����N1,N2�ķ�����N1=[(L+2)/3],������ȡ��;
#include<ctype.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<map>
using namespace std;

int L,N1,N2;
char A[100];

void GetN(){  //����Ǿ��������ó��ķ���,�ȱ�������Ҫ��;
	N1=(L+2)/3;
	N2=L+2-2*N1;
}

void Input(){
	scanf("%s",A);
	L=strlen(A);
	GetN();
}

void Process(){
	int i,j;
	for(i=0;i<N1-1;i++){
		printf("%c",A[i]);
		for(j=2;j<N2;j++)
			printf(" ");
		printf("%c\n",A[L-1-i]);
	}
	for(;i<N1+N2-1;i++)
		printf("%c",A[i]);
	printf("\n");
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