/*
Problem: LeetCode 269 - Alien Dictionary

Key Idea:
The key idea is to model the problem as a directed graph and perform a topological sort to find the order of characters in the alien language.

Approach:
1. Create a directed graph where each character is a node, and there is a directed edge from character 'a' to 'b' if 'a' comes before 'b' in the alien language.
2. To build the graph, compare adjacent words and add directed edges accordingly.
3. Perform a topological sort on the graph to find the order of characters.
   - Initialize an empty result string and a queue for topological sorting.
   - Add nodes with no incoming edges (in-degree = 0) to the queue.
   - While the queue is not empty:
     - Pop a character from the queue, append it to the result string.
     - For each neighbor of the character, decrement its in-degree by 1.
     - If a neighbor's in-degree becomes 0, add it to the queue.
4. If the result string's length is equal to the number of distinct characters, return the result as the correct character order; otherwise, return an empty string, indicating no valid ordering exists.

Time Complexity:
O(N + E), where N is the total number of characters (distinct characters in words) and E is the total number of edges (comparisons between adjacent words).

Space Complexity:
O(N + E) for the graph representation.
*/

// Since this is a hard question and I don't have access to it, can't write error free code