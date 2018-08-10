#include<iostream>  //���Ѵ������������һ��Last[100]��������¼����ѧУ����¼ȡ��ѧ����index;
#include<algorithm>  //���⻹Ҫע������ѧ����ѧ��(����ǰ)�Լ�index(�����)������;
#include<string.h>  //��˱�������һ��num���¼ѧ����ѧ��;
#include<ctype.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<map>
using namespace std;

struct student{
	int num,ge,gi,total,rank;
	int priority[5];
	bool operator<(const student &b)const{
		if(total!=b.total)
			return total>b.total;
		else 
			return ge>b.ge;
	}
}Stu[40000];

int N,M,K;
int Quota[100],Last[100];
priority_queue<int,vector<int>,greater<int>> Q[100];

void Input(){
	int i,j;
	scanf("%d%d%d",&N,&M,&K);
	for(i=0;i<M;i++){
		scanf("%d",&Quota[i]);
		Last[i]=-1;
	}
	for(i=0;i<N;i++){
		Stu[i].num=i;
		scanf("%d%d",&Stu[i].ge,&Stu[i].gi);
		Stu[i].total=Stu[i].ge+Stu[i].gi;
		for(j=0;j<K;j++)
			scanf("%d",&Stu[i].priority[j]);
	}
	sort(Stu,Stu+N);
	Stu[0].rank=0;
	for(i=1;i<N;i++){
		if(Stu[i].total==Stu[i-1].total&&Stu[i].ge==Stu[i-1].ge)
			Stu[i].rank=Stu[i-1].rank;
		else
			Stu[i].rank=i;
	}
}

void Process(){
	int i,j,k;
	k=Stu[0].priority[0];  //0��ѧ����¼ȡ;
	Q[k].push(Stu[0].num);
	Last[k]=0;	  //last��¼���±�¼ȡ��ѧ���ĺ�;
	for(i=1;i<N;i++){
		for(j=0;j<K;j++){
			k=Stu[i].priority[j];
			if(Q[k].size()<Quota[k]){  //�������,����¼ȡ;
				Q[k].push(Stu[i].num);
				Last[k]=i;				
				break;
			}
			else if(Stu[i].rank==Stu[Last[k]].rank){  //ͬ����,�������Ҫ��¼ȡ;
				Q[k].push(Stu[i].num);
				Last[k]=i;
				break;
			}
		}
	}
}

void Display(){
	int i;
	for(i=0;i<M;i++){
		if(Q[i].empty())
			printf("\n");
		else{
			printf("%d",Q[i].top());
			Q[i].pop();
			while(!Q[i].empty()){
				printf(" %d",Q[i].top());
				Q[i].pop();
			}
			printf("\n");
		}
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