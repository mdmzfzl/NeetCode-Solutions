// (Max value in lower half + Min value in upper half) / 2
// Will give us median
// https://leetcode.com/problems/find-median-from-data-stream/solutions/1330646/c-java-python-minheap-maxheap-solution-picture-explain-clean-concise/

class MedianFinder {
private:
    // Using max heap to store lower half values
    priority_queue<int> maxHeap;
    // Using minHeap to store upper half values
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        ios_base::sync_with_stdio(false);    
        cin.tie(NULL);
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        // Pushing top value of maxHeap into minHeap
        minHeap.push(maxHeap.top());
        // Popping the pushed value
        maxHeap.pop();

        // To balance both heaps
        if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        // maxHeap will fill first and then minHeap
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size())
            return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/*
class MedianFinder {
public:
    priority_queue<int>first_half;
    priority_queue<int, vector<int>, greater<int>>second_half;

    MedianFinder() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    void addNum(int num) {
        first_half.push(num);
        int fqsize = first_half.size(), sqsize = second_half.size();
        int total = fqsize + sqsize;
        while((fqsize - sqsize) != ((total) & 1) && fqsize >= sqsize){
            second_half.push(first_half.top()); first_half.pop();
            fqsize = first_half.size(), sqsize = second_half.size();
        }
        if(fqsize && sqsize){
            int ftop = first_half.top(), stop = second_half.top();
            if(ftop > stop){
                first_half.pop(), second_half.pop();
                first_half.push(stop), second_half.push(ftop);
            }
        }
    }
    
    double findMedian() {
        int fqsize = first_half.size(), sqsize = second_half.size();
        if((fqsize + sqsize) & 1) return first_half.top() * 1.0;
        else{
            double sum = first_half.top() * 1.0 + second_half.top() * 1.0;
            return sum / 2.0;
        }
    }
};
*/