class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        removed = 0
        for i in range(len(A[0])):
            ordered = True
            min_char = A[0][i]
            for j in range(len(A)):
                if A[j][i] < min_char:
                    removed += 1
                    break
                min_char = A[j][i]
        return removed