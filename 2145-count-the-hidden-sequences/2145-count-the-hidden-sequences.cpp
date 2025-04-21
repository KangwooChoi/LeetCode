class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long min = 0, max = 0;
        long sum = 0;
        for (auto diff : differences) { 
            sum += diff;
            if (sum < min) min = sum;
            if (sum > max) max = sum;
        }
        return upper < max + (lower - min) ? 0 : upper - max - lower + min + 1;
    }
};