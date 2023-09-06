"""
Problem: LeetCode 846 - Hand of Straights

Key Idea:
We can solve this problem using a greedy approach. The idea is to sort the hand and use a Counter to keep track of the frequency of each card. Then, for each card, we check if there are enough consecutive cards to form a group of size W. If so, we decrement the frequencies accordingly. If not, the hand cannot be grouped and we return False.

Time Complexity:
- The time complexity of this approach is O(n * log n), where n is the length of the input hand due to the sorting operation.

Space Complexity:
- The space complexity is O(n), as we use a Counter to store the frequencies of the cards.
"""

from collections import Counter


class Solution:
    def isNStraightHand(self, hand: List[int], W: int) -> bool:
        if len(hand) % W != 0:
            return False

        counter = Counter(hand)
        hand.sort()

        for card in hand:
            if counter[card] > 0:
                for i in range(W):
                    if counter[card + i] <= 0:
                        return False
                    counter[card + i] -= 1

        return True
