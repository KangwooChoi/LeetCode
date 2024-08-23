class Solution:
    def divide(self, expr: str):
        numerator = []
        denominator = []
        temp = ''
        is_num = True
        for c in expr:
            if (c == '+' or c == '-') and is_num == False:
                denominator.append(int(temp))
                is_num = True
                temp = c
                continue
            if c == '/':
                if is_num == True:
                    numerator.append(int(temp))
                    is_num = False
                temp = ''
            else:
                temp += c
        denominator.append(int(temp))
        return [numerator, denominator]
    
    def gcd(self, a: int, b: int) -> int:
        while b > 0:
            a, b = b, a % b
        return a
        
    def lcm(self, arr: list) -> int:
        ans = arr[0]
        for i in range(1, len(arr)):
            ans = ans * arr[i] // self.gcd(ans, arr[i])

        return ans
    
    def conv_num(self, numerator, denominator, lcm_):
        n = len(numerator)
        ans = 0
        for i in range(n):
            ans += numerator[i] * (lcm_ // denominator[i])
        return ans

        
    def fractionAddition(self, expression: str) -> str:
        numerator, denominator = self.divide(expression)
        #print(numerator)
        #print(denominator)
        lcm_denom = self.lcm(denominator)
        #print(lcm_denom)
        sum_numerator = self.conv_num(numerator, denominator, lcm_denom)
        #print(sum_numerator)
        if sum_numerator == 0:
            return '0/1'
        gcd_ = self.gcd(sum_numerator, lcm_denom)
        final_num = sum_numerator // gcd_
        final_denom = lcm_denom // gcd_
        return str(final_num) + '/' + str(final_denom)