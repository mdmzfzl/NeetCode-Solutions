public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        var indices = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++) {
            int c = target - nums[i];
            if (indices.ContainsKey(c)) {
                return new[] { indices[c], i };
            }
            indices[nums[i]] = i;
        }

        return new int[] {};
    }
}
