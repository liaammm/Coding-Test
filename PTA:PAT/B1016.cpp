#include<iostream>  //����Ҫע�⵽long long��������10^18,int��10^9;
#include<algorithm>  //��unsigned long long��10^19,unsigned int��10^9;
#include<string.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<map>
using namespace std;

long long A,DA,PA,B,DB,PB;

void Input(){
	scanf("%lld%lld%lld%lld",&A,&DA,&B,&DB);
}

void Process(){
	PA=PB=0;
	long long temp;
	while(A>0){
		if(A%10==DA)
			PA=PA*10+DA;
		A/=10;
	}
	while(B>0){
		if(B%10==DB)
			PB=PB*10+DB;
		B/=10;
	}
}

void Display(){
	printf("%lld\n",PA+PB);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}