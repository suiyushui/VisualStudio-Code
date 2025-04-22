// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     long long a=2250000000;
//     cout<<a;
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     cin.tie(0)->sync_with_stdio(0);
//     cout.tie(0);
//     string s="3cc?wfeaviswcgh@k-x2ddajyw+7zav5t/qrkwojsz$jdcr3p!c0f#frxcuwroaj<smgl+555qldrkv58btwt>qb5tahzd^nsj(*s*<d?idwf?boos2oyoweibg00hfp*ztepj^tz^sqiew18efrpw#y4#qvgd2@c3wyhu$jx*!fhtat^-5di>fch<e>e5sdogvki(i>iszujfu0vl5uj";
//     string a="weight";
//     int l=0,r=0;
//     int n=s.length(),m=a.length();
//     while(l<n && r<n){
//     vector<int> next(m,-1);
//     for(int i=0,j=-1;i<m;i++){
//         while(j!=-1 && a[i]!=a[j+1]) j=next[j];
//         if(a[i]==a[j+1]) j++;
//         next[i]=j;
//     }

// }


// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     cin.tie(0)->sync_with_stdio(0);
//     cout.tie(0);
//     int T;
//     cin>>T;
//     while(T--){
//         int N,M,K,t;
//         cin>>N>>M>>K>>t;
//         int count=0;
//         int time=t/N;
//         while(K>=M){
//             K-=M;
//             count++;
//         }
//         while(time--){
//             K<<=1;
//             if(K>=M){
//                 K-=M;
//                 count++;
//             }
//         }
//         cout<<count<<endl;
//     }
//     return 0;
// }


// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// // 检查子串是否包含"weight"子序列
// bool is_weight_subsequence(const string &s, int start, int end) {
//     const string weight = "weight";
//     int k = 0;
//     for (int i = start; i <= end; ++i) {
//         if (k < 6 && s[i] == weight[k]) {
//             k++;
//         }
//     }
//     return k == 6;
// }

// int main() {
//     // 读取输入直到EOF
//     // string s;
//     // while (cin) {
//     //     string line;
//     //     getline(cin, line);
//     //     s += line;
//     // }
//     string s="3cc?wfeaviswcgh@k-x2ddajyw+7zav5t/qrkwojsz$jdcr3p!c0f#frxcuwroaj<smgl+555qldrkv58btwt>qb5tahzd^nsj(*s*<d?idwf?boos2oyoweibg00hfp*ztepj^tz^sqiew18efrpw#y4#qvgd2@c3wyhu$jx*!fhtat^-5di>fch<e>e5sdogvki(i>iszujfu0vl5uj";
//     int n = s.size();
//     if (n == 0) {
//         cout << 0 << endl;
//         return 0;
//     }

//     // 预处理前缀和数组
//     vector<int> digits(n + 1, 0);
//     vector<int> symbols(n + 1, 0);

//     for (int i = 0; i < n; ++i) {
//         digits[i + 1] = digits[i] + (isdigit(s[i]) ? 1 : 0);
//         if (!isdigit(s[i]) && !isalpha(s[i])) {
//             symbols[i + 1] = symbols[i] + 1;
//         } else {
//             symbols[i + 1] = symbols[i];
//         }
//     }

//     int count = 0;

//     // 遍历所有可能的子串
//     for (int i = 0; i < n; ++i) {
//         for (int len = 8; len <= 16; ++len) {
//             int j = i + len - 1;
//             if (j >= n) break;

//             // 检查数字和符号条件
//             int d = digits[j + 1] - digits[i];
//             int sym = symbols[j + 1] - symbols[i];

//             if (d >= 1 && sym >= 1) {
//                 // 检查是否包含"weight"子序列
//                 if (!is_weight_subsequence(s, i, j)) {
//                     count++;
//                 }
//             }
//         }
//     }

//     cout << count << endl;

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// using ll=long long;

// ll count(ll n) {
//     ll count = 0;
//     for (ll i = 5; i <= n; i *= 5) {
//         count += n / i;
//     }
//     return count;
// }

// int main() {
//     cin.tie(0)->sync_with_stdio(0);
//     cout.tie(0);
//     int T;
//     cin>>T;
//     while(T--) {
//         ll n,m;
//         cin>>n>>m;
//         ll num = count(n);
//         if(2*num==m) cout<<"YES"<<endl;
//         else cout<<"NO"<<endl;
//     }
//     return 0;
// }






// #include<bits/stdc++.h>
// using namespace std;
// using ll=long long;

// int main() {
//     cin.tie(0)->sync_with_stdio(0);
//     cout.tie(0);
//     int T;
//     cin>>T;
//     while(T--) {
//         int n,c1,c2;
//         cin>>n>>c1>>c2;
//         ll cnt=0;
//         for(int i=0;i<n;i++) {
//             string s;
//             cin>>s;
//             unordered_map<char,int> mp;
//             for(int j=0;j<s.length();j++) 
//                 mp[s[j]]++;
//             if(c1>=c2){
//                 for(auto x:mp) cnt+=ceil(1.0*x.second/2)*c2;
//             }else if(2*c1<=c2){
//                 for(auto x:mp) cnt+=x.second*c1;
//             }else if(2*c1>c2){
//                 for(auto x:mp) cnt+=x.second/2*c2+x.second%2*c1;
//             }
//         }
//         cout<<cnt<<endl;
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     cin.tie(0)->sync_with_stdio(0);
//     cout.tie(0);
//     int T; cin>>T;
//     while(T--) {
//         int N; cin>>N;
//         int ans=0;
//         for(int i=0;i<N;i++){
//             char x;
//             int a,n;
//             cin>>n>>x;
//             if(x=='A') a=10;
//             else a=(x-'0');
//             ans=(a+ans)%10;  
//         }
//         cout<<(ans%5==0? "YES" : "NO")<<endl;
//     }
//     return 0;
// }





// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// int main() {
//     cin.tie(0)->sync_with_stdio(0);
//     cout.tie(0);
//     int T; cin>>T;
//     while(T--) {
//         ll n,m,q; 
//         cin>>n>>m>>q;
//         vector<array<ll,3>> v(q+1);
//         bitset<1000000> row(0), col(0);
//         for(ll i=1;i<=q;i++){
//             string s1, s2;
//             ll x;
//             cin >> s1 >> s2 >> x;
//             if(s2 == "row"){
//                 if(s1 == "flame") v[i] = {1, x, 1};
//                 else v[i] = {1, x, 0};
//             }else{
//                 if(s1 == "flame") v[i] = {0, x, 1};
//                 else v[i] = {0, x, 0};
//             }
//         }
//         ll sum=n*m,ans=0;
//         for(ll i=q;i>=1;i--){
//             ll x=v[i][0],y=v[i][1],z=v[i][2];
//             if(x==0){
//                 if(row.test(y)) continue;
//                 row.set(y);
//                 if(z) ans+=n;
//                 m--;
//             }else{
//                 if(col.test(y)) continue;
//                 col.set(y);
//                 if(z) ans+=m;
//                 n--;
//             }
//         }
//         cout<<sum-ans<<endl;
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// int main() {
//     cin.tie(0)->sync_with_stdio(0);
//     cout.tie(0);
//     int T; cin>>T;
//     while(T--) {
//         string s; cin>>s;
//         int n=s.length();
//         int left=0,right=0;
//         while(left<n&&s[0]==s[left]) left++;
//         while(right<n&&s[n-1]==s[n-1-right]) right++;
//         if(left+right>=n||n<3) {
//             cout<<0<<endl;
//             continue;
//         }
//         ll ans=(n+1)*n/2-1;
//         if(s[0]==s[n-1]) ans-=left+right+left*right;
//         else ans-=left+right;
//         cout<<ans<<endl;
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// ll cal(char c){
//     return c - 'a' + 1;
// }

// void solve(){
//     string s;
//     cin >> s;
//     ll n = s.size();
//     vector<ll> sum(28);
//     vector<vector<ll>> pre(28, vector<ll>(n + 1));
//     for(int i = 1; i <= n; i ++){
//         ll x = cal(s[i - 1]);
//         sum[x] ++;
//         for(int j = 1; j <= 26; j ++){
//             pre[j][i] = sum[j];
//         }
//     }
//     ll ans = 0;
//     set<ll> st;
//     for(int i = 1; i <= n; i ++){
//         ll x = cal(s[i - 1]);
//         st.insert(x);
//         auto check =[&](ll mid) -> bool{
//             set<ll> sp;
//             for(int j = 1; j <= 26; j ++){
//                 ll yu1 = pre[j][i - 1];
//                 ll yu2 = pre[j][n] - pre[j][mid];
//                 if(yu1 || yu2) sp.insert(j); 
//             }
//             return (sp.size() >= 2 ? true : false);
//         };
//         ll l = i, r = n;
//         while(l < r){
//             ll mid = l + r + 1 >> 1ll;
//             if(check(mid)) l = mid;
//             else r = mid - 1;
//         }
//         if(check(l)) ans += l - i + 1;
//         if(st.size() == 2){
//             ll yu = n - i;
//             ans += yu * (yu + 1) / 2;
//             break;
//         }
//     }
//     cout << ans << '\n';
// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;
//     cin >> t;
//     while(t --){
//         solve();
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     cout.tie(nullptr);
//     int T; cin >> T;
//     while (T--) {
//         int N; cin >> N;
//         vector<int> prev(N + 1);
//         for (int i = 1; i <= N; i++) cin >> prev[i];
//         vector<int> dp(N + 1);
//         for (int i = N; i >= 1; i--) {
//             auto it = lower_bound(dp.begin(), dp.end(), prev[i], greater<int>());
//             if (it == dp.end()) {
//                 dp.push_back(prev[i]);
//                 prev[i] = dp.size()-1;
//             } else {
//                 *it = prev[i];
//                 prev[i] = it - dp.begin() ;
//             }
//         }
//         for (int i = 1; i <= N; i++) cout << prev[i] << " ";
//         cout << endl;
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const ll MOD = 1e9 + 7;
// ll powmod(ll a, ll b) {
//     ll res = 1;
//     while (b) {
//         if (b & 1) res = res * a % MOD;
//         a = a * a % MOD;
//         b >>= 1;
//     }
//     return res;
// }
// ll inv(ll x) {
//     return powmod(x, MOD - 2);
// }
// ll Cr(ll n,ll m,vector<ll>&fact,vector<ll>&ifact) {
//     if (m > n||m<0|| n<0 ) return 0;
//     return fact[n] * ifact[m] % MOD * ifact[n - m] % MOD;
// }
// void pre(int n,vector<ll>&fact,vector<ll>&ifact) {
//     fact[0] = 1;
//     for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
//     ifact[n] = inv(fact[n]);
//     for (int i = n - 1; i >= 0; i--) ifact[i] = ifact[i + 1] * (i + 1) % MOD;
// }
// void solve(vector<ll>&fact,vector<ll>&ifact) {
//     int n,x; cin >> n>>x;
//     if(n<x){
//         cout<<0<<endl;
//     }else{
//         ll ans=0,INV=inv(x);
//         for(int i=x;i<=n;i++){
//             ll cnt=1;
//             cnt= cnt*powmod(INV,x-1)%MOD;
//             cnt= cnt*powmod(x-1,i-x)%MOD*powmod(INV,i-x)%MOD;
//             cnt= cnt*Cr(i-1,i-x,fact,ifact)%MOD;
//             cnt=(cnt*INV)%MOD;
//             ans=(ans+cnt)%MOD;
//         }
//         cout<<ans<<endl;
//     }
// }
// int main() {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     cout.tie(nullptr);
//     vector<ll> fact(1000001),ifact(1000001);
//     pre(1000000,fact,ifact);
//     int T; cin >> T;
//     while (T--) {
//         solve(fact,ifact);
//     }
//     return 0;
// }



#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 检查子串是否包含"weight"子序列
bool is_weight_subsequence(const string &s, int start, int end) {
    const string weight = "weight";
    int k = 0;
    for (int i = start; i <= end; ++i) {
        if (k < 6 && s[i] == weight[k]) {
            k++;
        }
    }
    return k == 6;
}

int main() {
    // 读取输入直到EOF
    // string s;
    // while (cin) {
    //     string line;
    //     getline(cin, line);
    //     s += line;
    // }
    string s="3cc?wfeaviswcgh@k-x2ddajyw+7zav5t/qrkwojsz$jdcr3p!c0f#frxcuwroaj<smgl+555qldrkv58btwt>qb5tahzd^nsj(*s*<d?idwf?boos2oyoweibg00hfp*ztepj^tz^sqiew18efrpw#y4#qvgd2@c3wyhu$jx*!fhtat^-5di>fch<e>e5sdogvki(i>iszujfu0vl5uj";
    int n = s.size();
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    // 预处理前缀和数组
    vector<int> digits(n + 1, 0);
    vector<int> symbols(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        digits[i + 1] = digits[i] + (isdigit(s[i]) ? 1 : 0);
        if (!isdigit(s[i]) && !isalpha(s[i])) {
            symbols[i + 1] = symbols[i] + 1;
        } else {
            symbols[i + 1] = symbols[i];
        }
    }

    int count = 0;

    // 遍历所有可能的子串
    for (int i = 0; i < n; ++i) {
        for (int len = 8; len <= 16; ++len) {
            int j = i + len - 1;
            if (j >= n) break;

            // 检查数字和符号条件
            int d = digits[j + 1] - digits[i];
            int sym = symbols[j + 1] - symbols[i];

            if (d >= 1 && sym >= 1) {
                // 检查是否包含"weight"子序列
                if (!is_weight_subsequence(s, i, j)) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}