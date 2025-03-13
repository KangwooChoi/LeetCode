class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cnt = 0;
        int p1 = 0;
        int curr = 1;
        while (cnt < k && p1 < arr.size()) {
            if (curr == arr[p1]) {
                curr++;
                p1++;
            } else {
                cnt++;
                curr++;
            }
        }
        while (cnt < k) {
            cnt++;
            curr++;
        }
        return curr-1;
    }
};