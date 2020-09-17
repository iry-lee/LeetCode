// 动态规划
// 可以将一个问题划分成两个子问题，但是两个子问题不一定有解
// 这个时候就要从最少的时候开始，从底向上计算子问题
// 此时问题的时间复杂度与amount的大小有关
// 但是此时会不会计算很多不需要的解
// 如果先是能知道那些值需要，然后再去逐一计算这些需要的值，但这就已经递归了
// 不如按着所有可能的情况，从一个硬币开始往后求
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct Coin{
        int amounts;
        int numbers;
    };
    int coinChange(vector<int>& coins, int amount) {
        // 先把coins排个序
        sort(coins.begin(), coins.end());
        // 然后叠加硬币，更新值
        int ptr[coins.size()];  // 这个数组存储的是每个硬币增加时的基础数额的地址
        vector<Coin> amounts;
        memset(ptr, -1, sizeof(int)*coins.size());
        while(true){
            int temp[coins.size()]; // 这个数组存储的当前各增加一个硬币得到的新的数额
            for(int i = 0; i < coins.size(); i++){
                if(ptr[i] == -1) temp[i] = coins[i];
                else temp[i] = amounts[ptr[i]].amounts + coins[i];
            }
            int temp_min = INT_MAX, temp_i = 0;
            for(int i = 0; i < coins.size(); i++){
                if(temp[i] < temp_min){
                    temp_min = temp[i];
                    temp_i = i;
                }
            }
            if(amounts.empty()){
                amounts.push_back({temp_min, 1});
            }
            else if(temp_min > amounts[amounts.size()-1].amounts)
                amounts.push_back({temp_min, amounts[ptr[temp_i]].numbers+1});
            else if (temp_min == amounts[amounts.size()-1].amounts){
                if(amounts[ptr[temp_i]].numbers + 1 < amounts[amounts.size()-1].numbers)
                    amounts[amounts.size()-1].numbers = amounts[ptr[temp_i]].numbers + 1;
            }
            ptr[temp_i]++;
            if(!amounts.empty() && amounts[amounts.size()-1].amounts > amount) break;
        }
        if(amounts.size() > 1 && amounts[amounts.size()-2].amounts == amount) return amounts[amounts.size()-2].numbers;
        else return -1;
    }
};