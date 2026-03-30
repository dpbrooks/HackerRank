/*
 * Implementation of a least recently used cache using a doubly
 * linked list
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
      
    public:
        
        // Constrcutor
        LRUCache (int cap) {
            cp = cap;
        }
        
        // Helper function to move a node to the head of the cache
        void move_to_head(Node* node) {
            if (node == head) return;
            
            // Detach node from current pos
            if (node == tail) {
                tail = tail->prev;
                tail->next = NULL;
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            
            // Move to front of cache
            node->next = head;
            node->prev = NULL;
            head->prev = node;
            head = node;
        }
        
        // Set a key-value pair in the cache
        void set (int k, int v) {
            // Check if key already exists
            if (mp.find(k) != mp.end()) {
                mp[k]->value = v;
                move_to_head(mp[k]);
                return;
            }   
            // Create node of the key value pair
            Node* n = new Node(k, v);
            // Check if any nodes have been added
            if (mp.size() == 0) {
                // No nodes yet
                // Set head and tail to n since its the only node
                tail = n;
                head = n;
            } else {
                // At least one node
                // Check if cache is at capacity
                if (mp.size() >= cp) {
                    // Need to remove the least recently used data
                    Node* toDelete = tail;
                    mp.erase(toDelete->key);
                    tail = tail->prev;
                    tail->next = NULL;
                    delete toDelete;
                }
                // Set node to be the head of the cache
                n->next = head;
                head->prev = n;
                head = n;
            }
            mp[k] = n;
        }
    
        int get(int k) {
            if (mp.find(k) == mp.end()) {
                return -1;
            }
            // Move node being accessed to head of cache
            move_to_head(mp[k]);
            return mp[k]->value;
        }
};


int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
