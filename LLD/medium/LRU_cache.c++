#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
    public:
    int data;
    int val;
    Node* next;
    Node* prev;

    public:
    Node(int data, int val) {
        this->data = data;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
    private:
        int capacity;
        unordered_map<int, Node*> cache;
        Node* head;
        Node* tail;

    public:
        LRUCache(int capacity) {
            this->capacity = capacity;
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
        }

        void deleteNode(Node* node) {
            Node* prev = node->prev;
            Node* next = node->next;
            prev->next = next;
            next->prev = prev;
        }

        void addNode(Node* node) {
            Node* temp = head ->next;;
            node ->next = temp;
            node->prev = head;

            head -> next = node;
            temp->prev = node;
        }

        int get(int key) {
            if(cache.find(key) != cache.end()) {
                Node* resNode = cache[key];
                int ans = resNode->val;
                deleteNode(resNode);
                addNode(resNode);
                return ans;
            }

            return -1;
        }

        void put(int key, int val) {
            if(cache.find(key) != cache.end()) {
                deleteNode(cache[key]);
                cache.erase(key);
            }

            if(cache.size() == capacity) {
                cache.erase(tail->prev->data);
                deleteNode(tail->prev);
            }

            Node* newNode = new Node(key, val);
            addNode(newNode);
            cache[key] = head->next;
        }
};

int main() {
    cout << "LRU Cache" << endl;

    LRUCache* lruCache = new LRUCache(2);

    lruCache->put(1, 1);
    lruCache->put(2,2);
    cout << lruCache->get(1) << endl;
    lruCache->put(3,3);
    cout << lruCache->get(2) << endl;
    lruCache->put(4,4);
    cout << lruCache->get(1) << endl;
    cout << lruCache->get(3) << endl;
    cout << lruCache->get(4) << endl;

    return 0;
}