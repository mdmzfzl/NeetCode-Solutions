public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        if (strs == null || strs.Length == 0) return new List<IList<string>>();
        
        var groups = new Dictionary<string, List<string>>();
        
        foreach (string s in strs) {
            string key = SortString(s);
            if (!groups.ContainsKey(key)) groups[key] = new List<string>();
            groups[key].Add(s);
        }
        
        return new List<IList<string>>(groups.Values);
    }

    private string SortString(string s) {
        char[] arr = s.ToCharArray();
        Array.Sort(arr);
        return new string(arr);
    }
}
