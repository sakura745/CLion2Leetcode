/**
给定一个 N 叉树，找到其最大深度。 

 最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。 

 N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。 

 

 示例 1： 

 

 
输入：root = [1,null,3,2,4,null,5,6]
输出：3
 

 示例 2： 

 

 
输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,
null,13,null,null,14]
输出：5
 

 

 提示： 

 
 树的深度不会超过 1000 。 
 树的节点数目位于 [0, 10⁴] 之间。 
 

 Related Topics 树 深度优先搜索 广度优先搜索 👍 345 👎 0

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
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    //递归后序遍历
/*    int maxDepth(Node* root) {
        if (!root) return 0;
        int depth = 0;
        for (auto& i: root->children) {
            depth = max(depth, maxDepth(i));//子节点中最高
        }
        return depth + 1;
    }*/
    //层序迭代
    int maxDepth(Node* root) {
        queue<Node*> que;
        if(!root) return 0;
        else que.push(root);
        int depth = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                Node* cur = que.front();
                que.pop();
                for (auto& i : cur->children) {
                    que.push(i);
                }
            }
            ++depth;
        }
        return depth;
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