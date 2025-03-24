// 牛客周赛 Round 83
//  https://ac.nowcoder.com/acm/contest/102896

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {   
//     char a;
//     cin>>a;
//     if(a=='U' || a=='D' ) cout<<'R'<<endl;
//     else cout<<'U'<<endl;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int  T;
//     cin>>T;
//     while(T--){
//         int n;
//         cin>>n;
//         for(int i=0;i<n;i++){
//             if(i&1) cout<<2<<' ';
//             else cout<<1<<' ';
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// 对于任意正整数，其数集定义为该数所有数位上的数字组成的集合。例如，对于数字 233，其数集为 {2, 3}。
// 给定一个正整数 x，找到一个满足 1 < y ≤ 10^18 的整数 y，使得 x × y 的数集是 x 的数集的非空子集。
// 题目保证这样的构造方案一定存在，输出任意一个即可。
// #include<iostream>
// #include <string>
// using namespace std;
// int main(){
//     int T=0;
//     cin>>T;
//     while(T--){
//         int x;
//         cin>>x;
//         unsigned long long y =10;
//         while(x/=10)y*=10;
// //         string s=to_string(x);
// //         y=stoll("1"+string(s.length(),'0'));
//         y++;
//         cout<<y<<endl;
//     }
//     return 0;
// }


// 藏宝库有 n 个格子，每个格子有一个权值 a_i。当 a_i ≥ 0 时，踩上该格子会获得 a_i 的金币；当 a_i < 0 时，会失去 |a_i| 的金币。
// 你的移动由一个六面骰子控制，但魔法猫可以操作骰子的读数，因此每次你可以前进 1 到 6 个格子。
// 初始时，你位于位置 0（藏宝阁外），口袋中的余额为 0。你需要计算，如果恰好移动 k 次，口袋中的最大余额是多少。
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// typedef long long ll;

// int main() {
//     int n, k;
//     cin >> n >> k;
//     int value[n + 1];
//     for (int i = 1; i <= n; ++i) cin >> value[i];
//     vector<vector<ll>> dp(n+1,vector<ll>(k + 1, -1e18));
//     dp[0][0] = 0;
//     ll ans=-1e18;
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= min(i,k); ++j) {
//             for (int p = max(0, i - 6); p <= i - 1; ++p) {
//                 dp[i][j] = max(dp[i][j], dp[p][j - 1] + value[i]);
//             }
//         }
//         ans=max(ans,dp[i][k]);
//     }

//     cout << ans << endl;

//     return 0;
// }

// 这是一个关于迷宫和水流扩散的问题。迷宫由 𝑛行 𝑚列的二维网格组成，每个格子可以是空方格 ‘.’ 或障碍物方格 ‘#’。迷宫的边缘被视为无法摧毁的边界。
// 每个障碍物的初始耐久度为 h。方向向下的水流接触到障碍物时，会每秒减少其耐久度 1 点。当耐久度降为 0 时，障碍物被摧毁，其位置变为可通行状态。
// Askalana 在第 0 秒召唤了一个水源（用 ‘*’ 表示），水可以在任意位置和任意时刻流动。每秒水流会按照以下规则扩散一个单位长度：
// 如果下方有障碍物，水流会同时向左、右两侧流动。如果下方无障碍物，水流只能向下流动。
// 当水流路径交叉时，例如水平水流上方有垂直水流，多条路径都会生效（垂直水流也会使下方障碍物耐久度损失），并且不会对原有的水平水流产生影响。但同一方向的水流效果不会叠加。
// 已存在的水流不会消失。 迷宫边界外不存在障碍物等实体，水流流出边界即消失。
// 如果水流抵达终点（用 ‘%’ 表示），则解谜完成。Askalana 想知道维持水源的最短时间，即水流抵达终点所需的最短时间。如果水流无法抵达终点，输出 -1。
// 需要求解的是水流从水源出发，按照上述规则扩散，最短经过多长时间可以抵达终点。

// #include<bits/stdc++.h>
// using namespace std;
// struct Node{
//     int x,y,time,abi;
//     // 重载小于运算符，用于比较两个Node对象的时间成员变量
//     // 返回当前对象的时间是否大于传入对象n的时间
//     bool operator <(const Node& n) const{
//         return n.time<time;
//     }
// };

// int main()
// {
//     int n,m,t;
//     cin>>n>>m>>t;
//     t++;
//     vector<vector<char>> map(n+2,vector<char>(m+2,'^'));
//     pair<int,int> start,end;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             cin>>map[i][j];
//             if(map[i][j]=='*') start=make_pair(i,j);
//             if(map[i][j]=='%') end=make_pair(i,j);
//         }
//     }
//     priority_queue<Node> pq;
//     pq.push({start.first,start.second,0,1});
//     vector<vector<bool>> vis(n+2,vector<bool>(m+2,false));
//     // 当优先队列不为空时，循环处理队列中的元素
//     while(!pq.empty()){
//         // 取出队列顶部的元素，并解构为坐标、时间和是否可移动的标志
//         int x=pq.top().x,y=pq.top().y,time=pq.top().time,can=pq.top().abi;
//         pq.pop();
//         // 如果当前节点不可移动且已经访问过，则跳过
//         if(!can&&vis[x][y]) continue;
//         // 标记当前节点为已访问
//         vis[x][y]=true;
//         // 如果当前节点是目标节点，则输出时间并结束程序
//         if(map[x][y]=='%'){
//             cout<<time<<endl;
//             return 0;
//         }
//         // 如果下方节点是障碍物，则根据条件将相邻节点加入队列
//         if(map[x+1][y]=='#'){
//             if(can && !vis[x+1][y]) pq.push(Node{x+1,y,time+t,1});
//             if(y+1<=m && map[x][y+1]!='#') pq.push(Node{x,y+1,time+1,0});
//             if(y-1>=1 && map[x][y-1]!='#') pq.push(Node{x,y-1,time+1,0});
//         }else{
//             // 如果下方节点不是障碍物，则将其加入队列
//             if(x+1<=n) pq.push(Node{x+1,y,time+1,1});
//         }
//     }
//     cout<<-1<<endl;
//     return 0;
// }

