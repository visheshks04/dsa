class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = nums[0]
        for i in nums[1:]:
            result ^= i
        return result
