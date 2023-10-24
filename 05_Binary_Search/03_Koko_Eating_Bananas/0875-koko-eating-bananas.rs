/*
Problem: LeetCode 875 - Koko Eating Bananas

Key Idea:
The key idea is to use binary search on the possible days. Calculate the mid-point of the search range as the number of days, then check if it's possible for the workers to finish the bananas in those days. Adjust the search range based on the result until you find the minimum possible number of days.

Approach:
1. Define a binary search range for the possible speeds.
   - Initialize `left` to 1 (minimum possible speed) and `right` to the maximum pile size.
2. Perform a binary search on the speed range:
   a. Calculate the middle speed as `mid` = (left + right) / 2.
   b. For each pile of bananas, calculate the time required to eat it completely at speed `mid`.
      - Time = (pile[i] + mid - 1) / mid
   c. Sum up the times for all piles to get the total time required.
   d. If the total time is less than or equal to `H` (maximum allowed time), reduce the speed by setting `right` = `mid`.
   e. If the total time exceeds `H`, increase the speed by setting `left` = `mid + 1`.
3. Return the minimum speed `left` after the binary search.

Time Complexity:
- Binary search takes O(log(max pile size)) time.
- Calculating the total time for all piles takes O(n) time.
- Overall time complexity is O(n * log(max pile size)).

Space Complexity:
- The space complexity is O(1) as we are using a constant amount of extra space.
*/

impl Solution {
    pub fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32 {
        let mut left = 1;
        let mut right = *piles.iter().max().unwrap();

        while left < right {
            let mid = left + (right - left) / 2;
            let total_time = piles
                .iter()
                .map(|&pile| (pile + mid - 1) / mid)
                .sum::<i32>();

            if total_time <= h {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        left
    }
}
