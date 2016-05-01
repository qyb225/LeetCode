class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        dic = {'(':0,')':0,'[':0, ']':0,'{':0,'}':0}
        if len(s) == 0:
            return True
        for i in s:
            dic[i] += 1
        if dic['('] != dic[')']:
            return False
        elif dic['['] != dic[']']:
            return False
        elif dic['{'] != dic['}']:
            return False
        
        for i in range(len(s)):
            for k in dic:
                dic[k] = 0
            dic[s[i]] += 1
            if s[i] == '(':
                if not ')' in s[i+1:]:
                    return False
                for j in range(i+1,len(s)):
                    dic[s[j]] += 1
                    if s[j] == ')':
                        if dic[s[i]] != dic[s[j]]:
                            if not ')' in s[j+1:]:
                                return False
                        elif dic['('] != dic[')']:
                            return False
                        elif dic['['] != dic[']']:
                            return False
                        elif dic['{'] != dic['}']:
                            return False
                        else:
                            break
            elif s[i] == '[':
                if not ']' in s[i+1:]:
                    return False
                for j in range(i+1,len(s)):
                    dic[s[j]] += 1
                    if s[j] == ']':
                        if dic[s[i]] != dic[s[j]]:
                            if not ']' in s[j+1:]:
                                return False
                        elif dic['('] != dic[')']:
                            return False
                        elif dic['['] != dic[']']:
                            return False
                        elif dic['{'] != dic['}']:
                            return False
                        else:
                            break
            elif s[i] == '{':
                if not '}' in s[i+1:]:
                    return False
                for j in range(i+1,len(s)):
                    dic[s[j]] += 1
                    if s[j] == '}':
                        if dic[s[i]] != dic[s[j]]:
                            if not '}' in s[j+1:]:
                                return False
                        elif dic['('] != dic[')']:
                            return False
                        elif dic['['] != dic[']']:
                            return False
                        elif dic['{'] != dic['}']:
                            return False
                        else:
                            break
        return True
