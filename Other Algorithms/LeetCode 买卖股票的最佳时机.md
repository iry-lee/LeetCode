# LeetCode 买卖股票的最佳时机 6道题1个解法总结

![在这里插入图片描述](LeetCode 买卖股票的最佳时机.assets/2020052607031159.png)
一个方法解决6道买卖股票题：来自[LeetCode题解](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-w-5/)

Leetcode 题目：

- [121.买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)

- [122.买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)

- [123.买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)

- [188.买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)

- [309.最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

- [714.买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

- [剑指 Offer 63. 股票的最大利润](https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/)

**个人总结**

这种题目，画状态转移图很重要，有的时候这个模板记不得了，但是换一个状态转移图以后就可以知道这个题怎么来做了，甚至穷举一下状态就可以得到最终的代码了。

## 一、穷举框架

利用「状态」进行穷举。我们具体到每一天，看看总共有几种可能的「状态」，再找出每个「状态」对应的「选择」。我们要穷举所有「状态」，穷举的目的是根据对应的「选择」更新状态。

```cpp
for 状态1 in 状态1的所有取值：
    for 状态2 in 状态2的所有取值：
        for ...
            dp[状态1][状态2][...] = 择优(选择1，选择2...)
1234
```

每天都有三种「选择」：买入、卖出、无操作。这个问题的「状态」有三个，第一个是天数，第二个是允许交易的最大次数，第三个是当前的持有状态（即之前说的 rest 的状态，我们不妨用 1 表示持有，0 表示没有持有）。然后我们用一个三维数组就可以装下这几种状态的全部组合：

```cpp
dp[i][k][0 or 1]
0 <= i <= n-1, 1 <= k <= K
n 为天数，大 K 为最多交易数
此问题共 n × K × 2 种状态，全部穷举就能搞定。

for 0 <= i < n:
    for 1 <= k <= K:
        for s in {0, 1}:
            dp[i][k][s] = max(buy, sell, rest)
123456789
```

用自然语言描述出每一个状态的含义，`dp[3][2][1]`的含义就是：今天是第3天，我现在手上持有着股票，至今最多进行 2 次交易。我们想求的最终答案是 dp[n - 1][K][0]，即最后一天，最多允许 K 次交易，最多获得多少利润。因为 [1] 代表手上还持有股票，[0] 表示手上的股票已经卖出去了，很显然后者得到的利润一定大于前者。
记住如何解释「状态」，一旦你觉得哪里不好理解，把它翻译成自然语言就容易理解了。

## 二、状态转移框架

状态转移图：
![在这里插入图片描述](LeetCode 买卖股票的最佳时机.assets/20200526071126993.png)

根据图写出状态转移方程：

```cpp
dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
              max(   选择 rest  ,           选择 sell      )

解释：今天我没有持有股票，有两种可能：
要么是我昨天就没有持有，然后今天选择 rest，所以我今天还是没有持有；
要么是我昨天持有股票，但是今天我 sell 了，所以我今天没有持有股票了。

dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
              max(   选择 rest  ,           选择 buy         )

解释：今天我持有着股票，有两种可能：
要么我昨天就持有着股票，然后今天选择 rest，所以我今天还持有着股票；
要么我昨天本没有持有，但今天我选择 buy，所以今天我就持有股票了。
12345678910111213
```

如果 buy，就要从利润中减去 prices[i]，如果 sell，就要给利润增加 prices[i]。今天的最大利润就是这两种可能选择中较大的那个。而且注意 k 的限制，我们在选择 buy 的时候，把 k 减小了 1（也可以在 sell 的时候减 1）。
定义 base case，即最简单的情况：

```cpp
dp[-1][k][0] = 0
解释：因为 i 是从 0 开始的，所以 i = -1 意味着还没有开始，这时候的利润当然是 0 。
dp[-1][k][1] = -infinity
解释：还没开始的时候，是不可能持有股票的，用负无穷表示这种不可能。
dp[i][0][0] = 0
解释：因为 k 是从 1 开始的，所以 k = 0 意味着根本不允许交易，这时候利润当然是 0 。
dp[i][0][1] = -infinity
解释：不允许交易的情况下，是不可能持有股票的，用负无穷表示这种不可能。
12345678
```

把上面的状态转移方程总结一下：

```cpp
base case：
dp[-1][k][0] = dp[i][0][0] = 0
dp[-1][k][1] = dp[i][0][1] = -infinity

状态转移方程：
dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
1234567
```

下面开始具体化。

## 三、解决题目

#### 第一题，k = 1

直接套状态转移方程，根据 base case，可以做一些化简：

```cpp
dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i]) 
            = max(dp[i-1][1][1], -prices[i])
解释：k = 0 的 base case，所以 dp[i-1][0][0] = 0。

现在发现 k 都是 1，不会改变，即 k 对状态转移已经没有影响了。
可以进行进一步化简去掉所有 k：
dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
dp[i][1] = max(dp[i-1][1], -prices[i])
123456789
```

直接写出代码：

```cpp
if(prices.size()<2) return 0;
int n = prices.size();
int dp[n][2];
for (int i = 0; i < n; i++) {
    dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
    dp[i][1] = max(dp[i-1][1], -prices[i]);
}
return dp[n - 1][0];
12345678
```

显然 i = 0 时 dp[i-1] 是不合法的。这是因为我们没有对 i 的 base case 进行处理。可以这样处理：

```cpp
for (int i = 0; i < n; i++) {
    if (i - 1 == -1) {
        dp[i][0] = 0;
        // 解释：
        //   dp[i][0] 
        // = max(dp[-1][0], dp[-1][1] + prices[i])
        // = max(0, -infinity + prices[i]) = 0
        dp[i][1] = -prices[i];
        //解释：
        //   dp[i][1] 
        // = max(dp[-1][1], dp[-1][0] - prices[i])
        // = max(-infinity, 0 - prices[i]) 
        // = -prices[i]
        continue;
    }
    dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
    dp[i][1] = max(dp[i-1][1], -prices[i]);
}
return dp[n - 1][0];
12345678910111213141516171819
```

第一题就解决了，但是这样处理 base case 很麻烦，而且注意一下状态转移方程，新状态只和相邻的一个状态有关，其实不用整个 dp 数组，只需要一个变量储存相邻的那个状态就足够了，这样可以把空间复杂度降到 O(1)：

```cpp
// k == 1
int maxProfit_k_1(vector<int>& prices) {
    int n = prices.size();
    // base case: dp[-1][0] = 0, dp[-1][1] = -infinity
    int dp_i_0 = 0, dp_i_1 = INT_MIN;
    for (int i = 0; i < n; i++) {
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        // dp[i][1] = max(dp[i-1][1], -prices[i])
        dp_i_1 = max(dp_i_1, -prices[i]);
    }
    return dp_i_0;
}
12345678910111213
```

两种方式都是一样的，不过这种编程方法简洁很多。但是如果没有前面状态转移方程的引导，是肯定看不懂的。后续的题目，主要写这种空间复杂度 O(1) 的解法。

#### 第二题，k = +infinity

如果 k 为正无穷，那么就可以认为 k 和 k - 1 是一样的。可以这样改写框架：

```cpp
dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
            = max(dp[i-1][k][1], dp[i-1][k][0] - prices[i])

我们发现数组中的 k 已经不会改变了，也就是说不需要记录 k 这个状态了：
dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
1234567
```

直接翻译成代码：

```cpp
int maxProfit_k_inf(vector<int>& prices) {
    int n = prices.size();
    int dp_i_0 = 0, dp_i_1 = INT_MIN;
    for (int i = 0; i < n; i++) {
        int tmp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, tmp - prices[i]);
    }
    return dp_i_0;
}
12345678910
```

#### 第三题，k = +infinity with cooldown

每次 sell 之后要等一天才能继续交易。只要把这个特点融入上一题的状态转移方程即可：

```cpp
dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])
解释：第 i 天选择 buy 的时候，要从 i-2 的状态转移，而不是 i-1 。
123
```

翻译成代码：

```cpp
int maxProfit_with_cool(vector<int>& prices) {
    int n = prices.size();
    int dp_i_0 = 0, dp_i_1 = INT_MIN;
    int dp_pre_0 = 0; // 代表 dp[i-2][0]
    for (int i = 0; i < n; i++) {
        int tmp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i]);
        dp_pre_0 = tmp;
    }
    return dp_i_0;
}
123456789101112
```

#### 第四题，k = +infinity with fee

每次交易要支付手续费，只要把手续费从利润中减去即可。改写方程：

```cpp
dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee)
解释：相当于买入股票的价格升高了。
在第一个式子里减也是一样的，相当于卖出股票的价格减小了。
1234
```

直接翻译成代码：

```cpp
int maxProfit_with_fee(vector<int>& prices, int fee) {
    int n = prices.size();
    int dp_i_0 = 0, dp_i_1 = INT_MIN;
    for (int i = 0; i < n; i++) {
        int tmp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, tmp - prices[i] - fee);
    }
    return dp_i_0;
}
12345678910
```

#### 第五题，k = 2

k = 2 和前面题目的情况稍微不同，因为上面的情况都和 k 的关系不太大。要么 k 是正无穷，状态转移和 k 没关系了；要么 k = 1，跟 k = 0 这个 base case 挨得近，最后也没有存在感。

这道题 k = 2 和后面要讲的 k 是任意正整数的情况中，对 k 的处理就凸显出来了。我们直接写代码，边写边分析原因。

```cpp
原始的动态转移方程，没有可化简的地方
dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
123
```

按照之前的代码，我们可能想当然这样写代码（错误的）：

```cpp
int k = 2;
int dp[n][k + 1][2];
for (int i = 0; i < n; i++)
    if (i - 1 == -1) { /* 处理一下 base case*/ }
    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
}
return dp[n - 1][k][0];
12345678
```

我们必须穷举所有状态。其实我们之前的解法，都在穷举所有状态，只是之前的题目中 k 都被化简掉了。这道题由于没有消掉 k 的影响，所以必须要对 k 进行穷举：

```cpp
int max_k = 2;
int dp[n][max_k + 1][2];
for (int i = 0; i < n; i++) {
    for (int k = max_k; k >= 1; k--) {
        if (i - 1 == -1) { /*处理 base case */ }
        dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
        dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
    }
}
// 穷举了 n × max_k × 2 个状态，正确。
return dp[n - 1][max_k][0];
1234567891011
```

如果不理解，可以返回第一点「穷举框架」重新阅读体会一下。

这里 k 取值范围比较小，所以可以不用 for 循环，直接把 k = 1 和 2 的情况手动列举出来也可以：

```cpp
dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][2][1] + prices[i])
dp[i][2][1] = max(dp[i-1][2][1], dp[i-1][1][0] - prices[i])
dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
dp[i][1][1] = max(dp[i-1][1][1], -prices[i])

int maxProfit_k_2(vector<int>& prices) {
    int dp_i10 = 0, dp_i11 = INT_MIN;
    int dp_i20 = 0, dp_i21 = INT_MIN;
    for (int price : prices) {
        dp_i20 = max(dp_i20, dp_i21 + price);
        dp_i21 = max(dp_i21, dp_i10 - price);
        dp_i10 = max(dp_i10, dp_i11 + price);
        dp_i11 = max(dp_i11, -price);
    }
    return dp_i20;
}
12345678910111213141516
```

有状态转移方程和含义明确的变量名指导，很容易看懂。其实可以把上述四个变量换成 a, b, c, d来装b。

#### 第六题，k = any integer

有了上一题 k = 2 的铺垫，这题应该和上一题的第一个解法没啥区别。但是出现了一个超内存的错误，原来是传入的 k 值会非常大，dp 数组太大了。

一次交易由买入和卖出构成，至少需要两天。所以说有效的限制 k 应该不超过 n/2，如果超过，就没有约束作用了，相当于 k = +infinity。这种情况是之前解决过的。

直接把之前的代码重用：

```cpp
int maxProfit_k_any(int max_k, vector<int>& prices) {
    int n = prices.size();
    if (max_k > n / 2) 
        return maxProfit_k_inf(prices);
    int dp[n][max_k + 1][2];
    for (int i = 0; i < n; i++) 
    	dp[i][0][0]=0; dp[i][0][1]=INT_MIN;
        for (int k = max_k; k >= 1; k--) {
            if (i - 1 == -1) {
				dp[i][j][0]=0; dp[i][j][1]=-prices[i];
				continue;
			}
            dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
            dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);     
        }
    return dp[n - 1][max_k][0];
}
1234567891011121314151617
```

## 四、总结

关键就在于列举出所有可能的「状态」，然后想想怎么穷举更新这些「状态」。具体到股票买卖问题，我们发现了三个状态，使用了一个三维数组，无非还是穷举 + 更新。
不要被各种高大上的名词吓到，再多的困难问题，奇技淫巧，也不过是基本套路的不断升级组合产生的。只要把住算法的底层原理，即可举一反三，逐个击破。

参考： [LeetCode英文题解](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems)