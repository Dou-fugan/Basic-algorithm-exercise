#include <iostream>
#include <algorithm>
#include "../headers/ex2.h"
#define num2 5
using namespace std;
namespace ex2 {
	//��Ʒ����
	int n=num2;
	//��������
	int c=10;
	//��Ʒ����
	vector<int> w= {2,2,6,5,4};
	//��Ʒ��ֵ
	vector<int> v= {6,3,5,4,6};

	optSub(int i,int j){
		if(i==n-1){
			//�жϱ��������ܷ�װ�����һ��
			if(j>=w[n-1]){
				//��װ�����һ��
				return v[n-1]; 
			} 
			else{
				return 0;
			}
		}
		//�����һ��,�����ܲ���װ����һ����ָ��i+1����optSub(0��c)ʱ�����ǵ�һ����Ʒ����Ӧ��������w[i]�� 
		if(j>=w[i]){
			int a=optSub(i+1,j);
			int b=optSub(i+1,j-w[i])+v[i];
			if(a>b){
				return a;
			}else {
				return b;
			}
		} else{
			int a=optSub(i+1,j);
			return a;
		}
	}
	void fex2() {
		int d=0;
		d=optSub(0,c);
		cout<<"��������װȡ������ֵΪ"<<d<<endl;
	}
}

