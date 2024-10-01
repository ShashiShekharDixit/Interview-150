class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int> > minHeap;
	priority_queue<int> maxHeap;
    MedianFinder() {}
    void addNum(int num) {
        maxHeap.push(num);
        if(!minHeap.empty() && !maxHeap.empty() && maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(maxHeap.size() > minHeap.size()+1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(minHeap.size() > maxHeap.size()+1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    double findMedian() {
        if(minHeap.size() > maxHeap.size()) return minHeap.top();
        if(maxHeap.size() > minHeap.size()) return maxHeap.top();
        else return ( minHeap.top() + maxHeap.top())/2.0;
    }
};