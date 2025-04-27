/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n < 2) return n;
        bool flag[128] = {false};
        int max_len = 0;
        for(int i = 0, j = 0; j < n; j++){
            if(flag[s[j]]){
                do{
                    flag[s[i]] = false;
                }while(s[i++]!= s[j]);
            }
            flag[s[j]] = true;
            max_len = max(max_len, j - i + 1);
        }
        return max_len;
    }
};
// @lc code=end

