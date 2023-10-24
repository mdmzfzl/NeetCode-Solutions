/*
Problem: LeetCode 621 - Task Scheduler

Description:
Given a characters array tasks, representing the tasks a CPU needs to do, where each character represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same task cannot be executed in adjacent units of time).
Return the least number of units of times that the CPU will take to finish all the given tasks.

Intuition:
To minimize the overall time, we need to arrange the tasks in such a way that the maximum number of occurrences of any task is spread apart by the cooldown period. We can then fill the gaps with idle cycles if needed.

Approach:
1. Count the frequency of each task and store it in a frequency array.
2. Sort the frequency array in descending order.
3. Find the maximum frequency `maxFreq`.
4. Calculate the number of idle cycles required:
   - Subtract 1 from `maxFreq` to exclude the last occurrence of the most frequent task (as it doesn't need an idle cycle after it).
   - Multiply `maxFreq - 1` by `n` to get the number of slots occupied by the most frequent task and its cooldown periods.
   - Subtract this value from the total number of tasks to get the number of remaining idle cycles.
5. Calculate the minimum number of time units required:
   - Add the total number of tasks to the number of idle cycles calculated in step 4.
   - Return the maximum of this value and the length of the tasks array.

Time Complexity:
The time complexity is O(n log n), where n is the number of tasks. This is due to the sorting operation on the frequency array.

Space Complexity:
The space complexity is O(1) since the frequency array has a fixed size of 26 (assuming tasks only contain uppercase letters).
*/

class Solution {
  public:
    int leastInterval(vector<char> &tasks, int n) {
        // Count the frequency of each task
        vector<int> frequency(26, 0);

        for (char task : tasks) {
            frequency[task - 'A']++;
        }

        // Sort the frequency array in descending order
        sort(frequency.rbegin(), frequency.rend());
        // Find the maximum frequency
        int maxFreq = frequency[0];
        // Calculate the number of idle cycles required
        int idleCycles = (maxFreq - 1) * n;

        // Subtract the remaining tasks from the idle cycles
        for (int i = 1; i < frequency.size(); i++) {
            idleCycles -= min(frequency[i], maxFreq - 1);
        }

        // Calculate the minimum number of time units required
        int minTime = tasks.size() + max(0, idleCycles);
        return minTime;
    }
};
