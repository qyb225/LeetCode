class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        judge = 1
        count = 0
        ans = 0
        n = 0
        if x < 0:
            judge = -1
        x = abs(x)
        print x
        while (count >= 0):
            if x / (10 ** count) == 0:
                break
            count += 1
        count -= 1
        while x > 0:
            mid = x / (10 ** count)
            ans += mid * (10 ** n)
            n += 1
            x -= mid * 10 ** count
            count -= 1
        return judge * ans
