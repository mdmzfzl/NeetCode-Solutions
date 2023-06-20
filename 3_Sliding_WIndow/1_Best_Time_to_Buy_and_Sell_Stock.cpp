/*
  -> Calculate LeastSoFar
  -> Measure profit, if greater than result, update result
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leastSoFar = 100000, profit = 0, result = 0;

        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < leastSoFar)
                leastSoFar = prices[i];
            
            profit = prices[i] - leastSoFar;
            if(result < profit)
                result = profit;
        }
        return result;
    }
};

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