/**
给你一个正整数 n ，生成一个包含 1 到 n² 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。 

 

 示例 1： 
 
 
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
 

 示例 2： 

 
输入：n = 1
输出：[[1]]
 

 

 提示： 

 
 1 <= n <= 20 
 

 Related Topics 数组 矩阵 模拟 👍 1049 👎 0

*/
#include<bits/stdc++.h>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ret(n, vector<int>(n, 0));//多维数组初始化
        int cnt = 1;//按顺序给数组赋值
        int loop = n / 2;
        int startX = 0, startY = 0;//初始位置
        int offset = 0;//每次按圈循环附加的变量
        int i = 0, j = 0;
        while (loop--) {
            for (j = startY; j < n - 1 - offset; ++j) ret[startX][j] = cnt++;
            for (i = startX; i < n - 1 - offset; ++i) ret[i][j] = cnt++;
            for (; j > startY; --j) ret[i][j] = cnt++;
            for (; i > startX; --i) ret[i][j] = cnt++;

            //下一圈
            startX++;
            startY++;
            offset++;
        }
        if (n % 2) {
            ret[n / 2][n / 2] = cnt;
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> a /*initilization*/
    auto x = s. /*function_name*/
    cout << x << endl;
    return 0;
}