class Solution:
    def shareCandies(self, candies, k):
        unique_flav = 0

        # Store the total number of unique flavors in the array.
        flav_freq = defaultdict(int)
        for c in candies:
            flav_freq[c] += 1
            if flav_freq[c] == 1:
                unique_flav += 1

        # Get the flavors used completely in the window.
        used_in_window = 0
        for i in range(k):
            flav_freq[candies[i]] -= 1
            if flav_freq[candies[i]] == 0:
                used_in_window += 1

        # Get the flavors in the remaining array currently.
        max_flav = unique_flav - used_in_window

        # Slide the window to the right.
        for i in range(k, len(candies)):
            # Remove the candy on the left end from the window.
            flav_freq[candies[i - k]] += 1
            if flav_freq[candies[i - k]] == 1:
                used_in_window -= 1

            # Add the candy on the right end at index i.
            flav_freq[candies[i]] -= 1
            if flav_freq[candies[i]] == 0:
                used_in_window += 1

            max_flav = max(max_flav, unique_flav - used_in_window)

        return max_flav