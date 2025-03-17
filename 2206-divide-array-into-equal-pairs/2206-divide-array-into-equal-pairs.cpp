class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> freq;
        int cnt = 0;
        for (int num : nums) {
            if(++freq[num] % 2 == 0) cnt++;
        } 
        return cnt == nums.size() / 2;
    }
};