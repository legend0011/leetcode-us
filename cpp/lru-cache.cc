// https://leetcode.com/problems/lru-cache/description/
// chi zhang, 2017-10-19

struct Node {
    int key;
    int val;
    Node* pre;
    Node* next;
    
    Node(int the_key, int the_value) {
        key = the_key;
        val = the_value;
        pre = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        // Init list
        head_.reset(new Node(0, 0));
        tail_.reset(new Node(0, 0));
        head_->next = tail_.get();
        tail_->pre = head_.get();
    }
    ~LRUCache() {
        for (auto& item : cache_) {
            delete item.second;
        }
    }
    int get(int key) {
        if (cache_.find(key) != cache_.end()) {
            Node* node = cache_[key];
            RemoveNode(node);
            InsertHead(node);
            return node->val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (cache_.find(key) != cache_.end()) {
            Node* node = cache_[key];
            RemoveNode(node);
            InsertHead(node);
            node->val = value;
            return;
        }
        if (cache_.size() == capacity_) {
            Node* node = tail_->pre;
            RemoveNode(node);
            cache_.erase(node->key);
            delete node; 
        }
        Node* node = new Node(key, value);
        cache_[key] = node;
        InsertHead(node);
    }
private:
    void RemoveNode(Node* node) {
        Node* pre = node->pre;
        Node* next = node->next;
        pre->next = next;
        next->pre = pre;
        node->next = nullptr;
        node->pre = nullptr;
    }
    void InsertHead(Node* node) {
        Node* next = head_->next;
        node->next = next;
        next->pre = node;
        head_->next = node;
        node->pre = head_.get();
    }
    unordered_map<int, Node*> cache_;
    unique_ptr<Node> head_;
    unique_ptr<Node> tail_;
    int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
