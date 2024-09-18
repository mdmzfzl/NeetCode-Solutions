public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        int n = nums.Length, leftProduct = 1, rightProduct = 1;
        int[] result = new int[n];
        
        for (int i = 0; i < n; i++) {
            result[i] = leftProduct;
            leftProduct = leftProduct * nums[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            result[i] = result[i] * rightProduct;
            rightProduct = rightProduct * nums[i];
        }

        return result;
    }
}
