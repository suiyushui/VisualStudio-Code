#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// 计算坏字符规则数组
// 对于模式串中的每个字符，记录它在模式串中最右边的位置
void getRight(string &pat, array<int, 256> &right)
{
    // 初始化数组为-1，表示不存在的字符在模式串中的位置
    right.fill(-1);
    for (int j = 0; j < pat.length(); j++)
        // 记录每个字符在模式串中最右边的位置
        right[(unsigned char)pat.at(j)] = j;
}

// 实现 Boyer-Moore 字符串匹配算法
// pat: 模式串
// txt: 文本串
// right: 坏字符规则数组
int Search(string &txt, string &pat, array<int, 256> &right)
{
    int n = txt.length();
    int m = pat.length();
    int skip = 0;
    // 遍历文本串，每次跳过skip个字符
    for (int i = 0; i <= n - m; i += skip)
    {
        skip = 0;
        // 从模式串的最右字符开始，与文本串中的相应字符进行比较
        for (int j = m - 1; j >= 0; j--)
        {
            if (txt[i + j] != pat[j])
            {
                // 如果字符不匹配，根据坏字符规则计算跳过步数
                skip = max(1, j - right[txt[i + j]]);
                break;
            }
        }
        // 如果skip为0，说明模式串与文本串的某一部分完全匹配，返回匹配起始位置
        if (skip == 0)
            return i;
    }
    // 如果没有找到匹配的模式串，返回-1
    return -1;
}

// 构建KMP算法中next数组
// pat: 模式串
vector<int> buildNext(string &pat)
{
    int n = pat.length();
    vector<int> next(n, 0);
    next[0] = -1; // next[0]初始化为-1，表示没有更长的相同前缀和后缀
    int i = 0, j = -1;
    // 构建next数组的过程
    while (i < n - 1)
    {
        if (j == -1 || pat[i] == pat[j])
        {
            i++; // 向后移动一个字符
            j++; // 向后移动一个字符
            next[i] = j; // 记录当前最长相同前缀和后缀的长度
        }
        else
        {
            // 如果字符不匹配，根据next数组进行回退
            j = next[j];
        }
    }
    return next;
}

// 实现KMP字符串匹配算法
// txt: 文本串
// pat: 模式串
int KMPSearch(string &txt, string &pat)
{
    int n = txt.length();
    int m = pat.length();
    vector<int> next = buildNext(pat); // 获取next数组
    int j = 0;
    // 遍历文本串
    for (int i = 0; i < n; i++)
    {
        // 如果模式串和文本串字符不匹配且j>0，根据next数组进行回退
        while (j > 0 && pat[j] != txt[i])
            j = next[j];
        // 如果字符匹配，继续向后匹配
        if (pat[j] == txt[i])
            j++;
        // 如果j等于模式串长度，说明模式串完全匹配，返回匹配起始位置
        if (j == m)
            return i - m + 1;
    }
    // 如果没有找到匹配的模式串，返回-1
    return -1;
}

// 测试 Boyer-Moore 和 KMP 算法
int main()
{
    std::string txt = "ABACADABRAC"; // 文本串
    std::string pat = "ABRA"; // 模式串

    std::array<int, 256> right;
    getRight(pat, right); // 计算坏字符规则数组

    int pos = Search(txt, pat, right);
    if (pos != -1)
    {
        std::cout << "模式串在文本串中的起始位置: " << pos << std::endl;
    }
    else
    {
        std::cout << "未找到匹配" << std::endl;
    }

    // 测试KMP算法
    cout << KMPSearch(txt, pat) << endl;

    return 0;
}
