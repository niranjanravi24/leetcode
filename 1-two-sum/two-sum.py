class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        mp = {}
        for i in range(len(nums)):
            compli = target - nums[i]
            if compli in mp:
                return [mp[compli],i]
            mp[nums[i]] = i
        return [-1,-1]