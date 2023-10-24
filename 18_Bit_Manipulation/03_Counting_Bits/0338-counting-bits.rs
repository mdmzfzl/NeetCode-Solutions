/*
Problem: LeetCode 338 - Counting Bits

Key Idea:
The key idea is to use dynamic programming to count the number of set bits (1s) in the binary representation of each number from 0 to the given number 'num'. We can observe certain patterns to optimize this process.

Approach:
1. Initialize a vector 'count' of size 'num + 1' to store the count of set bits for each number from 0 to 'num'.
2. For the base case, set 'count[0] = 0' since the count of set bits for 0 is 0.
3. Iterate through the numbers from 1 to 'num'.
4. To find the count of set bits for a number 'i', we can utilize the result for 'i / 2' (right-shifting by one position) and add 1 if 'i' is odd (i.e., 'i & 1 == 1').
5. Store the result in 'count[i]'.
6. After the loop, 'count' will contain the count of set bits for all numbers from 0 to 'num'.
7. Return 'count' as the result.

Time Complexity:
O(num), where 'num' is the given input number. We iterate through all numbers from 1 to 'num'.

Space Complexity:
O(num), as we use a vector of size 'num + 1' to store the count of set bits for each number.
*/

impl Solution {
    pub fn count_bits(num: i32) -> Vec<i32> {
        let mut count = vec![0; (num + 1) as usize];

        for i in 1..=num {
            count[i as usize] = count[(i / 2) as usize] + (i & 1);
        }

        count
    }
}

/*
impl Solution {
    pub fn count_bits(n: i32) -> Vec<i32> {
        let mut result:Vec<i32> = Vec::new();
        for i in 0..n+1 {
            result.push(i.count_ones() as i32);
        }
        result
    }
}
*/
