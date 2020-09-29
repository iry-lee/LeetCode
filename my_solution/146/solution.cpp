/**
 * 缓存的映射使用哈希，使用key映射哈希表的key，并且在哈希表中存储value和其在链表中的位置
 * 用链表来维持数据先来后到顺序：从链表头到尾，标志着最后一次使用时间从近到远，具体来说：
 * 1. 每次使用一个已经在缓存中的数据的时候，就对应到其在链表中的位置，将该数据从链表上取下来，放到链头。
 * 2. 如果时要插入一个新的数据，如果缓存已经填满，就从list尾部拿掉一个数据，并把当前数据放到链表头。
 *
 */
struct Node{
    int value;
    int key;
    Node * nextNode;
    Node * preNode;
};

class LRUCache {    
public:
    unordered_map<int, Node*> cache;
    int CACHE_SIZE = 0;
    int count = 0;
    Node *head = nullptr;
    Node *tail = nullptr;

    LRUCache(int capacity) {
        CACHE_SIZE = capacity;
        head = (Node*)malloc(sizeof(Node));
        tail = (Node*)malloc(sizeof(Node));
        head->nextNode = tail;
        head->preNode = nullptr;
        tail->nextNode = nullptr;
        tail->preNode = head;
    }

    void removeNode(Node *node){
        Node *pre = node->preNode;
        Node *next = node->nextNode;
        pre->nextNode = next;
        next->preNode = pre;
    }
    
    void insertAfterHead(Node *node){
        if(head->nextNode == node) return;
        Node *next = head->nextNode;
        head->nextNode = node;
        node->nextNode = next;
        next->preNode = node;
        node->preNode = head;
    }

    void removeTail(){
        Node *node = tail->preNode;
        Node *pre = node->preNode;
        pre->nextNode = tail;
        tail->preNode = pre;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        else{
            // 把其在链表中的位置提前，并返回值
            Node *node = cache[key];
            removeNode(node);
            insertAfterHead(node);
            return node->value;
        }
    }
    
    void put(int key, int value) {
        // 如果关键字存在，则变更其值，并且移到前方
        if(cache.find(key) != cache.end()){
            Node *temp_node = cache[key];
            temp_node->value = value;
            removeNode(temp_node);
            insertAfterHead(temp_node);  // 移动到前方之前记得先将其从原位置摘下来
            return; 
        }
        // 如果关键字不存在，则着手向内存中插入新的数据
        if(count == CACHE_SIZE){
            int tail_key = tail->preNode->key;
            removeTail();
            // 这里erase应该是按照key删除
            cache.erase(tail_key);
        }
        else count++;
        // 建立该节点
        Node *node = (Node*)malloc(sizeof(Node));
        node->value = value;
        node->key = key;
        insertAfterHead(node);
        // 存入哈希表中
        cache[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */