class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        curr_max = 0
        for i in range(1, len(nums)):
            if nums[i] > nums[curr_max]:
                curr_max += 1
                nums[i], nums[curr_max] = nums[curr_max], nums[i]
        return curr_max + 1
