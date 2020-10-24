// 本体的思路：
// 类似于递归求解：
// 1.初始化：先将people中所有k为0的找出来，时间复杂度为O(n)，然后将这些数据组织成一个小顶堆O(nlogn)
// 2.如果堆中元素数量大于0，取出堆顶的元素a，放入到结果中，堆的删除操作，时间复杂度为O(logn)；如果堆为空，则停止。
// 3.然后去到之前的数组中找高度比a.h小的元素，并且a.k--，如果此时a.k==0，则也将其放到堆中，堆的插入操作，时间复杂度为O(logn)，每往ans中插入一个元素，就要去到people中找一遍，这里的时间复杂度为O(n^2)，每个元素都会被从堆中插入删除一次，这些时间复杂度总体为O(nlogn)。
// 4.执行步骤2

// 总的时间复杂度为O(n^2)
/*
class Solution {
public:
    bool static MyCompare(const vector<int>& a, const vector<int>& b){
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans, zeroArr, backup = people;
        for(vector<int> p : people)
            if(p[1] == 0) zeroArr.push_back(p);
        make_heap(zeroArr.begin(), zeroArr.end(), MyCompare);
        bool flag = false; // 如果为false，表示people中的k值不全为0
        while(zeroArr.size() > 0){
            // cout << zeroArr[0][0] << " " << zeroArr[0][1] << endl;
            pop_heap(zeroArr.begin(), zeroArr.end(), MyCompare);
            vector<int> back = zeroArr[zeroArr.size()-1];
            ans.push_back(back);
            zeroArr.pop_back();
            if(flag) continue; // 如果所有的点都为0的时候，就不需要再做这个循环了
            for(int i = 0; i < people.size(); i++){
                if(people[i][1] == 0) continue;
                if(people[i][1] > 0 && people[i][0] <= back[0]){
                    flag = true;
                    // cout << people[i][0] << " " << people[i][1] << endl;  
                    people[i][1]--;
                    if(people[i][1] == 0){
                        zeroArr.push_back({people[i][0], backup[i][1]});
                        push_heap(zeroArr.begin(), zeroArr.end(), MyCompare);
                    }
                }
            }
            if(flag) flag = false;
        }
        return ans;
    }
};
*/

// 【官方题解】高个子看不见矮个子
// 所以从高到低依次插入，k就是其应该插入的位置
class Solution {
public:
    bool static MyCompare(const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1];    // 相同身高的话，按照出现次序排序
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(), people.end(), MyCompare); 
        // for(vector<int> p : people) cout << "[" << p[0] << "," << p[1] << "] "; 
        for(int i = 0; i < people.size(); i++){
            if(ans.size() <= people[i][1]) ans.push_back(people[i]);
            else ans.insert(ans.begin() + people[i][1], people[i]);
        }
        return ans;
    }
};