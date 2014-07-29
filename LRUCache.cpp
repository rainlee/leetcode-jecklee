/***
 * hash + list
 * Ϊ��ʹ���ҡ������ɾ�����нϸߵ����ܣ�����ʹ��һ��˫������(std::list) ��һ����ϣ��(std::unordered_map)
 * Խ��������ͷ������ʾ�ڵ��ϴη��ʾ�������ʱ����̣�β���Ľڵ��ʾ�����������
 * get���ʽڵ�ʱ������ڵ���ڣ��Ѹýڵ㽻��������ͷ����ͬʱ����hash���иýڵ�ĵ�ַ
 * set����ڵ�ʱ�����cache��size�ﵽ������capacity����ɾ��β���ڵ㣬ͬʱҪ��hash����ɾ����Ӧ����½ڵ��������ͷ��
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