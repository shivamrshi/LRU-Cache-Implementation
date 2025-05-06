
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            removeNode(node);
            insertAtHead(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            insertAtHead(node);
        } else {
            if (cache.size() == capacity) {
                Node* lru = tail->prev;
                removeNode(lru);
                cache.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insertAtHead(newNode);
        }
    }

    ~LRUCache() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LRUCache cache(3);
    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);
    cout << "Get 2: " << cache.get(2) << endl;
    cache.put(4, 40); // evicts key 1
    cout << "Get 1 (should be -1): " << cache.get(1) << endl;
    cout << "Get 3: " << cache.get(3) << endl;
    return 0;
}
