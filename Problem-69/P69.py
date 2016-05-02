class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if 1 == x or 0 == x:
            return x
        
        mi = 0
        ma = x
        ans = x / 2
        
        while mi != ma:
            if ans ** 2 <= x and (ans + 1) ** 2 > x:
                return ans
            else:
                if ans **2 < x:
                    mi = ans
                    ans = (ma + mi) / 2
                else:
                    ma = ans
                    ans = (ma + mi) / 2
        