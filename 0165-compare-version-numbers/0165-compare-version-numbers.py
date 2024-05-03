class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1_list = list(map(int, version1.split('.')))
        v2_list = list(map(int, version2.split('.')))
        if len(v1_list) > len(v2_list):
            v2_list += [0] * (len(v1_list) - len(v2_list))
        elif len(v1_list) < len(v2_list):
            v1_list += [0] * (len(v2_list) - len(v1_list))
        for i in range(len(v1_list)):
            if v1_list[i] > v2_list[i]:
                return 1
            elif v1_list[i] < v2_list[i]:
                return -1
        return 0