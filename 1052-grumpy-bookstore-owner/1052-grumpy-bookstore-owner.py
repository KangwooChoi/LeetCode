class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        n = len(customers)
        ans = 0
        for i in range(n):
            ans += customers[i] if grumpy[i] == 0 else 0
        max_plus = 0
        cur_plus = 0
        for i in range(minutes):
            cur_plus += customers[i] if grumpy[i] == 1 else 0
        max_plus = cur_plus
        for i in range(minutes, n): 
            plus = customers[i] if grumpy[i] == 1 else 0
            minus = customers[i-minutes] if grumpy[i-minutes] == 1 else 0
            cur_plus += plus - minus
            max_plus = max(max_plus, cur_plus) 
        ans += max_plus
        return ans


