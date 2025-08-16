class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        lowest_price = max(prices)
        max_difference = 0
        for i in prices:
            if i - lowest_price > max_difference:
                max_difference = i - lowest_price
            if i < lowest_price:
                lowest_price = i
        return max_difference