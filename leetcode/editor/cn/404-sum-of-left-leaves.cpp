/**
给定二叉树的根节点 root ，返回所有左叶子之和。 

 

 示例 1： 

 

 
输入: root = [3,9,20,null,null,15,7] 
输出: 24 
解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 

 示例 2: 

 
输入: root = [1]
输出: 0
 

 

 提示: 

 
 节点数在 [1, 1000] 范围内 
 -1000 <= Node.val <= 1000 
 

 

 Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 607 👎 0

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
    //递归 后序遍历
//    int sumOfLeftLeaves(TreeNode* root) {
//        if (!root) return 0;
//        if (!root->left && !root->right) return 0;
//
//        int left = sumOfLeftLeaves(root->left);//左
//        //判断左节点是否为叶子节点
//        if (root->left/*左节点存在*/ && !root->left->left && !root->left->right/*左节点的左右节点不存在*/)
//            left = root->left->val;
//        int right = sumOfLeftLeaves(root->right);//右
//
//        return left + right;//中
//    }
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        int res = 0;
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if (cur->left && !cur->left->left && !cur->left->right)//中
                res += cur->left->val;
            if (cur->right) st.push(cur->right);//右
            if (cur->left) st.push(cur->left);//左
        }
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