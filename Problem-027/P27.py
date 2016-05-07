class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        length = len(nums)
        i = 0
        while i < length:
            if val == nums[i]:
                nums.pop(i)
                i -= 1
                length -= 1
            i += 1
        return len(nums)