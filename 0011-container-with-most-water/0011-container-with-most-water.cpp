class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1 = 0, p2 = height.size() - 1; 
        int ans = min(height[p1], height[p2]) * (p2-p1);
        while (p1 < p2) {
            if (height[p1] < height[p2]) {
                p1++;
            } else {
                p2--;
            }
            ans = max(ans, min(height[p1], height[p2]) * (p2-p1));
        }
        return ans;
    }
};
//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        int n = height.size();
//        int ans = 0;
//        for (int i = 0; i < n - 1; i++) {
//            for (int j = i+1; j < n; j++) {
//                ans = max(ans, (j-i)*min(height[i], height[j]));
//            }
//        } 
//        return ans;
//    }
//};