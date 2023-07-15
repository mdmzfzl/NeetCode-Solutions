/*
Problem: LeetCode 322 - Coin Change

Description:
Given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money,
return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination
of the coins, return -1.

Approach:
1. Initialize an array dp of size (amount + 1) and set all values to a maximum number (amount + 1) to indicate the amount is not possible.
2. Set dp[0] = 0, as it takes 0 coins to make an amount of 0.
3. Iterate through each coin denomination:
    a. For each amount i from coin to the target amount:
        - Update dp[i] if dp[i - coin] + 1 is smaller, indicating a smaller number of coins to make the current amount.
4. Return dp[amount] if it is less than the maximum possible number of coins (amount + 1), otherwise return -1.

Time Complexity:
The time complexity of this approach is O(amount * coins.size()), as we need to compute the minimum number of coins for each amount
up to the given amount and for each coin denomination.

Space Complexity:
The space complexity is O(amount), as we are using an additional array dp of size (amount + 1) to store the results.
*/


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

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Create a DP array to store the minimum number of coins needed for each amount
        vector<int> DP(amount + 1, INT_MAX);
        // Set the base case: 0 coins are needed to make amount 0
        DP[0] = 0;
        sort(coins.begin(), coins.end());

        for (int i = 1; i <= amount; i++) {
            for (auto coin : coins) {
                // ! Statement 1
                if (coin > i)
                    break;
                // ! Statement 2
                if (DP[i - coin] != INT_MAX)
                    DP[i] = min(DP[i], DP[i - coin] + 1);
            }
        }

        // If the final amount is still INT_MAX, it means amount cannot be made with the given coins
        return (DP[amount] == INT_MAX) ? -1 : DP[amount];
    }
};

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
