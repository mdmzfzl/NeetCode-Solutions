/*
Problem: LeetCode 23 - Merge k Sorted Lists

Description:
You are given an array of k linked-lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Intuition:
To merge k sorted lists, we can use a priority queue (min heap). We start by pushing the head nodes of all k linked lists into the priority queue.
Then, while the priority queue is not empty, we pop the node with the minimum value, append it to the result list, and push its next node (if exists) back into the priority queue.
This way, we always pick the smallest element to add to the result list, which ensures that the final list is sorted.

Approach:
1. Create a struct ListNode to represent the nodes of the linked list.
2. Create a custom comparator function for the priority queue to compare ListNode pointers based on their values.
3. Initialize a priority queue (min heap) using the custom comparator.
4. Push the head nodes of all k linked lists into the priority queue.
5. Initialize a dummy ListNode to build the merged list.
6. While the priority queue is not empty, pop the node with the minimum value, append it to the dummy list, and push its next node (if exists) back into the priority queue.
7. Finally, return the next node of the dummy list, which will be the head of the merged sorted list.

Time Complexity:
The overall time complexity is O(n*log(k)), where n is the total number of nodes and k is the number of linked lists.
The priority queue operations take O(log(k)) time, and we do this for all n nodes.

Space Complexity:
The space complexity is O(k), as we store the head nodes of all k linked lists in the priority queue.
*/

struct ListNodeComparator {
    bool operator()(const ListNode *a, const ListNode *b) const {
        return a->val > b->val;
    }
};

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, ListNodeComparator> pq;

        for (ListNode *head : lists) {
            if (head) {
                pq.push(head);
            }
        }

        ListNode dummy(0);
        ListNode *current = &dummy;

        while (!pq.empty()) {
            ListNode *smallest = pq.top();
            pq.pop();
            current->next = smallest;
            current = current->next;

            if (smallest->next) {
                pq.push(smallest->next);
            }
        }

        return dummy.next;
    }
};