// Brute force way is to check if she can eat in h with k value from 1 to maximum in array 
// A better way is just using binary search to reduce the time


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Our K lies between 1 and MAX
        int L = 1, R = 0;

        // Finding the highest/max value in the piles array
        for (int i = 0; i < piles.size(); i++) {
            R = max(R, piles[i]);
        }
        // Our result aka minimum K where koko eats all
        int minK = R;

        while(L <= R) {
            long int count = 0;
            int K = (L+R) / 2; // Our mid value

            // Counting number of hours it takes to eat with K value
            for(int i = 0; i < piles.size(); i++) {
                count += ceil((double) piles[i] / K);
            }
            if(count > h) {
                L = K + 1;
            }
            else {
                R = K - 1;      
                minK = min(minK, K);
            }
        }
        return minK;
    }
};

/*
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        this->piles = piles;
        int lo = 1;
        int hi = piles[0];
        for (int p : piles) {
            if (p > hi) {
                hi = p;
            }
        }
        int best = hi;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            unsigned long long time = timeToEatAtSpeed(mid);
            if (time <= h) {
                best = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return best;
    }

private:
    vector<int> piles;

    unsigned long long timeToEatAtSpeed(int speed) {
        unsigned long long sum = 0;
        for (int p : piles) {
            sum += p / speed;
            if (p % speed != 0) {
                ++sum;
            }
        }
        return sum;
    }
};
*/