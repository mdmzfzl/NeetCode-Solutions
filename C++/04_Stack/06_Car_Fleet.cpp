/*
    n cars 1 road, diff pos/speeds, faster cars slow down -> car fleet, return # fleets
    Ex. target = 12, pos = [10,8,0,5,3], speeds = [2,4,1,1,3] -> 3 (10 & 8, 0, 5 & 3)

    Sort by start pos, calculate time for each car to finish, loop backwards
    If car behind finishes faster then catches up to fleet, else creates new fleet

    Time: O(n log n)
    Speed: O(n)
*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        // Storing position and time in stack
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++) {
            double time = (double) (target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        sort(cars.begin(), cars.end());
        
        double maxTime = 0.0;
        int result = 0;
        
        // Loop from behind, if the element before it arrives at the target in shorter time then it will collide, if not increment result as it will be seperate fleet

        for (int i = n - 1; i >= 0; i--) {
            double time = cars[i].second;
            if (time > maxTime) {
                maxTime = time;
                result++;
            }
        }
        return result;
    }
};

/*
const int sdfsafa = []{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        // vector<pair<int,int>> all(n);
        pair<int, int> all[n];
        for(int i = 0; i < n ; i++) {
            all[i] = {position[i], speed[i]};
        }
        sort(all, all+n, greater<pair<int, int>>());
        int count = 1;
        pair<int, int> top = all[0];
        for(int i = 1; i < n; i++) {
            auto curr = all[i];
            if(curr.second <= top.second) {
                top = curr;
                count++;
            }
            else {
                float time1 = target - top.first;
                time1 /= top.second;
                float time2 = target - curr.first;
                time2 /= curr.second;
                if(time2 > time1) {
                    top = curr;
                    count++;
                }
            }
        }
        return count;
    }
};
*/