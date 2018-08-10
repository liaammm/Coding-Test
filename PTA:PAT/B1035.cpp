#include<iostream>  //����ϴ�ӵ�:����Ԫ���п�������ͬ��,������ж��Ƿ�Ϊ��������ʱҪʮ��С�Ĵ����Ⱥ�;
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

bool Flag_Merge;
int N,Init[200],Sorting[200],Temp[200];

void Input(){
	int i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%d",&Init[i]);
	for(i=0;i<N;i++)
		scanf("%d",&Sorting[i]);
}

bool IsInsert(){  //�˴���Ŀû����ȷ˵��,���ǻ��ǵ���Ԫ��ֵ������ͬ����;
	int i,in_pos,temp;
	for(i=1;i<N&&Sorting[i]>=Sorting[i-1];i++);  //������Ҫ���������������п�������ͬԪ�ص�;
	in_pos=i;  //��¼�������λ��;
	for(;i<N;i++)
		if(Init[i]!=Sorting[i])
			return false;
	temp=Sorting[in_pos];
	for(i=in_pos-1;i>=0&&Sorting[i]>temp;i--)
		Sorting[i+1]=Sorting[i];
	Sorting[i+1]=temp;
	for(i=0;i<N;i++)
		Init[i]=Sorting[i];
	return true;
}

void MergeSort(int l){  //���õݹ�ʵ�ֵĹ鲢�����Եü��ܶ�;
	int i,j,k,step,p;
	step=l<<1;
	for(p=k=0;k<N;k+=step){
		i=k;
		j=k+l;
		while(i<k+l&&i<N&&j<k+step&&j<N){
			if(Init[i]<Init[j])
				Temp[p++]=Init[i++];
			else
				Temp[p++]=Init[j++];
		}
		while(i<k+l&&i<N)
			Temp[p++]=Init[i++];
		while(j<k+step&&j<N)
			Temp[p++]=Init[j++];
	}
	for(p=0;p<N;p++)
		Init[p]=Temp[p];
	if(Flag_Merge)
		return;
	for(p=0;p<N&&Init[p]==Sorting[p];p++);
	if(p==N)
		Flag_Merge=true;	
	MergeSort(l<<1);
}

void Process(){
	if(IsInsert())
		printf("Insertion Sort\n");
	else{
		printf("Merge Sort\n");
		Flag_Merge=false;
		MergeSort(1);
	}
}

void Display(){
	int i;
	printf("%d",Init[0]);
	for(i=1;i<N;i++)
		printf(" %d",Init[i]);
	printf("\n");
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}