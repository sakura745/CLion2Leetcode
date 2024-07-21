/**
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。 


 返回 滑动窗口中的最大值 。 

 

 示例 1： 

 
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

 示例 2： 

 
输入：nums = [1], k = 1
输出：[1]
 

 

 提示： 

 
 1 <= nums.length <= 10⁵ 
 -10⁴ <= nums[i] <= 10⁴ 
 1 <= k <= nums.length 
 

 Related Topics 队列 数组 滑动窗口 单调队列 堆（优先队列） 👍 2301 👎 0

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
//void printLinkedList(ListNode* head);
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> deq;
        for (int idx = 0; idx < nums.size(); ++idx) {
            //下面的if和while是当deq不为空时，才执行的，也就是循环的第二步
            //但是却是位于deq.push_back()之前

            //比较的是front，说明deq中最大值已经小于窗口的左侧
            if (!deq.empty() && deq.front() ==/*维持窗口范围*/ idx - k) {
                deq.pop_front();//限制窗口的范围
            }
            //==改为<=也可以，但是由于idx是遍历的，所以==比较准确，<=没有必要

            //是while而不是if，表明在筛选deq中的所有成员
            while (!deq.empty() && nums[deq.back()] < nums[idx]/*说明deq中是最大值的序号*/) {
                deq.pop_back();
            }
            deq.push_back(idx);//表示deq中存储nums中的序号

            if (idx >= k - 1) {//表示窗口已经形成
                res.push_back(nums[deq.front()]);
            }
        }
        return res;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> a{1, -1};
    s.maxSlidingWindow(a,1);
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