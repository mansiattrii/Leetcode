class LRUCache {
public:
    //we use a linked list to maintain the order of LRU. The node at the end of the list is the least recently used one.
    class Node{
        public:
        int key, val;
        Node* next;
        Node* prev;
        Node(int key1, int val1){
            key = key1;
            val = val1;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;
    unordered_map<int, Node*> mpp;
    //a new node is always added at the beginning of the list, i.e. the end of the list contains the least recently used key and its value.
    //Add using head.
    //Delete using tail.
    void addNode(int key, int value){
        Node* newNode = new Node(key, value);
        newNode -> next = head -> next;
        head -> next = newNode;
        newNode -> prev = head;
        newNode -> next -> prev = newNode;
    }
    void deleteNode(Node* node){
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        delete(node);
    }

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end())
        {
            Node* node = mpp[key];
            int vals = node -> val;
            deleteNode(node);
            addNode(key, vals);
            mpp[key] = head -> next;
            return vals;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            deleteNode(node);
            addNode(key, value);
            mpp[key] = head -> next;
            return;
        }    
        if(mpp.size() == cap){
            int k = tail -> prev -> key;
            deleteNode(tail -> prev);
            mpp.erase(k);
        }   
        addNode(key, value);
        mpp[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */