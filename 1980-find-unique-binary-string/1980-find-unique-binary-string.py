class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        integers = set()
        for num in nums:
            integers.add(int(num, 2))
        n = len(nums)
        for num in range(n+1):
            if num not in integers:
                ans = bin(num)[2:]
                return '0'*(n-len(ans)) + ans


            
        #from itertools import product
        #elements = ['0', '1']
        #pro = product(elements, repeat = len(nums[0]))
        #nums_dict = defaultdict()
        #for e in list(pro):
        #    nums_dict[''.join(e)] = 0
        #print(nums_dict)
        #for num in nums:
        #    nums_dict[num] += 1
        #for num in nums_dict.keys():
        #    if nums_dict[num] == 0:
        #        return num
        
        
