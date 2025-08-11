#
# @lc app=leetcode.cn id=8 lang=python3
#
# [8] 字符串转换整数 (atoi)
#

# @lc code=start
from curses.ascii import isdigit


class Solution:
    def myAtoi(self, s: str) -> int:
        s=s.lstrip()
        if not s:
            return 0
        sign,start=1,0
        if s[0]=='-':
            sign=-1
            start=1
        elif s[0]=='+':
            start=1
        max_limit=(1<<31)-1
        min_limit=-(1<<31)
        abs_max=max_limit if sign==1 else -min_limit
        num=0

        for i in range(start,len(s)):
            c=s[i]
            if not c.isdigit():
                break
            num=num*10+int(c)
            if num>abs_max:
                return max_limit if sign==1 else min_limit
        return sign*num


# @lc code=end

