// 最好还是边转二进制边求汉明距离，这样一次遍历就可以了
// 而且在转的过程中一旦发现此时x==y立即停止就好，又可以剩下一些时间
class Solution {
private:
    int BINARY_LEN = 32;
public:
    int hammingDistance(int x, int y){
        int res = 0, ptr = BINARY_LEN-1;
        while(ptr >= 0){
            if(x == y) break;
            if( (x|-2) != (y|-2) ) res++;
            ptr--;
            x = x >> 1;
            y = y >> 1;
        }
        return res;
    }
};

/*
方法：先转二进制数组，再求汉明距离
class Solution {
public:
    int BINARY_LEN = 32;
    vector<int> int2BinaryVec(int x){
        vector<int> res;
        res.resize(BINARY_LEN);
        int ptr = BINARY_LEN - 1;
        while(ptr >= 0){
            if((x | -2) == -1) res[ptr] = 1;
            else res[ptr] = 0;
            ptr--;
            x = x >> 1;     // 移位操作总是忘了需要赋值操作，不是在原本数据上移位
        }
        return res;
    }
    int hammingDistance(int x, int y) {
        int res = 0;
        vector<int> binaryX = int2BinaryVec(x);
        vector<int> binaryY = int2BinaryVec(y);
        for(int i = 0; i < BINARY_LEN; i++){
            if(binaryX[i] != binaryY[i]) res++;
        }
        return res;
    }
};
*/