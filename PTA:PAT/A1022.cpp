#include<iostream>  //����Ŀ���map��Ӧ��,��Ϊ�κ���Ŀ�Ĳ�����󶼹�ᵽmap��ӳ����ȥ��;
#include<algorithm>  //Ӧ�ý�����ͬ��ӳ��,��Ȼ�𰸹���,���������ͬ��Ŀ֮������ͬ�Ĵʳ��־ͻ��������;
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
using namespace std;

int N,M,K,Num;
char Temp[81];
map<string,int> MP;
vector<int> Ans[100000];

void Input(){
	int i,t;
	scanf("%d",&N);
	getchar();
	K=0;
	for(i=0;i<N;i++){
		scanf("%d",&Num);  //���;
		getchar();

		gets(Temp);  //����;
		t=MP[Temp];
		if(t==0)
			t=MP[Temp]=++K;
		Ans[t].push_back(Num);

		gets(Temp);  //����;
		t=MP[Temp];
		if(t==0)
			t=MP[Temp]=++K;
		Ans[t].push_back(Num);

		while(true){  //�ؼ���;
			scanf("%s",Temp);
			t=MP[Temp];		
			if(t==0)			
				t=MP[Temp]=++K;		
			Ans[t].push_back(Num);
			if(getchar()=='\n')
				break;
		}

		gets(Temp);  //������;
		t=MP[Temp];
		if(t==0)
			t=MP[Temp]=++K;
		Ans[t].push_back(Num);

		gets(Temp);  //�������;
		t=MP[Temp];
		if(t==0)
			t=MP[Temp]=++K;
		Ans[t].push_back(Num);
	}
	for(i=1;i<=K;i++)
		sort(Ans[i].begin(),Ans[i].end());
}

void Process(){
	int i,j;
	char s[88];
	scanf("%d",&M);
	getchar();
	while(M-->0){
		gets(s);
		printf("%s\n",s);
		strcpy(Temp,s+3);
		i=MP[Temp];
		if(i==0)
			printf("Not Found\n");
		else{
			for(j=0;j<Ans[i].size();j++)
				printf("%07d\n",Ans[i][j]);
		}
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
