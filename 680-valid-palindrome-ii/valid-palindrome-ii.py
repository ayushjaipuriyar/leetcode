class Solution:
    def validPalindrome(self, s: str) -> bool:
        l, r = 0, len(s)-1
        # if s == s[::-1]: return True
        while l < r:
            if s[l] == s[r]:
                l += 1
                r -= 1
                # news = s[0:l] + s[l+1:]
                # news2 = s[0:r] + s[r+1:]
            else:
                news = s[l + 1: r + 1]
                news2 = s[l: r]
                return news == news[::-1] or news2 == news2[::-1]
        return True