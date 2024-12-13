class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n+1,false);
        priority_queue<pair<int, int>> pq;
        long long score = 0;
        for (int i = 0; i < n; i++) {
            pq.push(make_pair(-nums[i], -i));
        }

        while (!pq.empty()) {
            pair<int, int> curr = pq.top();
            pq.pop();
            int val = -curr.first;
            int index = -curr.second;
            if (marked[index] == false) {
                marked[index] = true;
                if (1 <= index) marked[index - 1] = true; 
                if (index < n) marked[index + 1] = true; 
                cout << val << endl;
                score += val;
            }
        }
        return score; 
    }
};