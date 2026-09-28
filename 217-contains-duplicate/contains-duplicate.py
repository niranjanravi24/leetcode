class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        mp = {}
        for i in range(len(nums)):
            mp[nums[i]] = mp.get(nums[i],0) + 1
            if mp[nums[i]] > 1:
                return True
        return False