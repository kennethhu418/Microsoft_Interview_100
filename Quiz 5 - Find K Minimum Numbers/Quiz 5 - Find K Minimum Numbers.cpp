// Quiz 5 - Find K Minimum Numbers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <assert.h>
#include <time.h>

using namespace std;

#define DBG

class Solution
{
public:
    void    SearchMinimumNumbers(int arr[], int n, int K)
    {
        if (n <= K) return;

        int start = 0, end = n - 1, leftEnd = 0, rightStart = 0, leftCount = 0, rightCount = 0;
        while (start < end)
        {
            partition(arr, start, end, leftEnd, rightStart);
            leftCount = leftEnd - start + 1;
            rightCount = rightStart - start;

            if (K > leftCount && K <= rightCount)
                return;

            if (K <= leftCount)
                end = leftEnd;
            else
            {
                start = rightStart;
                K -= rightCount;
            }
        }
    }

private:
    void partition(int arr[], int start, int end, int &leftEnd, int &rightStart)
    {
        int mid = ((start + end) >> 1);
        int pivot = arr[mid];
        int leftNextPlace = start, rightNextPlace = end, curLeft = start, curRight = end, tmp = 0;

        while (curLeft <= curRight)
        {
            while (curLeft <= curRight && arr[curLeft] <= pivot)
            {
                if (arr[curLeft] < pivot)
                    arr[leftNextPlace++] = arr[curLeft];
                ++curLeft;
            }

            if (curLeft > curRight) break;
            
            while (curLeft <= curRight && arr[curRight] >= pivot)
            {
                if (arr[curRight] > pivot)
                    arr[rightNextPlace--] = arr[curRight];
                --curRight;
            }

            if (curLeft > curRight) break;

            tmp = arr[curRight];
            arr[rightNextPlace--] = arr[curLeft];
            arr[leftNextPlace++] = tmp;
            ++curLeft;
            --curRight;
        }

        for (int i = leftNextPlace; i <= rightNextPlace; i++)
            arr[i] = pivot;

        leftEnd = leftNextPlace - 1;
        rightStart = rightNextPlace + 1;
    }
};

void generateArray(int arr[], int n, int MAX_VAL)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (MAX_VAL + 1);
}

bool validateResult(int* volatileArr, const int* baseArr, int n)
{
    if (n == 0) return true;
    sort(volatileArr, volatileArr + n);
    for (int i = 0; i < n; i++)
    {
        if (volatileArr[i] != baseArr[i])   return false;
    }
    return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
    const int   MAX_VAL = 150;
    const int   MAX_ARR_SIZE = 100;
    const int   TRY_TIMES = 8000;
    const int   TRY_TIMES_EACH_ARRAY = 30;

    int     arr[MAX_ARR_SIZE];
    int     backupArr[MAX_ARR_SIZE];
    int     testArr[MAX_ARR_SIZE];
    int     arrSize;
    int     targetNum = 4;
    int     tryTimes = 0, tryTimesSingle = 0;
    Solution so;

    srand(time(0));

    while (tryTimes++ < TRY_TIMES)
    {
        arrSize = 2 + rand() % (MAX_ARR_SIZE - 1);
        generateArray(arr, arrSize, MAX_VAL);
        memmove(backupArr, arr, sizeof(int) * arrSize);
        sort(backupArr, backupArr + arrSize);
        tryTimesSingle = 0;

#ifdef DBG
        cout << "****************************************************" << endl;
        cout << "Pass number : " << tryTimes << endl;
#endif // DBG


        while (tryTimesSingle++ < TRY_TIMES_EACH_ARRAY)
        {
            targetNum = 1 + rand() % arrSize;
            memmove(testArr, arr, sizeof(int)* arrSize);

#ifdef DBG
            cout << "\t\t= sub pass number : " << tryTimesSingle << " with target number " << targetNum << endl;
#endif // DBG

            so.SearchMinimumNumbers(testArr, arrSize, targetNum);

            if (!validateResult(testArr, backupArr, targetNum))
            {
                cout << "Fail validate for " << tryTimes << " - " << tryTimesSingle << endl;
                assert(0);
            }
        }
    }

	return 0;
}

