// 这个题可以考虑分别使用“栈+迭代”和“递归”来做
// 这个题按照题面的话，应该要用广度优先搜索
#include <stack>
#include <memory.h>
#include <iostream>
#include <queue>

using namespace std;
// 【方法一】找规律
//class Solution {
//public:
//    int basic(int m, int n, int k){
//        int result = 0;
//        for(int i = 0; i < m; i++){
//            int temp = k - i + 1;
//            if(temp <= 0) break;
//            else if(temp < n) result += temp;
//            else result += n;
//        }
//        return result;
//    }
//    int movingCount(int m, int n, int k) {
//        int result = 0;
//        if (k < 9 || (m <= 9 && n <= 9)) return basic(m, n, k);
//        else{
//            // 划分成10x10的格子，然后使用basic计算
//            int x = 0, y = 0, _k = k;
//            while(x < m){
//                if(_k < 8) break;
//                y = 0;
//                int _kk = _k;
//                while (y < n){
//                    if(_kk < 8) break;
//                    printf("* ");
//                    int _m = 10, _n = 10;
//                    if(x + 10 > m) _m = m % 10;
//                    if(y + 10 > n) _n = n % 10;
//                    result += basic(_m, _n, _kk);
//                    y += 10;
//                    _kk--;
//                }
//                printf("\n");
//                _k--;
//                x += 10;
//            }
//        }
//        return result;
//    }
//};
/*
反例：
15 15 14
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 0 1 1 1 1 1
1 1 1 1 1 1 1 1 0 0 1 1 1 1 1
1 1 1 1 1 1 1 0 0 0 1 1 1 1 1
1 1 1 1 1 1 0 0 0 0 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
215

出错的原因：这里是数位之和，所以没那么简单，n和m在10以内是没问的，或者如果k小于等于8也是没问题的
解决：
所以是不是可以把mn超过10的情况，以10x10的格子进行划分
(0,0)所在的那个格子，k还是k,
(10,0)所在的那个格子，k是k-1,
(0,10)所在的那个格子，k是k-1,
依次类推，直到k小于8，就不方便往外扩展了
*/


// 【方法二】广度优先搜索 BFS
class Solution {
public:
    struct point{
        int x;
        int y;
    };
    int bitAdding(int a, int b){
        int result = 0;
        while (a > 0){
            result = result + (a % 10);
            a = a / 10;
        }
        while (b > 0){
            result = result + (b % 10);
            b = b / 10;
        }
        return result;
    }
    int movingCount(int m, int n, int k) {
        if(m == 0 || n == 0) return 0;
        int ct = 1;
        int map[m][n];
        queue<point> q;
        memset(map, 0, sizeof(int)*m*n);
        q.push({0, 0});
        map[0][0] = 1;
        while(!q.empty()) {
            point top = q.front();
            // 注意，这里要用广度优先搜索来做
            q.pop();
            // 下
            if(top.x + 1 < m && bitAdding(top.x+1, top.y) <= k && map[top.x+1][top.y] == 0) {
                q.push({top.x + 1, top.y});
                map[top.x+1][top.y] = 1;
                ct++;
            }
            // 右
            if(top.y + 1 < n && bitAdding(top.x, top.y+1) <= k && map[top.x][top.y+1] == 0) {
                q.push({top.x, top.y + 1});
                map[top.x][top.y+1] = 1;
                ct++;
            }
        }
//        for(int i = 0; i < m; i++){
//            for(int j = 0; j < n; j++){
//                cout << map[i][j] << " ";
//            }
//            cout << "\n";
//        }
        return ct;
    }
};
