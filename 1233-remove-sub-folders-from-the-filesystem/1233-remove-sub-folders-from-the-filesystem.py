class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort()
        print(folder)
        prefix = folder[0]
        ans = [prefix]
        for f in folder[1:]:
            prefix_ = prefix + '/'
            f_ = f + '/'
            if not f_.startswith(prefix_):
                prefix = f
                ans.append(prefix)
        return ans