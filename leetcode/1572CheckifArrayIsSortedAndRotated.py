class Solution:
    def check(self, nums: List[int]) -> bool:
        peak_hit = None
        for i in range(len(nums)-1):
            order = nums[i+1] >= nums[i]
            if not order:
                peak_hit = i
                break

        if peak_hit is None: return True

        for i in range(peak_hit+1, len(nums)-1):
            order = nums[i+1] >= nums[i]
            if not order: return False
        
        if nums[len(nums)-1] > nums[0]: return False

        return True
