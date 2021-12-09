class Solution:
    def maxSumOfOneSubarray(self, nums: List[int], k: int) -> List[int]:
        ans = []
        sum1, maxSum1 = 0, 0
        for i, num in enumerate(nums):
            sum1 += num
            if i >= k - 1:
                if sum1 > maxSum1:
                    maxSum1 = sum1
                    ans = [i - k + 1]
                sum1 -= nums[i - k + 1]
        return ans
