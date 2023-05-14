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


int lengthOfLIS(vector<int>& nums) {
	vector<int>tmp;
	for(auto val:nums){
		auto iter= lower_bound(tmp.begin(),tmp.end(),val);
		if(iter==tmp.end()){
			tmp.push_back(val);
		}else{
			*iter=val;
		}
	}
	return tmp.size();
}
vector<int> rec_tr(TreeNode*root){
	vector<int>ret(2,0);
	if(!root->left&&!root->right){
		ret[1]=root->val;
	}else if(root->left&&!root->right){
		auto next=rec_tr(root->left);
		ret[1]=next[0]+root->val;
		ret[0]=max(next[0],next[1]);
	}else if(!root->left&&root->right){
		auto next=rec_tr(root->right);
		ret[1]=next[0]+root->val;
		ret[0]=max(next[0],next[1]);
	}else{
		auto l=rec_tr(root->left);
		auto r=rec_tr(root->right);
		ret[1]=l[0]+r[0]+root->val;
		ret[0]=max({l[0]+r[0],l[0]+r[1],l[1]+r[0],l[1]+r[1]});
	}
	return ret;
}
int rob(TreeNode* root) {
	auto ret=rec_tr(root);
	return max(ret[0],ret[1]);
}

ostream& operator<<(ostream&os ,const vector<int>&v){
	for(auto e:v){
		//os<<e<<' ';
		printf("%3d ",e);
	}
	os<<endl;
	return os;
}
ostream& operator<<(ostream& os,const vector<vector<int>>&m){
	for(auto e:m){
		os<<e;
	}
	cout<<endl;
	return os;
}
//int maxProfit(vector<int>& prices) {
//	if(prices.size()==1)return 0;
//	vector<int>dp(prices.size());
//	dp[0]=dp[1]=prices[0];
//	int ret=0;
//	for(int i=1;i<prices.size();++i){
//		ret=max(prices[i]-dp[i-1],ret);
//		dp[i]=min(dp[i-1],prices[i]);
//	}
//	return ret;
//}


//int maxProfit(vector<int>& prices) {
//	int buy1,buy2,sell1,sell2;
//	buy1=-prices[0];sell1=0;
//	buy2=-prices[0];sell2=0;
//	for(int i=1;i<prices.size();++i){
//		buy1=max(buy1,-prices[i]);
//		sell1=max(sell1,buy1+prices[i]);
//		buy2=max(buy2,sell1-prices[i]);
//		sell2=max(buy2+prices[i],sell2);
//	}
//	return sell2;
//}


//int maxProfit(int k, vector<int>& prices) {
//	vector<vector<int>>dp(2*k,vector<int>(prices.size(),0));
//	for(int i=0;i<2*k;++i){
//		if(i%2==0){
//			dp[i][0]=-prices[0];
//		}
//	}
//	for(int i=1;i<prices.size();++i){
//		dp[0][i]=max(dp[0][i-1],-prices[i]);
//	}
//	for(int i=1;i<prices.size();++i){
//		for(int j=1;j<2*k;++j){
//			if(j%2==0){
//				dp[j][i]=max(dp[j-1][i]-prices[i],dp[j][i-1]);
//			}else{
//				dp[j][i]=max(dp[j][i-1],dp[j-1][i]+prices[i]);
//			}
//		}
//		//cout<<dp;
//	}
//	return dp.back().back();
//}

//int maxProfit(vector<int>& prices) {
//	int n=prices.size()-1;
//	vector<vector<int>>dp(3,vector<int>(prices.size(),0));
//	dp[0][0]=-prices[0];
//	//dp[0][i] having stock
//	//dp[1][i] not having stock and in freeze
//	//dp[2][i] not having stock and not in freeze
//	for(int i=1;i<prices.size();++i){
//		dp[0][i]=max(dp[2][i-1]-prices[i],dp[0][i-1]);
//		dp[1][i]=max(dp[0][i-1]+prices[i],dp[1][i-1]);
//		dp[2][i]=max(dp[1][i-1],dp[2][i-1]);
//	}cout<<dp<<endl;
//	return max({dp[0][n],dp[1][n],dp[2][n]});
//}

int maxProfit(vector<int>& prices, int fee) {
	vector<vector<int>>dp(2,vector<int>(prices.size(),0));
	dp[0][0]=-prices[0];
	for(int i=1;i<prices.size();++i){
		dp[0][i]=max(dp[0][i-1],dp[1][i-1]-prices[i]);
		dp[1][i]=max(dp[1][i-1],dp[0][i-1]+prices[i]-fee);
	}
//	cout<<dp;
	return dp.back().back();
}
int main(){
	vector<int>tmp{1,3,7,5,10,3};
	cout<<maxProfit(tmp,3)<<endl;
	return 0;
}