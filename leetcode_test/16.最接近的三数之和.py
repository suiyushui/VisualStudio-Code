#
# @lc app=leetcode.cn id=16 lang=python3
#
# [16] 最接近的三数之和
#

# @lc code=start
from typing import List
class Solution:

    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n=len(nums)
        closest_sum =nums[0]+nums[1]+nums[2]
        min_diff=abs(closest_sum-target)
        for i in range(n-2):
            if i>0 and nums[i]==nums[i-1]:
                continue
            left,right=i+1,n-1
            while left<right:
                current_sum=nums[i]+nums[left]+nums[right]
                current_diff=abs(current_sum-target)

                if current_diff<min_diff:
                    min_diff=current_diff
                    closest_sum=current_sum

                    if min_diff==0:
                        return closest_sum
                if current_sum>=target:
                    right-=1
                else:
                    left+=1
        return closest_sum

    def binarySearch(self, nums: List[int],start:int, end:int, target:int)->int:
        while start<end:
            mid=start+(end-start)//2
            if nums[mid]>target:
                end=mid-1
            else:
                start=mid+1
        return start

# @lc code=end

