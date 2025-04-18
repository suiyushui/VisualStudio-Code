// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;
//     vector<vector<int>> adj(n + 1);
//     for (int i = 1; i < n; ++i) {
//         int a, b;
//         cin >> a >> b;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }

//     vector<int> deg(n + 1);
//     for (int i = 1; i <= n; ++i) {
//         deg[i] = adj[i].size();
//     }

//     int max_deg = -1, cnt_max = 0, sec_max_deg = -1;
//     for (int i = 1; i <= n; ++i) {
//         int d = deg[i];
//         if (d > max_deg) {
//             sec_max_deg = max_deg;
//             max_deg = d;
//             cnt_max = 1;
//         } else if (d == max_deg) {
//             cnt_max++;
//         } else {
//             if (d > sec_max_deg) {
//                 sec_max_deg = d;
//             }
//         }
//     }

//     int best_k = n;
//     int best_node = n + 1;

//     for (int u = 1; u <= n; ++u) {
//         int current_k;
//         if (deg[u] == max_deg) {
//             int other_max;
//             if (cnt_max > 1) {
//                 other_max = max_deg;
//             } else {
//                 other_max = sec_max_deg;
//             }
//             current_k = max(max_deg, other_max - 1);
//         } else {
//             current_k = max(deg[u], max_deg - 1);
//         }

//         if (current_k < best_k || (current_k == best_k && u < best_node)) {
//             best_k = current_k;
//             best_node = u;
//         }
//     }

//     cout << best_k << ' ' << best_node << '\n';

//     return 0;
// }


#include <bits/stdc++.h>

using namespace std;

// 将int类型定义为long long类型，以支持更大的整数运算
#define int long long

// 如果没有定义Cai_Guang，则定义debug和test为空操作，即不进行任何调试或测试操作
#ifndef Cai_Guang
#define debug 
#define test 
#endif

void solve() {
    int n, m; // n表示数组a的大小，m表示要查询的次数
    std::cin >> n >> m;

    std::vector<int> a(n + 1); // 定义一个大小为n+1的数组a，用于存储输入的数据

    const int M = 1e4 + 10; // 定义常量M，用作动态规划表的大小，设为10010
    std::vector<vector<bool>> dp(M, std::vector<bool>()); // 定义一个二维布尔数组dp，用于动态规划
    std::vector<vector<std::array<int, 2>>> pre(M, std::vector<std::array<int, 2>>()); 
    // 定义一个二维数组pre，用于记录路径信息,array<int, 2>表示一个长度为2的数组，用于记录路径信息

    // 初始化dp[0]，所有元素设为false
    dp[0].assign(M, false);
    // 初始化pre[0]，所有元素设为空数组
    pre[0].assign(M, {});
    // 对于每个i，初始化dp[i]和pre[i]，dp[i][j]表示j是否可以被i整除，pre[i][j]用于记录到达dp[i][j]的路径信息
    for (int i = 1; i < M; i++) {
        dp[i].assign(M / i + 10, false); // dp[i][j]表示j是否可以被i整除
        pre[i].assign(M / i + 10, {});
    }

    // 读取输入的n个整数，存储在数组a中，注意数组索引从1开始
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    // 初始化dp[0][0]为true，表示0可以被0整除
    dp[0][0] = 1;

    // 动态规划，填充dp数组
    // 对于每个元素a[i]，尝试更新dp数组，检查通过减去a[i]后是否可以整除
    for (int i = 1; i <= n; i++) {
        for (int j = M - 1; j >= 0; j--) { // 倒序遍历j以避免覆盖
            for (int k = dp[j].size() - 1; k >= 0; k--) { // 倒序遍历k以避免覆盖
                // 检查k是否大于等于a[i]，并且dp[j][k-a[i]]为true，同时dp[j][k]为false
                // 如果满足条件，则更新dp[j][k]为true，并记录路径信息
                if(dp[j][k]) continue;
                if (k >= a[i] && dp[j][k - a[i]]) {
                    dp[j][k] = dp[j][k - a[i]];
                    pre[j][k] = {j, k - a[i]};
                }

                // 检查j是否大于等于a[i]，并且dp[j-a[i]][k]为true，同时dp[j][k]为false
                // 如果满足条件，则更新dp[j][k]为true，并记录路径信息
                else if (j >= a[i] && dp[j - a[i]][k] ) {
                    dp[j][k] = dp[j - a[i]][k];
                    pre[j][k] = {j - a[i], k};
                }
            }
        }
    }

    // 对于每个查询x，尝试找出两个数L和R，使得L*R=x，并且两者都可以被数组a中的数整除
    for (int i = 1, x; i <= m; i++) {
        std::cin >> x; // 读取查询的整数x

        // 遍历x的所有因子j，检查是否存在dp[j][x/j]为true的情况
        for (int j = 1; j * j <= x; j++) { // 只需要检查到sqrt(x)，因为因子是对称的
            if (x % j == 0) { // 如果j是x的因子
                // 检查dp[j][x/j]是否为true，即x/j是否可以被j整除
                if (dp[j][x / j]) {
                    std::cout << "Yes\n"; // 如果可以，输出"Yes"
                    int L = j, R = x / j; // 初始化L和R为因子j和x/j
                    std::vector<int> l, r; // 定义两个向量l和r，用于存储分解的路径信息

                    // 通过pre数组回溯路径，找出所有分解的步骤
                    while (L != 0 || R != 0) {
                        test(L, R); // 这里假设test是一个已定义的测试函数，但代码中未定义，因此可能是一个占位符
                        auto [LL, RR] = pre[L][R]; // 获取上一步的L和R值
                        if (L != LL) {
                            l.push_back(L - LL); // 如果L有变化，将变化量加入l
                        }
                        if (R != RR) {
                            r.push_back(R - RR); // 如果R有变化，将变化量加入r
                        }
                        L = LL; // 更新L为上一步的L值
                        R = RR; // 更新R为上一步的R值
                    }

                    // 输出分解步骤的数量以及具体步骤
                    std::cout << l.size() << ' ' << r.size() << '\n';
                    for (auto _ : l) {
                        std::cout << _ << ' ';
                    }
                    std::cout << '\n';
                    for (auto _ : r) {
                        std::cout << _ << ' ';
                    }
                    std::cout << '\n';

                    // 使用goto语句跳出循环，表示已经找到分解方案
                    goto G;
                }
            }
        }
        std::cout << "No\n"; // 如果没有找到分解方案，输出"No"
        G:;
    }
}

signed main() {
    // 提高速度，不使用标准输入输出流的同步
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

#ifdef Cai_Guang
// 如果定义了Cai_Guang，则将标准输入重定向到文件1.in，可能用于本地测试
//freopen("1.in", "r", stdin);
    localTest = true;
#endif

    // 默认只运行一次solve函数，如果需要多次运行，可以取消注释并从输入读取t的值
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve(); // 调用solve函数处理一次查询
    }
}
