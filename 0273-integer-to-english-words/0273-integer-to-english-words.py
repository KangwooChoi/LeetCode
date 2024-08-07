class Solution:
    def numberToWords(self, num: int) -> str:
        def chunker(num):
            ret = []
            while num:
                ret.append(num % 1000)
                num //= 1000
            return ret

        def helper(chunk, degree):
            if chunk == 0:
                return ""
            units = ['', 'Thousand', 'Million', 'Billion']
            digits = ['', 'One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine']
            teen_digit = ['Ten', 'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen']
            ten_unit = ['', '', 'Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety'] 
            ret = units[degree]
            hundred = chunk // 100
            two_digit = chunk % 100
            if 10 <= two_digit < 20:
                ret = teen_digit[two_digit - 10] + ' ' + ret
            elif two_digit != 0:
                if two_digit % 10:
                    ret = digits[two_digit % 10] + ' ' +  ret
                if two_digit // 10:
                    ret = ten_unit[two_digit // 10] + ' ' + ret
                
            if hundred:
                ret = digits[hundred] + ' Hundred ' + ret
            return ret if degree != 0 else ret[:-1]

        if num == 0:
            return 'Zero'

        chunks = chunker(num)
        ans = ''
        for i, chunk in enumerate(chunks):
            if chunk == 0:
                continue
            if ans != '':
                ans = helper(chunk, i) + ' ' + ans
            else:
                ans = helper(chunk, i)

        return ans