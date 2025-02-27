class Solution {
public:
    bool checkIfPangram(string sentence) {
        int distinctCnt = 0;
        vector<int> arr(26,0); 
        for (char c : sentence) {
            int idx = c - 'a';
            if (arr[idx]++ == 0) {
                if (++distinctCnt == 26) return true;
            }
        }
        return false;
    }
};