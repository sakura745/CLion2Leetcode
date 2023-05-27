/**
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。 

 

 示例 1： 
 
 
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]
 

 示例 2： 

 
输入：root = [1]
输出：[[1]]
 

 示例 3： 

 
输入：root = []
输出：[]
 

 

 提示： 

 
 树中节点数目在范围 [0, 2000] 内 
 -1000 <= Node.val <= 1000 
 

 Related Topics 树 广度优先搜索 二叉树 👍 1695 👎 0

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
    //迭代
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;//记录每层节点
        vector<vector<int>> res;
        if (root) que.emplace(root);
        while (!que.empty()) {
            vector<int> res1;
            int size = que.size();//用于记录弹出节点个数，就是每层节点个数
            while (size--) {
                TreeNode* cur = que.front();
                que.pop();
                res1.push_back(cur->val);//记录节点数值
                if (cur->left) que.push(cur->left);//左节点入队列
                if (cur->right) que.push(cur->right);//右节点入队列
            }
            res.push_back(res1);
        }
        return res;
    }
    //递归
    /*void recursive(TreeNode* cur, vector<vector<int>>& res, int depth) {
        if (!cur) return;//返回条件

        if (res.size() == depth) res.push_back(vector<int>());//开辟一个空的vector<int>
//        if (res.size() == depth) res.emplace_back();等价于上一行

        res[depth].emplace_back(cur->val);//
        recursive(cur->left, res, depth + 1);//depth+1是回溯
        recursive(cur->right, res, depth + 1);//depth+1是回溯
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int depth = 0;//给res二维数组，用来赋外层索引
        recursive(root, res, depth);
        return res;
    }*/
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);


    vector<vector<int>> a;
    a = s.levelOrder(root);
    for (auto &i: a) {
        for (auto &j: i) {
            cout << j << ' ';
        }
        cout << endl;
    }
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