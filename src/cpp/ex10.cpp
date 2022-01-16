#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "../headers/ex10.h"
using namespace std;
namespace ex10
{
    int fex10()
    {
    	ios::sync_with_stdio(false);
        int n;
        map<int,int> cmap;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int a;
            cin>>a;
//            map<int,int>::iterator it=  cmap.find(a);
//            if(it==cmap.end())
//            {
//                cmap[it->first]=a;
//            }
//            else
//            {
//                it->second+=1;
//            }
			cmap[a]++;
        }
        //max_element�ײ����ʱ���������Ĳ��ȵ�ǰ���ֵ����ʲô������ 
		//c++��׼�涨���������е����ǲ���key�ǽ���ķ�ʽ 
        cout << max_element(cmap.begin(), cmap.end(),
                            [](const pair<int, int>& p1, const pair<int, int>& p2)
        {
            return p1.second < p2.second;
        }) ->first;
        return 0;
    }

    template<class _Compare>
    bool test(_Compare __comp)
    {
        return __comp(1,2);
    }
}
