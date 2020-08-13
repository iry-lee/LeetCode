class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> dataflow;
    // 这个是不是适合用堆排序
    // 每次新加入的点放在叶子节点上，然后再根据情况移动位置
    // 但是堆排序对于找中位数是不是不好用？
    // 不然搞两个堆？一个大顶堆一个小顶堆，且小顶堆的最小值大于大顶堆的最大值，
    // 两者堆中数据量，当总数据量为偶数的时候两个堆数据量相等，如果为基数大顶堆多一个
    MedianFinder() {

    }
    
    void addNum(int num) {

    }
    
    double findMedian() {

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */