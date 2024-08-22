class LRUCache {
public:
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    unordered_map<int, Node*> cache;
    Node *head, *tail;

    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node *node = cache[key];
        moveToFront(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node *existingNode = cache[key];
            existingNode->val = value;
            moveToFront(existingNode);
        } else {
            if (cache.size() == capacity) {
                Node *lruNode = tail->prev;
                remove(lruNode);
                delete lruNode;
            }
            Node *newNode = new Node(key, value);
            insert(newNode);
        }
    }

private:
    void remove(Node *node) {
        cache.erase(node->key);
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void insert(Node *node) {
        cache[node->key] = node;
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    void moveToFront(Node *node) {
        remove(node);
        insert(node);
    }
};
