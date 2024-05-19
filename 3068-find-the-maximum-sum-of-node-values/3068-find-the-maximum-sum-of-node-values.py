class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        sumVal = 0
        count = 0
        positiveMinimum = 1 << 30
        negativeMaximum = -1 * (1 << 30)

        for nodeValue in nums:
            operatedNodeValue = nodeValue ^ k
            sumVal += nodeValue
            netChange = operatedNodeValue - nodeValue
            if netChange > 0:
                positiveMinimum = min(positiveMinimum, netChange)
                sumVal += netChange
                count += 1
            else:
                negativeMaximum = max(negativeMaximum, netChange)

        # If the number of positive netChange values is even, return the sum.
        if count % 2 == 0:
            return sumVal

        # Otherwise return the maximum of both discussed cases.
        return max(sumVal - positiveMinimum, sumVal + negativeMaximum)
#class Solution:
#    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
#        cand = []
#        for i in range(len(nums)):
#            print("nums: ", nums)
#            nums_cp = copy.deepcopy(nums)
#            for u, v in edges[:i] + edges[i+1:]:
#                base = nums_cp[u] + nums_cp[v]
#                comp = nums_cp[u]^k + nums_cp[v]^k
#                print("u, v, k: ", nums[u], nums[v], k)
#                print("u^k, v^k: ", nums[u]^k, nums[v]^k)
#                print("base, comp: ", base, comp)
#                if comp > base:
#                    nums_cp[u] ^= k
#                    nums_cp[v] ^= k
#            print("nums_cp: ", nums_cp)
#            cand.append(sum(nums_cp))
#        print(cand)
#        return max(cand)

        #ops = 1
        #while ops:
        #    ops = 0
        #    for u, v in edges:
        #        base = nums[u] + nums[v]
        #        comp = nums[u] ^ k + nums[v] ^ k
        #        print("u, v, k: ", nums[u], nums[v], k)
        #        print("u^k, v^k: ", nums[u]^k, nums[v]^k)
        #        print("base, comp: ", base, comp)
        #        if comp > base:
        #            ops += 1
        #            nums[u] ^= k
        #            nums[v] ^= k
        #return sum(nums)
