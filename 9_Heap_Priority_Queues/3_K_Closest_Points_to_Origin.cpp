/*
- Syntax for PQ: priority_queue<data_type, container, comparator> ds;
* Data_type(mandatory) : datatype that we are going to store in priority_queue. (int, float, or even any custom datatype)
* Container(optional) : Container is passed as an underlying container to store the elements. It needs to satisfy some properties, therefore it can be either vector<datatype> or deque<datatype>.
* Comparator(optional) : Comparator decides the ordering of elements.
*/
/*
class compare {
public:
    bool operator() (vector<int>& A, vector<int>& B) {
        // for max heap, comparator should be '<'
        return (A[0]*A[0] + A[1]*A[1]) > (B[0]*B[0] + B[1]*B[1]);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Min heap using comparator function(compare)
        priority_queue<vector<int>, vector<vector<int>>, compare> PQ(points.begin(), points.end());
        // Alternate way
        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> PQ(points.begin(), points.end());
        vector<vector<int>> result;
        for(int i = 0; i < k; i++) {
            result.push_back(PQ.top());  // PQ.top() is a vector
            PQ.pop();
        }
        return result;
    }
};
*/

// Method 2
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int>> dist(points.size());
        for (int i = 0; i < points.size(); i++) {
            // Storing the distance and index of points
            dist[i] = {points[i][0] * points[i][0] + points[i][1] * points[i][1], i};
        }
        // nth_element() is an STL algorithm which rearranges the list in such a way such that the element at the nth position is the one which should be at that position if we sort the list.
        // here n is k, since we are concerned about the first k elements only
        // It will be as if we sorted the array till Kth element
        nth_element(dist.begin(), dist.begin() + k - 1, dist.end());
        vector<vector<int>> result(k);
        for (int i = 0; i < k; i++) {
            result[i] = move(points[dist[i].second]);
        }
        return result;
    }
};