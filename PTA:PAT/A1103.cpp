#include<iostream>  // ����ʼ�����Ǽ��������㷨,Ҫѧ������Щ˼·���濿;
#include<algorithm>  //��ʦ����Ĺ��ü�����������������˳���Լ�һЩ���ӵ�����;
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

int N,K,P,L,Max_f_sum;
int Rec[21];
vector<int> Ans,Temp;

void Input(){
	int i,l,t;
	scanf("%d%d%d",&N,&K,&P);
	i=1;
	t=pow((double)i,P);
	while(t<=N){
		Rec[i]=t;
		i++;
		t=pow((double)i,P);
	}
	L=--i;
}

void DFS(int k,int n,int t_sum,int f_sum){
	if(n==K&&t_sum==N){
		if(f_sum>Max_f_sum){
			Ans=Temp;
			Max_f_sum=f_sum;
		}
	}
	else if(n>K||t_sum>N)
		return;
	else{
		Temp.push_back(k);
		DFS(k,n+1,t_sum+Rec[k],f_sum+k);
		Temp.pop_back();
		if(k>1)
			DFS(k-1,n,t_sum,f_sum);
	}
}

void Process(){
	Max_f_sum=0;
	Ans.clear();
	DFS(L,0,0,0);
}

void Display(){
	if(Ans.empty())
		printf("Impossible\n");
	else{
		printf("%d = %d^%d",N,Ans[0],P);
		for(int i=1;i<K;i++)
			printf(" + %d^%d",Ans[i],P);
		printf("\n");
	}
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
