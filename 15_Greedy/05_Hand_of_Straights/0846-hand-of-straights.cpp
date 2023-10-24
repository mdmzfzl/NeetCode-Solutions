/*
Problem: LeetCode 846 - Hand of Straights

Description:
Alice has a hand of cards, given as an array of integers `hand`, where `hand[i]` is the value of the ith card.
A valid hand is a hand where every group of W cards is made up of cards of the same value.
Return true if and only if she can reorder the cards in her hand to form a valid hand.

Intuition:
To check if Alice can form valid groups of cards, we can use a greedy approach.
We can sort the cards in ascending order and then try to form groups of size W.

Approach:
1. Create a map to store the frequency of each card in the hand.
2. Sort the hand in ascending order.
3. Iterate through the sorted hand and for each card, try to form a group of size W.
4. If the current card frequency in the map is greater than 0, decrement its frequency by 1.
   Then, check if there are W-1 consecutive cards with frequencies greater than 0 after this card.
   If true, decrement the frequencies of these consecutive cards by 1 to form a group.
5. If we can't form a group of size W, return false.
6. If all groups are successfully formed, return true.

Time Complexity:
The time complexity is O(n log n) due to sorting the hand, where n is the number of cards in the hand.

Space Complexity:
The space complexity is O(n) to store the card frequencies in the map.
*/

class Solution {
  public:
    bool isNStraightHand(vector<int> &hand, int W) {
        if (hand.size() % W != 0) {
            return false; // If the hand size is not divisible by W, can't form valid groups
        }

        map<int, int> cardFreq; // Map to store the frequency of each card

        for (int card : hand) {
            cardFreq[card]++;
        }

        sort(hand.begin(), hand.end()); // Sort the hand in ascending order

        for (int card : hand) {
            if (cardFreq[card] > 0) {
                for (int i = 0; i < W; i++) {
                    if (cardFreq[card + i] == 0) {
                        return false; // Can't form a group of size W
                    }

                    cardFreq[card + i]--;
                }
            }
        }

        return true; // All groups of size W are formed successfully
    }
};

/*
// Beats 99% Runtime and Memory
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        // Check if the hand size is divisible by the groupSize
        if (n % groupSize != 0)
            return false;

        // Sort the hand array in ascending order
        sort(hand.begin(), hand.end());

        // Iterate through the hand array
        for (int i = 0; i < n; i++) {
            // Skip elements that have been marked as used (-1)
            if (hand[i] == -1)
                continue;

            int k = i;
            // Try to find the next groupSize consecutive elements
            for (int j = 1; j < groupSize; j++) {
                // Search for the next consecutive element by incrementing k
                while (k < n && hand[i] + j != hand[k])
                    k++;

                // If k reaches the end or the next element is not found, return false
                if (k == n)
                    return false;

                // Mark the found element as used by setting it to -1
                hand[k] = -1;
            }
        }

        // If all groups are found successfully, return true
        return true;
    }
};
*/