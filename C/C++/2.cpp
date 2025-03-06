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
