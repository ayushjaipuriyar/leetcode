class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
            
        orgdic = dict()
        newdic = dict()

        for x in s:
            if x in orgdic:
                orgdic[x] += 1
            else:
                orgdic[x] = 1
        for x in t:
                if x in newdic:
                    newdic[x] += 1
                else:
                    newdic[x] = 1
        if orgdic == newdic:
            return True
        return False