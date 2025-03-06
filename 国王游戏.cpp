#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, K; // 声明棋盘大小 n 和国王数量 K
    n = 9; K = 13; // 将 n 设置为 9，K 设置为 13
    // cin >> n >> K; // 可替换为从用户输入获取 n 和 K 的值
    int limit = 1 << (n + 1); // 计算状态空间的上限，第 n 位用于表示左上角，0~n-1 表示轮廓线上每一列
    // 定义三维动态规划数组 dp，用于存储状态
    // 第一维: 当前位置（0 到 n*n）
    // 第二维: 放置的国王数量（0 到 K）
    // 第三维: 表示某一行的轮廓状态，初始化为 0
    vector<vector<vector<long long>>> dp(n * n + 1, vector<vector<long long>>(K + 1, vector<long long>(limit, 0))); 
    dp[0][0][0] = 1; // 设置初始状态：0 行、0 个国王，轮廓状态为 0 的放置方式为 1

    // 遍历棋盘上的每个位置状态
    for (int pos = 0; pos < n * n; pos++) {
        int j = pos % n; // 计算当前的列索引 j
        // 遍历国王个数状态
        for (int k = 0; k <= K; k++) {
            // 遍历轮廓状态
            for (int st = 0; st < limit; st++) {
                if (!dp[pos][k][st]) continue; // 如果当前状态的计数为 0，跳过

                int ul = (st >> n) & 1; // 提取左上角是否放了国王的状态
                int cols = st - (ul << n); // 轮廓线上的每一列是否有国王，此行不包括左上角

                // 检查条件，如果左上角没有国王且当前列及相邻列没有国王
                // 且当前放置的国王数量小于 K，可以在当前位置放一个国王
                if (!ul && !(cols & ((1 << j) >> 1 | (1 << j) | (1 << j) << 1)) && k < K) 
                    dp[pos + 1][k + 1][st | (1 << j)] += dp[pos][k][st]; // 更新状态，放置国王

                int nul = (cols >> j) & 1; // 获取当前列 j 的国王状态
                int ncols = cols & (~(1 << j)); // 更新轮廓状态，去掉当前列 j 的国王状态
                if (j == n - 1) nul = 0; // 如果当前是最后一列，将左上角的国王状态重置为 0

                // 更新状态，表示在当前位置不放置国王的情况
                dp[pos + 1][k][(nul << n) | ncols] += dp[pos][k][st];
            }
        }
    }
    
    long long result = 0; // 初始化结果计数
    // 累加所有可能的状态，计算放 K 个国王的有效配置
    for (int st = 0; st < limit; st++) 
        result += dp[n * n][K][st];
    
    cout << result << endl; // 输出结果
    return 0; // 程序正常结束
}