class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = ("".join([ c if c.isalnum() else "" for c in s ]))
        s = s.lower()
        return s == s[::-1]

