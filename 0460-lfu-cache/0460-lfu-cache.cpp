class LFUCache {
public:
    class Node{
        public:
        int key, value, cnt;
        Node* next;
        Node* prev;
        
        Node(int key1, int value1){
            key = key1;
            value = value1;
            cnt = 1;
        }
    };
    
    //each list consists of nodes for a certain frequency. the size is used to keep track of number of elements of that frequency.
    class List{
        public:
        int size;
        Node* head;
        Node* tail;

        List(){
            size = 0;
            head = new Node(0,0);
            tail = new Node(0,0);
            head -> next = tail;
            tail -> prev = head;
        }

        void addNode(Node* node){
            size++;
            Node* temp = head -> next;
            head -> next = node;
            temp -> prev = node;
            node -> next = temp;
            node -> prev = head;
        }

        void removeNode(Node* node){
            node -> prev -> next = node -> next;
            node -> next -> prev = node -> prev;;
            size--;
        }
    };

    /* We use two maps (unordered for O(1) lookup):
            1. keyMap for storing key and value.
            2. freqMap for storing freq -> lru list. */

    unordered_map<int, Node*> keyMap;
    unordered_map<int, List*> freqMap;
    int cap;
    int minFreq;
    int currSize;
    
    LFUCache(int capacity) {
        cap = capacity;  
        minFreq = 0;
        currSize = 0;  
    }
    
    void updateFreq(Node* node){
        //remove the entry in keyMap and freqMap
        keyMap.erase(node -> key);
        freqMap[node -> cnt] -> removeNode(node);
        //if the minFreq doesnt contain any other elements then update it
        if(node -> cnt == minFreq && freqMap[node -> cnt] -> size == 0)
            minFreq++;
        
        //add in next freq list:
        List* highList = freqMap.find(node -> cnt + 1) != freqMap.end() ? freqMap[node -> cnt + 1] : new List();
        node -> cnt += 1;
        highList -> addNode(node);
        freqMap[node -> cnt] = highList;
        keyMap[node -> key] = node;
    }

    int get(int key) {
        //if the key exists:
        if(keyMap.find(key) != keyMap.end()){
            int val = keyMap[key] -> value;
            updateFreq(keyMap[key]);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //if key exists in cache:
        if(keyMap.find(key) != keyMap.end()){
            //update keyMap's value and freqMap's value:
            keyMap[key] -> value = value;
            updateFreq(keyMap[key]);
            return;
        }

        /*key does not exist in map:
            check for maximum capacity.
                if reached -> remove the LRU element from the current minimum frequency list    */

        if(cap == currSize){
            //remove from keyMap then update frequency list.
            keyMap.erase(freqMap[minFreq] -> tail -> prev -> key);
            freqMap[minFreq] -> removeNode(freqMap[minFreq] -> tail -> prev);
            --currSize;
        }

        //add the new node to keyMap and freqMap:
        ++currSize;
        minFreq = 1;

        //if the min freq list exists, i.e. freq = 1, then point to it else make a new list.
        List* listFreq = (freqMap.find(minFreq) != freqMap.end()) ? freqMap[minFreq] : new List();
        Node* node = new Node(key, value);
        listFreq -> addNode(node);
        keyMap[key] = node;
        freqMap[minFreq] = listFreq;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */