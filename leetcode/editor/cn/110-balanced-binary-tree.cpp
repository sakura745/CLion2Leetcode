/**
给定一个二叉树，判断它是否是高度平衡的二叉树。 

 本题中，一棵高度平衡二叉树定义为： 

 
 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。 
 

 

 示例 1： 
 
 
输入：root = [3,9,20,null,null,15,7]
输出：true
 

 示例 2： 
 
 
输入：root = [1,2,2,3,3,null,null,4,4]
输出：false
 

 示例 3： 

 
输入：root = []
输出：true
 

 

 提示： 

 
 树中的节点数在范围 [0, 5000] 内 
 -10⁴ <= Node.val <= 10⁴ 
 

 Related Topics 树 深度优先搜索 二叉树 👍 1331 👎 0

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
    //递归，后序遍历
/*    int recursion(TreeNode* cur) {
        if (!cur) return 0;//终止条件
        //左
        int left = recursion(cur->left);
        if (left == -1) return -1;//剪枝
        //右
        int right = recursion(cur->right);
        if (right == -1) return -1;//剪枝
        //中
        return (abs(left - right) > 1) ?  -1 : 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        return recursion(root) != -1;
    }*/
    //迭代
    //后序遍历求深度
    int getHeight(TreeNode* cur) {
        stack<TreeNode*> st;
        if (cur) st.push(cur);
        int res = 0, height = 0;
        while (!st.empty()) {
            TreeNode* tmp = st.top();
            st.pop();
            if (tmp) {
                st.push(tmp); st.push(nullptr);//中
                ++height;
                if(tmp->right) st.push(tmp->right);//右
                if(tmp->left) st.push(tmp->left);//左
            } else {
                st.pop();//出栈
                --height;//回溯
            }
            res = res > height ? res : height;
        }
        return res;
    }
    //层序遍历每个节点
    bool isBalanced(TreeNode* root) {
        queue<TreeNode*> que;
        if (!root) return true;
        else que.push(root);
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            if (abs(getHeight(cur->left) - getHeight(cur->right)) > 1)
                return false;
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
        return true;
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
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    s.getHeight(root);
    
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