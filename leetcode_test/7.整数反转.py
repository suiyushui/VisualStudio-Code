#
# @lc app=leetcode.cn id=7 lang=python3
#
# [7] 整数反转
#

# @lc code=start
class Solution:
    def reverse(self, x: int) -> int:
        ans,flag=0,x>0
        boundry=(1<<31)-1 if flag else (1<<31)
        x=abs(x)
        while x:
            ans=ans*10+x%10
            x//=10
        if ans>boundry:
            return 0
        else :
            return ans if flag else -ans
# @lc code=end

