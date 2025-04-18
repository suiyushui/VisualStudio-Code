// https://ac.nowcoder.com/acm/contest/103151

// 小柒最近获得了一个长度为 𝑛n 的排列[1][1] {𝑎1,𝑎2,…,𝑎𝑛}。
// 作为一个计算逆序对的高手，小柒立马计算了出来这个排列的的逆序对[2][2] 数量为 m。
// 不过小柒还想知道，如果在计算逆序对前交换了 𝑎𝑖 和 𝑎𝑗(1≤𝑖≤𝑗≤𝑛)，
// 那么这个排列的逆序对会变成奇数还是偶数？为了更加有趣，小柒一共会进行 q 次交换，
// 每次交换后，你都需要回答当前排列的逆序对是奇数还是偶数。
// 作为编程高手，请你编写一个程序解决这个问题。

// 思路:对于一个排列来说，交换两个不下标的元素，逆序对数量的奇偶性必改变

// #include <iostream>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     long long n, m, q, a;
//     cin >> n >> m >> q;
    
//     bool current_parity = m % 2;
    
//     // 直接跳过输入排列（无需处理具体元素）
//     for (int i = 0; i < n; ++i) cin>>a; // 快速跳过n个数字
    
//     while (q--) {
//         int i, j;
//         cin >> i >> j;
//         if (i != j) current_parity^=1;; // 使用异或操作更高效
//         cout << (current_parity ? "odd\n" : "even\n");
//     }
    
//     return 0;
// }


// 小柒是一名科学家，最近他发现了平行宇宙的存在，并且在每个平行宇宙中，
// 字典序是不一样的。也就是说在某个平行宇宙，字母表的出现顺序也许是 ‘a’>‘b’>‘c’>⋯‘a’>‘b’>‘c’>⋯，
// 但是在另一个平行宇宙中，字母表的出现顺序是 ‘c’>‘b’>‘a’>⋯‘c’>‘b’>‘a’>⋯，
// 那么 ‘c’ 的字典序就会小于 ‘a’。小柒将会给你一个字符串 𝑠s，并且给你 q 个平行宇宙中的字母表。
// 他想知道在不同的平行宇宙中，这个字符串 𝑠s 分别拥有多少个逆序对。
// 在字符串中，若存在这样的两个下标 i,j 满足 i<j，且其对应的字符 ai​ 
// 在当前字母表中出现的顺序晚于 a j​ ，则称 i 与 j 构成一个逆序对。
// 输入描述:第一行输入两个整数 n,q(1≤n,q≤10^5 ) 代表字符串 s 的长度、平行宇宙的数量。
// 第二行输入一个长度为 𝑛n，仅由小写字母组成的字符串 s。 
// 此后 𝑞q 行，每行输入一个长度为 26，由小写字母组成、且每个字母只出现一次的字符串，代表每个宇宙的字母表。
// 输出描述:对于每一个宇宙，新起一行输出一个整数，代表在当前宇宙中，字符串 𝑠s 拥有的逆序对数量。
//预处理+矩阵维护 复杂度 ：时间复杂度 O(n*q*26^2) 空间复杂度 O(n*26)
/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    ll sum = 0;
    vector<int> f(26, 0), pos(26, 0);
    vector<vector<int>> g(26, vector<int>(26, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            if (j > s[i] - 'a')// 选择j>s[i]
                sum += f[j];
            g[j][s[i] - 'a'] += f[j];
        }
        f[s[i] - 'a']++;
    }
    while (q--)
    {
        string t;
        cin >> t;
        ll ans = sum;
        for (int i = 0; i < 26; ++i)
            pos[t[i] - 'a'] = i;
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < i; ++j) // 选择i>j
                if (pos[i] < pos[j])    // 修改(ai<bj)的结果
                    ans += g[j][i] - g[i][j];
        }
        cout << ans << endl;
    }
    return 0;
}*/
//树状数组 复杂度：时间复杂度 O(n*qlog26) 空间复杂度 O(n*26)
// 劣势：q 大时复杂度爆炸（如 q=1e5 时 O(1e10)）
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int size;

public:
    FenwickTree(int n) : size(n), tree(n + 1, 0) {}

    void update(int pos, int delta) {
        pos++; // 转换为 1-based 索引
        while (pos <= size) {
            tree[pos] += delta;
            pos += pos & -pos;
        }
    }

    int query(int pos) {
        pos++; // 转换为 1-based 索引
        int sum = 0;
        while (pos > 0) {
            sum += tree[pos];
            pos -= pos & -pos;
        }
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    while (q--) {
        string alphabet;
        cin >> alphabet;
        int rank[26];
        for (int i = 0; i < 26; ++i)
            rank[alphabet[i] - 'a'] = i;  // 字母的权重

        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
            nums[i] = rank[s[i] - 'a'];   // 转换字符串为权重数组

        FenwickTree ft(26);
        long long inversions = 0;
        for (int i = 0; i < n; ++i) {
            // 查询比当前元素大的元素数量
            inversions += ft.query(25) - ft.query(nums[i]);
            ft.update(nums[i], 1);  // 插入当前元素
        }
        cout << inversions << '\n';
    }

    return 0;
}*/

// 小柒作为班主任，最近为自己班的学生购买了n种糖果，第 i 种糖果有ai​颗。
// 班级里一共有 m 名学生，小柒可以决定每种糖果发几颗，发给哪几名学生，
// 每名学生获得的糖果数量。小柒想知道他一共有多少种发糖果的方法。
// 由于答案可能很大，请将答案对 (10^9+7)取模后输出。
// 如果两种发糖果的方法中，有任何一名学生得到的某种糖果数量不同，则认为这两种方法不同。
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;//max(ai)+m <= 2e5
ll a[maxn],b[maxn];
ll quick_pow(ll a, ll b) {
    ll res = 1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
void init(){
    a[0]=1;
    for(int i=1;i<maxn;i++) a[i]=a[i-1]*i%mod;
    b[maxn-1]=quick_pow(a[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;i--) b[i]=b[i+1]*(i+1)%mod;
}
long long solve(int x, int y) {
    if (x < 0 || y < 0 || x < y) return 0;
    return a[x] * b[y] % mod * b[x - y] % mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int n,m;
    cin>>n>>m;
    ll ans=1;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        ans=ans*solve(x+m,m)%mod;
    }
    cout<<ans<<endl;
    return 0;
}*/

// 小柒收集了 n 把神器，第 𝑖 把神器的能量为 𝑎𝑖。
// 这些神器之间有 𝑚 对直接融合关系，第 𝑖 对关系记为 (𝑢𝑖,𝑣𝑖)，
// 代表第 𝑢𝑖 把神器和第 𝑣𝑖​  把神器可以融合。小柒现在获得了一枚储物戒，
// 最初储物戒是空的，你可以将任意一把神器放入储物戒而不用付出任何代价；
// 其余每把神器只有在储物戒中存在与之具有直接融合关系的神器时才能放入，
// 放入代价为两者能量之和。形式化地，记 𝑆 为已经放入储物戒的神器集合，
// 若存在 𝑖∈𝑆 且第 i,j 把神器具有直接融合关系，才可以将第 𝑗 把神器放入
// ，代价为 𝑎𝑖+𝑎𝑗​ 。现在，小柒会进行 q 次独立询问，
// 每次询问指定一个区间 [𝑙,𝑟]，你需要求解：能否将区间 [𝑙,𝑟] 中的神器都放入储物戒？
// 如果可以，输出放入过程中，单次放入所需代价的最大值至少是多少；否则，输出 −1。