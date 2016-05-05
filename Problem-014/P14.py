class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        length = len(strs)
        ans = ''
        if length == 0:
            return ''
        elif length == 1:
            return strs[0]
        lenth_min = len(strs[0])
        for s in strs:
            if len(s) < lenth_min:
                lenth_min = len(s)
            if len(s) == 0:
                return ans
        i = 0
        j = 0
        count = 0
        while True:
            if strs[0][j] == strs[i][j]:
                count += 1
            else :
                break
            if count == length:
                ans += strs[0][j]
                count = 0
                j += 1
            if i == length - 1:
                i = 0
            i += 1
            if j >= lenth_min:
                break
        return ans
              