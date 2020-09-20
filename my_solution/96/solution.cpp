// 这是一个非常经典的DP问题
/*
思路：
二叉搜索树的数量是左右子树的情况的数量乘积
其实可以用动态规划: f(n) = f(i) * f(n-1-i)
*/
class Solution {
public:
    int numTrees(int n) {
        if(n == 0) return 1;
        int arr[n+1];
        memset(arr, 0, sizeof(arr));
        arr[0] = 1;
        arr[1] = 1;
        for(int i = 2; i <= n; i++)
            for(int j = 0; j < i; j++) 
                arr[i] += arr[j] * arr[i-j-1];
        return arr[n];
    }
};