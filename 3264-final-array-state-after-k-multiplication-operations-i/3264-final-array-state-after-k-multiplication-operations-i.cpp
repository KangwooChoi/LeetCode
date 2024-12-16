class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<pair<int, int>> heap;
        for (int i = 0; i < nums.size(); i++) {
            heap.push_back({nums[i], i});
        }
        make_heap(heap.begin(), heap.end(), greater<>());
        while(k--) {
            pop_heap(heap.begin(), heap.end(), greater<>());
            auto [value, i] = heap.back();
            heap.pop_back();

            nums[i] *= multiplier;
            heap.push_back({nums[i], i});
            push_heap(heap.begin(), heap.end(), greater<>());
        }
        return nums;
    }
};
//class Solution {
//public:
//    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
//        priority_queue<pair<int, int>> pq;
//        for (int i = 0; i < nums.size(); i++) {
//            pq.push({-nums[i], -i});
//        }
//        pair<int, int> curr;
//        int val = 0, index = 0;
//        while(k > 0) {
//            curr = pq.top();
//            val = -curr.first;
//            index = -curr.second;
//            nums[index] = val * multiplier;
//            pq.pop();
//            pq.push({-val*multiplier, -index});
//            k--;
//        }
//        return nums; 
//    }
//};