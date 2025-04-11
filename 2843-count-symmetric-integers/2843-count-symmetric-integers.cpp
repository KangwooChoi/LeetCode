class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++) {
            if (helper(i)) ans++;
        } 
        return ans;
    }
private:
    bool helper(int num) {
        string snum = to_string(num);
        if (snum.length() % 2 != 0) return false;
        int leftSum = 0, rightSum = 0;
        int left = 0, right = snum.length() - 1;
        while (left < right) {
            leftSum += snum[left] - '0';
            rightSum += snum[right] - '0';
            left++, right--;
        }
        return leftSum == rightSum;
    }
};