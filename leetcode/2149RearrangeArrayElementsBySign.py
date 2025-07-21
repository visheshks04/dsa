class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pos = []
        neg = []
        for i in range(len(nums)):
            if nums[i] > 0:
                pos.append(nums[i])
            if nums[i] < 0:
                neg.append(nums[i])
        for i in range(0, len(nums), 2):
            nums[i] = pos.pop(0)
            nums[i+1] = neg.pop(0)
        return nums
