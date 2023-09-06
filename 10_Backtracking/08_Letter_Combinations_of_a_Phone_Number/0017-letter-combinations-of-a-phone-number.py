"""
Problem: LeetCode 17 - Letter Combinations of a Phone Number

Key Idea:
To generate all possible letter combinations of a phone number, we can use a recursive approach. Starting from each digit of the phone number, we generate combinations by appending each letter corresponding to the digit to the current combinations. We repeat this process for all digits and all possible letters, building up the combinations.

Time Complexity:
- The total number of combinations is 4^n (where n is the number of digits) in the worst case, as each digit maps to up to 4 letters on a phone keypad. Therefore, the time complexity is O(4^n).

Space Complexity:
- The space complexity is O(n), where n is the number of digits, representing the maximum depth of the recursive call stack.
"""


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        phone_mapping = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        def backtrack(index, combination):
            if index == len(digits):
                combinations.append(combination)
                return

            digit = digits[index]
            letters = phone_mapping[digit]

            for letter in letters:
                backtrack(index + 1, combination + letter)

        combinations = []
        backtrack(0, "")
        return combinations
