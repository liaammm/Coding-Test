#include<iostream>  //������ȫ���������е��±�Ӧ�ô�1��ʼ;
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
#include<set>
using namespace std;

int N,InSeq[1000],Complete[1001];

void Input(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&InSeq[i]);
	sort(InSeq,InSeq+N);
}

void GetComp(int root,int low,int high){  //���õݹ�,�߼��ǳ�֮����;
	if(low<high){  //lowΪ���׽������,highΪĩ�������;
		int n,h,k,l,pos;
		n=high-low+1;  //������;
		h=log((double)n)/log(2.0);  //�߶�-1;
		k=n-pow(2.0,h)+1;  //��Ͳ��Ҷ�Ӹ���;
		l=pow(2.0,h);  //��Ͳ���ʱҶ�Ӹ���;
		if(2*k<l)	//����Ͳ㲻����;
			pos=k+pow(2.0,h-1)-1;  //ȷ������ƫ����;
		else  //����ײ����;
			pos=pow(2.0,h)-1;  //ȷ������ƫ����;
		Complete[root]=InSeq[low+pos];  //�������װ��Complete����;
		GetComp(root*2,low,low+pos-1);  //װ������;
		GetComp(root*2+1,low+pos+1,high);  //װ������;
	}
	else if(low==high)  //��������1,ֱ��װ��;
		Complete[root]=InSeq[low];
}

void Process(){
	GetComp(1,0,N-1);
}

void Display(){
	printf("%d",Complete[1]);
	for(int i=2;i<=N;i++)
		printf(" %d",Complete[i]);
	printf("\n");
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
