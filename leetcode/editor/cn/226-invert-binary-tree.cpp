/**
给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。 

 

 示例 1： 

 

 
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
 

 示例 2： 

 

 
输入：root = [2,1,3]
输出：[2,3,1]
 

 示例 3： 

 
输入：root = []
输出：[]
 

 

 提示： 

 
 树中节点数目范围在 [0, 100] 内 
 -100 <= Node.val <= 100 
 

 Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1597 👎 0

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
    //前序递归
/*    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        swap(root->left, root->right);//中
        invertTree(root->left);//左
        invertTree(root->right);//右
        return root;
    }*/
    //后序递归
/*    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        invertTree(root->left);//左
        invertTree(root->right);//右
        swap(root->left, root->right);//中
        return root;
    }*/
    //中序递归
/*    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        invertTree(root->left);//左
        swap(root->left, root->right);//中
        //因为上一行代码已经处理过左树，处理完换成右树
        //接下来要处理的是原来的右树，但是已经变成左树了
        invertTree(root->left);//右
        return root;
    }*/

    //前序迭代
/*    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        if (root) st.push(root);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if (cur) {
                if (cur->right) st.push(cur->right);//右
                if (cur->left) st.push(cur->left);//左
                st.push(cur);//中
                st.push(nullptr);
            } else {
                cur = st.top();
                st.pop();
                swap(cur->left, cur->right);
            }
        }
        return root;
    }*/
    //中序迭代
/*    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        if (root) st.push(root);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if (cur) {
                if (cur->right) st.push(cur->right);//右
                st.push(cur);//中
                st.push(nullptr);
                if (cur->left) st.push(cur->left);//左
            } else {
                cur = st.top();
                st.pop();
                swap(cur->left, cur->right);
            }
        }
        return root;
    }*/
    //后序迭代
/*    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        if (root) st.push(root);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if (cur) {
                st.push(cur);
                st.push(nullptr);
                if (cur->right) st.push(cur->right);
                if (cur->left) st.push(cur->left);
            } else {
                cur = st.top();
                st.pop();
                swap(cur->left, cur->right);
            }
        }
        return root;
    }*/

    //层序迭代
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                TreeNode* cur = que.front();
                que.pop();
                swap(cur->left, cur->right);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
        }
        return root;
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