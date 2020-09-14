class Solution(object):
    def partition(self, arr, p, r):
        pivot = arr[r]
        i = p - 1
        for j in range(p, r):
            if arr[j] <= pivot:
                i += 1
                arr[j], arr[i] = arr[i], arr[j]
        arr[i + 1], arr[r] = arr[r], arr[i + 1]
        return i + 1
    
    def quickSort(self, arr, p, r):
        if p < r:
            q = self.partition(arr, p, r)
            self.quickSort(arr, p, q - 1);
            self.quickSort(arr, q + 1, r);
    
    def relativeSortArray(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: List[int]
        """
        arr3 = [] # store all elements not in arr2 in arr3
        for i in arr1:
            if i not in arr2:
                arr3.append(i);
        # for each element in arr2, find it's corresponding elements in arr1
        # remove them from arr1 and append them to arr2
        arr4 = []
        for i in arr2:
            while(True):
                if i in arr1:
                    idx = arr1.index(i)
                else:
                    break
                arr4.append(arr1[idx])
                arr1[idx] = '-'
        self.quickSort(arr3, 0, len(arr3) - 1)
        res = arr4 + arr3
        return res