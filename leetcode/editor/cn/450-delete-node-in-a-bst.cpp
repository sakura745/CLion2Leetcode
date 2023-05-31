/**
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节
点的引用。 

 一般来说，删除节点可分为两个步骤： 

 
 首先找到需要删除的节点； 
 如果找到了，删除它。 
 

 

 示例 1: 

 

 
输入：root = [5,3,6,2,4,null,7], key = 3
输出：[5,4,6,2,null,null,7]
解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
另一个正确答案是 [5,2,6,null,4,null,7]。


 

 示例 2: 

 
输入: root = [5,3,6,2,4,null,7], key = 0
输出: [5,3,6,2,4,null,7]
解释: 二叉树不包含值为 0 的节点
 

 示例 3: 

 
输入: root = [], key = 0
输出: [] 

 

 提示: 

 
 节点数的范围 [0, 10⁴]. 
 -10⁵ <= Node.val <= 10⁵ 
 节点值唯一 
 root 是合法的二叉搜索树 
 -10⁵ <= key <= 10⁵ 
 

 

 进阶： 要求算法时间复杂度为 O(h)，h 为树的高度。 

 Related Topics 树 二叉搜索树 二叉树 👍 1155 👎 0

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
/*    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val == key) {
            if (!root->left && !root->right) return nullptr;
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            else {
                auto cur = root->right;//用来找右子树中最左侧叶子节点
                while (cur->left) {
                    cur = cur->left;
                }
                cur->left = root->left;
                return root->right;
            }
        }
        root->val > key ? root->left = deleteNode(root->left, key) :
                root->right = deleteNode(root->right, key);
        return root;
    }*/
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val == key) {
            if (!root->right) {//这里第二次操作目标值：最终删除的作用
               return root->left;
            }
            auto cur = root->right;
            while (cur->left) {
                cur = cur->left;
            }
            swap(root->val, cur->val);//这里第一次操作目标值：交换目标值其右子树最左面节点。
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
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
/*     TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode();
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right  = new TreeNode(2);
    root->left->right->left  = new TreeNode();
    root->left->right->right  = new TreeNode();
    root->right->left->left = new TreeNode();
    root->right->left->right  = new TreeNode();
    root->right->right->left  = new TreeNode();
    root->right->right->right  = new TreeNode(1);*/
    
    
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