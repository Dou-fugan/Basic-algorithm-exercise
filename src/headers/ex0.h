#include <vector>
#include <iostream>
using namespace std;
#ifndef __EX0_H__
#define __EX0_H__
// function **declarations**
namespace ex0{
	//��ʱ����
	class Timer
    {
        public:
            unsigned long startTime;
            unsigned long endTime;
            inline unsigned __int64 GetCycleCount();
            unsigned long startTiming();
            unsigned long endTiming();
            //��λK 
            unsigned long showClockCycles();
            unsigned long showNS();
            unsigned long showUS();
            unsigned long showMS();
    };
	//������� 
	class randVec
	{
		//���int���У����ظ� 
		vector<int> randArray1(int length); 
	};
};
#endif
