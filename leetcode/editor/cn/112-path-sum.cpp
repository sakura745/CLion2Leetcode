/**
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 
targetSum 。如果存在，返回 true ；否则，返回 false 。 

 叶子节点 是指没有子节点的节点。 

 

 示例 1： 
 
 
输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
输出：true
解释：等于目标和的根节点到叶节点路径如上图所示。
 

 示例 2： 
 
 
输入：root = [1,2,3], targetSum = 5
输出：false
解释：树中存在两条根节点到叶子节点的路径：
(1 --> 2): 和为 3
(1 --> 3): 和为 4
不存在 sum = 5 的根节点到叶子节点的路径。 

 示例 3： 

 
输入：root = [], targetSum = 0
输出：false
解释：由于树是空的，所以不存在根节点到叶子节点的路径。
 

 

 提示： 

 
 树中节点的数目在范围 [0, 5000] 内 
 -1000 <= Node.val <= 1000 
 -1000 <= targetSum <= 1000 
 

 Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1185 👎 0

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
/*    bool recursion(TreeNode* cur, int cnt) {
        if (!cur->left && !cur->right) {
            return cnt == 0;//如果成立，则返回true，不成立，返回false
        }
        if (cur->left) {
            if (recursion(cur->left, cnt - cur->left->val))//省略回溯
                return true;
        }
        if (cur->right) {
            if (recursion(cur->right, cnt - cur->right->val))//省略回溯
                return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return recursion(root, targetSum - root->val);
    }*/
    //简写 整合成一个函数
/*    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }*/

    //迭代 深度遍历
    bool hasPathSum(TreeNode* root, int targetSum) {
        stack<pair<TreeNode*, int>> st;
        if (!root) return false;
        else st.emplace(root, targetSum - root->val);
        while (!st.empty()) {
            auto tmp = st.top();
            st.pop();

            if (!tmp.first->left && !tmp.first->right && tmp.second == 0) return true;
            //为什么不能写成如下语句，而递归可以
            //if (!tmp.first->left && !tmp.first->right) return tmp.second == 0;
            //因为递归是嵌套，return是返回给上一层递归
            //这个是迭代，如果有false直接返回给hasPathSum函数，而错过了其他正确的路径

            if (tmp.first->right) st.emplace(tmp.first->right, tmp.second - tmp.first->right->val);
            if (tmp.first->left) st.emplace(tmp.first->left, tmp.second - tmp.first->left->val);
        }
        return false;
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
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
   /* root->left->left = new TreeNode(11);
    root->left->right = new TreeNode();
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(2);
    root->left->left->right  = new TreeNode(7);
    root->left->right->left  = new TreeNode();
    root->left->right->right  = new TreeNode();
    root->right->left->left = new TreeNode();
    root->right->left->right  = new TreeNode();
    root->right->right->left  = new TreeNode();
    root->right->right->right  = new TreeNode(1);*/

    s.hasPathSum(root, 5);

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