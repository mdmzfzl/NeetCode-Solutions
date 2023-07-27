/*
Problem: LeetCode 2013 - Detect Squares

Intuition:
Precompute the count of points in each row and column and then use this information to find the other three points of the square.

Approach:
1. We use two unordered maps "rowMap" and "colMap" to keep track of the count of points in each row and column, respectively.
2. When we add a new point (x, y), we increment its count in both "rowMap" and "colMap" accordingly.
3. To count the number of squares with a given point (x, y) as the bottom-right corner, we look for other points in the same row "x."
4. For each point found at column "col" in row "x," we calculate the edge length of the potential square. Let's call it "edgeLen," which is the absolute difference between "col" and "y."
5. Then, we check if the points (x - edgeLen, col), (x + edgeLen, col), and (x + edgeLen, y) exist in the maps. If they do, we have found a square with (x, y) as the bottom-right corner.
6. We repeat this process for all points in row "x" to find all squares with (x, y) as the bottom-right corner.
7. Finally, we sum up the counts of all these squares to get the total number of squares with (x, y) as the bottom-right corner.
8. The process is efficient as we use unordered maps to store the counts, making the lookups quick and allowing us to count squares in constant time.

Time Complexity:
The time complexity of this approach is O(1) for `add` and O(n) for `count` (where "n" is the average number of points in the same row as the given point).

Space Complexity:
The space complexity is O(N) (where "N" is the total number of points added).
*/

class DetectSquares {
  public:
    // We maintain two maps for row and column coordinates to store the count of points in each row and column.
    vector<unordered_map<int, int>> rowMap;
    vector<unordered_map<int, int>> colMap;

    DetectSquares() : rowMap(1001), colMap(1001) {
        // Constructor to initialize the rowMap and colMap with size 1001.
    }

    // Function to add a point to the grid.
    void add(vector<int> point) {
        // Increment the count of points in the corresponding row and column maps.
        rowMap[point[0]][point[1]]++;
        colMap[point[1]][point[0]]++;
    }

    // Function to count the number of squares that can be formed with a given point as the bottom-right corner.
    int count(vector<int> point) {
        int result = 0;

        // Iterate through the row map for the given point's row.
        for (auto [col, cCount] : rowMap[point[0]]) {
            int edgeLen = abs(col - point[1]);

            if (edgeLen == 0) {
                continue;    // Skip points that are at the same position as the given point.
            }

            // Calculate the row coordinates for the other two points of the square based on the edge length.
            int row = point[0] - edgeLen;

            if (colMap[col].find(row) != colMap[col].end()) {
                auto rCount = colMap[col][row];

                // Check if the other two points exist in the colMap.
                if (colMap[point[1]].find(row) != colMap[point[1]].end()) {
                    // If so, update the result by multiplying the counts of the four points.
                    result += (rCount * cCount * colMap[point[1]][row]);
                }
            }

            row = point[0] + edgeLen;

            if (colMap[col].find(row) != colMap[col].end()) {
                auto rCount = colMap[col][row];

                // Check if the other two points exist in the colMap.
                if (colMap[point[1]].find(row) != colMap[point[1]].end()) {
                    // If so, update the result by multiplying the counts of the four points.
                    result += (rCount * cCount * colMap[point[1]][row]);
                }
            }
        }

        return result;
    }
};