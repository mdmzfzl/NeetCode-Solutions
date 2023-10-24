/*
Problem: LeetCode 121 - Best Time to Buy and Sell Stock

Description:
You are given an array `prices` where `prices[i]` is the price of a given stock on the i-th day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Intuition:
To maximize the profit, we need to find the largest difference between any two prices, where the lower price comes before the higher price.
We can track the minimum price seen so far and calculate the maximum profit by subtracting the minimum price from each subsequent price.

Approach:
1. Initialize variables `minPrice` and `maxProfit`.
   - Set `minPrice` to the maximum possible value and `maxProfit` to 0.
2. Iterate through each price in the `prices` array:
   - Update `minPrice` to the minimum value between `minPrice` and the current price.
   - Calculate the potential profit by subtracting `minPrice` from the current price.
   - Update `maxProfit` to the maximum value between `maxProfit` and the potential profit.
3. Return `maxProfit`, which represents the maximum profit achievable.

Time Complexity:
The time complexity is O(n), where n is the number of elements in the input array. We iterate through the array once to calculate the maximum profit.

Space Complexity:
The space complexity is O(1) as we are using a constant amount of space to store the variables.
*/

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};

//   -> Calculate LeastSoFar
//   -> Measure profit, if greater than result, update result

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int leastSoFar = 100000, profit = 0, result = 0;

//         for(int i = 0; i < prices.size(); i++) {
//             if(prices[i] < leastSoFar)
//                 leastSoFar = prices[i];

//             profit = prices[i] - leastSoFar;
//             if(result < profit)
//                 result = profit;
//         }
//         return result;
//     }
// };

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(0);
        cout.tie(0);

        int profit = 0;
        int minbuy = prices[0];

        for(int x: prices) {
            int diff = x - minbuy;
            profit = max(profit, diff);
            minbuy = min(minbuy, x);
        }

        return profit;
    }
};
*/