/**
给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。 

 如果树中有不止一个众数，可以按 任意顺序 返回。 

 假定 BST 满足如下定义： 

 
 结点左子树中所含节点的值 小于等于 当前节点的值 
 结点右子树中所含节点的值 大于等于 当前节点的值 
 左子树和右子树都是二叉搜索树 
 

 

 示例 1： 
 
 
输入：root = [1,null,2,2]
输出：[2]
 

 示例 2： 

 
输入：root = [0]
输出：[0]
 

 

 提示： 

 
 树中节点的数目在范围 [1, 10⁴] 内 
 -10⁵ <= Node.val <= 10⁵ 
 

 

 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内） 

 Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 644 👎 0

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
    int maxCnt = 0/*记录最大出现频率*/, cnt = 0/*记录出现频率*/;
    vector<int> res;
    TreeNode* pre = nullptr;//为cur的前一个指针
    void traversal(TreeNode* cur) {
        if (!cur) return;
        traversal(cur->left);//左

        //中
        //更新cnt
        if (!pre) {//pre指向空节点，cur为遍历的第一个节点
            cnt = 1;//cur指向的数出现的频率为1
        } else if (pre->val == cur->val) {//双指针指向的值相等
            ++cnt;
        } else {//双指针指向的不相等，则重置cnt值。（cur一定大于pre的值，因为是BST）
            cnt = 1;
        }
        if (maxCnt < cnt) {
            maxCnt = cnt;//更新maxCnt
            res.clear();//更新res，清空之前的
            res.push_back(cur->val);
        } else if (maxCnt == cnt){
            res.push_back(cur->val);
        }
        pre = cur;//移动指针

        traversal(cur->right);//右
    }
    vector<int> findMode(TreeNode* root) {
        traversal(root);
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