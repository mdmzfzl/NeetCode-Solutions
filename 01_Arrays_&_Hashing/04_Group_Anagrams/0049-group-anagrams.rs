/*
Problem: LeetCode 49 - Group Anagrams

Key Idea:
The key idea is to recognize that anagrams will have the same sorted characters. We can use a hashmap to group words that share the same sorted characters.

Approach:
1. Create an empty hashmap where the keys are the sorted characters of words, and the values are vectors of words.
2. Iterate through the input list of words:
   - Sort the characters of the word to obtain a key.
   - Check if the key is present in the hashmap. If it is, add the word to the corresponding vector. If not, create a new vector with the word and insert it into the hashmap with the key.
3. After iterating through all words, collect the values of the hashmap into a result vector.

Time Complexity:
O(n * k * log k), where n is the number of words and k is the maximum length of a word. Sorting each word takes O(k * log k) time, and we perform this operation for each of the n words.

Space Complexity:
O(n * k), where n is the number of words and k is the maximum length of a word. In the worst case, each word has distinct sorted characters, so we have n keys in the hashmap.
*/

use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        // Keys are sorted character vectors and the values are vectors of strings.
        let mut anagram_groups: HashMap<Vec<u8>, Vec<String>> = HashMap::new();

        for s in strs {
            // Convert the string's characters to bytes and collect them into a vector.
            let mut sorted_chars = s.bytes().collect::<Vec<u8>>();
            // Sort the vector of bytes to create a unique key for anagrams.
            sorted_chars.sort();

            // Use the sorted key as an entry in the HashMap and push the original string into the group.
            // If the key doesn't exist in the HashMap, the entry will be created with an empty vector.
            anagram_groups.entry(sorted_chars).or_default().push(s);
        }

        // Transform the HashMap into an iterator of (sorted_key, group) pairs.
        // Then, extract only the group from each pair using the map() function.
        // Finally, collect the groups into a vector of vectors of strings.
        anagram_groups.into_iter().map(|(_, group)| group).collect()
    }
}

/*
// Alternative solution

use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        // Create a HashMap to store anagrams grouped by sorted strings
        let mut anagrams: HashMap<String, Vec<String>> = HashMap::new();

        // Iterate through each input string
        for s in strs {
            // Convert the string to a sorted string
            let mut sorted_str: Vec<char> = s.chars().collect();
            sorted_str.sort();
            let sorted_str: String = sorted_str.into_iter().collect();

            // Insert the sorted string as the key in the HashMap,
            // and insert the input string into the corresponding value list
            anagrams.entry(sorted_str).or_insert(vec![]).push(s);
        }

        // Collect and return the grouped anagrams as a Vec<Vec<String>>
        anagrams.values().cloned().collect()
    }
}
*/
