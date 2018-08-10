#include<iostream>  //�����ѵ���Ҫ��1)��β�ͬ��������;2)��������;3)�۰����;
#include<algorithm>  //�����ڹ���<��>��cmp()������ʱ��Ҫ��const DataType &x����;
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
	int num,a,c,m,e,best_r;
	char course;
	bool operator<(const student &b)const{
		return num<b.num;
	}
}Stu[2000];

int N,M;

bool cmp1(const student &a,const student &b){
	return a.a>b.a;
}

bool cmp2(const student &a,const student &b){
	return a.c>b.c;
}

bool cmp3(const student &a,const student &b){
	return a.m>b.m;
}

bool cmp4(const student &a,const student &b){
	return a.e>b.e;
}

void Input(){
	int i;
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++){
		scanf("%d%d%d%d",&Stu[i].num,&Stu[i].c,&Stu[i].m,&Stu[i].e);
		Stu[i].a=Stu[i].c+Stu[i].m+Stu[i].e;
	}
}

void Process(){
	int i,r;

	sort(Stu,Stu+N,cmp1);  //�ȶ�A����;
	r=1;
	Stu[0].best_r=1;
	Stu[0].course='A';
	for(i=1;i<N;i++){
		if(Stu[i].a!=Stu[i-1].a)
			r=Stu[i].best_r=i+1;
		else
			Stu[i].best_r=r;
		Stu[i].course='A';
	}

	sort(Stu,Stu+N,cmp2);  //��C����;
	r=1;
	if(r<Stu[0].best_r){
		Stu[0].best_r=1;
		Stu[0].course='C';
	}
	for(i=1;i<N;i++){
		if(Stu[i].c!=Stu[i-1].c){
			r=i+1;
			if(r<Stu[i].best_r){
				Stu[i].best_r=r;
				Stu[i].course='C';
			}
		}
		else{
			if(r<Stu[i].best_r){
				Stu[i].best_r=r;
				Stu[i].course='C';
			}
		}
	}

	sort(Stu,Stu+N,cmp3);  //��M����;
	r=1;
	if(r<Stu[0].best_r){
		Stu[0].best_r=1;
		Stu[0].course='M';
	}
	for(i=1;i<N;i++){
		if(Stu[i].m!=Stu[i-1].m){
			r=i+1;
			if(r<Stu[i].best_r){
				Stu[i].best_r=r;
				Stu[i].course='M';
			}
		}
		else{
			if(r<Stu[i].best_r){
				Stu[i].best_r=r;
				Stu[i].course='M';
			}
		}
	}

	sort(Stu,Stu+N,cmp4);  //��E����;
	r=1;
	if(r<Stu[0].best_r){
		Stu[0].best_r=1;
		Stu[0].course='E';
	}
	for(i=1;i<N;i++){
		if(Stu[i].e!=Stu[i-1].e){
			r=i+1;
			if(r<Stu[i].best_r){
				Stu[i].best_r=r;
				Stu[i].course='E';
			}
		}
		else{
			if(r<Stu[i].best_r){
				Stu[i].best_r=r;
				Stu[i].course='E';
			}
		}
	}

	sort(Stu,Stu+N);  //��ѧ������;
}

int HalfSearch(int key){
	int low=0,high=N-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(Stu[mid].num==key)
			return mid;
		else if(key<Stu[mid].num)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}

void Display(){
	int i,key;
	while(M-->0){
		scanf("%d",&key);
		i=HalfSearch(key);
		if(i==-1)
			printf("N/A\n");
		else
			printf("%d %c\n",Stu[i].best_r,Stu[i].course);
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