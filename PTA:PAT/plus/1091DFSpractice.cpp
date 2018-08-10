#include<iostream>  //��������ʺϽ�һЩʵ����Ҫ��ȵ�����,���ʺϴ�������,�ݹ�ᱬջ;
#include<algorithm>  //�������Maze����ĿҪע���ж����겻Խ��;
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

int M,N,L,T,C,Ans;
int Go[6][3]={{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};
bool Cube[60][1286][128];

void Input(){
	int i,j,k;
	scanf("%d%d%d%d",&M,&N,&L,&T);
	for(i=0;i<L;i++)
		for(j=0;j<M;j++)
			for(k=0;k<N;k++){
				scanf("%d",&Cube[i][j][k]);
				Cube[i][j][k]=!Cube[i][j][k];
			}
}

void DFS(int i,int j,int k){
	int ti,tj,tk;
	Cube[i][j][k]=true;
	C++;
	for(int p=0;p<6;p++){
		ti=i+Go[p][0];
		tj=j+Go[p][1];
		tk=k+Go[p][2];
		if(ti>=0&&ti<L&&tj>=0&&tj<M&&tk>=0&&tk<N&&!Cube[ti][tj][tk])
			DFS(ti,tj,tk);
	}
}

void Process(){
	Ans=0;
	int i,j,k;
	for(i=0;i<L;i++)
		for(j=0;j<M;j++)
			for(k=0;k<N;k++){
				if(!Cube[i][j][k]){
					C=0;
					DFS(i,j,k);
					if(C>=T)
						Ans+=C;
				}
			}
}

void Display(){
	printf("%d\n",Ans);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
