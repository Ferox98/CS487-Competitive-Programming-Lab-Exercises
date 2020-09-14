class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        idx, i = -1, 0
        while i < len(s):
            idx = t.find(s[i], idx + 1)
            if idx == -1:
                return False
            i += 1
        return True