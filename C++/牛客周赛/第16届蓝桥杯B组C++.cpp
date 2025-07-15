// #include<bits/stdc++.h>
// using namespace std;
// #define PI 3.14159265358979323846
// void solve1(){
//     pair<int,int> p1={233,666};
//     double r=sqrt(pow(p1.first,2)+pow(p1.second,2));
//     double alpha=atan2(p1.second,p1.first);
//     double x=r+r*alpha;
//     cout<<round(x)<<endl;
//     cout<<alpha<<endl;
//     cout<<atan(1.0*p1.second/p1.first)<<endl;
// //    round , 四舍五入
// //    floor , 向下取整
// //    ceil  , 向上取整
// }
// void solve2(){
//     /*
//     当i==j时,Ai*Aj<=i*j+2025,解的最值

//     A1=1 2
//     A2=1 2 3
//     A3=1 2 3 4
//     ...
//     A1013=1 2 3...1013
//     A1~A1012每个数有两个选择,故答案为(2^1012)%1000000007
//     */
//     // 快速幂
//     int MOD=1e9+7;
//     long long ans=1,x=2;
//     int n=1012;
//     while(n){
//         if(n&1) ans=(ans*x)%MOD;
//         x=(x*x)%MOD;
//         n>>=1;
//     }
//     cout<<ans<<endl;
// }
// void solve3(){
//     int T;
//     cin>>T;
//     int ans=0;
//     while(T--){
//         int n;
//         cin>>n;
//         if(n!=1) ans++;
//     }
//     cout<<ans<<endl;
// }
// void solve4(){
//     int T;
//     cin>>T;
//     while(T--){
//         int a,b,c,k;
//         cin>>a>>b>>c>>k;
//         while(k--){
//             int a1=(b+c)/2;
//             int b1=(a+c)/2;
//             int c1=(a+b)/2;
//             a=a1;
//             b=b1;
//             c=c1;
//             if(a==b&&b==c) break;
//         }
//         cout<<a<<" "<<b<<" "<<c<<endl;
//     }
// }
// void solve5(){
//     int n,m;
//     cin>>n>>m;
//     vector<long long> nums(n);
//     for(int i=0;i<n;i++) cin>>nums[i];
//     sort(nums.begin(),nums.end());
//     long long ans=LLONG_MAX;
//     for(int i=m-1;i<n;i++){
//         ans=min(ans,nums[i]*nums[i]-nums[i-m+1]*nums[i-m+1]);
//     }
//     cout<<ans<<endl;
// }
// void solve6(){
//     string s1,s2;
//     cin>>s1>>s2;
//     int len=s1.length();
//     vector<int> vue(len,0);
//     for(int i=0;i<len;i++){
//         if(s1[i]=='#'&&s2[i]=='#') vue[i]=3;
//         else if(s1[i]=='.'&&s2[i]=='#') vue[i]=2;
//         else if(s1[i]=='#'&&s2[i]=='.') vue[i]=1;
//     }
//     int ans=0;
//     for(int i=0;i<len;i++){
//         if(vue[i]==0) continue;
//         int j=i+1;
//         while(j<len&&vue[j]==0) j++;
//         if(j==len) break;
//         if(vue[i]==3||vue[j]==3||vue[i]==vue[j]){
//             ans+=j-i-1;
//         }else{
//             ans+=j-i;
//             vue[j]=3;
//         }
//     }
//     cout<<ans<<endl;
// }

// int main(){
//     solve2();
//     return 0;
// }


#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_NODES = 1005;  // 最大节点数
const int MAX_CAPACITY = 1005;  // 最大容量值

int n;  // 节点数量
int capacity[MAX_NODES];  // 节点容量/产能
int out_degree[MAX_NODES];  // 节点出度
bool dp[MAX_NODES][MAX_CAPACITY];  // dp[u][k] = 节点u能否向上传递k单位材料
bool temp[MAX_NODES][MAX_CAPACITY];  // 临时DP数组

// 树结构
vector<vector<int>> tree;

// 深度优先搜索处理每个子树
void dfs(int u, int parent) {
    // 叶节点处理：可传递自身产能或不传递(删除)
    if (out_degree[u] == 1 && u != 1) {  // 非根叶节点
        dp[u][capacity[u]] = true;  // 可传递自身产能
        return;
    }

    // 处理所有子节点
    for (int child : tree[u]) {
        if (child == parent) continue;  // 跳过父节点
        dfs(child, u);  // 递归处理子树
        // 重置临时数组（当前子节点可能带来的新状态）
        for (int k = 1; k <= capacity[u]; k++) {
            temp[u][k] = false;
        }
        
        // 动态规划：组合当前子节点的状态
        // 遍历子节点可能传递的材料量(child_units)
        for (int child_units = 1; child_units <= capacity[u]; child_units++) {
            // 遍历父节点已有状态(parent_units)
            int max_parent_units = capacity[u] - child_units;
            for (int parent_units = 0; parent_units <= max_parent_units; parent_units++) {
                // 如果两种状态都可行，则组合状态可行
                if (dp[child][child_units] && dp[u][parent_units]) {
                    temp[u][child_units + parent_units] = true;
                }
            }
        }
        
        // 合并新状态到主DP数组
        for (int k = 1; k <= capacity[u]; k++) {
            dp[u][k] = dp[u][k] || temp[u][k];
        }
    }
}

int main() {
    // 初始化
    cin >> n;
    tree.resize(n + 1);
    memset(dp, false, sizeof(dp));
    memset(temp, false, sizeof(temp));
    
    // 所有节点都可以选择不传递材料(删除子树)
    for (int i = 1; i <= n; i++) {
        dp[i][0] = true;
    }
    
    // 读取节点容量
    for (int i = 1; i <= n; i++) {
        cin >> capacity[i];
    }
    
    // 构建树结构
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        out_degree[u]++; 
        out_degree[v]++;
    }
    
    // 从根节点开始处理
    dfs(1, 0);
    
    // 查找根节点最大可行产能
    for (int k = capacity[1]; k >= 0; k--) {
        if (dp[1][k]) {
            cout << k << endl;
            return 0;
        }
    }
    
    // 理论上不会执行到这里
    cout << 0 << endl;
    return 0;
}


// #include<bits/stdc++.h>
// #define ll long long
// #define p 1000000007ll
// using namespace std;
// int main(){
//     ll ans=0,sum=0;int n;
// 	cin>>n;
//     for(int i=1,x;i<=n;i++)
//         cin>>x,ans=(ans*3-sum+(sum^=x)+p)%p,cout<<ans<<' ';
//     cout<<ans;
// 	return 0;
// }