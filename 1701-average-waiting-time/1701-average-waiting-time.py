class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        n = len(customers)
        elapsed = [0.] * n
        cooked = 0.
        for i in range(n):
            start, need = customers[i][0], customers[i][1]
            if start > cooked:
                cooked = start + need
            else:
                cooked += need
            elapsed[i] = cooked - start 
        
        return sum(elapsed) / float(n)