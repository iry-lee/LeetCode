// 回溯
/*
class Solution {
public:
    struct Point{
        int x;
        int y;
    };
    vector<vector<Point>> total;
    bool isValid(vector<Point> path, Point p){
        // 判断是否有同列的
        // 判断是否有同斜线的
        for(auto point : path){
            // cout << point.x << " " << point.y << endl;
            if(point.y == p.y) return false;
            if(point.x + point.y == p.x + p.y) return false;
            if(point.x - point.y == p.x - p.y) return false;
        }
        // cout << "true\n";
        return true;
    }

    void dfs(int n, vector<Point>& path){
        int x = path.size();
        // cout << x << endl;
        if(x == n) {
            total.push_back(path);
            return;
        }
        for(int j = 0; j < n; j++){
            if(isValid(path, {x, j})){
                path.push_back({x, j});
                dfs(n, path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<Point> path;
        dfs(n, path);
        // 先不用vector<vector<string>>存
        vector<vector<string>> res;
        string dotstring = "";
        for(int i = 0; i < n; i++) dotstring.append(".");
        for(auto t : total){
            vector<string> temp (n, dotstring);
            for(auto p : t){
                temp[p.x][p.y] = 'Q';
            }
            res.push_back(temp);
        }
        return res;
    }
};
*/

// 为了提高效率，引入哈希
class Solution {
private:
    struct Point{
        int x;
        int y;
    };
    vector<vector<Point>> total;
    // 引入列的哈希，斜线上的哈希
    unordered_set<int> hashCols, hashSlash1, hashSlash2;
public:
    bool isValid(Point p){
        // 判断是否有同列的
        // 判断是否有同斜线的
        if(hashCols.find(p.y) != hashCols.end()) return false;
        if(hashSlash1.find(p.x+p.y) != hashSlash1.end()) return false;
        if(hashSlash2.find(p.x-p.y) != hashSlash2.end()) return false;
        return true;
    }

    void dfs(int n, vector<Point>& path){
        int x = path.size();
        // cout << x << endl;
        if(x == n) {
            total.push_back(path);
            return;
        }
        for(int j = 0; j < n; j++){
            if(isValid({x, j})){
                path.push_back({x, j});
                hashCols.insert(j);
                hashSlash1.insert(x+j);
                hashSlash2.insert(x-j);
                dfs(n, path);
                hashCols.erase(j);
                hashSlash1.erase(x+j);
                hashSlash2.erase(x-j);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<Point> path;
        dfs(n, path);
        // 先不用vector<vector<string>>存
        vector<vector<string>> res;
        string dotstring = "";
        for(int i = 0; i < n; i++) dotstring.append(".");
        for(auto t : total){
            vector<string> temp (n, dotstring);
            for(auto p : t){
                temp[p.x][p.y] = 'Q';
            }
            res.push_back(temp);
        }
        return res;
    }
};