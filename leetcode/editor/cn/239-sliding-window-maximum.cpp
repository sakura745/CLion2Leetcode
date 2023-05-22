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
private:
    class MyQue {
    public:
        deque<int> que;//单调队列

        void push(int& val) {
            while (!que.empty() && val > que.back()/*加入的依次比较，比val小的都弹出，用来维持单调性*/) {
                que.pop_back();
            }
            que.push_back(val);
        }
        void pop(int& val) {
            if (!que.empty() && val == que.front()/*如果弹出的值为队首（最大值），则弹出*/) {
                que.pop_front();
            }
        }

        //因为维护的是单调队列，直接获取队首即可
        int getNextValue() {
            return que.front();
        }

    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        MyQue que;
        for (int i = 0; i < k; ++i) {//加入第一个窗口的值
            que.push(nums[i]);
        }
        res.push_back(que.getNextValue());
        for (int i = k; i < nums.size(); ++i) {//补上之前的遍历，使其完整遍历
            que.pop(nums[i - k/*维护窗口的大小*/]);
            que.push(nums[i/*维护窗口的大小*/]);
            res.push_back(que.getNextValue());
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