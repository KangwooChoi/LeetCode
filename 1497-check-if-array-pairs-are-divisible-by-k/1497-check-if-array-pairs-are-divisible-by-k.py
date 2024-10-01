class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        residue = [0] * k
        for num in arr:
            q = num % k
            comp = (k - q) % k
            if residue[comp]:
                residue[comp] -= 1
            else:
                residue[q] += 1
        if any(residue):
            return False
        else:
            return True