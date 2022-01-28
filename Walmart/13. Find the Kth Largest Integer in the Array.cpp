class NumStrMinComparator {
public:
    bool operator() (string &b, string &a) { // Please note, I swap position of `a` and `b` here!
        if (a.size() != b.size()) return a.size() < b.size();
        return  a < b;
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, NumStrMinComparator> minHeap;
        for (string& num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};