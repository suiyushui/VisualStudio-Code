#include<iostream>
#include<vector>
using namespace std;
inline int lowbit(int x){
	return x&-x;
}
void initialize(const vector<int>& nums, vector<int>& tree) {
	tree.assign(nums.size() + 1, 0); // 初始化树状数组
	for (size_t i = 1; i <= nums.size(); i++) {
		tree[i] += nums[i - 1]; // 当前位置的值加上原数组的值
		size_t parent = i + lowbit(i); // 找到当前节点的父节点
		if (parent <= nums.size()) {
			tree[parent] += tree[i]; // 累加子节点的值到父节点
		}
	}
}
void update(int index,int delta,vector<int>& tree){
	while(index<tree.size()){
		tree[index]+=delta;
		index+=lowbit(index);
	}
}
int query(int x,vector<int>& tree){
	int sum=0;
	while(x>0){
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}
int query(int L,int R,vector<int>& tree){
	int sum=0;
	sum=query(R,tree)-query(L-1,tree);
	return sum;
}
int main(){
	vector<int>nums={1,2,3,4,5,6,7,8};
	vector<int> tree(nums.size()+1,0);
	for(int i=1;i <= nums.size(); i++){
		update(i,nums[i-1],tree);
	}
	cout <<query(1,3,tree) << endl;
	return 0;
}