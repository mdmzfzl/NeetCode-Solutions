/*
Problem: K Closest Points to Origin

Description:
Given an array points representing coordinates of N points on a 2D plane, and an integer k, you need to return the k closest points to the origin (0, 0).

Intuition:
To find the K closest points to the origin, we can utilize the concept of a priority queue (min-heap).
We iterate through the points and calculate the distance of each point from the origin.
We add the points to the priority queue, and if the size of the queue exceeds K, we remove the farthest point.
In the end, the priority queue will contain the K closest points to the origin.
Approach:

1.Create a vector distances to store pairs of distances and indices of points.
2.Iterate through each point in the points vector and calculate its distance from the origin using the formula distance = x^2 + y^2, where (x, y) are the coordinates of the point.
3. Store each distance along with its corresponding index in the distances vector.
4. Use the nth_element function to find the k-th smallest distance in the distances vector. This function partially sorts the vector, placing the k-th smallest element in its correct position. Elements before it are smaller or equal, while elements after it are greater.
5. Create a result vector result to store the k closest points.
6. Iterate through the first k elements of the distances vector. For each element, retrieve the index and use it to access the corresponding point in the points vector. Add this point to the result vector.
7. Return the result vector containing the k closest points to the origin.

Time Complexity:
The time complexity of this approach is O(N log k), where N is the number of points. Calculating the distance for each point takes O(N), and the nth_element function takes O(N log k).

Space Complexity:
The space complexity is O(N), where N is the number of points. We use the distances vector to store the distances and indices of points
*/

/*
* Syntax for PQ: priority_queue<data_type, container, comparator> ds;
* Data_type(mandatory) : datatype that we are going to store in priority_queue. (int, float, or even any custom datatype)
* Container(optional) : Container is passed as an underlying container to store the elements. It needs to satisfy some properties, therefore it can be either vector<datatype> or deque<datatype>.
* Comparator(optional) : Comparator decides the ordering of elements.
*/

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        // Create a vector to store the distances and indices of points
        vector<pair<int, int>> distances(points.size());

        // Calculate the distance of each point from the origin and store it along with its index
        for (int i = 0; i < points.size(); i++) {
            int distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            distances[i] = make_pair(distance, i);
        }

        // Find the k-th smallest distance using nth_element
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        // Create a result vector to store the k closest points
        vector<vector<int>> result(k);

        // Add the k closest points to the result vector
        for (int i = 0; i < k; i++) {
            int index = distances[i].second;
            result[i] = move(points[index]);
        }

        return result;
    }
};