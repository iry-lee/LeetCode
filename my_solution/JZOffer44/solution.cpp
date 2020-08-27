class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10) return n;
        long long num_count = 10;
        int bit = 1;
        long long nine_power = 9;
        long long ten_power = 1;
        while(n > num_count){
            // cout << "num_count:" << num_count << "\n";
            bit++;
            nine_power *= 10;
            ten_power *= 10;
            num_count += nine_power*bit;
        }
        int delta = n - (num_count - nine_power*bit);
        // cout << delta << "\n";
        int posi = delta / bit;
        int offset = delta % bit;
        int number = ten_power + posi;
        return to_string(number)[offset]-'0';
    }
};