/*
Problem: LeetCode 309 - Best Time to Buy and Sell Stock with Cooldown

Description:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
You cannot buy and sell the stock on the same day (i.e., you must sell the stock before buying again).
Additionally, you must not participate in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Intuition:
To maximize the profit while taking into account the cooldown period, we can use dynamic programming.
At each day, we have three possible states: buy, sell, or rest.
The key idea is to track the maximum profit for each state and determine the optimal action to take on each day.

Approach:
1. Initialize three variables: buy (maximum profit if the stock is bought), sell (maximum profit if the stock is sold), and rest (maximum profit if no action is taken).
   Set buy = -prices[0], sell = 0, and rest = 0.
2. Iterate through the prices array starting from the second day:
   - Update the buy variable as the maximum between the previous buy value and the profit from the previous rest state minus the current stock price.
   - Update the sell variable as the maximum between the previous sell value and the profit from the previous buy state plus the current stock price.
   - Update the rest variable as the maximum between the previous sell value and the previous rest value.
3. Return the sell value, which represents the maximum profit at the end.

Time Complexity:
The time complexity is O(n), where n is the length of the prices array.

Space Complexity:
The space complexity is O(1) as we only need three variables to store the maximum profit.

Dynamic Programming:
- Subproblem: The subproblem is determining the maximum profit at each day considering the buy, sell, and rest states.
- Recurrence Relation: buy = max(buy, rest - price), sell = max(sell, buy + price), rest = max(sell, rest).
- Base Case: Initialize buy = -prices[0], sell = 0, and rest = 0.
*/

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();

        if (n <= 1) {
            return 0; // If there are no prices or only one price, no profit can be made
        }

        int buy = -prices[0]; // The maximum profit if the stock is bought at the current day
        int sell = 0; // The maximum profit if the stock is sold at the current day
        int rest = 0; // The maximum profit if no action is taken at the current day

        for (int i = 1; i < n; i++) {
            int prevBuy = buy; // Store the previous buy value for calculation
            int prevSell = sell; // Store the previous sell value for calculation
            int prevRest = rest; // Store the previous rest value for calculation
            // Calculate the maximum profit if the stock is bought at the current day
            // It is the maximum of the previous buy value (indicating that we didn't buy on the current day)
            // and the profit of not buying on the previous day minus the current price
            buy = max(prevBuy, prevRest - prices[i]);
            // Calculate the maximum profit if the stock is sold at the current day
            // It is the maximum of the previous sell value (indicating that we didn't sell on the current day)
            // and the profit of buying on the previous day plus the current price
            sell = max(prevSell, prevBuy + prices[i]);
            // Calculate the maximum profit if no action is taken at the current day
            // It is the maximum of the previous sell value (indicating that we didn't make any transactions on the current day)
            // and the previous rest value (indicating that we carried over the same profit from the previous day)
            rest = max(prevSell, prevRest);
        }

        return sell; // Return the maximum profit at the end of all days
    }
};

/*
Each day presents three options or states that can be chosen:
    1. Resting state (resting[i]): In this state, we choose not to take any action related to buying or selling stocks. The maximum profit in this state is determined by the maximum profit achieved in the previous day's resting state or selling state. Essentially, we carry over the maximum profit from the previous day's resting or selling state.

    2. Buying state (buying[i]): In this state, we choose to buy stocks. The maximum profit in this state is determined by the maximum profit achieved in the previous day's buying state or the maximum profit achieved in the previous day's resting state minus the current day's stock price. We select the higher value between these two options to maximize our profit.

    3. Selling state (selling[i]): In this state, we choose to sell stocks. The maximum profit in this state is determined by adding the stock price of the current day to the maximum profit achieved in the previous day's buying state. Selling stocks in this state allows us to realize the profit accumulated from the previous buying state.
*/
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // Create three auxiliary arrays to store the maximum profit at each state
        vector<int> resting(n, 0);  // Maximum profit when in a resting state
        vector<int> buying(n, 0);   // Maximum profit when in a buying state
        vector<int> selling(n, 0);  // Maximum profit when in a selling state

        // Initialize the base cases for the first day
        resting[0] = 0;                 // No profit in resting state
        buying[0] = -prices[0];         // Maximum profit in buying state (buying on the first day)
        selling[0] = INT_MIN;           // No profit in selling state (impossible to sell on the first day)


        // In buying state, we can either buy or rest
        // In selling state, we either sell or rest but we can ignore rest to calculate what profit will be if we sold everyday
        // In resting state, we carry over the maximum profit from the previous day's selling state.

        // Iterate through the prices array to update the maximum profit at each state
        for (int i = 1; i < n; i++) {
            resting[i] = max(resting[i - 1], selling[i - 1]);

            buying[i] = max(buying[i - 1], resting[i - 1] - prices[i]);

            // Max profit if sold today
            selling[i] = buying[i - 1] + prices[i];
        }

        // The maximum profit at the end will be the maximum between the resting state and the selling state
        return max(resting[n - 1], selling[n - 1]);
    }
};
*/