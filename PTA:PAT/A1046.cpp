#include<iostream>  //��Ϊ��һ��ѭ����Ȧ,�����ľ���ֻ������,˳ʱ�����ʱ��,�ֱ��¼�Ƚϼ���;
#include<algorithm>  //����˫��˼��,��1����¼����;
#include<string.h>  //���õ�˼·�ǲ���sum����,���ѯ����ֻ��Ҫ��һ������;
#include<ctype.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<map>
using namespace std;

int N,M;
int Dist[100001],DistL[100001],DistR[100001];

void Input(){
	int i;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
		scanf("%d",&Dist[i]);
	DistR[1]=0;
	DistR[2]=Dist[1];
	for(i=3;i<=N;i++)
		DistR[i]=DistR[i-1]+Dist[i-1];
	DistL[N]=Dist[N];
	for(i=N-1;i>=1;i--)
		DistL[i]=DistL[i+1]+Dist[i];
}

void Process(){
	int p1,p2,ans;
	scanf("%d",&M);
	while(M-->0){
		scanf("%d%d",&p1,&p2);
		if(p1>p2){
			ans=p1;
			p1=p2;
			p2=ans;
		}
			
		ans=min(DistR[p2]-DistR[p1],DistR[p1]+DistL[p2]);
		printf("%d\n",ans);
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