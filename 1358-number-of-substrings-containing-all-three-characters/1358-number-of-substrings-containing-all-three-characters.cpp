class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int left = 0, right = 0;
        vector<int> freq(3,0);
        int ans = 0;
        while (right < n) {
            char curr = s[right];
            freq[curr - 'a']++;
            while (hasAllChars(freq)) {
                ans += n - right;
                char leftChar = s[left];
                freq[leftChar - 'a']--;
                left++;
            }
            right++;
        }
        return ans; 
    }
private:
    bool hasAllChars(vector<int> freq) {
        return freq[0] >= 1 && freq[1] >= 1 && freq[2] >= 1;
    }
};