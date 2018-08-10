#include<iostream>  //����Ŀӵ�:��һ���˵��˵���0ʱ�ǲ���Ҫ�����;
#include<algorithm>
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

struct record{
	string name;
	int time;
	bool on_off;
	bool operator<(const record &b)const{  //�����õĺ���;
		if(name!=b.name)
			return name<b.name;
		else
			return time<b.time;
	}
}Rec[1000];

struct bill{  //�˵��ṹ��,��¼ĳ��ĳ�µ��˵�;
	string name;
	vector<int> phone_rec;
}BI[1000];

int N,K,Month;  //�·�ֻ��Ҫһ��ȫ�ֱ���,��Ϊ�·�ȫ����ͬ;
int Toll[24];

void Input(){
	int i,mo,da,ho,mi;
	char Temp[15];
	for(i=0;i<24;i++)
		scanf("%d",&Toll[i]);
	scanf("%d",&N);
	for(i=0;i<N;i++){
		cin>>Rec[i].name;
		scanf("%d:%d:%d:%d%s",&mo,&da,&ho,&mi,Temp);
		if(Temp[1]=='n')
			Rec[i].on_off=true;
		Rec[i].time=da*24*60+ho*60+mi;  //ʱ��ͳһת��Ϊ��,�߼�����������;
	}
	Month=mo;
	sort(Rec,Rec+N);  //��Ҫ�Ե绰��¼����,������:1)����;2)ʱ��;
}

void Process(){  //����Ҫ��¼����Ϣ����¼��bill����BI[1-K]��,��������������string��vector;
	int i;
	BI[0].name="\0";
	for(i=0,K=0;i<N-1;i++){  //BI[1-K]��¼��K����Ҫ������û��˵���Ϣ;
		if(Rec[i].on_off&&!Rec[i+1].on_off&&Rec[i].name==Rec[i+1].name){				
			if(Rec[i].name==BI[K].name)					
				BI[K].phone_rec.push_back(i);				
			else{					
				K++;					
				BI[K].name=Rec[i].name;					
				BI[K].phone_rec.push_back(i);				
			}
		}
	}
}

int printitem(int in,int out){  //���һ��ͨ���ļ�¼,in��out�ֱ���ͨ����ʼ������ʱ��;
	int i,temp,out_t=out,in_t=in;
	int s,s0,s1,s2,in_d,in_h,in_m,out_d,out_h,out_m;

	s0=s1=s2=0;  //��ʼ���м����,s0,s1,s2;

	in_m=in_t%60;  //���Ի�inʱ��Ϊʱ����;
	in_t/=60;
	in_h=in_t%24;
	in_t/=24;
	in_d=in_t;

	out_m=out_t%60;  //��ʼ��outʱ��Ϊʱ����;
	out_t/=60;
	out_h=out_t%24;
	out_t/=24;
	out_d=out_t;

	for(i=temp=0;i<24;i++)  //����s0;
		temp+=60*Toll[i];
	for(i=in_d;i<out_d;i++)
		s0+=temp;

	for(i=0;i<in_h;i++)  //����s1;
		s1+=60*Toll[i];
	s1+=in_m*Toll[i];

	for(i=0;i<out_h;i++)  //����s2;
		s2+=60*Toll[i];
	s2+=out_m*Toll[i];

	s=s0+s2-s1;  //����s=s0+s2-s1,����˼·������ʱ��ļ����к���Ҫ;

	printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",in_d,in_h,in_m,out_d,out_h,out_m,out-in,(double)s/100);  //����˴�ͨ��;

	return s;  //���ش˴�ͨ������;
}

void printlist(int k){
	int i,total;
	total=0;
	for(i=0;i<BI[k].phone_rec.size();i++)  //�������ͨ�����μ�¼,���ۼ�total;
		total+=printitem(Rec[BI[k].phone_rec[i]].time,Rec[BI[k].phone_rec[i]+1].time);
	printf("Total amount: $%.2f\n",(double)total/100);  //���total;
}

void Display(){
	int i;
	for(i=1;i<=K;i++){
		cout<<BI[i].name<<" ";  //������ֺ��·�;
		printf("%02d\n",Month);
		printlist(i);
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