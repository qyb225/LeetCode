class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        while length >= 0:
            i = 0
            while i + length <= len(s):
                if self.notRepeat(s[i: i + length]):
                    return length
                i += 1
            length -= 1
        return length
        
    def notRepeat(self, s):
        for i in range(len(s)):
            for j in range(len(s)):
                if s[i] == s[j] and i != j:
                    return False
        return True
