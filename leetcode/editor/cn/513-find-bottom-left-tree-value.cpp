/**
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。 

 假设二叉树中至少有一个节点。 

 

 示例 1: 

 

 
输入: root = [2,1,3]
输出: 1
 

 示例 2: 

 

 
输入: [1,2,3,4,null,5,6,null,null,7]
输出: 7
 

 

 提示: 

 
 二叉树的节点个数的范围是 [1,10⁴] 
 
 -2³¹ <= Node.val <= 2³¹ - 1 
 

 Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 484 👎 0

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
    //递归
    int res = 0;
    int maxDepth = -1;
    void recursion(TreeNode* cur, int depth) {
        //当节点为叶子节点时，记录深度最深的节点
        if (!cur->left && !cur->right && maxDepth < depth) {
                maxDepth = depth;
                res = cur->val;
        }
        if (cur->left) {
            ++depth;
            recursion(cur->left, depth);
            --depth;//回溯
        }
        if (cur->right) {
            recursion(cur->right, depth + 1);//也相当于回溯
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        recursion(root, 0);
        return res;
    }

    //迭代 层序遍历
/*    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int res = 0;
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            if (cur->right) que.push(cur->right);//右
            if (cur->left) que.push(cur->left);//左
            res = cur->val;
        }
        return res;
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