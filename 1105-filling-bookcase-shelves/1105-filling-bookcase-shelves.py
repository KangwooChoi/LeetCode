class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        #n = len(books)
        #INF = 1e9
        #dp = [INF] * n
        #dp[0] = books[0][1]
        #for i in range(1, n):
        #    cur_w, h_max = books[i][0], books[i][1]
        #    dp[i] = dp[i-1] + h_max
        #    for j in range(i-1, -1, -1):
        #        if cur_w + books[j][0] > shelfWidth:
        #            break
        #        cur_w += books[j][0]
        #        h_max = max(h_max, books[j][1])
        #        dp[i] = min(dp[i], (dp[j-1] + h_max if j-1 >= 0 else h_max))
#
        #return dp[n-1]
        n = len(books)
        # dp[i] will store the minimum height of the bookcase containing all
        # books up to and excluding i
        dp = [0] * (n + 1)
#
        # Base cases
        dp[0] = 0
        dp[1] = books[0][1]
#
        for i in range(2, n + 1):
            # new shelf built to hold current book
            remaining_shelf_width = shelfWidth - books[i - 1][0]
            max_height = books[i - 1][1]
            dp[i] = books[i - 1][1] + dp[i - 1]
#
            j = i - 1
            # calculate the height when previous books are added to new shelf
            while j > 0 and remaining_shelf_width - books[j - 1][0] >= 0:
                max_height = max(max_height, books[j - 1][1])
                remaining_shelf_width -= books[j - 1][0]
                dp[i] = min(dp[i], max_height + dp[j - 1])
                j -= 1
#
        return dp[n]