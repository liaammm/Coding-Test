#include<iostream>  //�˴�����Two Pointer˼��,i,j��ֻ����������,ֱ��j�ߵ���,��һ��j�Ķ�λ�������۰����;
#include<algorithm>  //�˷��������ڵ������۰����;
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

int N,Max;
long long P,A[100000];

void Input(){
	scanf("%d%lld",&N,&P);
	for(int i=0;i<N;i++)
		scanf("%lld",&A[i]);
	sort(A,A+N);
}

int HalfSearch(){  //�����۰���Ҷ�λj�ĳ�ʼֵ;
	int low=0,high=N-1,mid;  //Ҫע�⵽�۰����ʱlow��high�ǿ���Խ��(-1��Nλ��)��;
	long long guard=P*A[0];
	while(low<=high){
		mid=(low+high)/2;
		if(A[mid]<=guard)
			low=mid+1;
		else
			high=mid-1;
	}
	if(low<N&&A[low]<=guard)
		return low;
	else
		return high;
}

void Process(){
	int i,j;
	long long guard;
	j=HalfSearch();
	Max=j+1;
	i=1;
	while(j<N-1){  //i,jһ��������,ֱ��j����Ϊֹ;
		guard=P*A[i];
		while(j<N-1&&A[j+1]<=guard)  //j������,ֱ�������������ߵ�����߽�;
			j++;
		if(j-i+1>Max)
			Max=j-i+1;
		i++;
	}
}

void Display(){
	printf("%d\n",Max);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}