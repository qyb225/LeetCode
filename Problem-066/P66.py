class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        if len(digits) == 0:
            return [1]
        i = len(digits) - 1
        digits[i] += 1
        while digits[i] >= 10:
            if i > 0:
                digits[i] -= 10
                digits[i - 1] += 1
                i -= 1
            elif i == 0:
                digits[i] -= 10
                digits = [1] + digits    
        return digits
