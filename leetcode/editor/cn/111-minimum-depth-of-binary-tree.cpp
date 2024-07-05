/**
给定一个二叉树，找出其最小深度。 

 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。 

 说明：叶子节点是指没有子节点的节点。 

 

 示例 1： 
 
 
输入：root = [3,9,20,null,null,15,7]
输出：2
 

 示例 2： 

 
输入：root = [2,null,3,null,4,null,5,null,6]
输出：5
 

 

 提示： 

 
 树中节点数的范围在 [0, 10⁵] 内 
 -1000 <= Node.val <= 1000 
 

 Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1015 👎 0

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
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
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
    //层序迭代
/*    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if (!root) return 0;
        if (root) que.push(root);
        int res = 1;//至少有一层
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
                if (!cur->left && !cur->right) return res;
            }
            ++res;
        }
        return res;
    }*/
    //递归 后序遍历
/*    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int left = minDepth(root->left);//左
        int right = minDepth(root->right);//右
        //中
        if (!root->left && root->right)
            return 1 + right;
        if (root->left && !root->right)
            return 1 + left;
        return 1 + min(left, right);
    }*/
    //递归 前序遍历
    int res = INT_MAX;
    void recursion(TreeNode* cur, int depth) {
        if (!cur) return;
        //中
        if (!cur->left && !cur->right) {
            res = min(res, depth);
        }
        if (cur->left) recursion(cur->left, depth + 1);//左
        if (cur->right) recursion(cur->right, depth + 1);//右
        return;
    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        recursion(root, 1);
        return res;
    }
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