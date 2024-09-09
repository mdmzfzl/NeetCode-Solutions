public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        HashSet<int> uniqueNumbers = new HashSet<int>();
        foreach (int num in nums) {
            if (!uniqueNumbers.Add(num)) {
                return true;
            }
        }
        return false;
    }
}
