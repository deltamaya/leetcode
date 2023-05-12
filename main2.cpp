#include <bits/stdc++.h>
using namespace std;

int change(int amount, vector<int>& coins) {
	vector<int>dp(amount+1,0);
	dp[0]=1;
	for(auto e:coins){
		for(int i=e;i<=amount;++i){
			dp[i]+=dp[i-e];
		}
	}
	return dp.back();
}
int combinationSum4(vector<int>& nums, int target) {
	vector<int>dp(target+1,0);
	dp[0]=1;
	for(int i=1;i<=target;++i){
		for(auto e:nums)
			if(i-e>=0 && dp[i] < INT_MAX - dp[i - e])dp[i]+=dp[i-e];
	}
	return dp.back();
}
//int coinChange(vector<int>& coins, int amount) {
//	if(!amount)return 0;
//	vector<int>dp(amount+1,INT_MAX);
//	dp[0]=0;
//	for(auto coin:coins){
//		for(int i=coin;i<=amount;++i){
//			if(dp[i-coin]!=INT_MAX)dp[i]=min(dp[i],dp[i-coin]+1);
//		}
//	}
//	if(dp.back()==INT_MAX)return -1;
//	return dp.back();
//}
int numSquares(int n) {
	vector<int>dp(n+1,INT_MAX);
	dp[0]=0;
	for(int i=1;i*i<=n;++i){
		for(int j=i*i;j<=n;++j){
			dp[j]=min(dp[j],dp[j-i*i]+1);
		}
	}
	return dp.back();
}
bool wordBreak(string s, vector<string>& wordDict) {
	vector<bool>dp(s.size()+1,false);
	dp[0]=true;
	for(int i=1;i<=s.size();++i){
		for(auto& word:wordDict){
			if(i>=word.size()
			&&word==s.substr(i-word.size(),word.size())){
				dp[i]=dp[i]||dp[i-word.size()];
			}
		}
	}
	return dp.back();
}
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//int rob(vector<int>& nums) {
//	if(nums.size()==1)return nums[0];
////	vector<int>dp(nums.size()+1,0);
//	int dp[101]={0};
//	dp[1]=nums[0];dp[2]=nums[1];
//	for(int i=3;i<=nums.size();++i){
//		dp[i]=max(dp[i-2],dp[i-3])+nums[i-1];
//	}
//	return max(dp[nums.size()],dp[nums.size()-1]);
//}
//int rob(vector<int>& nums) {
//	if(nums.size()==1)return nums[0];
//	if(nums.size()==2)return max(nums[0],nums[1]);
//	vector<int>dp(nums.size(),0);
//	dp[1]=nums[0];dp[2]=nums[1];
//	for(int i=3;i<nums.size();++i){
//		dp[i]=max(dp[i-2],dp[i-3])+nums[i-1];
//	}
//	int ret=max(dp.back(),dp[dp.size()-2]);
//	dp[1]=nums[1],dp[2]=nums[2];
//	for(int i=3;i<nums.size();++i){
//		dp[i]=max(dp[i-2],dp[i-3])+nums[i];
//	}
//	return max({ret,dp.back(),dp[dp.size()-2]});
//}

//vector<vector<int>> rec(TreeNode*root){
//	vector<vector<int>>ret(2,vector<int>(2));
//	if(!root->left&&!root->right){
//		ret[0][0]=0;ret[0][1]=root->val;
//		ret[1][0]=ret[1][1]=0;
//	}else if(!root->left&&root->right){
//		auto tmp=rec(root->right);
//		ret[0][0]=max(tmp[0][1],tmp[1][1]);
//		ret[0][1]=max(tmp[0][0],tmp[1][0])+root->val;
//		ret[1]=tmp[0];
//	}else if(root->left&&!root->right){
//		auto tmp=rec(root->left);
//		ret[0]=tmp[1];
//		ret[1]=tmp[0]+root->val;
//	}else{
//		auto l=rec(root->left);
//		auto r=rec(root->right);
//		ret[0]=l[1]+r[1];
//		ret[1]=l[0]+r[0]+root->val;
//	}
//	return ret;
//}
//int rob(TreeNode* root) {
//	auto ret=rec(root);
//	return max(ret[0],ret[1]);
//}
int lengthOfLIS(vector<int>& nums) {
	int len=1;
	int end=0;
	vector<int>inc(nums.size());
	inc[0]=nums[0];
	for(int i=1;i<nums.size();++i){
		if(nums[i]>inc[end]){
			inc[++end]=nums[i];
			++len;
		}else{
			end=lower_bound(inc.begin(),inc.begin()+end+1,nums[i])-inc.begin();
			inc[end]=nums[i];
		}
	}
	return len;
}
int main(){
	vector<int>tmp{0,1,0,3,2,3};
	cout<<lengthOfLIS(tmp)<<endl;
	return 0;
}