// Microsoft_Interview_100.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct __TreeNode
{
    int                             val;
    __TreeNode*         left;
    __TreeNode*         right;
    __TreeNode(int val) : val(val), left(NULL), right(NULL) {}
}TreeNode;

typedef     TreeNode    DLLNode;

class Solution
{
private:
    TreeNode    *lastVisitNode;

public:
    DLLNode*   convertToDLL(TreeNode*   root)
    {
        lastVisitNode = NULL;
        return convertToDLLInternal(root);
    }

private:
    DLLNode*    convertToDLLInternal(TreeNode* root)
    {
        if (root == NULL)   return NULL;

        DLLNode* head = convertToDLLInternal(root->left);

        if (lastVisitNode)
        {
            lastVisitNode->right = root;
            root->left = lastVisitNode;
        }

        lastVisitNode = root;

        convertToDLLInternal(root->right);

        return head == NULL ? root : head;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    TreeNode    node8(8);
    TreeNode    node5(5);
    TreeNode    node18(18);
    TreeNode    node3(3);
    TreeNode    node7(7);
    TreeNode    node30(30);
    TreeNode    node19(19);

    node8.left = &node5;
    node8.right = &node18;
    node5.left = &node3;
    node5.right = &node7;
    node18.right = &node30;
    node30.left = &node19;

    Solution so;
    DLLNode * result = so.convertToDLL(&node8);

	return 0;
}

