class Solution {
public:
    int cuttingRope(int n) {
        if(n < 2) return 0;
        if(n == 2) return 1;    // 至少切一刀，所以是1
        if(n == 3) return 2;    // 至少切一刀，所以是2

        // 绳子可以得到长度为3的绳子段的个数
        int timesOf3 = n / 3;
        int timesOf2 = 0;
        int result = 1;

        // 最后剩下一个长度为1的绳子段，不可以
        // 当绳子最后还剩下长度为4的绳子段的时候，分成两个长度为2的
        if(n - timesOf3 * 3 == 1)
            timesOf3 --;

        // 需要剪成长度的为2的绳子的个数
        timesOf2 = (n - timesOf3*3)/ 2;

        for(int i = 0; i < timesOf2; i++){
            result *= 2;
        }

        for(int i = 0; i < timesOf3; i++){
            long long temp = (long)result * 3;
            if(temp > 1000000007) temp %= 1000000007;
            result = (int)temp;
        }
        return result;
    }
};