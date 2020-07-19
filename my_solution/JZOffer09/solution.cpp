// 本题也是从LeetCode上复制下来的，在本项目搭建的环境中无法运行
class CQueue {
public:
    stack <int> sin;
    stack <int> sout;
    CQueue() {

    }

    void appendTail(int value) {
        sin.push(value);
    }

    int deleteHead() {
        if(sout.empty()){
            // 把sin里面的值全都导入sout
            if(sin.empty()) return -1;
            else{
                int number;
                while(!sin.empty()){
                    number = sin.top();
                    sin.pop();
                    sout.push(number);
                }
            }
        }
        int number = sout.top();
        sout.pop();
        return number;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */