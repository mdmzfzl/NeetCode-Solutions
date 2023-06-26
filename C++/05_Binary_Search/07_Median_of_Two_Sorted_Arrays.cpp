/*
    Given 2 sorted arrays of size m & n, return the median of these arrays
    Ex. nums1 = [1,3] nums2 = [2] -> 2, nums1 = [1,2] nums2 = [3,4] -> 2.5

    Binary search, partition each array until partitions are correct, get median
    [1,2,3,4,5]
    |  a|b    |
    [1,2,3,4,5,6,7,8]    -->    a <= d ? yes, c <= b ? no, so need to fix
    |      c|d      |

    Time: O(log min(m, n))
    Space: O(1)
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {      
        if (nums1.size() > nums2.size()) {
            // if nums1 is bigger we swap it because we're gonna assume nums1 is smaller
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();

        double Answer = 0.0; 

        // Now that nums1 is smaller
        int L = 0, R = m;

        while(L <= R) {
            // Mid of nums1 & nums2
            int MidM = L + (R-L)/2;
            int MidN = (m+n+1)/2 - MidM;

            int a = (MidM > 0) ? nums1[MidM - 1] : INT_MIN;
            int b = (MidM < m) ? nums1[MidM] : INT_MAX;
            int c = (MidN > 0) ? nums2[MidN - 1] : INT_MIN;
            int d = (MidN < n) ? nums2[MidN] : INT_MAX;
            

            // If both halves are correctly sorted
            if(a <= d && c <= b) {
                // Checking if the merged array has even elements or odd
                if( (m + n) % 2 == 0)
                    Answer = (max(a, c) + min(b, d)) / 2.0;
                else
                    Answer = max(a, c);
                
                break;
            }

            // If not correctly sorted and right part of nums2 is lesser than left part of nums1
            else if(d < a)
                R = MidM - 1;
            // If not correctly sorted and right side of nums1 is lesser than left part of nums2 i.e. c < b
            else 
                L = MidM + 1;
        }

        return Answer;
    }
};