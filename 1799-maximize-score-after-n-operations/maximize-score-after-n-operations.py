from math import gcd

class Solution:
    def maxScore(self, nums: List[int]) -> int:
        res = 0
        def recur(nums: list[int], acc: list[int]):
            if not nums:
                nonlocal res
                res = max(res, sum(i * num for i, num in enumerate(sorted(acc), start=1)))
                return

            for i0 in range(1, len(nums)):
                acc.append(gcd(nums[0], nums[i0]))
                recur([nums[i] for i in range(1, len(nums)) if i != i0], acc)
                acc.pop()

        recur(nums, [])

        return res        