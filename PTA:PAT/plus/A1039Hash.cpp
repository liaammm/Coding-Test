#include<iostream>  //��Ҫ���Ŀռ�,��ʮ���QҲ�ǿ�����㿪��;
#include<algorithm>  //���ù�ϣӳ��ľ��䰸��;
#include<string.h>  //�����ǲ�ѯ��Ŀ,���ų���β�ͬһ��ѧ��,��˲���vector+sort����;
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

int N,K,C;
vector<int> Graph[175760];

int GetNum(char s[]){
	int i,p;
	p=0;
	for(i=0;i<3;i++)
		p=p*26+s[i]-'A';
	p=p*10+s[3]-'0';
	return p;
}

void Input(){
	int i,course,n,stu;
	char s[5];
	C=0;
	scanf("%d%d",&N,&K);
	for(i=0;i<K;i++){
		scanf("%d%d",&course,&n);
		while(n-->0){
			scanf("%s",s);
			stu=GetNum(s);
			Graph[stu].push_back(course);
		}
	}
	for(i=0;i<175760;i++)
		if(!Graph[i].empty())
			sort(Graph[i].begin(),Graph[i].end());
}

void Process(){
	int i,stu;
	char s[5];
	while(N-->0){
		scanf("%s",s);
		stu=GetNum(s);
		printf("%s %d",s,Graph[stu].size());
		for(i=0;i<Graph[stu].size();i++)	
			printf(" %d",Graph[stu][i]);
		printf("\n");
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
