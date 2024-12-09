class Solution {
public:
    int tribonacci(int n) {
        vector<int> tribo(n+1, 0);
        
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        tribo[1] = 1;
        tribo[2] = 1;

        for (int i = 3; i < n + 1; i++) {
            tribo[i] = tribo[i - 1] + tribo[i - 2] + tribo[i - 3];
        }
        return tribo[n];
    }
};