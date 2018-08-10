#include<iostream>  //�ӵ�λ����λ���������жϵ�˼��;
#include<algorithm>  //���ж����ĵ����ֶ���������Ϥ;
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

int N;
int Digit[9];
char Refer[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
stack<string> S;

void Input(){
	scanf("%d",&N);
	if(N<0)
		printf("Fu ");
	N=abs(N);
}

void GetStack(){  //���ö�ջ�洢��Ҫ������ַ�;
	bool flag;
	int i,j,k;

	if(Digit[0])  //�ȴ���0-3�ĸ���λ;
		S.push(Refer[Digit[0]]);
	if(Digit[1]){
		S.push("Shi");
		S.push(Refer[Digit[1]]);
	}
	if(Digit[2]){
		if(Digit[1]==0&&Digit[0])
			S.push("ling");
		S.push("Bai");
		S.push(Refer[Digit[2]]);
	}
	if(Digit[3]){
		if(Digit[2]==0&&(Digit[1]||Digit[0]))
			S.push("ling");
		S.push("Qian");
		S.push(Refer[Digit[3]]);
	}

	for(i=4;i<8;i++)  //��������,ע������4λȫΪ0�ǲ������;
		if(Digit[i]){
			if(Digit[3]==0&&(Digit[2]||Digit[1]||Digit[0]))
				S.push("ling");
			S.push("Wan");
			break;
		}

	if(Digit[4])  //����4-7�ĸ���λ;
		S.push(Refer[Digit[4]]);
	if(Digit[5]){
		S.push("Shi");
		S.push(Refer[Digit[5]]);
	}
	if(Digit[6]){
		if(Digit[5]==0&&Digit[4])
			S.push("ling");
		S.push("Bai");
		S.push(Refer[Digit[6]]);
	}
	if(Digit[7]){
		if(Digit[6]==0&&(Digit[5]||Digit[4]))
			S.push("ling");
		S.push("Qian");
		S.push(Refer[Digit[7]]);
	}

	if(Digit[8]){  //������λ;
		flag=false;
		for(i=6;i>=0;i--)
			if(Digit[i]){
				flag=true;
				break;
			}
		if(Digit[7]==0&&flag)
			S.push("ling");
		S.push("Yi");
		S.push(Refer[Digit[8]]);
	}
}

void Process(){
		int i,j,k;
		for(i=0;i<9;i++){
			Digit[i]=N%10;
			N/=10;
		}
		GetStack();
}

void Display(){
	if(S.empty())
		printf("ling\n");
	else{
		cout<<S.top();
		S.pop();
		while(!S.empty()){
			cout<<" "<<S.top();
			S.pop();
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