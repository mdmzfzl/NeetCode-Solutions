/*
Solution - 
In example, tasks = ["A","A","A","B","B","B"], n = 2
Each round is: A B _ 
The number of rounds will be decided by what character occurs the most ie maxFreq
and every character can occur every n+1 times, ie A can occur on 0, 3, 6 etc
so formula will be maxFreq * (n+1) but we will calculate the last round seperately
(adding all elements with maxFreq because they are the only elements in last round)
    for example, if A occurs 5 times and B occurs 3 times
    Last two rounds will just be A
so final formula is, (maxFreq-1)*(n+1) + (no of times maxFreq occured)
*/

// https://medium.com/@swgarciab/task-scheduler-leetcode-problem-a74acadf0e22

/*
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> M;
        int result, maxFrequency = 0;

        // Making frequency map
        for(int i: tasks){
            M[i - 'A']++;
            // Calculating most freq element
            if(M[i - 'A'] > maxFrequency)
                maxFrequency = M[i - 'A'];
        }
            
        result = (maxFrequency - 1) * (n + 1);

        // Calculating number of occurences that equal maxFreq
        for(auto i: M) 
            if(i.second == maxFrequency)
                result++;

        return max((int)tasks.size(), result);
    }
};
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequency(26, 0);
        for(int i = 0; i < tasks.size(); i++)
            frequency[tasks[i] - 'A']++;
        
        sort(frequency.begin(), frequency.end(), greater<int>());

        int maxFreq = frequency[0];
        int count = 0;

        // Calculating number of occurences that equal maxFreq
        while(count <= 25 && frequency[count] == maxFreq )
            count++;

        int result = (maxFreq-1) * (n+1) + count;
        result = max((int)tasks.size(), result);
        
        return result;
    }
};

/*
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Create a frequency array to keep track of the count of each task
        vector<int> freq(26);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        // Sort the frequency array in non-decreasing order
        sort(freq.begin(), freq.end());
        // Calculate the maximum frequency of any task
        int maxFreq = freq[25] - 1;
        // Calculate the number of idle slots that will be required
        int idleSlots = maxFreq * n;
        // Iterate over the frequency array from the second highest frequency to the lowest frequency
        for (int i = 24; i >= 0 && freq[i] > 0; i--) {
            // Subtract the minimum of the maximum frequency and the current frequency from the idle slots
            idleSlots -= min(maxFreq, freq[i]);
        }
        // If there are any idle slots left, add them to the total number of tasks
        return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
    }
};
*/