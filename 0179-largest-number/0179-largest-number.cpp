bool compare(string& a, string& b) {
    return a+b > b+a;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        for (int num : nums) {
            snums.push_back(to_string(num));
        }
        sort(snums.begin(), snums.end(), compare);
        if (snums[0] == "0") return "0";
        string ans = "";
        for (int i = 0; i < snums.size(); i++) {
            ans += snums[i];
        }
        return ans;
    }
};