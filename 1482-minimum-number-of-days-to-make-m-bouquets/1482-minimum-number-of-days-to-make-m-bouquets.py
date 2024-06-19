class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        def check(locations, m, k):
            done = 0
            cont = 0
            for i in range(len(locations)):
                if locations[i] == 1:
                    cont += 1
                    if cont == k:
                        done += 1
                        cont = 0
                else:
                    cont = 0
            return done  

        n = len(bloomDay)
        if n < m * k:
            return -1
        if n == m * k:
            return max(bloomDay)

        from heapq import heappop, heappush
        bloomed = [0] * n
        day_index = []
        for i in range(n):
            heappush(day_index, (-bloomDay[i], i))
        ans = -1
        flowers = 0
        while day_index:
            day, index = day_index.pop()
            print("day, index: ", day, index) 
            flowers += 1
            bloomed[index] = 1
            prev = day
            while day_index:
                day, index = day_index.pop()
                print("day, index: ", day, index)
                if day != prev:
                    heappush(day_index, (day, index))
                    break
                flowers += 1
                bloomed[index] = 1
            print("day: ", -day)
            if flowers >= m * k:
                ret = check(bloomed, m, k)
                print("done: ", ret)
                if ret >= m:
                    return -prev
        return ans
            
                

