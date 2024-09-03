class Solution:
    def getLucky(self, s: str, k: int) -> int:
        numeric_str = ''
        for ch in s:
            numeric_str += str(ord(ch) - ord('a') + 1)

        while k > 0:
            digit_sum = 0
            for digit in numeric_str:
                digit_sum += int(digit)
            numeric_str = str(digit_sum)
            k -= 1

        return int(numeric_str) 