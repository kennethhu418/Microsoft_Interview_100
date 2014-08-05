// Quiz 18 - Remaining Number in Circle (Joseph Circle).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Solution
{
public:
    int getJosephNumber(int n, int m)
    {
        if (n == 1 || m == 1)   return n - 1;

        //Init DP
        int lastNumber = 0;

        //Run DP
        for (int count = 2; count <= n; ++count)
            lastNumber = (lastNumber + m) % count;

        return lastNumber;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    int n = 5, m = 2;
    Solution so;

    cout << "result is " << so.getJosephNumber(n, m) << endl;

	return 0;
}

