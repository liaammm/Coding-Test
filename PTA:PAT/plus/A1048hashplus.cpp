#include<iostream>  //����Ŀ��������ֵ�ķ�Χ����ʱ,һ��Ҫѧ����Hash˼���Ͽ�;
#include<algorithm>  //�˴����ŵ�������Ȼcoin�ķ�Χֻ��1-500,�������鿪����1-1000,������Ϊ��ֹ�δ�������Ķ��������ж�;
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

int N,M;
int Count[1001];

void Input(){
	int t;
	scanf("%d%d",&N,&M);
	while(N-->0){
		scanf("%d",&t);
		Count[t]++;
	}
}

void Process(){
	int i,l;
	l=M>>1;
	for(i=1;i<=l;i++){
		if(i!=M-i&&Count[i]&&Count[M-i]){  //M=i+(M-i)��i!=M-i�����;
			printf("%d %d\n",i,M-i);
			return;
		}
		else if(i==M-i&&Count[i]>1){  //���뿼��M%2==0�Ҹպ�M=M/2+M/2�����;
			printf("%d %d\n",i,i);
			return;
		}
	}		
	printf("No Solution\n");  //������������ͨ��,˵�������ڴ�;
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