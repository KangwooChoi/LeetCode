class StockSpanner:

    def __init__(self):
        self.stack = []

    def next(self, price: int) -> int:
        #print(self.stack)
        #print(price)
        if not self.stack or price < self.stack[-1][0]:
            self.stack.append([price, 1])
            return 1
        ans = 1
        while self.stack:
            if price >= self.stack[-1][0]:
                _, plus = self.stack.pop()
                ans += plus 
            else:
                break
        self.stack.append([price, ans]) 
        return ans

        


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)