class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        sort(nums.begin(), nums.end(), greater<int>());
//        return nums[k-1];
//    }
//
//};

//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        priority_queue<int> heap;
//        for (int num: nums) {
//            heap.push(-num);
//            if (heap.size() > k) {
//                heap.pop();
//            }
//        }
//        
//        return -heap.top();
//    }
//};

//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        priority_queue<int> pq;
//        int n = nums.size();
//        for (int i = 0; i < n; i++) {
//            pq.push(nums[i]);
//        }
//        while (--k) {
//            pq.pop(); 
//        }
//        return pq.top(); 
//    }
//};