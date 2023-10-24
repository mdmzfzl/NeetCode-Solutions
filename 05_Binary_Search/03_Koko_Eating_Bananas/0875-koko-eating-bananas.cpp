/*
Problem: LeetCode 875 - Koko Eating Bananas

Description:
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards come back.
Return the minimum integer k such that she can eat all the bananas within h hours.

Intuition:
To find the minimum eating speed that allows Koko to eat all the bananas within h hours, we can use binary search. By defining the search space and adjusting the speed based on the time taken to eat bananas, we can find the optimal speed.

Approach:
1. Set the left and right pointers to 1 and the maximum number of bananas in piles, respectively.
2. While the left pointer is less than the right pointer:
   - Calculate the middle value as (left + right) / 2, which represents the eating speed.
   - Initialize the total hours as 0.
   - Iterate through each pile of bananas:
     - Calculate the time taken to eat the pile as ceil(piles[i] / (double)middle), which represents the number of hours needed to eat the bananas in the pile.
     - Add the time taken to the total hours.
   - If the total hours is less than or equal to h, update the right pointer to middle to search for a lower eating speed.
   - If the total hours is greater than h, update the left pointer to middle + 1 to search for a higher eating speed.
3. Return the left pointer, which represents the minimum eating speed.

Time Complexity:
The time complexity is O(n log m), where n is the number of piles of bananas and m is the maximum number of bananas in piles. Binary search is performed on the search space of eating speeds.

Space Complexity:
The space complexity is O(1), as the algorithm uses a constant amount of extra space.
*/

#include <cmath>

class Solution {
  public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int middle = left + (right - left) / 2;
            int totalHours = 0;

            for (int bananas : piles) {
                // handling integer overflow by using ceil to round up the division result
                // and ensuring the result is accurate by casting bananas to double before performing division
                totalHours += ceil(static_cast<double>(bananas) / middle);
            }

            if (totalHours <= h) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }

        return left;
    }
};

/*
class Solution {
public:
    // Helper function to check if a given eating speed works within the given time constraint
    bool isSpeedFeasible(vector<int>& piles, int k, int h) {
        double hours = 0;
        for (int bananas : piles) {
            hours += ceil(static_cast<double>(bananas) / k);
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int bestSpeed = end;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isSpeedFeasible(piles, mid, h)) {
                bestSpeed = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return bestSpeed;
    }
};
*/