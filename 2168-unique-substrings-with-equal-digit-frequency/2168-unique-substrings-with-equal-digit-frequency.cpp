class Solution {
public:
    int equalDigitFrequency(string s) {
        int n = s.size();
        unordered_set<string> validSubstrings;

        for (int start = 0; start < n; start++) {
            vector<int> digitFrequency(10, 0);
            for (int end = start; end < n; end++) {
                digitFrequency[s[end] - '0']++;
                int commonFrequency = 0;
                bool isValid = true;

                for (int i = 0; i < digitFrequency.size(); i++) {
                    if (digitFrequency[i] == 0) continue;

                    if (commonFrequency == 0) commonFrequency = digitFrequency[i];
                    if (commonFrequency != digitFrequency[i]) {
                        isValid = false;
                        break;
                    }
                }

                if (isValid) {
                    string substring = s.substr(start, end-start+1);
                    validSubstrings.insert(substring);
                }
            }
        }
        return validSubstrings.size();
    }
};