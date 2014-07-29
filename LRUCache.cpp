/***
 * hash + list
 * 为了使查找、插入和删除都有较高的性能，我们使用一个双向链表(std::list) 和一个哈希表(std::unordered_map)
 * 越靠近链表头部，表示节点上次访问距离现在时间最短，尾部的节点表示最近访问最少
 * get访问节点时，如果节点存在，把该节点交换到链表头部，同时更新hash表中该节点的地址
 * set插入节点时，如果cache的size达到了上限capacity，则删除尾部节点，同时要在hash表中删除对应的项；新节点插入链表头部
 ***/
class LRUCache{
private:
    struct CacheNode
    {
        int key;
        int value;
        CacheNode(int k, int v): key(k), value(v) {}
    };
public:
    // construct
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    // get the cachenode, and reorder the nodes
    // return -1, if failed
    int get(int key) {
        if (mcache.find(key) == mcache.end())
            return -1;
        
        lcache.splice(lcache.begin(), lcache, mcache[key]);  // move to head
        mcache[key] = lcache.begin();   // update map
        return mcache[key]->value;      // get value
    }
    
    // set the cachenode, and move the node to head
    // if not exist, create a new node
    void set(int key, int value) {
        if (mcache.find(key) == mcache.end())  // create a new node
        {
            if (lcache.size() == capacity)  // no more space, delete the tail
            {
                mcache.erase(lcache.back().key);  // delete map node
                lcache.pop_back();                // delete list node
            }
            lcache.push_front(CacheNode(key, value));  // add list node
            mcache[key] = lcache.begin();              // add map node
        }
        else
        {
            mcache[key]->value = value;    // update node value
            lcache.splice(lcache.begin(), lcache, mcache[key]);  // move to head
            mcache[key] = lcache.begin();  // update map
        }
        return;
    }
private:
    int capacity;            // max size
    list<CacheNode> lcache;  // cache list
    unordered_map<int, list<CacheNode>::iterator> mcache;  // key-value, cache map
};