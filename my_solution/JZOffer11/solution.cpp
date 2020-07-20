class Solution {
public:
    int findPosition(vector<int> &numbers, int begin, int end){
        printf("[%d, %d]\n", begin, end);
        if(begin > end) return -1;
        else if(begin == end){ //如果子数组的长度为1
            if(begin > 0 && numbers[begin-1] > numbers[begin]) return begin;
            else return -1;
        }
        else if(begin + 1 == end){ //如果子数组的长度为2
            if(numbers[begin] > numbers[end]) return end;
            if(begin > 0 && numbers[begin-1] > numbers[begin]) return begin;
            else return -1;
        }
        else{
            // 缩小问题规模
            int middle = (begin + end)/2, lpt = (begin + middle)/2, rpt = (middle + end)/2;
            if(middle > 0 && numbers[middle-1] > numbers[middle]) return middle;
            // 这里的等号如何处理？
            if(numbers[lpt] == numbers[rpt]){
                int leftp = findPosition(numbers, begin, middle-1);
                int rightp = findPosition(numbers, middle+1, end);
                if(leftp == -1) return rightp;
                else return leftp;
            }
            else if(numbers[lpt] < numbers[rpt]){
                int leftp = findPosition(numbers, begin, lpt);
                int rightp = findPosition(numbers, rpt, end);
                if(leftp == -1) return rightp;
                else return leftp;
            }
            else{
                int leftp = findPosition(numbers, lpt, middle-1);
                int rightp = findPosition(numbers, middle+1, rpt);
                if(leftp == -1) return rightp;
                else return leftp;
            }
        }
    }
    int minArray(vector<int>& numbers) {
        int p = findPosition(numbers, 0, numbers.size()-1);
        if(p > 0) return numbers[p];
        else return numbers[0];    // 如果没找到，说明旋转了0个元素
    }
};