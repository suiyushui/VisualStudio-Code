//经典ST表
/*
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5; // 数组最大长度
const int LOG = 20;  // log2(MAXN) 的最大值
int st[MAXN][LOG];   // ST表
int log_table[MAXN]; // 预计算 log2 值

// 预处理函数
void build(int arr[], int n) {
    // 预计算 log2 值
    log_table[1] = 0;
    for (int i = 2; i <= n; i++) {
        log_table[i] = log_table[i / 2] + 1;
    }

    // 初始化 ST 表
    for (int i = 0; i < n; i++) {
        st[i][0] = arr[i]; // 每个元素自身是最值
    }

    // 动态规划填充 ST 表
    for (int j = 1; (1<<j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// 查询函数
int query(int L, int R) {
    int k = log_table[R - L + 1]; // 计算 log2(R - L + 1)
    return max(st[L][k], st[R - (1 << k) + 1][k]);
}

int main() {
    int arr[] = {1, 3, 2, 5, 4, 6}; // 示例数组
    int n = sizeof(arr) / sizeof(arr[0]);

    // 构建 ST 表
    build(arr, n);

    // 查询示例
    cout << "Max in [1, 3]: " << query(1, 3) << endl; // 输出 5
    cout << "Max in [0, 5]: " << query(0, 5) << endl; // 输出 6
    cout << "Max in [2, 4]: " << query(2, 4) << endl; // 输出 5
    cout << "Max in [0, 6]: " << query(0, 5) << endl; // 输出 6

    return 0;
}
*/

//给定一个静态数组，多次查询区间 [L, R] 的最大值或最小值。
/*#include<iostream>
using namespace std;
const int LOGN=20;
const int MAXN=1e5+5;
int st_max[MAXN][LOGN];
int st_min[MAXN][LOGN];
int log_table[MAXN];

void build(int arr[],int n){
	log_table[1]=0;
	for(int i=2;i<=n;i++)
		log_table[i]=log_table[i>>1]+1;
	for(int i=1;i<=n;i++)
		st_max[i][0]=arr[i],
		st_min[i][0]=arr[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st_max[i][j]=max(st_max[i][j-1],st_max[i+(1<<(j-1))][j-1]),
			st_min[i][j]=min(st_min[i][j-1],st_min[i+(1<<(j-1))][j-1]);
}
int query(int op,int l,int r){
	int k=log_table[r-l+1];
	return (op==1?max(st_max[l][k],st_max[r-(1<<k)+1][k]):min(st_min[l][k],st_min[r-(1<<k)+1][k]));
}
int main(){
	int n,t;
	cin>>n>>t;
	int arr[n+1];
	for(int i=1;i<=n;++i)
		cin>>arr[i];
	while(t--){
		int op,l,r;
		cin>>op>>l>>r;
		cout<<query(op,l,r)<<endl;
	}
	return 0;
}*/
// 给定一个静态数组，多次查询区间 [L, R] 的最大公约数（GCD）。
/*
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int log_table[MAXN];
int st[MAXN][20];
void build_log_table(){
	log_table[1]=0;
	for(int i=2;i<MAXN;i++)
		log_table[i]=log_table[i>>1]+1;
}
int gcd(int a,int b){
    while(b){
        int temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}

void build_st(int arr[],int n){
	build_log_table();
	for(int i=1;i<=n;i++)
		st[i][0]=arr[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int query(int l,int r){
	int k=log_table[r-l+1];
	return gcd(st[l][k],st[r-(1<<k)+1][k]);
}
int main(){
	int n,q;
	cin>>n>>q;
	int arr[n+1];
	for(int i=1;i<=n;++i)
		cin>>arr[i];
	build_st(arr,n);
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<query(l,r)<<endl;
	}
	return 0;
}
*/


// #include<bits/stdc++.h>
// using namespace std;
// const int MAXN=1e5+5; 
// int log_table[MAXN];
// int st[MAXN][20];
// void build_log_table(){
// 	log_table[1]=0;
// 	for(int i=2;i<MAXN;i++)
// 		log_table[i]=log_table[i>>1]+1;
// }
// void build_st(int arr[],int n){
// 	build_log_table();
// 	for(int i=1;i<=n;i++)
// 		st[i][0]=arr[i];
// 	for(int j=1;(1<<j)<=n;j++)
// 		for(int i=1;i+(1<<j)-1<=n;i++)
//             st[i][j]=st[i][j-1]&st[i+(1<<(j-1))][j-1];
//             //st[i][j]=st[i][j-1]|st[i+(1<<(j-1))][j-1];
// }
// int query(int l,int r){
// 	int k=log_table[r-l+1];
// 	return st[l][k]&st[r-(1<<k)+1][k];
//     //return st[l][k]|st[r-(1<<k)+1][k];
// }
// int main(){
// 	int n,q;
// 	cin>>n>>q;
// 	int arr[n+1];
// 	for(int i=1;i<=n;++i)
// 		cin>>arr[i];
// 	build_st(arr,n);
// 	while(q--){
// 		int l,r;
// 		cin>>l>>r;
// 		cout<<query(l,r)<<endl;
// 	}
// 	return 0;
// }


