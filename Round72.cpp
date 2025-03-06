// 小红定义一个字符串是好串，当且仅当该字符串任意一对相邻字符都不同。现在小红拿到了一个01串，请你帮小红求出有多少个长度不小于2的连续子串是好串。
// #include <iostream>
// using namespace std;

// int main() {
//     string s;
//     cin >> s;
//     long long ans = 0;
//     int n = s.size();

//     for (int i = 0, j = 0; i < n; i++) {
//         if (j < i + 1) {
//             j = i + 1;
//         }
//         while (j < n && s[j] != s[j - 1]) {
//             j++;
//         }
//         ans += j - i - 1;
//     }
//     cout << ans << endl;
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string s;
//     cin>>s;
//     int n=s.length();
//     long long num=1,ans=0;
//     for(int i=0;i<n-1;i++){
//         if(s[i]!=s[i+1])
//             num++;
//         if(s[i]==s[i+1]||i==n-2){
//             ans+=num*(num-1)/2;
//             num=1;
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }

// 思路：
// 1. 遍历字符串，对于每个字符，判断其是否与前一个字符相同，若相同则跳过，若不同则开始计数，直到遇到相同的字符或到达字符串末尾。
// 2. 对于每个计数的子串，判断其是否为好串，若为好串则累加，若不是好串则跳过。
// 3. 最后输出累加的好串个数。


// 小红拿到了一个由0和1组成的字符串，她站在字符串的第一个字符处。小红可以进行两种移动：花费 x 能量，移动到当前位置右边、离当前位置最近的，和当前字符相同的字符；花费 y 能量，移动到当前位置右边、离当前位置最近的，和当前字符不同的字符。小红想知道，她移动到字符串最右端的最小花费是多少。 

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y;
    n=5;x=1;y=2;
    //cin>>n>>x>>y;
    if(n<2) {cout<<0<<endl; return 0;}
    string s;
    s="01011";
    //cin>>s;
    int last[2]={-1,-1};
    vector<int> dp(n,0x3f3f3f3f);
    dp[0]=0;
    last[s[0]-'0']=0;
    for(int i=1;i<n;i++){
        if(last[s[i]-'0']!=-1)
            dp[i]=min(dp[last[s[i]-'0']]+x,dp[i]);
        if(last[s[i]-'0'^1]!=-1)
            dp[i]=min(dp[last[(s[i]-'0')^1]]+y,dp[i]);
    }
    cout<<dp[n-1]<<endl;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 关闭C和C++标准库之间的同步
    cin.tie(0)->sync_with_stdio(0);
    // 设置cout为固定精度
    cout << fixed << setprecision(20);


    // 读取测试用例的数量
    int t = 1;
    // cin >> t;

    while (t--) {
        int64_t n, x, y;
        cin >> n >> x >> y;

        // 定义一个足够大的数作为无穷大
        constexpr int64_t inf = 0x3f3f3f3f3f3f3f3f;
        // 初始化动态规划数组，所有值设为无穷大
        vector<int64_t> dp(n, inf);
        // 最后一个位置到达的花费为0
        dp[n - 1] = 0;
        deque<int> q[2];
        // 注意：q[0]存储相同字符的索引，q[1]存储不同字符的索引
        string s;
        cin >> s;

        // 从字符串末尾开始处理
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            // 如果不是最后一个字符
            if (i != n - 1) {
                int64_t v = inf;
                // 如果相同字符队列不为空
                if (!q[c - '0'].empty()) {
                    v = min(v, dp[q[c - '0'].back()] + x);
                }
                // 如果不同字符队列不为空
                if (!q[c - '0' ^ 1].empty()) {
                    v = min(v, dp[q[c - '0' ^ 1].back()] + y);
                }
                // 更新当前位置的dp值
                dp[i] = v;
            }
            // 将当前索引推入对应的双端队列
            q[c - '0'].push_back(i);
        }
        cout << dp[0] << endl;
    }

    return 0;
}*/