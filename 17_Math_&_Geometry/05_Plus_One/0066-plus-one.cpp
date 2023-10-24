/*
Problem: LeetCode 66 - Plus One

Description:
Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
You may assume the integer does not contain any leading zero, except for the number 0 itself.

Intuition:
To increment a number represented as an array of digits, we need to add one to the last digit and handle any carry that may occur.

Approach:
1. Start from the end of the digits array.
2. Add one to the last digit.
3. If the digit becomes 10 (carry occurs), set it to 0 and move to the next digit.
4. Continue this process until there is no more carry or we reach the beginning of the digits array.
5. If there is still a carry after processing all digits, it means the original number was all nines, and we need to add a new digit at the beginning of the array with a value of 1.

Time Complexity:
The time complexity is O(n), where n is the number of digits in the array. In the worst case, we may need to carry the addition all the way to the beginning of the array.

Space Complexity:
The space complexity is O(1) as we are modifying the input array in place and not using any additional data structures.
*/

class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        // Start from the end and add one to the last digit
        digits[n - 1] += 1;

        // Handle any carry
        for (int i = n - 1; i > 0; i--) {
            if (digits[i] == 10) {
                digits[i] = 0;
                digits[i - 1] += 1;
            } else {
                break; // No more carry, exit the loop
            }
        }

        // If there is still a carry, add a new digit at the beginning of the array
        if (digits[0] == 10) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

/*
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1; i>=0; i--){
            digits[i]++;
            if(digits[i]==10){
                digits[i]=0;
            }
            else{
                break;
            }
        }
        if(digits[0]==0){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
*/