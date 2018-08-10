#include<iostream>  //��������зֵ��߼�����Ҫ���͸��,�ſ��������Ľ������;
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

struct student{
	int num,perfect,score[6],total;
	bool compile;
	bool operator<(const student &b)const{  //�������,ע��bool������ʵҲ���ԱȽϴ�С;
		if(total!=b.total)
			return total>b.total;
		else if(perfect!=b.perfect)
			return perfect>b.perfect;
		else if(compile!=b.compile)
			return compile>b.compile;
		else
			return num<b.num;
	}
}Stu[10001];

int N,K,M;
int Full_Score[6];

void Input(){
	int i,j,user,pro,obt;
	scanf("%d%d%d",&N,&K,&M);
	for(i=1;i<=K;i++)
		scanf("%d",&Full_Score[i]);  //��¼�¸���ŵ�����;
	for(i=1;i<=N;i++){
		Stu[i].num=i;  //������������Ҵ���,�����ȵǼ���ѧ��;
		for(j=1;j<=K;j++)
			Stu[i].score[j]=-1;  //��-1��ʾδ�ύ��״̬;
	}
	for(i=0;i<M;i++){
		scanf("%d%d%d",&user,&pro,&obt);
		if(Stu[user].score[pro]<0)  //֮ǰδ�ύ,�����ȵǼ�Ϊ0,˵���ύ����;
			Stu[user].score[pro]=0;
		if(obt>=0){  //�Ƿ�Ϊ��Ч�ύ;
			Stu[user].compile=true;  //���±���״̬;
			if(obt>Stu[user].score[pro]){  //�ɼ���֮ǰ�ύ�ĸ�,����³ɼ�;
				Stu[user].score[pro]=obt;
				if(obt==Full_Score[pro])  //���´ﵽ���ֵĴ���;
					Stu[user].perfect++;
			}
		}
	}
	for(i=1;i<=N;i++)
		for(j=1;j<=K;j++)
			if(Stu[i].score[j]>0)
				Stu[i].total+=Stu[i].score[j];  //����ÿλѧ�����ܷ�,����ע��-1��Ҫ�ӽ���;
	sort(Stu+1,Stu+N+1);  //��Ҫ������;
}

void Process(){

}

void Display(){
	int i,j,r;
	Stu[0].total=1000;  
	for(i=r=1;i<=N;i++){
		if(!Stu[i].compile)  //�������������ѧ�����˳�;
			break;
		if(Stu[i].total!=Stu[i-1].total)  //��ǰ���ֲܷ�ͬ,��������,���򲻸���,���θ��漴��;
			r=i;
		printf("%d %05d %d",r,Stu[i].num,Stu[i].total);  //�������,ѧ��,�ܷ�;
		for(j=1;j<=K;j++){
			if(Stu[i].score[j]>=0)
				printf(" %d",Stu[i].score[j]);  //�������;
			else
				printf(" -");  //δ�ύ���'-';
		}
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