//
// Created by 11029 on 2020/6/12.
//

// 输入确保在 1 到 3999 的范围内。
// 一个需要注意的点是，4/9/40/90/400/900 的特殊表示：
// 4 -> IV, 9 -> IX, ...
// 这是有限的六种情况

class Solution {
public:
    string intToRoman(int num) {
        string roman;
        // 范围是0-3999
        int arr [4]  = {0, 0, 0, 0};
        for(int i = 3; i > -1; i--){
            arr[i] = num % 10;
            num /= 10;
        }
        // 从左边数第一位
        for(int i = 0; i < arr[0]; i++){
            roman.append("M");
        }
        string table [3][3] = {{"M", "D", "C"},
                               {"C", "L", "X"},
                               {"X", "V", "I"}};
        // 从左边数第二位
        for(int i = 1; i < 4; i++){
            if(arr[i] == 9){
                roman.append(table[i-1][2]);
                roman.append(table[i-1][0]);
            }
            else if(arr[i] >= 5 && arr[i] <= 8){
                roman.append(table[i-1][1]);
                arr[i] -= 5;
                for(int j = 0; j < arr[i]; j++){
                    roman.append(table[i-1][2]);
                }
            }
            else if(arr[i] == 4){
                roman.append(table[i-1][2]);
                roman.append(table[i-1][1]); //4
            }
            else{
                for(int j = 0; j < arr[i]; j++){
                    roman.append(table[i-1][2]);
                }
            }
        }
        return roman;
    }
};

/*
 * 我的方法像是介于硬编码和循环取余之间
 */