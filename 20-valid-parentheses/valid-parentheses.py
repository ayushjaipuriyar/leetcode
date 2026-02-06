class Solution:
    def isValid(self, s: str) -> bool:
        if not s:
            return True
        stack = []
        for x in s:
            if x == "[" or x == "{" or x == "(":
                stack.append(x)
            elif not stack:
                return False
            elif x == "]" and stack[-1] == "[":
                stack.pop()
            elif x == "}" and stack[-1] == "{":
                stack.pop()
            elif x == ")" and stack[-1] == "(":
                stack.pop()
            else:
                return False
        return not stack
