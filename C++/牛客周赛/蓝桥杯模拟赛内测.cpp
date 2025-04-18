// https://ac.nowcoder.com/acm/contest/102407 邀请码:1234

// 第五题:你有一个小写字母序列，你需要按顺序将所有的字母入栈，
// 你可以在任何时间选择让栈顶的元素出栈，这时就会出现很多的出栈顺序，请问出栈顺序一共有多少种
// 比如数列为a a b的出栈顺序有顺序 
// 1：操作：入 a → 出 a → 入 a → 出 a → 入 b → 出 b出栈顺序：a, a, b顺序 
// 2：操作：入 a → 入 a → 出 a → 出 a → 入 b → 出 b出栈顺序：a, a, b顺序
// 3：操作：入 a → 入 a → 入 b → 出 b → 出 a → 出 a出栈顺序：b, a, a顺序
// 4：操作：入 a → 出 a → 入 a → 入 b → 出 b → 出 a出栈顺序：a, b, a顺序 
// 5：操作：入 a → 入 a → 入 b → 出 b → 出 a → 出 a出栈顺序：b, a, a顺序 
// 6：操作：入 a → 入 a → 出 a → 入 b → 出 b → 出 a出栈顺序：a, b, a
// 其中顺序1和顺序2相同视作同一种，顺序3和顺序5相同视作同一种，顺序4和顺序6相同视作同一种故答案为3种
// 输入描述:第一行一个整数n代表数列中有n个字母第二行n个字母，中间以空格分隔，代表数列中的字母
// 输出描述:一个数字代表出栈顺序一共有多少种?
/*
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;
void dfs(int i, int n, string s, stack<char>& st, unordered_set<string>& vis, vector<char>& temp){
    if(i==n&&st.empty()){
        string seq(temp.begin(),temp.end());
        vis.insert(seq);
        return;
    }
    if(i<s.size()){
        st.push(s[i]);
        dfs(i+1,n,s,st,vis,temp);
        st.pop();
    }
    if(!st.empty()){
        char top=st.top();
        st.pop();
        temp.push_back(top);
        dfs(i,n,s,st,vis,temp);
        temp.pop_back();
        st.push(top);
    }
}
int main()
{
    int n;
    cin>>n;
    char a;
    string s;
    for(int i=0;i<n;i++){
        cin>>a;
        s+=a;
    }
    stack<char> st;
    unordered_set<string> vis;
    vector<char> temp;
    dfs(0,n,s,st,vis,temp);
    cout<<vis.size()<<endl;
    return 0;
}
*/
// 给定一个n×m的网格图，每个格子可能是空地（.）或障碍物（#）。
// 你从左上角出发，每次只能向右或向下移动，到达右下角。
// 请计算从起点到终点的最短路径数量。答案可能很大，请输出答案对1e9+7取模的结果
/*
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n+1,vector<char>(m+1));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    vector<int> dp(m+1,0);
    dp[1]=1;
    for(int i=0;i<n;i++)
        for(int j=1;j<=m;j++)
            if(grid[i][j-1]!='#')
                //每一步都要取模mod
                dp[j]=dp[j-1]%mod+dp[j]%mod;
            else
                dp[j]=0;
    cout<<dp[m]%mod<<endl;
    return 0;
}
*/


// 阜阳师范大学为了选拔蓝桥杯参赛选手，在实验室门口张贴一道题目，
// 做出来的就可以参与蓝桥杯集训，题目如下给你一个奇数长度 n 的数组，
// 数组中有若干个数字，每个数字在数组中出现的个数都为偶数，
// 只有一个数出现的次数是奇数，请输出这个数如1 1 2 2 3 3 3 3 4 4 4 5 5 中
//  1有两个 2有两个 3有四个 5有两个 4有三个 
//  故特殊的数字就是4题目保证数组中只有一个数字出现的次数是奇数次
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> prev(n,0);
    for(int i=0;i<n;++i){
        cin>>prev[i];
    }
    sort(prev.begin(),prev.end());
    for(int i=0;i<n;i+=2)
        if(prev[i]!=prev[i+1]){
            cout<<prev[i]<<endl;
            break;
        }
    return 0;
}
*/

// 第九题:你有n个任务需要完成，每个任务有一个完成时间t和一个收益p.
// 任务之间存在依赖关系：如果任务 u依赖任务v，则任务v必须在任务u之前完成。
// 所有满足依赖条件的任务可以同时进行，请问最后可以获得多少收益，获得这些收益需要多少时间
// 输入描述:
// 第一行包含两个整数n和m，表示任务数量和依赖关系数量。
// 第二行包含n个整数 t1,t2,…,tn，表示每个任务的完成时间。
// 第三行包含n个整数 p1,p2,…,pn，表示每个任务的收益。
// 接下来m行，每行包含两个整数u和v，表示任务u依赖任务v。
// 输出描述:
// 一行两个整数，表示总收益和需要的时间

/*
#include <bits/stdc++.h> // 包含各种常用库的头文件
using namespace std;    // 使用标准命名空间

int main() {
    ios::sync_with_stdio(false); // 关闭C++标准流与C标准流的同步，提高输入输出效率
    cin.tie(nullptr);            // 解除cin与cout的绑定，进一步提高效率

    int n; // 定义变量n，表示任务的数量
    cin >> n; // 从输入中读取任务数量
    int m; // 定义变量m，表示任务之间的依赖关系数量
    cin >> m; // 从输入中读取任务依赖关系的数量
    vector<int> t(n), p(n); // 定义两个大小为n的向量t和p，分别存储每个任务的耗时和优先级
    long long sum_p = 0; // 定义变量sum_p，用于累加所有任务的优先级

    // 读取每个任务的耗时
    for (int i = 0; i < n; ++i) {
        cin >> t[i]; // 从输入中读取第i个任务的耗时并存储在向量t的第i个位置
    }

    // 读取每个任务的优先级，并累加计算总优先级
    for (int i = 0; i < n; ++i) {
        cin >> p[i]; // 从输入中读取第i个任务的优先级并存储在向量p的第i个位置
        sum_p += p[i]; // 累加优先级到sum_p
    }

    // 定义三个大小为n的向量，用于存储任务的前驱节点、邻接表以及入度
    vector<vector<int>> predecessors(n); // predecessors[i]存储第i个任务的前驱节点列表
    vector<vector<int>> adj(n); // adj[i]存储第i个任务的后继节点列表（邻接表）
    vector<int> in_degree(n, 0); // in_degree[i]存储第i个任务的入度（依赖它的任务数量）

    // 读取每个任务的依赖关系
    for (int i = 0; i < m; ++i) {
        int u, v; // 定义u和v，表示两个任务之间的依赖关系，u依赖v
        cin >> u >> v; // 从输入中读取依赖关系
        u--; v--; // 将任务编号转换为0索引
        predecessors[u].push_back(v); // 将v添加到u的前驱节点列表中
        adj[v].push_back(u); // 将u添加到v的邻接表（后继节点列表）中
        in_degree[u]++; // 增加u的入度，因为u依赖v
    }

    queue<int> q; // 定义队列q，用于广度优先搜索（BFS）
    vector<int> ect(n, 0); // 定义向量ect，用于存储每个任务的最早完成时间（Earliest Completion Time）
    int max_time = 0; // 定义变量max_time，用于记录所有任务中最长的最早完成时间

    // 初始化队列，将所有入度为0的任务（没有前驱的任务）加入队列
    for (int i = 0; i < n; ++i) {
        if (in_degree[i] == 0) { // 如果第i个任务的入度为0
            q.push(i); // 将第i个任务加入队列q
        }
    }

    // 使用BFS处理每个任务的最早完成时间
    while (!q.empty()) { // 当队列不为空时，继续处理
        int u = q.front(); // 取出队列的第一个任务u
        q.pop(); // 从队列中移除任务u

        int current_ect = 0; // 定义变量current_ect，用于记录当前任务u的最早完成时间
        // 遍历任务u的所有前驱节点，计算current_ect为所有前驱节点的最早完成时间的最大值
        for (int v : predecessors[u]) {
            current_ect = max(current_ect, ect[v]);
        }

        // 计算任务u的最早完成时间，并更新max_time
        ect[u] = current_ect + t[u]; // 任务u的最早完成时间为其前驱节点的最早完成时间加上自身的耗时
        max_time = max(max_time, ect[u]); // 更新max_time，记录最长的最早完成时间

        // 遍历任务u的所有邻接节点（后继节点），减少它们的入度
        for (int w : adj[u]) {
            if (--in_degree[w] == 0) { // 如果后继节点w的入度减少为0
                q.push(w); // 将后继节点w加入队列q
            }
        }
    }

    // 输出所有任务的总优先级以及最长的最早完成时间
    cout << sum_p << ' ' << max_time << endl;

    return 0; // 返回0，表示程序正常结束
}
*/
// 某某师范大学实验室出现了1e8个不学习的同学，现在要被你排队踢出实验室，
// 所有人排成一个队伍，你现在有一个数字n开始时为0，你会循环进行如下操作直到只剩一人
// 1.数字n加1 即令n变成n+1
// 2.如果数字与7有关（7的倍数或者数位中含有7）就踢出队头同学，否则让队头同学走到队尾
// 解释：7 14 21因为是7的倍数要被踢出 ，7 17 27 71等因为数位中含有7要被踢出
// 请问最后剩下的那个人，是初始队伍中的第几个,可以使用暴力
/*
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

bool isRelatedTo7(int n) {
    if (n % 7 == 0) return true;
    while (n > 0) {
        if (n % 10 == 7) return true;
        n /= 10;
    }
    return false;
}

int main() {
    int n = 0;
    deque<int> q;

    // 初始化队列
    for (int i = 1; i <= 100000000; ++i) {
        q.push_back(i);
    }

    while (q.size() > 1) {
        n++;
        if (isRelatedTo7(n)) {
            q.pop_front(); // 踢出队头
        } else {
            int front = q.front();
            q.pop_front();
            q.push_back(front); // 移到队尾
        }
    }

    cout  << q.front() << endl;

    return 0;
}
*/

// 给定一个大小为 n×m 的矩阵，矩阵中的元素为整数（可能为负数）。
// 请找到一个子矩阵，使得该子矩阵中所有元素的和最大，并输出这个最大和。
// 输入描述:第一行包含两个整数n和m，表示矩阵的行数和列数。接下来n行，每行包含m个整数，表示矩阵中的元素。
// 输出描述:输出一个整数，表示最大子矩阵的和。
/*
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 计算一维数组的最大子数组和
int maxSubarraySum(vector<int>& arr) {
    int maxSum = INT_MIN; // 初始化最大和为最小整数
    int currentSum = 0; // 初始化当前和为0
    for (int num : arr) { // 遍历数组中的每一个元素
        // 更新当前和：要么是当前元素本身，要么是加上当前元素后的和
        currentSum = max(num, currentSum + num);
        // 更新最大和
        maxSum = max(maxSum, currentSum);
    }
    return maxSum; // 返回最大子数组和
}

// 计算二维矩阵中的最大子矩阵和
int maxSubmatrixSum(vector<vector<int>>& matrix) {
    int n = matrix.size(); // 获取矩阵的行数
    if (n == 0) return 0; // 如果矩阵为空，返回0
    int m = matrix[0].size(); // 获取矩阵的列数
    int maxSum = INT_MIN; // 初始化最大和为最小整数

    // 固定左边界
    for (int left = 0; left < m; ++left) {
        vector<int> rowSum(n, 0); // 初始化行和数组，用于存储当前列边界下的行和
        // 移动右边界
        for (int right = left; right < m; ++right) {
            // 计算每一行的和，并累加到rowSum中
            for (int i = 0; i < n; ++i) {
                rowSum[i] += matrix[i][right];
            }
            // 计算当前边界下的最大子数组和，并更新最大矩阵和
            maxSum = max(maxSum, maxSubarraySum(rowSum));
        }
    }

    return maxSum; // 返回最大子矩阵和
}

int main() {
    int n, m; // 定义矩阵的行数和列数
    cin >> n >> m; // 从标准输入读取矩阵的行数和列数
    vector<vector<int>> matrix(n, vector<int>(m)); // 创建一个n行m列的矩阵

    // 读取矩阵的每一个元素
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << maxSubmatrixSum(matrix) << endl; // 计算并输出最大子矩阵和
    return 0;
}
*/
// 众所周知，程序设计竞赛有很多赛制，有ACM赛制，IOI赛制和OI赛制ACM排名
// 规则如下：解题数量 ：队伍解出的题目数量越多，排名越高。
// 罚时（Penalty Time）：如果两支队伍解出的题目数量相同，则比较罚时。
// 罚时由以下公式计算：罚时 = 每道题目的提交时间 + 错误提交次数 × 20分钟
// 每道题目的提交时间  ：从比赛开始到该题目首次通过的时间。
// 错误提交次数 ：在该题目首次通过之前的所有错误提交次数。
// 排名顺序：先按解题数量降序排列，解题数量相同则按罚时升序排列，
// 若都相同则排名相同现给出一场比赛中的所有提交，
// 请问id为0的选手，在ACM赛制下的排名是第几名,若选手在比赛中没有任何提交则不参与排名,
// 题目保证0号选手有提交
// 输入描述:第一行 一个数字n，代表这一场比赛一共有n个提交接下来n行 
// 每行四个数字x,a,b,t 分别是选手的编号,提交的题号,
// 本次提交结果（AC用1表示 所有非1情况都视为提交没有AC）,提交的时间是距离开始多少分钟
// 输出描述:一个数字n代表id为0的选手，在ACM赛制下的排名是第几名
//傻B题目,需要考虑多一点细节
/*
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Submission {
    int correct;
    int time;
};

struct ProblemResult {
    bool solved = false;
    int first_ac_time = 0;
    int wrong_before_ac = 0;
};

struct Contestant {
    int total_solved = 0;
    long long total_penalty = 0;
    unordered_map<int, ProblemResult> problems; // 题目到结果的映射
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 使用嵌套map存储每个选手每个题目的提交记录，按时间排序
    unordered_map<int, unordered_map<int, vector<Submission>>> submissions;

    for (int i = 0; i < n; ++i) {
        int uid, pid, correct, time;
        cin >> uid >> pid >> correct >> time;
        submissions[uid][pid].push_back({correct, time});
    }

    // 处理每个选手的每个题目，按时间排序后计算
    unordered_map<int, Contestant> contestants;

    for (auto &user_entry : submissions) {
        int uid = user_entry.first;
        Contestant &c = contestants[uid];

        for (auto &prob_entry : user_entry.second) {
            int pid = prob_entry.first;
            auto &subs = prob_entry.second;

            // 按时间升序排序
            sort(subs.begin(), subs.end(), [](const Submission &a, const Submission &b) {
                return a.time < b.time;
            });

            ProblemResult pr;
            for (const auto &sub : subs) {
                if (pr.solved) {
                    break; // 已经AC，后续提交忽略
                }
                if (sub.correct == 1) {
                    pr.solved = true;
                    pr.first_ac_time = sub.time;
                } else {
                    pr.wrong_before_ac++;
                }
            }

            if (pr.solved) {
                c.total_solved++;
                c.total_penalty += pr.first_ac_time + pr.wrong_before_ac * 20;
            }
        }
    }

    // 处理0号选手不存在的情况（题目保证存在）
    if (!contestants.count(0)) {
        cout << 0 << endl;
        return 0;
    }

    const Contestant &zero = contestants[0];
    int num0 = zero.total_solved;
    long long penalty0 = zero.total_penalty;

    int k = 0; // 统计排在0号前的选手数量
    for (const auto &pair : contestants) {
        int uid = pair.first;
        if (uid == 0) continue;

        const Contestant &c = pair.second;
        if (c.total_solved > num0) {
            k++;
        } else if (c.total_solved == num0 && c.total_penalty < penalty0) {
            k++;
        }
    }

    cout << k + 1 << endl;
    
    return 0;
}
*/