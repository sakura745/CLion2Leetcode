/**
给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组： 

 
 选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。 
 

 重复这个过程恰好 k 次。可以多次选择同一个下标 i 。 

 以这种方式修改数组后，返回数组 可能的最大和 。 

 

 示例 1： 

 
输入：nums = [4,2,3], k = 1
输出：5
解释：选择下标 1 ，nums 变为 [4,-2,3] 。
 

 示例 2： 

 
输入：nums = [3,-1,0,2], k = 3
输出：6
解释：选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。
 

 示例 3： 

 
输入：nums = [2,-3,-1,5,-4], k = 2
输出：13
解释：选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4] 。
 

 

 提示： 

 
 1 <= nums.length <= 10⁴ 
 -100 <= nums[i] <= 100 
 1 <= k <= 10⁴ 
 

 Related Topics 贪心 数组 排序 👍 362 👎 0

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
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(),
             [](const auto &lhs, const auto &rhs) {
                 return abs(lhs) > abs(rhs);
             });//按照绝对值从大到小排序
        for (int& num : nums) {
            if (num < 0 && k > 0) {
                num *= -1;
                --k;
            }
        }
        if (k % 2 == 1) nums.back() *= -1;//当经过上一步遍历如果k还有剩下，则运行这一步代码
        int res = 0;
        for (auto& num : nums) res += num;
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> a{-2, 4, 4, 4, 6, 3};
    s.largestSumAfterKNegations(a, 1);
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