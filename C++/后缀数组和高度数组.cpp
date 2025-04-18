#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100010;

// 构建字符串 s 的后缀数组
vector<int> buildSuffixArray(string s) {
    int n = s.length();
    vector<int> cnt(n), rank(n), tmp(n);
    for (int i = 0; i < n; i++) cnt[i] = i, rank[i] = s[i];
    // 通过不断倍增 k 的值来构建后缀数组
    for(int k = 1; k < n; k <<= 1){
        auto cmp = [&](int i, int j){
            return rank[i] == rank[j]? ((i + k < n) ? rank[i + k] : -1) < ((j + k < n) ? rank[j + k] : -1) : rank[i] < rank[j];  
        };
        sort(cnt.begin(), cnt.end(), cmp);
        tmp[cnt[0]] = 0; // 初始化 tmp 数组
        // 计算 rank 数组
        for (int i = 1; i < n; i++) 
            tmp[cnt[i]] = tmp[cnt[i - 1]]+(cmp(cnt[i - 1], cnt[i]))? 0 : 1;
        rank.swap(tmp);
    }
    return cnt;
}

vector<int> buildLCP(const string &s, const vector<int> &sa) {
    int n = s.size();
    vector<int> lcp(n), rank(n);
    for (int i = 0; i < n; i++) rank[sa[i]] = i; // 记录每个后缀的排名
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] > 0) {
            int j = sa[rank[i] - 1]; // 前一个后缀
            while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++; // 计算 LCP
            lcp[rank[i]] = h;
            if (h > 0) h--; // 递减 h
        }
    }
    return lcp;
}

int main(){
    string s="banana";
    vector<int> sa = buildSuffixArray(s);
    vector<int> lcp = buildLCP(s, sa);
    for(int i=0;i<lcp.size();i++){
        cout<<lcp[i]<<" ";
    }
    return 0;
}