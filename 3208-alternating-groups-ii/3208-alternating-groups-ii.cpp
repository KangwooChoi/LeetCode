class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }
        int length = colors.size();
        int ans = 0;
        int left = 0;
        int right = 1;
        while (right < length) {
            if (colors[right] == colors[right-1]) {
                left = right;
                right++;
                continue;
            }
            right++;
            if (right - left < k) continue;
            ans++;
            left++;
        }
        return ans;
    }
};
//class Solution {
//public:
//    int numberOfAlternatingGroups(vector<int>& colors, int k) {
//        int n = colors.size();
//        for (int i = 0; i < k; i++) {
//            colors.push_back(colors[i]);
//        } 
//        int ans = 0;
//        for (int i = 0; i < n; i++) {
//            int j = 1;
//            bool isAlter = true;
//            while (j < k) {
//                if (colors[i+j] == colors[i+j-1]) {
//                    isAlter = false;
//                    break;
//                }
//                j++;
//            }
//            if (isAlter) ans++;
//        }
//        return ans;
//    }
//};