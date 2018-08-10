#include<iostream>  //����Ĺؼ��Ƿ�������3�����;
#include<algorithm>  //����,���о��ǵ�������û�м���վ��ʱ��,��Զ����Ϊ0;
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

struct station{
	double price,dist;
	bool operator<(const station &b)const{
		return dist<b.dist;
	}
}P[502];

int N;
const double INF=1000000000;
double Cmax,Davg,Dmax,D,Tank,X,Cost;

void Input(){
	scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&N);
	Dmax=Davg*Cmax;
	for(int i=0;i<N;i++)
		scanf("%lf%lf",&P[i].price,&P[i].dist);
	sort(P,P+N);
	P[N].dist=D;  //���յ�λ�������ڱ�;
	P[N].price=0;
}

void Process(){  //�ؼ���������������˼·�Ϳ�����;
	if(P[0].dist>0)  //����վû�м���վ,ֱ����0;
		X=0;
	else{  //����վ�м���վ,��ʼģ��;	
		int i,j,min_j;	
		double m;
		bool flag;	
		Tank=0;  //��ʼ�����;	
		X=0;  //��ʼλ��0;	
		i=0;	
		Cost=0;	
		while(i<N){  //δ�����յ�վ;	
			flag=true;	
			m=INF;
			for(j=i;j<N&&P[j+1].dist-X<=Dmax;j++){	
				if(P[j+1].price<m){  //��¼��Χ������˵ļ���վ;
					m=P[j+1].price;
					min_j=j+1;
				}
				if(P[j+1].price<P[i].price){  //�ɵ���ķ�Χ��������ĸ��ӱ��˵ļ���վ,�����ӵ��ոպó���ȥ;							
					Cost+=P[i].price*((P[j+1].dist-X)/Davg-Tank);				
					X=P[j+1].dist;				
					Tank=0; 				
					i=j+1;				
					flag=false;				
					break;			
				}		
			}		
			if(flag){  //��Χ��û�и��ӱ��˵ļ���վ;		
				if(i==j){  //���ܵ����Զ��;			
					X+=Dmax;				
					Cost+=P[i].price*(Cmax-Tank);			
					Tank=0;				
					break;		
				}		
				else{  //�ܵ����վ����û�и����˵�վ,�����ͳ����ߵ���Χ������˵���վ;			
					Cost+=P[i].price*(Cmax-Tank);			
					Tank=Cmax-(P[min_j].dist-X)/Davg;			
					X=P[min_j].dist;		
					i=min_j;		
				}		
			}
		}
	}
}

void Display(){
	if(X==D)
		printf("%.2f\n",Cost);
	else
		printf("The maximum travel distance = %.2f\n",X);
}

int main(){
//	while(true){
	Input();
	Process();	
	Display();
//	}
	return 0;
}