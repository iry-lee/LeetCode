// 这个题，如果每次找最小的数出来，则需要找k次，时间复杂度为O(kn)
// 如果是快排的话，时间复杂度O(nlogn)
// 有没有O(n)的方法？哈希？partition算法
// 【方法三 堆排序】复杂度O(nlogk)
class Solution{
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k){
        vector<int> result;
        if(arr.size() == 0 || k == 0) return result;
        for(int i = 0; i < k; i++){
            result.push_back(arr[i]);
        }
        make_heap(result.begin(), result.end());
        for(int i = k; i < arr.size(); i++){
            if(arr[i] < result[0]){
                pop_heap(result.begin(), result.end());
                result.pop_back();
                result.push_back(arr[i]);
                push_heap(result.begin(), result.end());
            }
        }
        return result;
    }
};
/*
【方法二 partition算法】复杂度O(n)
// 如果使用partition算法的话，只需要找到第k小的数字，然后其左边的都是比第k小的数字还小的
class Solution {
public:
    void partition(vector<int>& arr, int k, int begin, int end){
        // t的选取对于速度影响非常显著，
        // t取i的时候，用时1372ms，击败5%的用户
        // t取k-1的时候，用时56ms，击败80%的用户
        // t取j的时候，用时64ms，击败75%的用户
        int i = begin, j = end, t = j;
        while(i < j){
            if(i < t){
                if(arr[i] <= arr[t]) i++;
                else{
                    int temp = arr[i];
                    arr[i] = arr[t];
                    arr[t] = temp;
                    t = i;
                }
            }
            else{
                if(arr[j] >= arr[t]) j--;
                else{
                    int temp = arr[j];
                    arr[j] = arr[t];
                    arr[t] = temp;
                    t = j;
                }
            }
        }
        if(t == k-1) return;
        else if (t < k-1) partition(arr, k, t+1, end);
        else partition(arr, k, 0, t-1);
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k){
        vector<int> result;
        if(arr.size() == 0 || k == 0) return result;
        partition(arr, k, 0, arr.size()-1);
        for(int i = 0; i < k; i++){
            result.push_back(arr[i]);
        }
        return result;
    }
};
*/
/*
【方法一 哈希】 复杂度O(n)
class Solution {
public:
    int HASH = 10002;
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int hash[10002] = {0};
        vector<int> result;
        for(int i = 0; i < arr.size(); i++){
            hash[arr[i]]++;
        }
        for(int i = 0; i < HASH && k > 0; i++){
            if(hash[i] > 0){
                if(hash[i] <= k){
                    for(int j = 0; j < hash[i]; j++)
                        result.push_back(i);
                }
                else{
                    for(int j = 0; j < k; j++)
                        result.push_back(i);
                }
                k -= hash[i];
            }
            else continue;
        }
        return result;
    }
};
*/