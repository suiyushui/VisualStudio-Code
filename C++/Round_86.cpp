// 牛客周赛 Round 86
// https://ac.nowcoder.com/acm/contest/104637



// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> v(n);
//         for (int i = 0; i < n; ++i) {
//             cin >> v[i];
//         }

//         sort(v.begin(), v.end());
//         //bitset头文件中定义了bitset类，它是一个模板类，可以用来处理位运算。
//         bitset<10005> dp;//bitset是一种快速处理位运算的容器，这里用bitset来表示dp数组
//         dp[0] = 1;
//         int ans = -1;
//         for (int i = 0; i < n; ++i) {
//             int S = v[i] + 1;// 假设v[i]是当前的最大值，那么v[i]+1就是当前的最小值
//             if (S < 10005) {
//                 int pos = v[i]+1;// 找到第一个大于v[i]的位置
//                 while(pos < 10005 && dp[pos] == 0){
//                     pos++;
//                 }
//                 // _Find_next(v[i])返回的是第一个大于v[i]的位置，如果没有，返回20005
//                 if (pos != 10005) {
//                     if (ans == -1 || pos + v[i] < ans) {
//                         ans = pos + v[i];
//                     }
//                 }
//             }
//             dp |= dp << v[i];// 向左移位v[i]位，并与dp进行或运算，表示把v[i]加入集合中
//         }
//         cout << ans << '\n';
        
//     }
//     return 0;
// }

// 小苯的线性dp

// #include<bits/stdc++.h>
// using namespace std; 
// using ll=long long;
// int main(){
//     int T;
//     cin >> T;
//     while(T--){
//         int n;
//         cin >> n;
//         vector<ll> v(n+1),s(n+1,0);
//         for (int i = 1; i <= n; i++) cin >> v[i];
//         for (int i = 1; i <= n; i++) s[i]=s[i-1]+v[i];  
//         for(int k=1;k<=n-2;k++){
//             vector<ll> pre(n+1,0),suf(n+2,0);
//             for(int i=1;i<=n;i++) pre[i]=max(pre[i-1],s[i]-s[max(i-k,0)]);
//             for(int i=n;i>=1;i--) suf[i]=max(suf[i+1],s[min(i+k-1,n)]-s[i-1]);
//             ll ans=0;
//             for(int i=1;i<=n;i++) ans=max(ans,max(pre[i-1],suf[i+1])-v[i]);
//             cout<<ans<<' ';
//         }
//         cout<<max(s[n]-2*v[1],s[n-1]-v[n])<<" 0\n";
//     }
//     return 0;
// }



#include<iostream>
#include<vector>
#include<utility>
using namespace std; 
int main(){
    cout<<"Hello World"<<endl;
    vector<pair<int,int>> v;
    v.push_back(make_pair(1,2));
    v.push_back(make_pair(3,4));
    for(auto t :v){
        cout<<t.first<<" "<<t.second<<endl;
    }
    return 0;
}