/*
Problem: LeetCode 202 - Happy Number

Key Idea:
The key idea is to use two pointers, one slow and one fast, to determine if the sequence of numbers ends in a cycle. If the sequence ends in a cycle, it means the number is not a happy number.

Approach:
1. Define a function 'get_next' that calculates the sum of the squares of the digits of a number.
2. Initialize two variables, 'slow' and 'fast', to the given number.
3. Use a loop to repeatedly calculate the next number using 'get_next' for both 'slow' and 'fast'.
4. In each iteration, move 'slow' one step and 'fast' two steps.
5. If 'slow' and 'fast' become equal at any point, break the loop as this indicates a cycle.
6. Check if 'slow' is equal to 1. If it is, return true as the number is a happy number.
7. If the loop completes without finding a cycle and 'slow' is not equal to 1, return false as the number is not a happy number.

Time Complexity:
O(log n), where 'n' is the given number. The time complexity is determined by the number of digits in the input number.

Space Complexity:
O(1), as we are using only a constant amount of extra space.
*/

impl Solution {
    pub fn is_happy(n: i32) -> bool {
        fn get_next(n: i32) -> i32 {
            let mut sum = 0;
            let mut n = n;
            while n > 0 {
                let digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            sum
        }

        let mut slow = n;
        let mut fast = n;

        loop {
            slow = get_next(slow);
            fast = get_next(get_next(fast));

            if slow == fast {
                break;
            }
        }

        slow == 1
    }
}

/*
impl Solution {
    pub fn is_happy(n: i32) -> bool {
        let mut n = n;
        while n != 1 && n != 4 {
            let mut sum = 0;
            while n > 0 {
                let d = n % 10;
                sum += d * d;
                n /= 10;
            }
            n = sum;
        }
        n == 1
    }
}
*/
