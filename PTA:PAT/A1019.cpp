#include<iostream>  //�˴���B��������ͨ���ı�ʾ��ʽ��ͬ,ֻ�漰��λ����,���漰��ĸ��ʾ;
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

int N,B;
bool Flag;
vector<int> Ans;

void Input(){
	Ans.clear();
	scanf("%d%d",&N,&B);
	while(N>0){
		Ans.push_back(N%B);
		N/=B;
	}
}

void Process(){
	int i,l;
	Flag=true;
	l=(Ans.size()+1)/2;
	for(i=0;i<l;i++)
		if(Ans[i]!=Ans[Ans.size()-1-i]){
			Flag=false;
			break;
		}
}

void Display(){
	if(Flag)
		printf("Yes\n");
	else
		printf("No\n");
	if(Ans.empty())  //������0����������;
		printf("0\n");
	else{
	int i;
	i=Ans.size()-1;
	printf("%d",Ans[i--]);
	for(;i>=0;i--)
		printf(" %d",Ans[i]);
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