/*
Problem: LeetCode 1899 - Merge Triplets to Form Target Triplet

Description:
A triplet is an array of three integers. You are given a 2D integer array `triplets`, where triplets[i] = [ai, bi, ci] describes the ith triplet.
You are also given an integer array `target`, where target = [x, y, z] represents the target triplet.
You want to form the target triplet by choosing three triplets from the triplets array (not necessarily distinct) and bitwise-ORing the elements of each chosen triplet.

Return true if it is possible to form the target triplet, otherwise, return false.

Intuition:
To form the target triplet [x, y, z], we must be able to select three triplets from the given triplets array such that bitwise-OR of their elements results in [x, y, z].

Approach:
1. Initialize three variables `x`, `y`, and `z` as 0.
2. Iterate through each triplet in the `triplets` array.
3. For each triplet, check if it can contribute to `x`, `y`, or `z`.
   - If the triplet's elements are greater than or equal to `x`, `y`, and `z` respectively, then the triplet can contribute to `x`, `y`, or `z`.
   - If it can contribute, update the corresponding `x`, `y`, or `z` value to the triplet's elements.
4. After iterating through all triplets, check if `x`, `y`, and `z` are equal to the target triplet elements.
5. If they are equal, return true, else return false.

Time Complexity:
The time complexity of this approach is O(n), where n is the number of triplets.

Space Complexity:
The space complexity is O(1) as we are using only a constant amount of extra space.
*/

class Solution {
  public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
        int x = 0, y = 0, z = 0;

        for (auto &t : triplets) {
            if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                x = max(x, t[0]);
                y = max(y, t[1]);
                z = max(z, t[2]);
            }
        }

        return (x == target[0] && y == target[1] && z == target[2]);
    }
};