class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        n = len(quality)
        total_cost = float("inf")
        current_total_quality = 0
        wage_to_quality_ratio = []

        # Calculate wage-to-quality ratio for each worker
        for i in range(n):
            wage_to_quality_ratio.append((wage[i] / quality[i], quality[i]))

        # Sort workers based on their wage-to-quality ratio
        wage_to_quality_ratio.sort(key=lambda x: x[0])

        # Use a heap to keep track of the highest quality workers
        highest_quality_workers = []

        # Iterate through workers
        for i in range(n):
            heapq.heappush(highest_quality_workers, -wage_to_quality_ratio[i][1])
            current_total_quality += wage_to_quality_ratio[i][1]

            # If we have more than k workers, 
            # remove the one with the highest quality
            if len(highest_quality_workers) > k:
                current_total_quality += heapq.heappop(highest_quality_workers)

            # If we have exactly k workers, 
            # calculate the total cost and update if it's the minimum
            if len(highest_quality_workers) == k:
                total_cost = min(
                    total_cost, current_total_quality * wage_to_quality_ratio[i][0]
                )

        return total_cost
#class Solution:
#    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
#        from itertools import combinations
#        index_list = [i for i in range(len(quality))]
#        combos = combinations(index_list, k)
#        #print(combos)
#        ans = 987654321.
#        for combo in combos:
#            unit = 0.
#            total_quality = 0.
#            for i in combo:
#                unit = max(unit, wage[i]/quality[i])
#                total_quality += quality[i]
#            #print(unit, total_quality)
#            ans = min(ans, total_quality * unit)
#        #print(ans)
#        return ans