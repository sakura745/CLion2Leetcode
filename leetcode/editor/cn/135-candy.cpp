/**
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。 

 你需要按照以下要求，给这些孩子分发糖果： 

 
 每个孩子至少分配到 1 个糖果。 
 相邻两个孩子评分更高的孩子会获得更多的糖果。 
 

 请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。 

 

 示例 1： 

 
输入：ratings = [1,0,2]
输出：5
解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
 

 示例 2： 

 
输入：ratings = [1,2,2]
输出：4
解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。 

 

 提示： 

 
 n == ratings.length 
 1 <= n <= 2 * 10⁴ 
 0 <= ratings[i] <= 2 * 10⁴ 
 

 Related Topics 贪心 数组 👍 1214 👎 0

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
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> child(ratings.size(), 1);
        //向右遍历，右侧大于左侧，右侧为左侧+1
        for (int i = 1/*从1开始，0没有左侧*/; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                child[i] = child[i - 1] + 1;
            }
        }
        //向左遍历，左侧大于右侧，左侧为右侧+1，同时要和向右遍历的取最大值，因为满足上一个遍历的同时满足本次
        for (int i = ratings.size() - 2/*从-2开始。-1没有右侧*/; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
               child[i] = max(child[i + 1] + 1, child[i] );
            }
        }
        int res = 0;
        for (auto& i : child) {
            res += i;
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