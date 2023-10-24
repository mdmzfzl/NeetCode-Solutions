/*
Problem: LeetCode 287 - Find the Duplicate Number

Description:
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
prove that at least one duplicate number must exist in the array.
Assume that there is only one duplicate number, find the duplicate one.

Intuition:
To find the duplicate number, we can use the concept of cycle detection in a linked list.
Since the numbers in the array are between 1 and n, we can treat the array as a linked list,
where each element points to the value at its index.
If there is a duplicate number, it means there is a cycle in the linked list.

Approach:
1. Use the two-pointer technique to detect the cycle in the array.
2. Initialize slow and fast pointers to the first element (index 0) of the array.
3. Move the slow pointer one step at a time and the fast pointer two steps at a time.
4. When the two pointers meet, reset one of the pointers to the first element (index 0).
5. Move both pointers one step at a time until they meet again. The meeting point is the duplicate number.

Time Complexity:
The time complexity is O(n), where n is the length of the array.
The loop to detect the cycle takes at most n steps.

Space Complexity:
The space complexity is O(1) since we are not using any additional data structures.

Note:
The given array is assumed to have at least one duplicate number, and the duplicate number will always exist.
*/

class Solution {
  public:
    int findDuplicate(vector<int> &nums) {
        int slow = nums[0];     // Tortoise
        int fast = nums[0];     // Hare

        // Step 1: Detect the cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Step 2: Find the entrance to the cycle (duplicate number)
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};