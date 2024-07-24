class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        def convert(mapping, num):
            if num == 0:
                return mapping[0]
            temp = ''
            while num:
                temp = str(mapping[num % 10]) + temp
                num //= 10
            return int(temp)

        conv_org = defaultdict(list)
        for num in nums: 
            conv = convert(mapping, num)
            conv_org[conv].append(num)
        #print(conv_org)
        keys_sorted = sorted(conv_org.keys())
        ans = []
        for key in keys_sorted:
            ans += conv_org[key]
        return ans