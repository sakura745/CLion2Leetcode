/**
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。 

 请必须使用时间复杂度为 O(log n) 的算法。 

 

 示例 1: 

 
输入: nums = [1,3,5,6], target = 5
输出: 2
 

 示例 2: 

 
输入: nums = [1,3,5,6], target = 2
输出: 1
 

 示例 3: 

 
输入: nums = [1,3,5,6], target = 7
输出: 4
 

 

 提示: 

 
 1 <= nums.length <= 10⁴ 
 -10⁴ <= nums[i] <= 10⁴ 
 nums 为 无重复元素 的 升序 排列数组 
 -10⁴ <= target <= 10⁴ 
 

 Related Topics 数组 二分查找 👍 2011 👎 0

*/
#include<bits/stdc++.h>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (target == nums[middle]) {
                return middle;
            } else if (target < nums[middle]) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        return left;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> a {-1, 0, 3, 5, 9, 12};
    auto x = s.searchInsert(a, 2);
    cout << x << endl;
    return 0;
}