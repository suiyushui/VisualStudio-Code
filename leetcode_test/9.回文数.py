#
# @lc app=leetcode.cn id=9 lang=python
#
# [9] 回文数
#

# @lc code=start
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0 or x % 10 == 0 and x != 0:
            return False
        rev=0
        while x>rev:
            rev =rev* 10+x%10
            x//=10
        return x==rev or x==rev//10
# @lc code=end

