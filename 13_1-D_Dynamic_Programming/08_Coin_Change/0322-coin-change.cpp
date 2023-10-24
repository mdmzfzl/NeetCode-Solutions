/*
Problem: LeetCode 322 - Coin Change

Description:
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Intuition:
To find the fewest number of coins needed to make up a given amount, we can use dynamic programming.
The problem can be broken down into smaller subproblems by considering different coin denominations.
We can build the solution by considering the minimum number of coins needed for smaller amounts and combining them to find the answer.

Approach:
1. Initialize an array dp of size amount+1, where dp[i] represents the fewest number of coins needed to make up the amount i.
   - Initialize all elements of dp to infinity, except dp[0] which is set to 0.
2. Iterate through the coin denominations:
   - For each coin, iterate through the amounts from the coin value to the target amount.
   - Update dp[j] by taking the minimum between dp[j] and dp[j-coin] + 1.
3. Return dp[amount], which represents the fewest number of coins needed to make up the target amount.

Time Complexity:
The time complexity is O(amount * n), where amount is the target amount and n is the number of coins. We iterate through all possible amounts and all coin denominations.

Space Complexity:
The space complexity is O(amount) as we use an array dp to store the fewest number of coins needed for each amount.

Dynamic Programming:
- Subproblem: The subproblem is calculating the fewest number of coins needed to make up an amount i.
- Recurrence Relation: dp[i] = min(dp[i], dp[i-coin] + 1) for each coin in the coin denominations.
- Base Case: dp[0] = 0 (zero coins are needed to make up an amount of zero).
*/

class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);  // DP array to store the minimum number of coins needed for each amount
        dp[0] = 0;  // Base case: zero coins are needed to make up an amount of zero

        for (int coin : coins) {  // Iterate through each coin
            for (int j = coin; j <= amount; j++) {  // Iterate through each amount from coin to the target amount
                if (dp[j - coin] != INT_MAX) {  // Check if there is a valid previous amount (j - coin) that can be made up with coins
                    dp[j] = min(dp[j], dp[j - coin] + 1);  // Update dp[j] with the minimum number of coins needed
                }
            }
        }

        return dp[amount] != INT_MAX ? dp[amount] : -1;  // If dp[amount] is still INT_MAX, return -1 as the amount cannot be made with the given coins
    }
};

/**
 * ! Statement 1 -
 * * Since the coins array is sorted in ascending order, once we encounter a coin that is larger than i, we can safely break out of the loop.
 *
 * ! Statement 2 -
 * * We are taking mimimum because there could be multiple ways of getting the current amount but we want the lowest amt of coins
 *     * Ex: coins = [1, 3, 4, 7], so while iterating through first denomination ie 1
 *     * DP[3] will be 3, min(dp[3], dp[2] + 1) => min(MAX_INT, 2 + 1) => 3
 *     * But next iteration we find that 3 denomination exists
 *     * So,  min(DP[i], DP[i-coin] + 1) => min(3, 0 + 1) => DP[i] = 1
*/

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         // Create a DP array to store the minimum number of coins needed for each amount
//         vector<int> DP(amount + 1, INT_MAX);
//         // Set the base case: 0 coins are needed to make amount 0
//         DP[0] = 0;
//         sort(coins.begin(), coins.end());

//         for (int i = 1; i <= amount; i++) {
//             for (auto coin : coins) {
//                 // ! Statement 1
//                 if (coin > i)
//                     break;
//                 // ! Statement 2
//                 if (DP[i - coin] != INT_MAX)
//                     DP[i] = min(DP[i], DP[i - coin] + 1);
//             }
//         }

//         // If the final amount is still INT_MAX, it means amount cannot be made with the given coins
//         return (DP[amount] == INT_MAX) ? -1 : DP[amount];
//     }
// };

// int coinChange(vector<int>& coins, int amount) {
//     vector<int> dp(amount + 1, amount + 1);

//     // Base case
//     dp[0] = 0;

//     for (int i = 1; i <= amount; ++i) {
//         for (int j = 0; j < coins.size(); ++j) {
//             if (coins[j] <= i) {
//                 dp[i] = min(dp[i], dp[i - coins[j]] + 1);
//             }
//         }
//     }

//     return dp[amount] > amount ? -1 : dp[amount];
// }
