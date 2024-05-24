class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        def backtrack(arr, letters_cnt):
            print("arr: ", arr)
            print("letters_cnt: ", letters_cnt)
            total = []
            for i in range(len(arr)):
                letters_cnt_cp = copy.deepcopy(letters_cnt)
                point, word = arr[i]
                flag = True
                for c in word:
                    index = ord(c) - ord('a')
                    if letters_cnt_cp[index] > 0:
                        letters_cnt_cp[index] -= 1
                    else:
                        flag = False
                        break
                if flag:
                    total.append(point)
                    total[-1] += backtrack(arr[i:], letters_cnt_cp)
            return max(total) if total else 0

        avail_words = [] 
        letters_cnt = [0] * 26
        for l in letters:
            letters_cnt[ord(l)-ord('a')] += 1
        for word in words:
            letters_cnt_cp = copy.deepcopy(letters_cnt)
            flag = True
            avail_score = 0
            for c in word:
                index = ord(c) - ord('a')
                if letters_cnt_cp[index] > 0:
                    letters_cnt_cp[index] -= 1
                    avail_score += score[index]
                else:
                    flag = False
                    break
            if flag:
                avail_words.append([avail_score, word])
        avail_words.sort(reverse=True)
        print("avail_words: ", avail_words)

        return backtrack(avail_words, letters_cnt) 