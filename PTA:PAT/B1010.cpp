#include<iostream>  //���������������İ��շǳ���Ҫ;
#include<algorithm>  //Ū�����������������Ҫ������������;
#include<string.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<map>
using namespace std;

int Ex,Co;

void Input(){
	bool flag=false;
	while(true){
		scanf("%d%d",&Co,&Ex);
		if(Ex){
		if(flag)
			printf(" ");
		printf("%d %d",Co*Ex,Ex-1);
		flag=true;
		}
		if(getchar()=='\n')
			break;
	}
	if(!flag)
		printf("0 0");
	printf("\n");
}

void Process(){

}

void Display(){

}

int main(){
//	while(true){
	Input();
//	Process();
//	Display();
//	}
	return 0;
}