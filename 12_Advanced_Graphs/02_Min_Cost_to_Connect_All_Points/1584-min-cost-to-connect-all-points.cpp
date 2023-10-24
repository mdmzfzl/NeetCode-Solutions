/*
Problem: LeetCode 1584 - Min Cost to Connect All Points

Description:
You are given an array points representing integer coordinates of some points on a 2D-plane,
where points[i] = [xi, yi]. The cost of connecting two points [xi, yi] and [xj, yj] is the
manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
Return the minimum cost to make all points connected. All points are connected if there is exactly
one simple path between any two points.

Intuition:
To connect all the points, we need to find the minimum spanning tree (MST) of the graph. The MST is a
subgraph that connects all vertices together with the minimum possible total edge weight.

Approach:
1. Create a graph representation using an adjacency matrix, where graph[i][j] represents the manhattan
   distance between point i and point j.
2. Use Prim's algorithm to find the MST of the graph.
3. Start the MST with an arbitrary point (let's say the first point), and keep adding the nearest
   non-visited point until all points are visited.
4. Calculate the total cost of the MST, which will be the minimum cost to connect all points.

Time Complexity:
The time complexity of Prim's algorithm is O(V^2), where V is the number of vertices (points).

Space Complexity:
The space complexity is O(V^2), where V is the number of vertices (points). We use an adjacency matrix
to represent the graph.
*/

class Solution {
  public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        int n = points.size();
        vector<bool> visited(n, false);
        vector<int> minCost(n, INT_MAX);
        // A lambda function to calculate the Manhattan distance between two points
        auto getManhattanDistance = [](const vector<int> &p1, const vector<int> &p2) {
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
        };
        int result = 0;
        minCost[0] = 0; // Start with the first point

        for (int i = 0; i < n; ++i) {
            int u = -1;

            // Find the nearest non-visited point
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (u == -1 || minCost[j] < minCost[u])) {
                    u = j;
                }
            }

            visited[u] = true;
            result += minCost[u];

            // Update the minimum cost for the remaining points
            for (int j = 0; j < n; ++j) {
                if (!visited[j]) {
                    minCost[j] = min(minCost[j], getManhattanDistance(points[u], points[j]));
                }
            }
        }

        return result;
    }
};

/*
   Lambda Function in C++:

   A lambda function, also known as an anonymous function or a lambda expression, is a compact and inline way
   to define small functions in C++. It allows you to create function objects (functors) on the fly without
   explicitly defining a named function. Lambda functions are particularly useful when you need a simple function
   that you don't want to define separately.

   The syntax for a lambda function is as follows:

   [ captures ] ( parameters ) -> return_type {
       // function body
   }

   - `captures`: This is an optional part that allows the lambda function to capture and use variables from the
     surrounding scope. It can be used to access local variables, class members, or global variables within the lambda.

   - `parameters`: These are the input parameters of the lambda function, similar to regular function parameters.

   - `return_type`: This specifies the return type of the lambda function. If the return type is not specified, it
     will be deduced automatically by the compiler.

   - `function body`: This is the code that defines the behavior of the lambda function. It is similar to the body
     of a regular function.

   Example of a simple lambda function that adds two integers:

   auto add = [](int a, int b) -> int {
       return a + b;
   };

   int result = add(3, 5); // result will be 8

   Lambda functions provide a concise and efficient way to define short, local functions, improving the readability
   of your code and reducing the need for creating separate named functions.
*/