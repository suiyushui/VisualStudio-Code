// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<cmath>
// using namespace std;
// typedef long long ll;

// vector<vector<int>>adj;
// vector<int>parent;
// vector<ll>steep;

// void dfs(int u,int p){
//     parent[u]=p;
//     for(int v:adj[u]){
//         if(v==p) continue;
//         dfs(v,u);
//         steep[u]+=steep[v]+abs(u-v);
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     int n; cin>>n;
//     for(int i=0;i<n-1;++i){
//         int v,u;
//         cin>>v>>u;
//         adj[v].push_back(u);
//         adj[u].push_back(v);
//     }
//     dfs(1,-1);
//     ll ans=0x3f3f3f3f3f3f3f3f;
//     for(int v=2;v<=n;++v){
//         ll prev=steep[1]-abs(parent[v]-v);
//         ll diff=abs(2*steep[v]-prev);
//         ans=min(ans,diff);
//     }
//     cout<<ans<<endl;
//     return 0;
// }
/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> BSA(const string& s){
    int n=s.size();
    vector<int>sa(n),rank(n),temp(n);
    for(int i=0;i<n;i++) sa[i]=i,rank[i]=s[i];
    for(int k=1;k<n;k*=2){
        auto cmp=[&](int i,int j){
            if(rank[i]!=rank[j]) return rank[i]<rank[j];
            return (i+k<n?rank[i+k]:-1)<(j+k<n?rank[j+k]:-1);
        };
        sort(sa.begin(),sa.end(),cmp);
        temp[0]=0;
        for(int i=1;i<n;i++)
            temp[sa[i]]=temp[sa[i-1]]+(cmp(sa[i-1],sa[i])?1:0);
        rank.swap(temp);
    }
    return sa;
}
vector<int> buildLCP(const string& s, const vector<int>& sa) {
    int n = s.size();
    vector<int> lcp(n, 0);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++) {
        rank[sa[i]] = i;
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] == 0) {
            lcp[rank[i]] = 0;
            continue;
        }
        int j = sa[rank[i] - 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
            k++;
        }
        lcp[rank[i]] = k;
        if (k > 0) k--;
    }
    return lcp;
}
int main(){
    string s="banana";
    // cin>>s;
    vector<int>sa=BSA(s);
    for(int i=0;i<s.size();i++) cout<<sa[i]<<" ";
    cout<<endl;
    return 0;
}
*/

// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;

// // 定义树的节点数量
// const int MAXN = 1000;

// // 定义树的深度和倍增法的最大层数
// const int LOG = 10;

// // 树的线性表表示
// vector<int> tree[MAXN]; // tree[u] 存储节点 u 的子节点
// int parent[MAXN];       // parent[u] 存储节点 u 的父节点
// int depth[MAXN];        // depth[u] 存储节点 u 的深度
// int up[MAXN][LOG];      // up[u][k] 存储节点 u 的第 2^k 级祖先

// // DFS 预处理
// void dfs(int u, int p) {
//     parent[u] = p;       // 记录父节点
//     depth[u] = depth[p] + 1; // 记录深度

//     // 初始化 up[u][0] 为父节点
//     up[u][0] = p;

//     // 填充 up[u][k] 的值
//     for (int k = 1; k < LOG; k++) {
//         up[u][k] = up[up[u][k - 1]][k - 1];
//     }

//     // 递归处理子节点
//     for (int v : tree[u]) {
//         if (v != p) {
//             dfs(v, u);
//         }
//     }
// }

// // 查找 LCA
// int findLCA(int u, int v) {
//     // 确保 u 是较深的节点
//     if (depth[u] < depth[v]) {
//         swap(u, v);
//     }

//     // 将 u 提升到与 v 同一层
//     for (int k = LOG - 1; k >= 0; k--) {
//         if (depth[u] - (1 << k) >= depth[v]) {
//             u = up[u][k];
//         }
//     }

//     // 如果 v 是 u 的祖先
//     if (u == v) {
//         return u;
//     }

//     // 同时提升 u 和 v
//     for (int k = LOG - 1; k >= 0; k--) {
//         if (up[u][k] != up[v][k]) {
//             u = up[u][k];
//             v = up[v][k];
//         }
//     }

//     return up[u][0];
// }

// // 主函数
// int main() {
//     // 示例树结构
//     int n = 9; // 节点数量
//     tree[3] = {5, 1};    // 节点 3 的子节点是 5 和 1
//     tree[5] = {6, 2};    // 节点 5 的子节点是 6 和 2
//     tree[1] = {0, 8};    // 节点 1 的子节点是 0 和 8
//     tree[2] = {7, 4};    // 节点 2 的子节点是 7 和 4

//     // 预处理
//     dfs(3, 3); // 根节点是 3，其父节点也是 3

//     // 查询 LCA
//     int u = 5, v = 4; // 查询 LCA(5, 4)
//     int lca = findLCA(u, v);
//     cout << "LCA of " << u << " and " << v << " is: " << lca << endl;

//     return 0;
// }

/*
#include<bits/stdc++.h>
using namespace std;
#define N 100000

typedef struct Person{
    char gender;
    string monther_id;
    string father_id;
} Person;

unordered_set<string> GetAncestors(const string& id, unordered_map<string, Person>& peoples){
    unordered_set<string> ancestors;
    queue<pair<string, int>> q;
    if (!peoples.count(id)) return ancestors;
    auto it = peoples.find(id);
    Person p = it->second;
    if (p.monther_id != "-1") q.push(make_pair(p.monther_id, 2));
    if (p.father_id != "-1") q.push(make_pair(p.father_id, 2));
    while (!q.empty()){
        auto p = q.front();
        q.pop();
        if (p.second > 5) continue;
        if (ancestors.count(p.first)) continue;
        ancestors.insert(p.first);
        auto it_current = peoples.find(p.first);
        if (it_current == peoples.end()) continue;
        Person &currentPerson = it_current->second;
        if (currentPerson.monther_id != "-1") q.push(make_pair(currentPerson.monther_id, p.second + 1));
        if (currentPerson.father_id != "-1") q.push(make_pair(currentPerson.father_id, p.second + 1));
    }
    return ancestors;
}

int main(){
    int T;
    cin >> T;
    unordered_map<string, Person> peoples;
    while (T--){
        string id, monther_id, father_id;
        char gender;
        cin >> id >> gender >> monther_id >> father_id;
        peoples[id] = {gender, monther_id, father_id};
        if (father_id != "-1" && !peoples.count(father_id))
            peoples[father_id] = {'M', "-1", "-1"};
        if (monther_id != "-1" && !peoples.count(monther_id))
            peoples[monther_id] = {'F', "-1", "-1"};
    }
    int K;
    cin >> K;
    while (K--){
        string id1, id2;
        cin >> id1 >> id2;
        if (peoples[id1].gender == peoples[id2].gender)
            cout << "Never Mind" << endl;
        else{
            unordered_set<string> ancestors1 = GetAncestors(id1, peoples);
            unordered_set<string> ancestors2 = GetAncestors(id2, peoples);
            bool flag = false;
            for (auto it1 : ancestors1)
                if (ancestors2.count(it1)){
                    flag = true;
                    break;
                }
            if (!flag) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
struct person
{
    char gender;
    string father_id;
    string mother_id;
};

bool bfs(string &a, string &b, unordered_map<string, person> &people)
{
    queue<pair<string, int>> qA, qB;
    unordered_set<string> visitedA, visitedB;
    auto push_Parents = [&](queue<pair<string, int>> &q, string id, int depth)
    {
        auto it = people.find(id);
        if (it == people.end())
            return;
        const person &p = it->second;
        if (p.father_id != "-1")
            q.emplace(make_pair(p.father_id, depth));
        if (p.mother_id != "-1")
            q.emplace(make_pair(p.mother_id, depth));
    };
    push_Parents(qA, a, 2);
    push_Parents(qB, b, 2);
    while (!qA.empty() || !qB.empty())
    {
        int sizeA = qA.size(), sizeB = qB.size();
        for (int i = 0; i < sizeA; i++)
        {
            string id = qA.front().first;
            int depth = qA.front().second;
            qA.pop();
            if (depth > 5)
                continue;
            if (visitedB.count(id))
                return true;
            if (visitedA.count(id))
                continue;
            visitedA.insert(id);
            push_Parents(qA, id, depth + 1);
        }
        for (int i = 0; i < sizeB; i++)
        {
            string id = qB.front().first;
            int depth = qB.front().second;
            qB.pop();
            if (depth > 5)
                continue;
            if (visitedA.count(id))
                return true;
            if (visitedB.count(id))
                continue;
            visitedB.insert(id);
            push_Parents(qB, id, depth + 1);
        }
    }
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    unordered_map<string, person> people;
    int T;
    cin >> T;
    auto add_person = [&](string id, char gender)
    {
        if (!people.count(id))
            people[id] = {gender, "-1", "-1"};
    };
    while (T--)
    {
        string id, father_id, mother_id;
        char gender;
        cin >> id >> gender >> father_id >> mother_id;
        people[id] = {gender, father_id, mother_id};
        if (father_id != "-1")
            add_person(father_id, 'M');
        if (mother_id != "-1")
            add_person(mother_id, 'F');
    }
    int K;
    cin >> K;
    while (K--)
    {
        string a, b;
        cin >> a >> b;
        if (!people.count(a) || !people.count(b))
        {
            cout << "Yes\n";
            continue;
        }
        if (people[a].gender == people[b].gender)
        {
            cout << "Never Mind\n";
        }
        else
        {
            cout << (bfs(a, b, people) ? "No\n" : "Yes\n");
        }
    }
    return 0;
}*/

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <climits>
// #include <algorithm>

// using namespace std;

// typedef pair<int, int> pii; // 存储距离和节点编号

// int main() {
//     int n, m, s, d;
//     cin >> n >> m >> s >> d;

//     vector<int> city_rescue(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> city_rescue[i];
//     }

//     vector<vector<pair<int, int>>> adj(n); // 邻接表，存储邻接节点和边权
//     for (int i = 0; i < m; ++i) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].emplace_back(v, w);
//         adj[v].emplace_back(u, w);
//     }

//     vector<int> dist(n, INT_MAX);
//     vector<int> rescue(n, 0);
//     vector<int> num(n, 0);
//     vector<int> pre(n, -1);

//     // 初始化起点
//     dist[s] = 0;
//     rescue[s] = city_rescue[s];
//     num[s] = 1;

//     // 优先队列，按距离从小到大排列
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     //greater<pii> 按距离从大到小排列
//     pq.emplace(0, s);

//     while (!pq.empty()) {
//         auto [current_dist, u] = pq.top();
//         pq.pop();

//         // 如果当前的距离已经大于记录的最短距离，跳过
//         if (current_dist > dist[u]) continue;

//         for (auto &[v, w] : adj[u]) {
//             int new_dist = current_dist + w;

//             if (new_dist < dist[v]) {
//                 dist[v] = new_dist;
//                 rescue[v] = rescue[u] + city_rescue[v];
//                 num[v] = num[u];
//                 pre[v] = u;
//                 pq.emplace(new_dist, v);
//             } else if (new_dist == dist[v]) {
//                 num[v] += num[u]; // 路径数目累加
//                 // 如果当前路径的救援队更多，则更新
//                 if (rescue[u] + city_rescue[v] > rescue[v]) {
//                     rescue[v] = rescue[u] + city_rescue[v];
//                     pre[v] = u;
//                     // 需要重新入队吗？可能存在更优的后续路径
//                     // 为了确保正确性，可以重新入队
//                     pq.emplace(new_dist, v);
//                 }
//             }
//         }
//     }

//     // 输出结果
//     cout << num[d] << " " << rescue[d] << endl;

//     // 回溯路径
//     vector<int> path;
//     int current = d;
//     while (current != s) {
//         path.push_back(current);
//         current = pre[current];
//     }
//     path.push_back(s);
//     reverse(path.begin(), path.end());

//     for (size_t i = 0; i < path.size(); ++i) {
//         if (i != 0) cout << " ";
//         cout << path[i];
//     }
//     cout << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// void solve(const std::vector<int>& a) {
//     int n = a.size();
//     for (int i = 0; i < n; ++i) {
//         int ai = a[i];
//         std::bitset<MAX_K> old_dp[MAX_M];
//         for (int j = 0; j < MAX_M; ++j) {
//             old_dp[j] = dp[j];
//         }

//         // 倒序遍历j
//         for (int j = MAX_M - 1; j >= 0; --j) {
//             std::bitset<MAX_K> new_bits, new_bits_shift;

//             // 处理放入背包1的情况
//             if (j >= ai) {
//                 new_bits = old_dp[j - ai] & ~dp[j];
//                 dp[j] |= old_dp[j - ai];  // 更新状态
//             }

//             // 处理放入背包2的情况
//             new_bits_shift = (old_dp[j] << ai) & ~dp[j];
//             dp[j] |= (old_dp[j] << ai);  // 更新状态

//             // 合并路径记录逻辑
//             auto process_new_bits = [&](const std::bitset<MAX_K>& bits, int dj, int dk) {
//                 for (int k = bits._Find_first(); k < MAX_K; k = bits._Find_next(k)) {
//                     pre[j][k] = {j + dj, k + dk};
//                 }
//             };

//             process_new_bits(new_bits, -ai, 0);        // 背包1的前驱偏移 (j-ai, k)
//             process_new_bits(new_bits_shift, 0, -ai);  // 背包2的前驱偏移 (j, k-ai)
//         }
//     }
// }
// int main(){
//     cin.tie(0)->sync_with_stdio(0);
//     cout.tie(0);
//     int n,m;
//     cin >> n >> m;
//     const int MAXN = 1e4+5;
//     vector<int> nums(n);
//     for(int i=0;i<n;i++) cin>>nums[i];
//     bitset<MAXN> dp[MAX_M];
//     dp[0].set(0);
//     for(int i=0;i<n;i++){
//         for(int j=MAXN-1;j>=0;j--){
//             if(j>nums[i]) dp[j] |= dp[j-nums[i]];
//             dp[j]|=(dp[j]<<nums[i]);
//         }
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     cin.tie(0)->sync_with_stdio(0);
//     cout.tie(0);
//     int n;cin>>n;
//     vector<int> prev;
//     int count=0;
//     auto dfs=[&](auto&& self,int cnt,int sum)->void{
//         if(sum==n){
//             cout<<n<<"="<<prev.front();
//             int len=prev.size();
//             for(int i=1;i<n;i++) cout<<'+'<<prev[i];
//             if(++count%=4) cout<<';';
//             else cout<<endl;
//             return;
//         }
//         for(int i=cnt;i<n;i++){
//             if(sum+i>n) break;
//             prev.push_back(i);
//             self(self,i,sum+i);
//             prev.pop_back();
//         }
//     };
//     dfs(dfs,1,0);
//     cout<<n<<"="<<n<<endl;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n; cin>>n;
//     vector<int> primes;
//     auto seive=[&](int n)->int{
//         vector<bool> vis(n+1,true);
//         vis[0]=vis[1]=false;
//         for(int i=2;i<=n;i++){
//             if(vis[i]) primes.push_back(i);
//             for(int& prime:primes){
//                 if(prime*i>n) break;
//                 if(i%prime==0) break;
//                 vis[prime*i]=false;
//             }
//         }
//     };

//     cout<<n<<'=';
//     for(int prime:primes){
//         int cnt=0;
//         while(n%prime==0){
//             cnt++;
//             n/=prime;
//         }
//         if(cnt!=0){
//             cout<<prime<<'^'<<cnt;
//             if(n==0) cout<<'*';
//         }
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     string s;
//     cin>>s;
//     int n=s.length();
//     string t="ZUCC";
//     int n2=t.length();
//     if(n<n2){
//         cout<<0<<endl;
//         return 0;
//     }
//     int ans=0,count=0;
//     undordered_map<char,int> mp;
//     for(char c:t){
//         if(mp.count(c)==0) mp[c]=count++;
//     }
//     vector<vector<int>> prev(n+1,vector<int>(4,0));
//     for(int i=0;i<n;i++){
//         prev[i+1]=prev[i];
//         prev[i+1][mp[s[i]]]++;
//     }
//     int ans=1;
//     for(int i=0;i<n;i++){
//     }
// }

// #include <vector>
// #include <queue>
// #include <climits>

// using namespace std;

// // 定义函数minimumCost，用于计算最小生成树的总成本
// // 参数n表示节点的数量，connections是一个二维向量，其中每个元素包含两个节点和它们之间的连接成本
// int minimumCost(int n, vector<vector<int>>& connections) {
//     // 创建一个邻接表来表示图
//     // graph[i]包含所有与节点i直接相连的节点及其连接成本
//     vector<vector<pair<int, int>>> graph(n+1);
//     for(const auto& conn : connections) {
//         // 对于每一条连接，将其添加到两个节点的邻接表中
//         graph[conn[0]].emplace_back(conn[1], conn[2]);
//         graph[conn[1]].emplace_back(conn[0], conn[2]);
//     }

//     // 使用优先队列（最小堆）来存储当前可以访问的节点及其连接成本
//     // 每次从堆顶取出成本最小的节点进行访问
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     // 创建一个布尔向量visited来记录每个节点是否已经被访问过
//     vector<bool> visited(n+1, false);
//     // 将起始节点1（假设从节点1开始）及其连接成本0（初始节点没有连接成本）加入优先队列
//     pq.push({0, 1});
//     // res用于累加最小生成树的总成本
//     // count用于记录已访问的节点数量
//     int res = 0, count = 0;

//     // 当优先队列不为空且已访问节点数量小于n时，继续执行循环
//     while(!pq.empty() && count < n) {
//         // 从优先队列中取出成本最小的节点u
//         auto [cost, u] = pq.top();
//         pq.pop();
//         // 如果节点u已经被访问过，则跳过本次循环
//         if(visited[u]) continue;
//         // 标记节点u为已访问

//         visited[u] = true;
//         // 将节点u的连接成本加入总成本res中
//         res += cost;
//         // 增加已访问节点的数量
//         count++;

//         // 遍历节点u的所有邻居节点v及其连接成本c
//         for(const auto& [v, c] : graph[u]) {
//             // 如果邻居节点v尚未被访问，则将其及其连接成本加入优先队列
//             if(!visited[v]) {
//                 pq.push({c, v});
//             }
//         }
//     }

//     // 如果已访问的节点数量等于n，则返回最小生成树的总成本res
//     // 否则，返回-1，表示无法形成包含所有节点的最小生成树（即图不是连通的）
//     return count == n ? res : -1;
// }
// #include <bits/stdc++.h>
// using namespace std;
// int gcd(int a,int b){
//     if(b==0) return a;
//     return gcd(b,a%b);
// }
// int main()
// {
//     cout<<fixed<<setprecision(2);
//     int n=343720,m=233333;
//     int dn=15,dm=17;
//     int g=gcd(dn*m,dm*n);
//     int p=n*dm/g,q=m*dn/g;
//     int t=2*n*q/dn;//来回需要乘以2
//     double ans=sqrt(dn*dn+dm*dm)*t;
//     cout<<ans<<endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int N, ans = 0;
// vector<int> fac(10); // 存储构造的数字
// vector<int> ji = {1, 3, 5, 7, 9}; // 奇数位候选
// vector<int> ou = {0, 2, 4, 6, 8}; // 偶数位候选

// int main() {
//     cin.tie(0)->sync_with_stdio(0);
//     // freopen("D:\\Download\\input.txt", "r", stdin);// 输入重定向到文件
//     // freopen("D:\\Download\\output.txt", "w", stdout);// 输出重定向到文件
//     // srand(time(0));// 随机数种子
//     // N=rand()%100+1;
//     cin >> N;
//     for (int i = 1; i <= N; i++) {
//         int num=i;
//         while(num>0){
//             if(~(num%10)&1) break;
//             num/=10;
//             if((num%10)&1) break;
//             num/=10;
//         }
//         if(!num) ans++;
//     }
//     cout<< ans << endl;
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;
// int main(){

//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n=2;
//     string s="3.14";
//     // cin>>n>>s;
//     int len=s.length();
//     vector<int> prev(len,0);
//     int j=0,t=0;
//     for(int i=len-1;i>=0;i--){
//         if(s[i]=='.'){
//             t=j;
//             continue;
//         }
//         prev[j++]=s[i]-'0';
//     }
//     while(n--){
//         int t2=0;
//         for(int i=0;i<j;i++){
//             int x=prev[i]*2+t2;
//             t2=x/10;
//             prev[i]=x%10;
//         }
//         if(t2){
//             prev[j++]=t2;
//         }
//     }
//     if(prev[t-1]>=5) {
//         int t3=1;
//         for(int i=t;i<j;i++){
//             int x=prev[i]+t3;
//             t3=x/10;
//             prev[i]=x%10;
//         }
//         if(t3) prev[j++]=t3;
//     }
//     for (int i = j - 1; i >= t; i--) {
//         cout << prev[i];
//     }
//     cout << endl;

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// string MaxSubString(string s){
//     int n=s.length();
//     string str="#$";
//     for(int i=0;i<n;i++) str+=s[i],str+="$";
//     int len=n*2+2,max_id=0;
//     vector<int> nums(len,1);

//     for(int i=2,l,r=1;i<len;i++){
//         if(i<r) nums[i]=min(nums[r-i+l],r-i+1);
//         while(str[i-nums[i]]==str[i+nums[i]]) nums[i]++;
//         if(i+nums[i]-1>r) l=i-nums[i]+1,r=i+nums[i]-1;
//         if(nums[i]>nums[max_id]) max_id=i;
//     }
//     return s.substr((max_id-nums[max_id])/2,nums[max_id]-1);
// }
// string MaxSubString2(string s){
//     int start=0,length=1,n=s.length();
//     auto maxlength=[&](int l,int r)->pair<int,int>{
//         while(l>=0&&r<n&&s[l]==s[r]) l--,r++;
//         return {l+1,r-1};
//     };
//     for(int i=0;i<n;i++){
//         pair<int,int> p=maxlength(i,i);
//         pair<int,int> q=maxlength(i,i+1);
//         if(p.second-p.first>length-1){
//             start=p.first;
//             length=p.second-p.first+1;
//         }
//         if(q.second-q.first>length-1){
//             start=q.first;
//             length=q.second-q.first+1;
//         }
//     }
//     return s.substr(start,length);
// }
// int main(){
//     freopen("D:\\Download\\input.txt", "r", stdin);// 输入重定向到文件
//     freopen("D:\\Download\\output.txt", "w", stdout);// 输出重定向到文件
//     string s="abcabcbb";
//     cin>>s;
//     cout<<MaxSubString(s)<<endl;
//     cout<<MaxSubString2(s)<<endl;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     string s="abcabcbb";
//     string t="abca";
//     int n=s.length();
//     int m=t.length();
//     vector<int> next(m,0);
//     for(int i=1,j=0;i<m;){
//         while(j&&t[i]!=t[j]) j=next[j-1];
//         if(t[i]==t[j]) j++;
//         next[i++]=j;
//     }
//     for(int i=0,j=0;i<n;){
//         while(j&&s[i]!=t[j]) j=next[j-1];
//         if(s[i]==t[j]) j++;
//         if(j==m) cout<< i-m+1<<" "<<i<<endl,j=next[j-1];
//         i++;
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<vector<int>> nums={{0,-2,3},{-1,0,0},{-3,-3,-2}};
//     int n=nums.size(),m=nums[0].size();
//     vector<int> dp(m+1,INT_MIN);
//     dp[m-1]=1;
//     for(int i=n-1;i>=0;i--){
//         for(int j=m-1;j>=0;j--){
//             dp[j]=max(min(dp[j+1],dp[j])-nums[i][j],1);
//         }
//     }
//     cout<<dp[0]<<endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int a = 10;
// // do 循环执行
// LOOP:
//     do
//     {
//         if (a == 15)
//         {
//             // 跳过迭代
//             a = a + 1;
//             goto LOOP;
//         }
//         cout << "a 的值：" << a << endl;
//         a = a + 1;
//     } while (a < 20);
//     return 0;
// }


// #include<unordered_map>
// #include<list>
// #include<utility>
// #include<iostream>
// #include<mutex>

// using namespace std;

// class LRUCache {
// private:
//     int capacity;
//     // 双向链表，用于存储缓存
//     list<pair<int, int>> cacheList;
//     // 哈希表，用于快速查找元素
//     unordered_map<int, list<pair<int, int>>::iterator> cacheMap;
//     // 互斥锁，用于保护共享资源
//     mutable mutex mtx;

// public:
//     LRUCache(int capacity) : capacity(capacity) {}

//     int get(int key) {
//         lock_guard<mutex> lock(mtx); // 锁定互斥锁，自动解锁
//         auto it = cacheMap.find(key);
//         if (it == cacheMap.end()) {
//             return -1;
//         }
//         // 将找到的元素移动到链表的开头
//         cacheList.splice(cacheList.begin(), cacheList, it->second);
//         return it->second->second;
//     }

//     void put(int key, int value) {
//         lock_guard<mutex> lock(mtx); // 锁定互斥锁，自动解锁
//         auto it = cacheMap.find(key);
//         if (it != cacheMap.end()) {
//             // key存在，更新value
//             it->second->second = value;
//             cacheList.splice(cacheList.begin(), cacheList, it->second);
//             return;
//         }
//         if (cacheList.size() == capacity) {
//             // 缓存满了，删除最后一个
//             int lastKey = cacheList.back().first;
//             cacheMap.erase(lastKey);
//             cacheList.pop_back();
//         }
//         cacheList.emplace_front(key, value);
//         cacheMap[key] = cacheList.begin();
//     }

//     void print() const {
//         lock_guard<mutex> lock(mtx); // 锁定互斥锁，自动解锁
//         for (auto [k, v] : cacheList) {
//             cout << k << " " << v << endl;
//         }
//     }
// };

// int main() {
//     LRUCache cache(3);

//     cache.put(1, 1);
//     cache.put(2, 2);
//     cache.put(3, 3);
//     cout << cache.get(2) << endl; // 输出 2
//     cache.put(4, 4);
//     cout << cache.get(3) << endl; // 输出 -1，因为3被移除了

//     cache.print();

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// void solve(){
//     int n;
//     cin>>n;
//     int m=log2(n);
//     if(pow(2,m)==n) cout<<-1<<endl;
//     else cout<<pow(2,m)<<endl;
// }
// void solve2(){
//     int n;
//     cin>>n;
//     string s;
//     cin>>s;
//     int count=0;
//     bool flag=false;
//     for(int i=0;i<n;i++){
//         if(s[i]=='1'){
//             count++;
//         }else{
//             if(count>1)flag=true;
//             if(i>0&&s[i]=='0'&&s[i-1]=='0') flag=false;
//             if(count==1&&!flag){
//                 cout<<"NO"<<endl;
//                 return;
//             }
//             count=0;
//         }
//     }
//     if(s[n-1]=='1')cout<<"NO"<<endl;
//     else cout<<"YES"<<endl;
// }
// void solve3(){
//     int n,k;
//     cin>>n>>k;
//     int ans=k+1;
//     while(n>0){
//         if(n&1){
//             if(n==1){
//                 ans++;
//             }else{
//                 ans+=k;
//             }
//         }else{
//             ans++;
//         }
//     }
//     cout<<ans<<endl;
// }
// int main(){
//     int T;
//     cin>>T;
//     while(T--){
//         solve2();
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// const int MAX_NODES=1005;//最大节点数
// const int MAX_CAPACITY=1005;//最大容量

// int n;
// int capacity[MAX_NODES];//容量数组
// int out_degree[MAX_NODES];  // 节点出度
// bitset<MAX_NODES> dp[MAX_NODES]; // 记录访问过的节点

// vector<vector<int>> tree;//邻接表

// void dfs(int u,int parent){
//     if(out_degree[u]==1&&u!=1){
//         dp[u][capacity[u]]=true;
//         return;
//     }
//     bitset<MAX_CAPACITY> dp_u;
//     for(int i=0;i<=capacity[u];i++){
//         dp_u.set(i);
//     }
//     for(int child:tree[u]){
//         if(child==parent) continue;
//         dfs(child,u);
//         bitset<MAX_CAPACITY> dp_child;
//         for(int k=0;k<=capacity[u];k++){
//             if(dp[child][k]){
//                 dp_child|=(dp[u]<<k);
//             }
//         }
//         dp[u]=dp_child&dp_u;
//     }
// }

// int main(){
//     cin>>n;
//     tree.resize(n+1);

//     for (int i = 1; i <= n; i++) {
//         dp[i].set(0);
//     }

//     for(int i=1;i<=n;i++){
//         cin>>capacity[i];
//     }

//     for(int i=1;i<n;i++){
//         int u,v;
//         cin>>u>>v;
//         tree[u].push_back(v);
//         tree[v].push_back(u);
//         out_degree[u]++;
//         out_degree[v]++;
//     }
//         dfs(1, 0);
    
//     // 查找根节点最大可行产能
//     for (int k = capacity[1]; k >= 0; k--) {
//         if (dp[1][k]) {
//             cout << k << endl;
//             return 0;
//         }
//     }
// }


// #include<iostream>
// #define ll long long
// using namespace std;
// const int N = 1e5+5,mod = 1e9+7;
// ll n,a[N],pow3[N];
// int main(){
// 	scanf("%d",&n);
// 	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
// 	pow3[0] = 1;	// 预处理 3 的次幂
// 	for(int i=1;i<=n;i++) pow3[i] = pow3[i-1]*3%mod;
// 	ll eor = 0, res = 0;	// eor 记录从 a[1] 一直异或到 a[i]
// 	for(int i=1;i<=n-1;i++){
// 		eor ^= a[i];
// 		res = (res + (2*pow3[n-i-1]%mod)*eor%mod)%mod; 	// 每步都要取模
// 	}
// 	res = (res + (eor^a[n]))%mod;	// 最后一个数字
// 	printf("%lld",res);
// 	return 0;
// } 



// #include<bits/stdc++.h>
// using namespace std;
// const int MAXN=15;
//  int main() {
//     int n;
//     cin >> n;
//     vector<vector<int>> grid(n+1, vector]<int>(n+1,0));
//     while(true){
//         int x,y,num;
//         cin >> x >> y >> num;
//         if(x==0&&y==0&&num==0) break;
//         grid[x][y]=num;
//     }
//     int dp[2*MAXN][MAXN][MAXN][MAXN];
//     for(int k=1;k<=2*n-1;k++){
//         for(int i=1;i<=n;i++){
//             int j=k-i+1;
//             if(j<1||j>n) continue;
//             for(int p=1;p<=n;p++){
//                 int q=k-p+1;
//                 if(q<1||q>n) continue;

//                 int max_pre=0;

//                 if(i>1&&p>1)
//                     max_pre=max(max_pre,dp[k-1][i-1][j][p-1]);
//                 if(i>1&&q>1)
//                     max_pre=max(max_pre,dp[k-1][i-1][j][p]);
//                 if(j>1&&p>1)
//                     max_pre=max(max_pre,dp[k-1][i][j-1][p-1]);
//                 if(j>1&&q>1)
//                     max_pre=max(max_pre,dp[k-1][i][j-1][p]);

//                 int current=(i==p&&j==q)?grid[i][j]:grid[i][j]+grid[p][q];
//                 dp[k][i][j][p]=max_pre+current;
//             }
//         }
//     }
//     cout << dp[2*n-1][n][n][n] << endl;
//     return 0;
// }
    

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        auto dp=vector(2*n,vector(n,vector(n,INT_MIN)));
        dp[0][0][0]=grid[0][0];
        for(int step=1;step<2*n-1;step++){
            for(int x=0;x<n;x++){
                int y=step-x;
                if(y<0||y>=n||grid[x][y]<0) continue;
                for(int X=0;X<n;X++){
                    int Y=step-X;
                    if(Y<0||Y>=n||grid[X][Y]<0) continue;
                    int& res=dp[step][x][X];
                    auto& last=dp[step-1];
                    res=max(res,last[x][X]);
                    if(x) res=max(res,last[x-1][X]);// 左上
                    if(X) res=max(res,last[x][X-1]);// 左下
                    if(x&&X) res=max(res,last[x-1][X-1]);
                    res+=grid[x][y];
                    if(x!=X) res+=grid[X][Y];
                }
            }
        }
        return max(0,dp[2*n-2][n-1][n-1]);
    }
    int cherryPickup1(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n,vector(n,vector(n,INT_MIN)));
        dp[0][0][0] = grid[0][0];
        for(int k=0;k<2*n-1;k++){;
            for(int x=max(k-n,0);x<min(k,n-1);x++){

            }
        }
    }
    bool check(int mid,int n,int k,int wood[]){
        int count=0;
        for(int i=0;i<n;i++){
            count+=wood[i]/mid;
            if(count>=k) return true;
        }
        return false;
    }
}; 