#include<iostream>  //��ʹ���۰���ҵ�ʱ��,�ر�Ҫע�����low��high���ܳ���Խ������;
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
	char name[15],id[15];
	int score;
	bool operator<(const student &b)const{
		return score>b.score;
	}
}Stu[101];

int N,Grade1,Grade2;

void Input(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%s%s%d",Stu[i].name,Stu[i].id,&Stu[i].score);
	scanf("%d%d",&Grade1,&Grade2);
	sort(Stu,Stu+N);
}

void Process(){
	bool flag=true;
	for(int i=0;i<N;i++)
		if(Stu[i].score<=Grade2&&Stu[i].score>=Grade1){  //�������������жϽ��в��ҵķ���������,��Ҫ����ȥ��������������,��Ϊ�����ǿ���Խ���,���������ǳ��鷳;
			printf("%s %s\n",Stu[i].name,Stu[i].id);
			flag=false;
		}
	if(flag)
		printf("NONE\n");
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