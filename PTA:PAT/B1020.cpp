#include<iostream>  //��Ҫ�ȶ��±����ݼ��۸�����;
#include<algorithm>  //������ܴ��ڿ�治����߿�渻������,ѭ��ʱҪ�ۺϿ����˳�������;
#include<string.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<map>
using namespace std;

struct caketype{
	double store,total,per_price;
	bool operator<(const caketype &b)const{
		return per_price>b.per_price;
	}
}Cake[1000];

int N;
double D,S;

void Input(){
	int i;
	scanf("%d%lf",&N,&D);
	for(i=0;i<N;i++)
		scanf("%lf",&Cake[i].store);
	for(i=0;i<N;i++){
		scanf("%lf",&Cake[i].total);
		Cake[i].per_price=Cake[i].total/Cake[i].store;
	}
	sort(Cake,Cake+N);
}

void Process(){
	int i=0;
	S=0;
	while(i<N&&D>0){
		if(D>Cake[i].store){
			S+=Cake[i].total;
			D-=Cake[i].store;
		}
		else{
			S+=Cake[i].per_price*D;
			D=0;
		}
		i++;
	}
}

void Display(){
	printf("%.2f\n",S);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}