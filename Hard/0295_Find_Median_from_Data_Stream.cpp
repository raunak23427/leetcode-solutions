/*
 * Problem: Find Median from Data Stream
 * Problem ID: 295
 * Difficulty: Hard
 * Language: C++
 * Runtime: 58 ms
 * Memory: 148.6 MB
 * Synced From: LeetCode
 * Date: 2026-08-19
 */

class MedianFinder {
public:
    priority_queue<int> leftmaxheap;
    priority_queue<int, vector<int>, greater<int>>rightminheap;
void balance() {
        if (leftmaxheap.size()>rightminheap.size() + 1) {
			rightminheap.push(leftmaxheap.top());
			leftmaxheap.pop();
		}
		else {
			if (leftmaxheap.size()<rightminheap.size()) {
				leftmaxheap.push(rightminheap.top());
				rightminheap.pop();
			}
		}

    }
    

    void addNum(int x) {
        if (leftmaxheap.empty()) {
			leftmaxheap.push(x);
			return;
		}
		if (x>leftmaxheap.top()) {
			rightminheap.push(x);
		}
		else {
			leftmaxheap.push(x);
		}
		balance();
		
    }
    

    double findMedian() {
        	if (leftmaxheap.size()>rightminheap.size()) {
			return leftmaxheap.top();
		}
		else {
			
			 return (static_cast<double>(leftmaxheap.top()) +
                rightminheap.top()) / 2.0;
			}
		}
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */