class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        arr_dict = defaultdict(int)
        for s in arr:
            arr_dict[s] += 1
        #print(arr_dict)
        count = 0
        for key in arr_dict:
            if arr_dict[key] == 1:
                count += 1
                if count == k:
                    return key
        return ''