// Quiz 09 - Check Post Order Traversal.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Solution
{
public:
    bool    isBSTPostTraversalSequence(int arr[], int n)
    {
        if (n < 2)  return true;

        return isBSTPostTraversalSequence(arr, 0, n - 1);
    }

private:
    bool     isBSTPostTraversalSequence(int arr[], int start, int end)
    {
        if (start >= end)   return true;
        int root = arr[end];

        int curPos = end - 1;
        while (curPos >= 0)
        {
            if (arr[curPos] < root) break;
            --curPos;
        }

        if (curPos < 0)
            return isBSTPostTraversalSequence(arr, start, end - 1);

        int leftEnd = curPos;
        while (curPos >= 0)
        {
            if (arr[curPos] >= root) return false;
            --curPos;
        }

        return isBSTPostTraversalSequence(arr, start, leftEnd) && isBSTPostTraversalSequence(arr, leftEnd + 1, end - 1);
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    int postOrderArr[] = {7, 5, 3, 14, 13, 22, 15, 6};
    Solution so;

    cout << "Result: " << so.isBSTPostTraversalSequence(postOrderArr, sizeof(postOrderArr) / sizeof(int)) << endl;
	return 0;
}

