#include<iostream>  //��ϣ������Ӧ��,̰���㷨�����Ӧ��;
#include<algorithm>  //ͨ��̰���㷨���������뵽�ķ���;
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

int N,Count,Step,Hash[100000];

void Input(){
	int temp,i;
	scanf("%d",&N);
	for(Count=i=0;i<N;i++){
		scanf("%d",&temp);
		Hash[temp]=i;
		if(temp==i)
			Count++;
	}
}

void Process(){
	int s_pos,p0,px;
	for(Step=0,s_pos=1;Hash[s_pos]==0||Hash[s_pos]==s_pos;s_pos++);  //ʼ�ձ���s_posָ��ָ�����ڴ������⽻��������λ��;
	while(Count<N){
		if(Hash[0]!=0){  //��0λ��Ϊ0,���û�0λ������ֵ���ȷλ��;
			Step++;  //Step�ۼ�;
			p0=Hash[0];  //ȡ0λ�������p0;
			px=Hash[p0];  //ȡp0λ�������px;
			Hash[p0]=p0;  //��p0�ŵ�p0;
			Hash[0]=px;  //��0�ŵ�px;
			Count++;  //��ȷ���ָ���+1;
			if(Hash[0]==0)  //���˴�0Ҳ���û���0λ��,��ȷ���ָ�����+1;
				Count++;
			for(;Hash[s_pos]==0||Hash[s_pos]==s_pos;s_pos++);  //ʼ�ձ���s_posָ��ָ�����ڴ������⽻��������λ��;
		}
		else{  //��0λΪ0,����Ҫ����һ�ζ���������û�,��0������s_posλ�ô�,��Count��-1(��һ����λ��);
			Step++;  //Step�ۼ�;
			px=Hash[s_pos];  //ȡs_posλ�������px;
			Hash[0]=px;  //��px�ŵ�0λ;
			Hash[s_pos]=0;  //��0�ŵ�s_posλ;
			Count--;  //��ȷ���ָ���-1;
			for(;Hash[s_pos]==0||Hash[s_pos]==s_pos;s_pos++);  //ʼ�ձ���s_posָ��ָ�����ڴ������⽻��������λ��;
		}
	}
}

void Display(){
	printf("%d\n",Step);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}