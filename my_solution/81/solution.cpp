class Solution {
public:
    bool traverseSearch(vector<int>& vec, int begin, int end, int target){
        for(int i = begin; i <= end; i++) if(vec[i] == target) return true;
        return false;
    }
    bool binarySearch(vector<int>& vec, int begin, int end, int target){
        int middle = (begin + end) / 2;
        if(end < begin) return false;
        if(begin == end) return vec[middle] == target;
        if(vec[middle] == target) return true;
        else if(vec[middle] == vec[end] && vec[middle] == vec[begin]) return traverseSearch(vec, begin, end, target);
        // 这里，vec[middle] == vec[begin] 也就说，vec[middle] >= vec[end]
        else if(vec[middle] == vec[begin]){
            return binarySearch(vec, middle+1, end, target);
        }
        // 这里，vec[middle] == vec[end] 也就是说，vec[middle] <= vec[begin]
        else if(vec[middle] == vec[end]){
            return binarySearch(vec, begin, middle-1, target);
        }
        else if(vec[begin] > vec[middle]){
            if(vec[middle] > target) return binarySearch(vec, begin, middle-1, target);
            else return binary_search(vec.begin()+middle+1, vec.begin()+end+1, target) 
                            || binarySearch(vec, begin, middle-1, target);
        }
        else if(vec[begin] < vec[middle]){
            if(vec[middle] > target) return binary_search(vec.begin()+begin, vec.begin()+middle, target) 
                                                || binarySearch(vec, middle+1, end, target);
            else return binarySearch(vec, middle+1, end, target);
        }
        else return false;
    }
    bool search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, (int)nums.size()-1, target);
    }
};