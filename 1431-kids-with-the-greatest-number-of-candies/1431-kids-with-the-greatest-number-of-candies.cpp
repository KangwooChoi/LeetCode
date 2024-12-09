class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int max_candy = 0;
        for (int num: candies) {
            if (num > max_candy) max_candy = num;
        }
        for (int candy: candies) {
            if ((candy + extraCandies) >= max_candy) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        } 
        return ans;
    }
};