#include <iostream>
#include <algorithm>
#include "../headers/ex0.h"
#include <intrin.h>
#include <stdio.h>

using namespace std;
namespace ex0
{
	///////////////////////////////////////
	//class Timer ��ʵ�� 
    inline unsigned __int64 Timer::GetCycleCount()
    {
		//windows ����Ҫ������࣬�п� 
		return __rdtsc();
    }
    unsigned long Timer::startTiming()
    {
    	this->startTime=(unsigned long)GetCycleCount();
    	return this->startTime;
	}
	unsigned long Timer::endTiming()
	{
		this->endTime=(unsigned long)GetCycleCount();
		return this->endTime;
	}
    unsigned long Timer::showClockCycles()
    {
    	return (this->endTime-this->startTime)*1.0;
	}
	unsigned long Timer::showNS()
    {
    	return (this->endTime-this->startTime)*1.0*0.0000000004*1000*1000*1000;
	}
	unsigned long Timer::showUS()
    {
    	return (this->endTime-this->startTime)*1.0*0.0000000004*1000*1000;
	}
	unsigned long Timer::showMS()
    {
    	return (this->endTime-this->startTime)*1.0*0.0000000004*1000;
	}
	
	///////////////////////////////////////
	//class randVec ��ʵ��
	//����ֵ��ֵ���ݻ������ô��ݣ� 
	vector<int> randArray1(int length)
	{
		unsigned seed;
        srand(seed);
		vector<int> randvec;
		int temp;
		for(temp=0;temp<length;temp++)
		{
			randvec.push_back(rand() % length + 0);	
		}
		return randvec;
	}
}
