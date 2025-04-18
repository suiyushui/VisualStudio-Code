/*
#include <iostream>
#include <map>
#include <vector>

// 函数：质因数分解
std::map<int, int> primeFactorization(int n) {
	std::map<int, int> factors;
	std::vector<bool> vis(n + 1, false);
	std::vector<int> primes;
	
	vis[0] = vis[1] = true;
	
	for (int i = 2; i <= n; ++i) {
		if (!vis[i])
			primes.push_back(i);
		for (int j = 0; primes[j]*i <= n; ++j) {
			vis[i * primes[j]] = true;
			if (i % primes[j] == 0) 
				break;
		}
	}
	
	for (int prime : primes) {
		while (n % prime == 0) {
			factors[prime]++;
			n /= prime;
		}
	}
	if (n > 1) {
		factors[n]++;
	}
	return factors;
}

// 函数：计算复制字符的总步数
int calculateSteps(int n) {
	auto factors = primeFactorization(n);
	int x = 0, y = 0;
	int result = 0;
	
	// 提取4^x和6^y的指数
	if (factors.find(2) != factors.end()) {
		x = factors[2] / 2;
		if (factors[2] % 2 != 0) {
			factors[2] = 1; // 剩余的2的因子
		} else {
			factors.erase(2); // 如果2的因子都被分配到4^x中
		}
	}
	if (factors.find(3) != factors.end()) {
		y = factors[3];
		factors.erase(3); // 3的因子都被分配到6^y中
	}
	
	// 计算结果
	result += 6 * x + 8 * y;
	
	// 计算剩余部分的贡献
	for (const auto& factor : factors) {
		int pi = factor.first;
		int ki = factor.second;
		result += (pi + 2) * ki; // 贡献计算
	}
	
	return result;
}

int main() {
	int n = 100000; // 目标数量
	int steps = calculateSteps(n);
	std::cout << steps << std::endl;
	return 0;
}
*/


//24个01串中,任意连续5个中不存在3个1,则称为可行串。求有多少可行串。
#include <iostream>
#include <vector>
#include <numeric>// accumulate

using namespace std;
void solve(){
	int n=24,k=3;
	vector<vector<long long>> dp(n+1,vector<long long>(1<<4,0));
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int mask=0;mask<(1<<4);mask++){
			if(dp[i-1][mask]==0)continue;

			int new_mask=(mask<<1)&0b1111;
			dp[i][new_mask]+=dp[i-1][mask];

			new_mask=(mask<<1|1)&0b1111;
			if(__builtin_popcount(mask)<k)
				dp[i][new_mask]+=dp[i-1][mask];
		}
	}
	long long ans=accumulate(dp[n].begin(),dp[n].end(),0);
	cout<<ans<<endl;
}
void solve2(){
	int n=24,k=3,ans=0;
	int max_num=1<<24;
	for(int i=0;i<max_num;i++){
		vector<int> num(25,0);
		for(int j=0;j<24;j++)
			num[j+1]=num[j]+((i>>j)&1);
		int cnt=1;
		if(num[4]>k) cnt=0;
		for(int j=5;j<=24;j++)
			if(num[j]-num[j-5]>k) cnt=0;
		ans+=cnt;
	}
	cout<<ans<<endl;
}
int main(){
	solve2();
	return 0;
}