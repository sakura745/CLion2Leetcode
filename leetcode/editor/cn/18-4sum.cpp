/**
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b],
 nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）： 

 
 0 <= a, b, c, d < n 
 a、b、c 和 d 互不相同 
 nums[a] + nums[b] + nums[c] + nums[d] == target 
 

 你可以按 任意顺序 返回答案 。 

 

 示例 1： 

 
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 

 示例 2： 

 
输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
 

 

 提示： 

 
 1 <= nums.length <= 200 
 -10⁹ <= nums[i] <= 10⁹ 
 -10⁹ <= target <= 10⁹ 
 

 Related Topics 数组 双指针 排序 👍 1592 👎 0

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
void printLinkedList(ListNode* head);
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int idx = 0; idx < nums.size(); ++idx) {
            if (nums[idx] >= 0 && nums[idx] > target) break;//剪枝，由于target可能小于零，所以要两个条件
            if (idx > 0 && nums[idx] == nums[idx - 1]) continue;//去重
            for (int idx2 = idx + 1; idx2 < nums.size(); ++idx2){
                if (nums[idx] + nums[idx2] >= 0 && nums[idx] + nums[idx2] > target) break;//剪枝
                if (idx2 > idx + 1 && nums[idx2] == nums[idx2 - 1]) continue;//去重
                int left = idx2 + 1, right = nums.size() - 1;
                while (left < right) {
                    if (static_cast<long>(nums[idx]) + nums[idx2] + nums[left] + nums[right] < target) {
                        ++left;
                    } else if (static_cast<long>(nums[idx]) + nums[idx2] + nums[left] + nums[right] > target) {
                        --right;
                    } else {
                        res.push_back({nums[idx], nums[idx2], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) ++left;//去重
                        while (left < right && nums[right] == nums[right - 1]) --right;//去重
                        ++left;
                        --right;
                    }
                }
            }
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
    
    
    
    return 0;
}

void printLinkedList(ListNode* head) {
    if(head == nullptr) return;
    while(head->next != nullptr){//为了调整输出中 "->" 的位置
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << head->val << endl;//同上
}