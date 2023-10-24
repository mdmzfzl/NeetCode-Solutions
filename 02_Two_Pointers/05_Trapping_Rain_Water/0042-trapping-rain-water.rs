/*
Problem: LeetCode 42 - Trapping Rain Water

Key Idea:
The key idea is to calculate the amount of trapped rainwater at each position by finding the maximum height on the left and right sides.

Approach:
1. Create two arrays, `max_left` and `max_right`, to store the maximum height on the left and right sides of each position.
2. Iterate through the input array and fill the `max_left` array:
   - For each position `i`, the maximum height on the left is the maximum of `max_left[i-1]` and the height at position `i-1`.
3. Iterate through the input array in reverse and fill the `max_right` array:
   - For each position `i`, the maximum height on the right is the maximum of `max_right[i+1]` and the height at position `i+1`.
4. Iterate through the input array and calculate the trapped rainwater at each position:
   - The trapped rainwater at position `i` is the minimum of `max_left[i]` and `max_right[i]` minus the height at position `i`.
5. Sum up the trapped rainwater from step 4 to obtain the total trapped rainwater.

Time Complexity:
O(n), where n is the number of elements in the input array. We perform three passes through the array to fill the `max_left`, `max_right`, and calculate the trapped rainwater.

Space Complexity:
O(n), as we use two additional arrays of size n to store the `max_left` and `max_right` values.
*/

impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let n = height.len();
        if n == 0 {
            return 0;
        }

        let mut max_left = vec![0; n];
        let mut max_right = vec![0; n];

        max_left[0] = height[0];
        for i in 1..n {
            max_left[i] = max_left[i - 1].max(height[i]);
        }

        max_right[n - 1] = height[n - 1];
        for i in (0..n - 1).rev() {
            max_right[i] = max_right[i + 1].max(height[i]);
        }

        let mut trapped_water = 0;
        for i in 0..n {
            trapped_water += (max_left[i].min(max_right[i]) - height[i]) as i32;
        }

        trapped_water
    }
}
