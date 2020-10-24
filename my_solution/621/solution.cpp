// 求最短时间
// 时间存在最短的原因是，两个相同种类的任务之间有冷冻期
// 按照贪心法的话，先把数量最多的任务给安排上，然后其他的任务插在此任务的空隙中
// 但是这个思路怎么转变成方法
// 冷冻期可以看成是宽度，同一任务执行两次之间执行的任务可以看作是宽度
// 可以用一个泳道来形象地描述，泳道条数为n+1
// 所以可以建立n+1个队列，队列里放的是待执行的任务，
// 任务从长到短排序，每次都加入到长度最短的队列中
/*
【思路不太对，也无法跑通全部测试点】
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.size() == 0) return 0;
        // 先用一个hash来统计任务的出现次数
        vector<int> taskArr, q(n+1, 0); 
        unordered_map<char, int> hash;
        for(char t : tasks)
            if(hash.find(t) != hash.end()) hash[t]++;
            else hash[t] = 1;
        unordered_map<char, int>::iterator it = hash.begin();
        for(; it != hash.end(); it++)
            taskArr.push_back(it->second);
        sort(taskArr.begin(), taskArr.end());  // 排完序是升序的
        for(int i = (int)taskArr.size()-1; i >= 0; i--){
            // 找q的最小值
            int minPosition = min_element(q.begin(), q.end()) - q.begin();
            q[minPosition] += taskArr[i];
        }
        // 通过分析q的内容，确定最终解
        // for(int item : q) cout << item << " "; 
        int maxValue = *max_element(q.begin(), q.end());
        int ct = count(q.begin(), q.end(), maxValue);
        return (maxValue-1)*(n+1) + ct;
    }
};
*/
// 反例
/*
["A","A","A","B","B","B", "C","C","C", "D", "D", "E"]
2
我的解：13
正确解：12
原因如下：
|-A-| |-D-| |----A----|
|-D-| |------B--------|
|-E-| |------C--------|
这个反例直接使得我的方法不能用了

*/
// 【改进后的方法】
// 不如每次取最多的出来安排，就是每次任务都只执行一次，再取最多的出来执行，而不是一下全部安排进去
// 下面的方法可以通过：
/*
class Solution {
public:
    struct Task{
        char name;
        int times;
    };
    bool static MyCompare(const Task& a, const Task& b){
        return a.times > b.times;
    }
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.size() == 0) return 0;
        // 建立一个vector，先初始化为hashTable，后续作为vector使用
        vector<Task> hashTable(26, {'A', 0});
        for(int i = 0; i < 26; i++) hashTable[i].name = 'A' + i;
        for(char c : tasks) hashTable[c - 'A'].times++;
        // 执行任务
        int ct = 0, subct = 0;
        while(true){
            // 对hashTable排序
            sort(hashTable.begin(), hashTable.end(), MyCompare);
            // 删掉没有出现的任务
            while(hashTable.size() > 0 && (hashTable.end()-1)->times == 0)
                hashTable.pop_back();
            // 如果数组中没有了待运行的任务，结束
            if(hashTable.size() == 0) break;
            // 然后对于出现了的任务，每种安排一个进CPU
            // 如果任务种数不够n+1，则剩下的时间只能被浪费掉
            ct++;
            subct = 0;
            for(int i = 0; i < hashTable.size() && i < n + 1; i++){
                hashTable[i].times--;
                subct++;
            }
        }
        // for(auto t : hashTable) cout << t.name << ": " << t.times << endl;
        return (ct - 1)*(n+1) + subct;
    }
};
*/

// 【官方题解中的优先队列方法】
/*
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int hashTable[26] = {0};
        priority_queue<int> taskPQ;     // 等同于下面这句
        // priority_queue <int, vector<int>, less<int>> taskPQ;   // 这里的less换成greater就是小顶堆
        // 利用哈希表，记录每个任务的出现次数 
        for(int t : tasks) hashTable[t - 'A']++;
        // 将哈希表中的任务放入到优先级队列中
        for(int i = 0; i < 26; i++){
            if(hashTable[i] != 0) taskPQ.push(hashTable[i]);
        }
        int ct = 0, subct = 0;
        while(!taskPQ.empty()){
            int len = taskPQ.size();
            // 建立一个新的优先级队列，目的是为了防止高优先级任务的被push回去以后又再次被执行
            // 只有执行完一轮以后，下一轮才轮到它
            priority_queue<int> tempPQ;
            // 将优先队列中的任务依次执行一次
            ct++;
            subct = 0;
            for(int i = 0; i < len; i++){
                int temp;
                // n+1以内的才被拿出来执行
                if(i < n + 1) temp = taskPQ.top() - 1;
                else temp = taskPQ.top();
                taskPQ.pop();
                if(temp > 0) tempPQ.push(temp);
                subct++;
            }
            taskPQ = tempPQ;
        }
        return (ct - 1)*(n+1) + subct;
    }
};
*/

// 官方题解中的“设计”方法
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
    }
};
