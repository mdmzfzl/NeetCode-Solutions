/*
Problem: LeetCode 621 - Task Scheduler

Key Idea:
The key idea is to arrange tasks by their frequency and then insert the most frequent tasks into the schedule, leaving gaps equal to the cooldown period. Fill these gaps with less frequent tasks if available.

Approach:
1. Calculate the frequency of each task and store it in a character frequency array.
2. Sort the frequency array in descending order to prioritize scheduling tasks with higher frequencies.
3. Initialize a variable 'idle_slots' to represent the number of idle CPU cooling intervals.
4. While there are tasks left to schedule:
   - Start scheduling tasks from the task with the highest frequency.
   - Place the task in an available slot in the CPU cooling intervals.
   - Decrease its frequency by 1.
   - If there are no more tasks with a higher frequency, use an idle slot.
   - If all slots are used, increase 'idle_slots' by the number of available slots.
   - Repeat this process until all tasks are scheduled.
5. The minimum time required to execute all tasks will be the sum of the tasks and idle slots.

Time Complexity:
O(n), where n is the number of tasks. We iterate through the tasks once to calculate frequencies and once to schedule them.

Space Complexity:
O(26) = O(1), as we use an array of size 26 to store the task frequencies.
*/

impl Solution {
    pub fn least_interval(tasks: Vec<char>, n: i32) -> i32 {
        if n == 0 {
            return tasks.len() as i32;
        }

        let mut task_count = vec![0; 26];
        for &task in &tasks {
            task_count[(task as u8 - b'A') as usize] += 1;
        }

        task_count.sort_unstable();
        task_count.reverse();

        let max_task = task_count[0] as i32;
        let mut idle_slots = (max_task - 1) * n;

        for &count in task_count.iter().skip(1) {
            idle_slots -= std::cmp::min(count as i32, max_task - 1);
        }

        idle_slots = idle_slots.max(0);

        tasks.len() as i32 + idle_slots
    }
}
