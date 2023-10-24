/*
Problem: LeetCode 138 - Copy List with Random Pointer

Description:
A linked list is given such that each node contains an additional random pointer that could point to any node in the list or null.
Return a deep copy of the list.

Intuition:
To create a deep copy of the given linked list, we can use a hashmap to keep track of the mapping between the original nodes and their copies. We will traverse the original list, create a copy of each node, and store the mapping in the hashmap. Then we will traverse the list again to connect the copied nodes with their corresponding random pointers.

Approach:
1. Traverse the original list, create a copy of each node, and store the mapping in the hashmap.
2. Traverse the original list again, and for each node, connect its copy with the corresponding random pointer using the hashmap.

Time Complexity:
The time complexity is O(N), where N is the number of nodes in the linked list, as we need to traverse the list twice.

Space Complexity:
The space complexity is O(N) as we use extra space to store the hashmap, where N is the number of nodes in the linked list.
*/

class Solution {
  public:
    Node *copyRandomList(Node *head) {
        if (!head) {
            return nullptr;
        }

        unordered_map<Node *, Node *> nodeMap;
        Node *current = head;

        // Traverse the original list and create a copy of each node
        while (current) {
            nodeMap[current] = new Node(current->val);
            current = current->next;
        }

        current = head;

        // Traverse the original list again to connect the copied nodes with their random pointers
        while (current) {
            nodeMap[current]->next = nodeMap[current->next];
            nodeMap[current]->random = nodeMap[current->random];
            current = current->next;
        }

        return nodeMap[head];
    }
};