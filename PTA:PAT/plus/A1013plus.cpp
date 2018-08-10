#include<iostream>  //ʵ����������DFS����BFS������ͼ��ͨ�����ĸ���;
#include<algorithm>  //ʱ����BFS��DFS���,DFS��Ҫ�յ�����ջ����;
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

int N,M,K,C;
bool Mark[1001];
vector<int> Graph[1001];
queue<int> Q;

void Input(){
	int c1,c2;
	scanf("%d%d%d",&N,&M,&K);
	while(M-->0){
		scanf("%d%d",&c1,&c2);
		Graph[c1].push_back(c2);
		Graph[c2].push_back(c1);
	}
}

void BFS(int i){
	int j,k,l;
	Mark[i]=true;
	Q.push(i);
	while(!Q.empty()){
		j=Q.front();
		Q.pop();
		for(k=0;k<Graph[j].size();k++){
			l=Graph[j][k];
			if(!Mark[l]){
				Mark[l]=true;
				Q.push(l);
			}
		}
	}
}

void Process(){
	int i,check;
	while(K-->0){
		for(i=1;i<=N;i++)
			Mark[i]=false;
		scanf("%d",&check);
		Mark[check]=true;
		C=-1;
		for(i=1;i<=N;i++)
			if(!Mark[i]){
				C++;
				BFS(i);
			}
		printf("%d\n",C);
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
