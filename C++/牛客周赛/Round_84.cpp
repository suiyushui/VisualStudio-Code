// 牛客竞赛Round 84
// https://ac.nowcoder.com/acm/contest/103152
/*
小红定义了一棵树的陡峭值为：每条边连接的两个相邻节点的编号差值的绝对值之和。
如果一棵树只有一个节点，则其陡峭值为0。例如，对于一棵由3个节点组成的树，
若节点2和节点3连边，节点3和节点1连边，则该树的陡峭值为|2-3| + |3-1| = 3。
现在，小红拿到了一棵由n个节点组成的树，她准备断掉一条树边，使得形成两棵树。
她希望这两棵树的陡峭值尽可能接近。
我们的任务是求出这两棵树陡峭值之差的绝对值的最小值。
*/
/*
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

vector<vector<int>> adj;
vector<int> parent;
vector<ll> steep;
ll total;

void dfs(int u, int p) {
    parent[u] = p;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            steep[u] += steep[v] + abs(u - v);
        }
    }
}

int main() {
    int n;
    cin >> n;
    adj.resize(n + 1);
    parent.resize(n + 1);
    steep.resize(n + 1, 0);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1); // 选择节点1为根
    total = steep[1];
    ll min_diff = 1e18;
    for (int v = 2; v <= n; ++v) {
        int u = parent[v];
        ll s = steep[v];
        ll current_total_minus_edge = total - abs(u - v);
        ll diff = abs(2 * s - current_total_minus_edge);
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    cout << min_diff << endl;
    return 0;
}
*/

/*
小红定义了一个数组的陡峭值为：每两个相邻元素的差值的绝对值之和。
例如，数组 {2, 3, 1} 的陡峭值是 |2−3| + |3−1| = 3。
现在，小红拿到了一个由 n 个整数组成的数组 {a₁, a₂, ..., aₙ}，
然后蒙眼打乱了数组。她希望我们求出该数组陡峭值的期望，
并将答案对 10⁹ + 7 取模后输出。
*/
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long mod = 1e9 + 7;
long long quick_pow(long long n, long long k)
{
    long long ans = 1;
    while (k)
    {
        if (k & 1)
            ans = ans * n % mod;
        n = n * n % mod;
        k >>= 1;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    long long ans = 0, sum = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = (ans + a[i] * i - sum) % mod;
        sum = (sum + a[i]) % mod;
    }
    ans = ans * 2 % mod;
    ans = ans * quick_pow(n, mod - 2) % mod;
    cout << ans << endl;
    return 0;
}
*/