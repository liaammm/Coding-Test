#include<iostream>
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

struct ration_number{  //�������ṹ��,������long long,��Ϊ�漰�˷�,int�����;
	long long a,b;
}N1,N2,Ans1,Ans2,Ans3,Ans4;

long long OCG(long long a,long long b){  //շת����������Լ��,�����������յļ���;
	a=abs(a);
	b=abs(b);
	while(a&&b){
		if(a>=b)
			a%=b;
		else
			b%=a;
	}
	return a>b?a:b;
}

void Input(){
	long long temp;
	scanf("%lld/%lld",&N1.a,&N1.b);  //����N1��Լ��;
	temp=OCG(N1.a,N1.b);
	N1.a/=temp;
	N1.b/=temp;
	scanf("%lld/%lld",&N2.a,&N2.b);  //����N2��Լ��;
	temp=OCG(N2.a,N2.b);
	N2.a/=temp;
	N2.b/=temp;
}

void Operate1(){  //ִ�мӷ�����;
	long long temp;
	Ans1.a=N1.a*N2.b+N1.b*N2.a;
	Ans1.b=N1.b*N2.b;
	temp=OCG(Ans1.a,Ans1.b);
	Ans1.a/=temp;
	Ans1.b/=temp;
}

void Operate2(){  //ִ�м�������;
	long long temp;
	Ans2.a=N1.a*N2.b-N1.b*N2.a;
	Ans2.b=N1.b*N2.b;
	temp=OCG(Ans2.a,Ans2.b);
	Ans2.a/=temp;
	Ans2.b/=temp;
}

void Operate3(){  //ִ�г˷�����;
	long long temp;
	Ans3.a=N1.a*N2.a;
	Ans3.b=N1.b*N2.b;
	temp=OCG(Ans3.a,Ans3.b);
	Ans3.a/=temp;
	Ans3.b/=temp;
}

void Operate4(){  //ִ�г�������;
	long long temp;
	Ans4.a=N1.a*N2.b;
	Ans4.b=N1.b*N2.a;
	if(Ans4.b){
		temp=OCG(Ans4.a,Ans4.b);	
		Ans4.a/=temp;
		Ans4.b/=temp;
	}
	if(Ans4.b<0){
		Ans4.a=-Ans4.a;
		Ans4.b=-Ans4.b;
	}
}

void Process(){  //���ε��üӡ������ˡ���;
	Operate1();
	Operate2();
	Operate3();
	Operate4();
}

void Disp(const ration_number &X){  //��ʾһ����,�˴���������϶�,�����׳���,�迼���������;
	long long a=X.a,b=X.b;
	if(a==0){
		printf("0");
		return ;
	}
	if(b==0){
		printf("Inf");
		return;
	}

	long long aa=abs(a),y=aa%b;

	if(a<0)
		printf("(-");

	if(y==0)
		printf("%lld",aa/b);
	else if(aa/b>0)
		printf("%lld %lld/%lld",aa/b,y,b);
	else
		printf("%lld/%lld",aa,b);

	if(a<0)
		printf(")");
}

void Disp1(){  //��ʾ�ӷ�;
	Disp(N1);
	printf(" + ");
	Disp(N2);
	printf(" = ");
	Disp(Ans1);
	printf("\n");
}

void Disp2(){  //��ʾ����;
	Disp(N1);
	printf(" - ");
	Disp(N2);
	printf(" = ");
	Disp(Ans2);
	printf("\n");
}

void Disp3(){  //��ʾ�˷�;
	Disp(N1);
	printf(" * ");
	Disp(N2);
	printf(" = ");
	Disp(Ans3);
	printf("\n");
}

void Disp4(){  //��ʾ����;
	Disp(N1);
	printf(" / ");
	Disp(N2);
	printf(" = ");
	Disp(Ans4);
	printf("\n");
}

void Display(){  //������ʾ�ӡ������ˡ���;
	Disp1();
	Disp2();
	Disp3();
	Disp4();
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}