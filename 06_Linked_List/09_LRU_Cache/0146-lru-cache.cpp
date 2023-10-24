/*
Problem: LeetCode 146 - LRU Cache

Description:
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:
- LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
- int get(int key) Return the value of the key if the key exists, otherwise return -1.
- void put(int key, int value) Update the value of the key if the key exists.
  Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation,
  evict the least recently used key.

Intuition:
To efficiently implement an LRU cache, we can use a combination of a hashmap and a doubly linked list.
The hashmap will store the key-value pairs, and the doubly linked list will maintain the order of the elements based on their usage.

Approach:
1. We use a hashmap to store the key-value pairs for quick access.
2. We use a doubly linked list to maintain the order of the elements based on their usage.
3. When getting a value from the cache, we first check if the key exists in the hashmap.
   If it does, we update the usage order in the doubly linked list by moving the corresponding node to the front (most recently used).
4. When putting a key-value pair into the cache, we check if the key already exists in the hashmap.
   If it does, we update the value and move the corresponding node to the front (most recently used).
   If it doesn't, we add a new node to the front of the doubly linked list and update the hashmap.
   If the number of keys exceeds the capacity, we remove the least recently used node from the back of the doubly linked list
   and also remove the corresponding key from the hashmap.

Time Complexity:
Both get and put operations have a time complexity of O(1) since all operations (insert, delete, and access) on the doubly linked list are constant time.

Space Complexity:
The space complexity is O(capacity) to store the key-value pairs and doubly linked list nodes.
*/

class LRUCache {
  private:
    // Structure to represent a doubly linked list node
    struct ListNode {
        int key;         // The key of the cache item
        int value;       // The value of the cache item
        ListNode *prev;  // Pointer to the previous node in the list
        ListNode *next;  // Pointer to the next node in the list

        ListNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;                     // Maximum capacity of the LRUCache
    unordered_map<int, ListNode *> hashmap; // Hashmap to store key-node mappings
    ListNode *head;                   // Dummy head node for the doubly linked list
    ListNode *tail;                   // Dummy tail node for the doubly linked list

    // Helper function to add a node to the front of the linked list
    void addToFront(ListNode *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Helper function to remove a node from the linked list
    void removeFromList(ListNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

  public:
    // Constructor to initialize the LRUCache with a given capacity
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new ListNode(-1, -1); // Initialize dummy head with key and value -1
        tail = new ListNode(-1, -1); // Initialize dummy tail with key and value -1
        head->next = tail;           // Connect head to tail initially (empty list)
        tail->prev = head;           // Connect tail to head initially (empty list)
    }

    // Function to get the value of the given key from the cache
    int get(int key) {
        if (hashmap.find(key) != hashmap.end()) {
            ListNode *node = hashmap[key];
            removeFromList(node); // Move the accessed node to the front
            addToFront(node);
            return node->value;   // Return the value associated with the key
        }

        return -1; // Key not found, return -1
    }

    // Function to put a key-value pair in the cache
    void put(int key, int value) {
        if (hashmap.find(key) != hashmap.end()) {
            ListNode *node = hashmap[key];
            removeFromList(node);  // Remove the existing node from the list
            node->value = value;   // Update the value
            addToFront(node);      // Move the updated node to the front
        } else {
            if (hashmap.size() >= capacity) {
                ListNode *removedNode = tail->prev;
                removeFromList(removedNode); // Remove the last node (least recently used)
                hashmap.erase(removedNode->key); // Remove the key from the hashmap
                delete removedNode; // Free the memory of the removed node
            }

            ListNode *newNode = new ListNode(key, value); // Create a new node for the key-value pair
            addToFront(newNode); // Add the new node to the front of the list
            hashmap[key] = newNode; // Add the key-node mapping to the hashmap
        }
    }

    // Destructor to properly deallocate memory for the ListNode objects
    ~LRUCache() {
        ListNode *curr = head;

        while (curr) {
            ListNode *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};