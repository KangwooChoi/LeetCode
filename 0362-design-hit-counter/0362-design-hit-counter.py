class HitCounter:

    def __init__(self):
        from collections import deque
        self.dq_counter = deque() 

    def hit(self, timestamp: int) -> None:
        self.dq_counter.append(timestamp)
        while self.dq_counter:
            if self.dq_counter[0] + 300 <= timestamp:
                self.dq_counter.popleft()
            else:
                break

    def getHits(self, timestamp: int) -> int:
        while self.dq_counter:
            if self.dq_counter[0] + 300 <= timestamp:
                self.dq_counter.popleft()
            else:
                break
        return len(self.dq_counter)
        


# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)