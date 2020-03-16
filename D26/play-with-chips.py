class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        evens, odds = 0, 0
        for chip in chips:
            if chip % 2 == 0:
                evens += 1
            else:
                odds += 1
        if evens >= odds:
            return odds;
        else:
            return evens;