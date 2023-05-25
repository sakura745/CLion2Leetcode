/**
给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。 

 完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第
 h 层，则该层包含 1~ 2ʰ 个节点。 

 

 示例 1： 
 
 
输入：root = [1,2,3,4,5,6]
输出：6
 

 示例 2： 

 
输入：root = []
输出：0
 

 示例 3： 

 
输入：root = [1]
输出：1
 

 

 提示： 

 
 树中节点的数目范围是[0, 5 * 10⁴] 
 0 <= Node.val <= 5 * 10⁴ 
 题目数据保证输入的树是 完全二叉树 
 

 

 进阶：遍历树来统计节点是一种时间复杂度为 O(n) 的简单解决方案。你可以设计一个更快的算法吗？ 

 Related Topics 树 深度优先搜索 二分查找 二叉树 👍 945 👎 0

*/
#include<bits/stdc++.h>

using namespace std;

/*struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};*/
/*struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};*/
//void printLinkedList(ListNode* head);
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        //判断是否为满二叉树
        TreeNode* l = root->left, * r = root->right;
        int leftCnt = 0, rightCnt = 0;
        while (l) {
            l = l->left;
            ++leftCnt;
        }
        while (r) {
            r = r->right;
            ++rightCnt;
        }
        if (leftCnt == rightCnt) return (2 << leftCnt) - 1;//注意<<的优先级小于-的优先级

        int leftSum = countNodes(root->left);//左
        int rightSum = countNodes(root->right);//右
        return leftSum + rightSum + 1/*cur节点*/;//中
    }

    //迭代层序遍历
/*    int countNodes(TreeNode* root) {
        queue<TreeNode*> que;
        if (!root) return 0;
        else que.push(root);
        int cnt = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                TreeNode* cur = que.front();
                que.pop();
                ++cnt;
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
        }
        return cnt;
    }*/
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
//    vector<int> a /*initilization*/;
//    auto x = s. /*function_name*/;
//    cout << x << endl;
    /*    ListNode* test = new ListNode(1);
    test->next = new ListNode(2);
    test->next->next = new ListNode(6);
    test->next->next->next = new ListNode(3);
    test->next->next->next->next = new ListNode(4);
    test->next->next->next->next->next = new ListNode(5);
    test->next->next->next->next->next->next = new ListNode(6);*/
//    ListNode* head = generateRandomLinkedList(MaxSize, MaxValue);
//    auto x = s. /*function_name*/;
/*    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);*/
    
    
    return 0;
}

/*void printLinkedList(ListNode* head) {
    if(head == nullptr) return;
    while(head->next != nullptr){//为了调整输出中 "->" 的位置
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << head->val << endl;//同上
}*/