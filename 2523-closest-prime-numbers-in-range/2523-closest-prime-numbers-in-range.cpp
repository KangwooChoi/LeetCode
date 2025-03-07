class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if (right == 1 || right == 2 || right == 3) return {-1, -1};
        vector<bool> isPrime(right+1,true); 
        isPrime[0] = false, isPrime[1] = false;
        vector<int> primes;
        for (int i = 2; i <= right; i++) {
            if (isPrime[i] == true) {
                for (int j = 2; j < i; j++) {
                    if (isPrime[j] && i % j == 0) isPrime[i] = false;
                }
            }
            int k = 2;
            while (i*k <= right) {
                isPrime[i*k++] = false;
            } 
        }
        for (int i = left; i <= right; i++) {
            if (isPrime[i] == true) {
                primes.push_back(i);
            } 
        }
        if (primes.size() < 2) return {-1, -1}; 
        else {
            int prev = left-1, post = right+1;
            for (int i = 0; i < primes.size() - 1; i++) { 
                if (primes[i+1] - primes[i] < post - prev) {
                    post = primes[i+1], prev = primes[i];
                } 
            }
            return {prev, post};
        }
    }
};