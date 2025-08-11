#
# @lc app=leetcode.cn id=6 lang=python3
#
# [6] Z 字形变换
#

# @lc code=start
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows==1 or len(s)<=numRows:
            return s
        n=len(s)
        cycle=2*numRows-2
        res=[]
        for i in range(numRows):
            for j in range(0,n-i,cycle):
                res.append(s[i+j])
                if 0<i<numRows-1 and j+cycle-i<n:
                    res.append(s[j+cycle-i])
        return ''.join(res)
        
# @lc code=end

