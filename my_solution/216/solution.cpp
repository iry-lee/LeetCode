// bfs 
/*
class Solution {
private:
    vector<vector<int>> res;
public:
    void bfs(int be, int end, int k, int n, int len, vector<int> path){
        for(int i = be; i <= end; i++){
            vector<int> newPath = path;
            int l = i + len;
            if(l == n && (int)newPath.size() == k-1) {
                newPath.push_back(i);
                res.push_back(newPath);
            }
            else if(l < n && (int)newPath.size() < k-1){
                newPath.push_back(i);
                bfs(i+1, end, k, n, len+i, newPath);
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        bfs(1, 9, k, n, 0, path);
        return res;
    }
};
*/

// 广度优先搜索可以看作是树的先序遍历，先处理当前节点，然后将当前节点的状态加到总的状态中，然后传递给后序的节点
// 而深度优先搜索则可以看作是树的后序遍历，先处理子节点，当遍历完所有的子节点，再根据子节点的返回值判断当前应该做的事情

// dfs + 回溯
class Solution{
private:
    vector<vector<int>> res;
    const int Begin = 1;
    const int End = 9;
public:
    void dfs(int be, int sum, int k, int n, vector<int>& path){
        for(int i = be; i <= End; i++){
            path.push_back(i);
            if(sum + i < n && path.size() < k) dfs(i+1, sum+i, k, n, path);
            if(sum + i == n && path.size() == k) res.push_back(path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        dfs(Begin, 0, k, n, path);
        return res;
    }
};
