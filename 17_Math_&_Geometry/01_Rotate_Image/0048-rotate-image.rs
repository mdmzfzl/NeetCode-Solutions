/*
Problem: LeetCode 48 - Rotate Image

Key Idea:
The key idea is to perform a series of swaps and rotations to rotate the given square matrix in-place.

Approach:
1. Initialize variables 'n' to the size of the matrix (number of rows or columns) and 'layer' to 0.
2. Use a loop to iterate through each layer from the outermost layer to the innermost layer (if any).
3. Within each layer, use a nested loop to iterate through the elements in the layer:
   a. Swap the four elements in a cycle (top, left, bottom, right).
   b. Repeat this process for all elements in the layer except for the corners.
4. Increment 'layer' and repeat the process until all layers have been rotated.
5. The matrix is now rotated 90 degrees clockwise in-place.

Time Complexity:
O(n^2), where 'n' is the size of the matrix. We need to touch each element once to perform the rotations.

Space Complexity:
O(1), as we perform the rotations in-place without using any extra space.
*/

impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        let n = matrix.len();
        let mut layer = 0;

        while layer < n / 2 {
            for i in layer..n - layer - 1 {
                let top = matrix[layer][i];
                let left = matrix[n - i - 1][layer];
                let bottom = matrix[n - layer - 1][n - i - 1];
                let right = matrix[i][n - layer - 1];

                matrix[layer][i] = left;
                matrix[n - i - 1][layer] = bottom;
                matrix[n - layer - 1][n - i - 1] = right;
                matrix[i][n - layer - 1] = top;
            }

            layer += 1;
        }
    }
}

/*
impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        let n = matrix.len();

        for i in 0..n {
            for j in i+1..n {
                matrix.swap(i, j, j, i);
            }
        }

        for row in matrix.iter_mut() {
            row.reverse();
        }
    }
}

trait MatrixSwap {
    fn swap(&mut self, i1: usize, j1: usize, i2: usize, j2: usize);
}

impl MatrixSwap for Vec<Vec<i32>> {
    fn swap(&mut self, i1: usize, j1: usize, i2: usize, j2: usize) {
        let tmp = self[i1][j1];
        self[i1][j1] = self[i2][j2];
        self[i2][j2] = tmp;
    }
}
*/
