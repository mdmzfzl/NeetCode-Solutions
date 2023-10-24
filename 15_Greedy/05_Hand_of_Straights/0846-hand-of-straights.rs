/*
Problem: LeetCode 846 - Hand of Straights

Key Idea:
The key idea is to group the cards into consecutive hands of 'W' cards each, where 'W' is the given group size, such that each group is consecutive and all groups are of the same size.

Approach:
1. Create a HashMap to count the frequency of each card in the input hand.
2. Sort the unique cards from the input hand.
3. Iterate through the sorted unique cards:
   - For each card, check if its frequency is greater than zero.
   - If so, try to form a group of 'W' consecutive cards starting from the current card.
   - To do this, iterate from the current card to the next 'W - 1' cards, reducing their frequencies.
   - If a group of 'W' consecutive cards cannot be formed, return false.
4. If all groups can be formed, return true.

Time Complexity:
O(N * log(N)), where N is the number of unique cards in the input hand. This is because we need to sort the unique cards.

Space Complexity:
O(N), where N is the number of unique cards in the input hand. This is for the HashMap to store the frequencies of the cards.
*/

use std::collections::HashMap;

impl Solution {
    pub fn is_n_straight_hand(hand: Vec<i32>, w: i32) -> bool {
        if hand.len() % w as usize != 0 {
            return false;
        }

        let mut freq_map: HashMap<i32, i32> = HashMap::new();

        // Count the frequency of each card in the hand
        for card in &hand {
            *freq_map.entry(*card).or_insert(0) += 1;
        }

        let mut unique_cards: Vec<i32> = freq_map.keys().cloned().collect();
        unique_cards.sort();

        for card in unique_cards {
            let freq = *freq_map.get(&card).unwrap();

            if freq > 0 {
                for i in 0..w {
                    let next_card = card + i;

                    if let Some(&next_freq) = freq_map.get(&next_card) {
                        if next_freq < freq {
                            return false; // Cannot form a group
                        }
                        *freq_map.get_mut(&next_card).unwrap() -= freq;
                    } else {
                        return false; // Cannot form a group
                    }
                }
            }
        }

        true
    }
}

/*
// Using heap

use std::collections::{BinaryHeap, HashMap};
use std::cmp::Reverse;

impl Solution {
    pub fn is_n_straight_hand(hand: Vec<i32>, group_size: i32) -> bool {
        if hand.len() % group_size as usize != 0 {
            return false;
        }

        let mut card_counts: HashMap<i32, i32> = HashMap::new();
        for card in hand {
            *card_counts.entry(card).or_insert(0) += 1;
        }

        let mut min_heap: BinaryHeap<Reverse<i32>> = BinaryHeap::new();
        for &card in card_counts.keys() {
            min_heap.push(Reverse(card));
        }

        while let Some(Reverse(first_card)) = min_heap.peek() {
            for card in *first_card..(*first_card + group_size) {
                if !card_counts.contains_key(&card) {
                    return false;
                }

                if let Some(&count) = card_counts.get(&card) {
                    if count == 1 {
                        if let Some(Reverse(peeked_card)) = min_heap.peek() {
                            if card != *peeked_card {
                                return false;
                            }
                            min_heap.pop();
                        }
                    } else {
                        *card_counts.get_mut(&card).unwrap() -= 1;
                    }
                }
            }
        }

        true
    }
}
*/
