class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        x = str(x)
        if len(x) == 1 or len(x) == 0:
            return True
        else:
            return (x[0] == x[-1]) and self.isPalindrome(x[1:-1])
