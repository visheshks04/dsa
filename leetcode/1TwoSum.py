class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        difference_to_index = {}
        for i,n in enumerate(nums):
            if difference_to_index.get(n, None) != None:
                return [difference_to_index[n], i]
            difference_to_index[target-n] = i
