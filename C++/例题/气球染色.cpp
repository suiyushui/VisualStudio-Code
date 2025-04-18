#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int minTime(int n, string& color, vector<int>& value) {
    vector<vector<int>> dp(n+1, vector<int>(3, 0));
    for(int i=1;i<=n;i++){
        int a=INT_MAX, b=INT_MAX, c=INT_MAX;
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j==k)
                    dp[i][j]=min(dp[i][j], dp[i-1][k]);
                else
                    dp[i][j]=min(dp[i][j], dp[i-1][k]+value[i-1]);
            }
        }
        if(color[i-1]=='0') a=min(a, dp[i][0]);
        if(color[i-1]=='1') b=min(b, dp[i][1]);
        if(color[i-1]=='2') c=min(c, dp[i][2]);
        dp[i][0]=a+(color[i-1]=='0'?0:value[i-1]);
        dp[i][1]=b+(color[i-1]=='1'?0:value[i-1]);
        dp[i][2]=c+(color[i-1]=='2'?0:value[i-1]);
    }
    return min({dp[n][0], dp[n][1], dp[n][2]});
}
int main() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    vector<int> b(n);
    for(int i=0;i<n;i++)
        cin >> b[i];

    cout<<minTime(n, a, b)<<endl;
    return 0;
}
