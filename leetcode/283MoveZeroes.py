class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        first_zero = -1
        for i,n in enumerate(nums):
            if n == 0 and first_zero == -1:
                first_zero = i
            if n != 0 and first_zero != -1:
                nums[i], nums[first_zero] = nums[first_zero], nums[i]
                first_zero += 1
