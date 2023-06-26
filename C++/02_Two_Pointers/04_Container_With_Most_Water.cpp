/*
  -> Use left and right pointers
  -> Calculare TempMaxArea i.e. min(L, R) x Distance
  -> If TempMaxArea > Max, update Max
  -> Move the pointer with lower height. Ex: L - 1 and R - 7, so L++
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftPointer = 0, rightPointer = height.size() - 1;
        int result = -1, currResult = 0;

        while(leftPointer < rightPointer){
            int dist = rightPointer - leftPointer;
            currResult = min(height[leftPointer], height[rightPointer]) * dist;

            result = max(result, currResult);
            
            if( height[leftPointer] > height[rightPointer] ) 
                rightPointer--;
            else 
                leftPointer++;
        }
        return result;
    }
};

/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while(height[i] <= h && i < j) 
                i++;
            while(height[j] <= h && i < j) 
                j--;
        }
        return water;
    }
};
*/