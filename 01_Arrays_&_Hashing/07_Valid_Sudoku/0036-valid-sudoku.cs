public class Solution {
    public bool IsValidSudoku(char[][] board) {
        var seen = new HashSet<string>();
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    string row = $"Row {i}: {c}";
                    string col = $"Col {j}: {c}";
                    string box = $"Box {i / 3}{j / 3}: {c}";

                    if (seen.Contains(row) || seen.Contains(col) || seen.Contains(box)) {
                        return false;
                    }

                    seen.Add(row); seen.Add(col); seen.Add(box);
                }
            }
        }

        return true;
    }
}
