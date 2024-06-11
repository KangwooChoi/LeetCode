class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        hashmap = defaultdict(int)
        for i in arr2:
            hashmap[i] = 1

        remains = []
        for num in arr1:
            if hashmap[num]: 
                hashmap[num] += 1
            else:
                remains.append(num) 
        ans = []
        for key in hashmap.keys():
            ans += [key] * (hashmap[key] - 1)
        ans += sorted(remains)
        return ans