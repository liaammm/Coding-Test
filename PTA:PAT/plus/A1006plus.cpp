#include<iostream>  //ʵ���Ͽ������ø����ڽṹ����ֻ����һ��time;
#include<algorithm>  //�ṹ����Ƕ�׽ṹ��һ��Ҫ��struct,������벻ͨ��;
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

struct time{
	int h,m,s;
	bool operator<(const time &b)const{
		if(h!=b.h)
			return h<b.h;
		else if(m!=b.m)
			return m<b.m;
		else
			return s<b.s;
	}
};

struct student{
	char ID[20];
	struct time t;
}Temp,Early,Late;

int M;

void Input(){
	Early.t.h=24;
	Early.t.m=Early.t.s=0;
	Late.t.h=Late.t.m=Late.t.s=0;
	scanf("%d",&M);
}

void Process(){
	while(M--){
		scanf("%s%d:%d:%d%",Temp.ID,&Temp.t.h,&Temp.t.m,&Temp.t.s);
		if(Temp.t<Early.t)
			Early=Temp;
		scanf("%d:%d:%d",&Temp.t.h,&Temp.t.m,&Temp.t.s);		
		if(Late.t<Temp.t)
			Late=Temp;
	}
}

void Display(){
	printf("%s %s\n",Early.ID,Late.ID);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}