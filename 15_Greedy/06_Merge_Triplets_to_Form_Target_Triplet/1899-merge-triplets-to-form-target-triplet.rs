/*
Problem: LeetCode 1899 - Merge Triplets to Form Target Triplet

Key Idea:
The key idea is to iterate through the triplets and check if they can be combined to form the target triplet.

Approach:
1. Initialize three boolean variables 'exists_x', 'exists_y', and 'exists_z' to track whether each component (x, y, and z) exists in any valid triplet.
2. Initialize an empty vector 'valid_triplets' to store valid triplets that satisfy the conditions.
3. Iterate through the triplets:
   - For each triplet (a, b, c), if a <= target_x, b <= target_y, and c <= target_z, add the triplet to 'valid_triplets'.
   - While iterating, if a == target_x, set 'exists_x' to true. If b == target_y, set 'exists_y' to true. If c == target_z, set 'exists_z' to true.
4. After iterating through all triplets, check if 'exists_x', 'exists_y', and 'exists_z' are all true, indicating that each component exists in at least one valid triplet.
5. Also, check if 'valid_triplets' is not empty, as this confirms that there are valid triplets satisfying the conditions.
6. If both conditions are met, return true; otherwise, return false.

Time Complexity:
O(n), where n is the number of triplets. We perform a single pass through the triplets.

Space Complexity:
O(n), as the 'valid_triplets' vector can potentially store all valid triplets.
*/

impl Solution {
    pub fn merge_triplets(triplets: Vec<Vec<i32>>, target: Vec<i32>) -> bool {
        let (target_x, target_y, target_z) = (target[0], target[1], target[2]);
        let mut exists = [false; 3];
        let mut valid_triplets = vec![];

        for triplet in triplets {
            let (x, y, z) = (triplet[0], triplet[1], triplet[2]);

            if x <= target_x && y <= target_y && z <= target_z {
                if x == target_x {
                    exists[0] = true;
                }
                if y == target_y {
                    exists[1] = true;
                }
                if z == target_z {
                    exists[2] = true;
                }
                valid_triplets.push(triplet);
            }
        }

        exists.iter().all(|&e| e) && !valid_triplets.is_empty()
    }
}
