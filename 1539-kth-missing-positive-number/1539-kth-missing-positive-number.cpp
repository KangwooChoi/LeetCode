class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missingArr;
        int curr = 1;
        int p = 0;
        while (p < arr.size() && missingArr.size() < k) {
            if (arr[p] != curr) {
                missingArr.push_back(curr++);
            } else {
                p++;
                curr++;
            } 
        }
        while (missingArr.empty() || missingArr.size() <= k ) {
            missingArr.push_back(curr++);
        } 
        return missingArr[k-1];
    }
};