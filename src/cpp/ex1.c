#include <iostream>
#include <vector>
#include <algorithm>
#include "../headers/ex1.h"
#define num 3
using namespace std;
//��Ʒ���� 
int n=num;
//��������
int c=30;
//��Ʒ����
vector<int> w={16,15,15};
//��Ʒ��ֵ
vector<int> v={45,25,25};
//��߼�ֵ 
int bestP;
//����·�� 
vector<int> bestPath(num);
//��¼�׶����� 
vector<int> varC(num+1);
//��¼�׶μ�ֵ 
vector<int> value(num+1);
//��¼�׶�path 
vector<int> path(num);
//�Լ۱� 
vector<float> costP(num);

float bound(int stage){
	return (*max_element(costP.begin()+stage,costP.end()))*(c-varC[stage]);
}
void backTrace(int stage){
	if(stage>=n){
		cout<<"����Լ����������������ǰpathΪ��"
		<<' '<<path[0]<<' '<<path[1]<<' '<<path[2]<<' '<<varC[stage]<<" stageΪ:"<<stage<<endl;
		if(value[stage]>bestP){
			bestP=value[stage];
			copy(path.begin(),path.end(),bestPath.begin());
		}
		return ;	
	}  
	int temp1=0;
	for(temp1;temp1<2;temp1++){
		path[stage]=temp1;
		varC[stage+1]=varC[stage]+w[stage]*temp1; 
		if(varC[stage+1]<=c&&bound(stage)+value[stage]>bestP){
			value[stage+1]=value[stage]+v[stage]*temp1;
			backTrace(stage+1);
		}else{
			cout<<"����Լ����������������ǰpathΪ��"
			<<' '<<path[0]<<' '<<path[1]<<' '<<path[2]<<' '<<varC[stage]<<" stageΪ:"<<stage<<endl;
			if(value[stage]>bestP){
				bestP=value[stage];
				copy(path.begin(),path.end(),bestPath.begin());
			}
			return ;
		}
	}
}
void ex1(){
	int temp3=0;
	for(temp3;temp3<num;temp3++){
		costP[temp3]=(float)v[temp3]/w[temp3];
	}
	backTrace(0);
	cout<<"���valueΪ��"<<bestP<<endl;
	cout<<"·��Ϊ��";
	int temp2=0;
	for(temp2;temp2<n;temp2++){
		cout<<' '<<bestPath[temp2];
	} 
	cout<<endl;
	return ;
}
