/**
给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足： 

 
 0 <= i, j, k, l < n 
 nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0 
 

 

 示例 1： 

 
输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
输出：2
解释：
两个元组如下：
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) +
 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) +
 0 = 0
 

 示例 2： 

 
输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
输出：1
 

 

 提示： 

 
 n == nums1.length 
 n == nums2.length 
 n == nums3.length 
 n == nums4.length 
 1 <= n <= 200 
 -2²⁸ <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2²⁸ 
 

 Related Topics 数组 哈希表 👍 817 👎 0

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
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;
        for (auto num1 : nums1) {
            for (auto num2 : nums2) {
                map[num1 + num2]++;//nums1 nums2之和存入map
            }
        }
        int res = 0;
        for (auto num3 : nums3) {
            for (auto num4 : nums4) {
                auto target = 0 - (num3 + num4);//查找target是否存在与map中
                if (map.find(target) != map.end()) {
                    res += map[target];//target对应存在多少个，都加入
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