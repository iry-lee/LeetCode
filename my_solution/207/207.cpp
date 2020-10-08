// 思路一：检查这个有向图是否存在环？
// 那么又如何检查是否存在环呢，是不是需要n^2的时间复杂度
// 或者建立一个hash表来存储遍历过的节点？
// 一门课的先导课是不是可能不止一个？
// 同样一门课的后续课程可能也不止一个
// 而且居然会给输入课程的数量，是不是这个也有用？

// 【思路】：
// 是不是可以，从每个节点开始遍历，然后看是否存在环，如果存在环？
// 这里需要引入栈，可能需要两个，一个来存储还未遍历到的分支，一个来存储已经遍历过的路径
// 判断一个路径是否被遍历过了需要使用一下哈希
// 还有一个可以化简的点，就是如果某一个点的序号小于当前开始遍历的点的序号，那么从这个点往后一定是无环的，直接剪枝就可以
/*
class Solution {
public:
    struct Section{
        int begin;
        int end;
    };
    bool static myComp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Section section [numCourses];
        for(int i = 0; i < numCourses; i++){
            section[i].begin = -1;
            section[i].end = -1;
        }
        sort(prerequisites.begin(), prerequisites.end(), myComp);
        for(int i = 0; i < (int)prerequisites.size(); i++){
            vector <int>p = prerequisites[i];
            if(section[p[0]].begin == -1){ 
                section[p[0]].begin = i;
                section[p[0]].end = i;
            }
            else section[p[0]].end = i;
        }
        for(int i = 0; i < numCourses; i++){
            stack <vector<int>> branchStack;
            stack <int> pathStack;
            int pathHash[numCourses];
            memset(pathHash, 0, sizeof(pathHash));
            // 这里通过对prerequisites排序，优化掉一层循环
            if(section[i].begin == -1) continue;
            for(int j = section[i].begin; j <= section[i].end; j++)
                branchStack.push(prerequisites[j]);
            while(!branchStack.empty()){
                vector<int> branch = branchStack.top();
                branchStack.pop();
                // 先把栈头加入到pathStack和pathHash中
                if(pathHash[branch[0]] == 1) return false;  // 此处说明已经成环
                pathHash[branch[0]] = 1;
                pathStack.push(branch[0]);
                // 然后在表中查它的后继
                int nextCt = 0;
                if(branch[1] > i){      // 在这里做一个剪枝
                    // 这里通过对prerequisites排序，优化掉一层循环
                    if(section[branch[1]].begin != -1){
                        for(int j = section[branch[1]].begin; j <= section[branch[1]].end; j++){
                            branchStack.push(prerequisites[j]);
                            nextCt++;
                        }
                    }
                }
                if(nextCt == 0){  //后继无人，则开始退pathStack和pathHash
                    // 后继无人这个后继节点依旧要判断一下啊
                    if(pathHash[branch[1]] == 1) return false;
                    // 下面的这一步判断有问题，branch[0]就只是一跳之前的点，应该回到分支的那个点
                    // 所以应该回到branchStack的top，还要注意这个时候branchStack如果为空那就直接break就好了
                    if(branchStack.size() == 0) break;
                    while(pathStack.top() != branchStack.top()[0]) {
                        pathHash[pathStack.top()] = 0;
                        pathStack.pop();
                    }
                    pathHash[pathStack.top()] = 0;
                    pathStack.pop();    // 最后弹出当前的分支
                }
            }
        }
        return true;
    }
};
*/
// 上面的方法还是时间复杂度太高了，优化了半天，过了数据量为1000的点，2000的没过
// 还可以优化的一个点是，对prerequisites做一个排序，然后通过一个数组生成一个索引
// 索引中记录的是该点在prerequisites中的起始位置和终止位置，这样就又减少了一个复杂度上的n
// 果然这次优化以后通过了



// 官方解答中的方法二、广度优先搜索
// 每轮移除入度为0的点，直到没有入度为0的点
// 如果此时vector中还有边，表示有环
// 这里有一个基本的操作，就是节点的出入度
class Solution{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 保存每个节点的出入度
        int nodeDegree [numCourses][2];
        memset(nodeDegree, 0, sizeof(nodeDegree));
        // 保存每个节点的后续节点有哪些
        vector<int> nextNode [numCourses];
        for(auto p : prerequisites){
            nodeDegree[p[0]][0]++;      // 出度
            nodeDegree[p[1]][1]++;      // 入度
            nextNode[p[0]].push_back(p[1]);
        }
        // 组织成一个队列，入度为0的先进入队列
        queue <int> pointQueue;
        int ct = 0;
        for(int i = 0; i < numCourses; i++)
            if(nodeDegree[i][1] == 0) pointQueue.push(i);
        while(!pointQueue.empty()){
            int node = pointQueue.front();
            pointQueue.pop();
            ct++;
            // 该节点的相邻节点入度都减一
            for(auto n : nextNode[node]){
                nodeDegree[n][1]--;
                // 如果减一以后入度为0，加入到队列中
                if(nodeDegree[n][1] == 0) pointQueue.push(n);
            }
        }
        return ct == numCourses;
    }
};
