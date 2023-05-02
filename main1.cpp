#include <bits/stdc++.h>
using namespace std;
void backtracking_77(vector<vector<int>>&ret,vector<int>&path,int begin,int end,int k){
	if(path.size()==k){
		ret.push_back (path);
		return;
	}
	for(int i=begin;i<=end;++i){
		if(path.size()+end-i+1<k)return;
		path.push_back (i);
		backtracking_77 (ret,path,i+1,end,k);
		path.pop_back();
	}
	
}
vector<vector<int>> combine(int n, int k) {
	vector<vector<int>>ret;
	vector<int>path;
	backtracking_77 (ret,path,1,n,k);
	return ret;
}
void backtracking_216(vector<vector<int>>&ret,vector<int>&path,int sum,int level,int k,int n){
	if(sum==n&&path.size()==k){
		ret.push_back (path);
		return;
	}
	if(sum>=n)return;
	for(int i=level;i<=9;++i){
		if(sum+45-(((9-k-path.size())*(9-k-path.size()+1))/2)<n)return;
		path.push_back (i);
		backtracking_216 (ret,path,sum+i,i+1,k,n);
		path.pop_back();
	}
}
vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>>ret;
	vector<int>path;
	backtracking_216 (ret,path,0,1,k,n);
	return ret;
}
void backtracking_17(vector<string>&ret,string&path,const string& digits,int idx,const vector<string>&board){
	if(idx==digits.size()){
		ret.push_back (path);
		return;
	}
	for(auto ch:board[digits[idx]-'0']){
		path.push_back (ch);
		backtracking_17 (ret,path,digits,idx+1,board);
		path.pop_back();
	}
}
vector<string> letterCombinations(string digits) {
	vector<string>board={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	vector<string>ret;
	string path;
	backtracking_17(ret,path,digits,0,board);
	return ret;
}
void backtracking_39(vector<vector<int>>&ret,vector<int>&path,vector<int>&candidate,int sum,int target,int level){
	if(sum==target){
		ret.push_back (path);
		return;
	}
	if(sum>target)return;
	for(int i=level;i<candidate.size();++i){
		if(candidate[i]+sum>target)return;
		path.push_back (candidate[i]);
		backtracking_39 (ret,path,candidate,sum+candidate[i],target,i);
		path.pop_back();
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(),candidates.end());
	vector<vector<int>>ret;
	vector<int>path;
	backtracking_39 (ret,path,candidates,0,target,0);
	return ret;
}
void backtracking_40(vector<vector<int>>&ret,vector<int>&path,vector<int>&candidate,int sum,int target,int level){
	if(sum>target)return;
	if(sum==target){
		ret.push_back (path);
		return;
	}
	for(int i=level;i<candidate.size();){
		if(sum+candidate[i]>target)return;
		path.push_back (candidate[i]);
		backtracking_40 (ret,path,candidate,sum+candidate[i],target,i+1);
		int tmp=path.back();
		path.pop_back();
		while(i<candidate.size()&&candidate[i]==tmp)++i;
		
	}
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	sort(candidates.begin(),candidates.end());
	vector<vector<int>>ret;
	vector<int>path;
	backtracking_40 (ret,path,candidates,0,target,0);
	return ret;
}
bool IsPalindromeString(const string& str){
	int l=0,r=str.size()-1;
	while(l<=r){
		if(str[l]==str[r]){
			++l;--r;
		}else{
			return false;
		}
	}
	return true;
}
void BackTracking_131(vector<vector<string>>&ret,vector<string>&path,string s,int begin,int end){
	if(begin>end){
		ret.push_back (path);
		return;
	}
	for(int i=begin;i<=end;++i){
		if( IsPalindromeString (s.substr (begin,i-begin+1))){
			path.push_back (s.substr (begin,i-begin+1));
			BackTracking_131 (ret,path,s,i+1,end);
			path.pop_back();
		}
	}
}
vector<vector<string>> partition(string s) {
	vector<vector<string>>ret;
	vector<string>path;
	BackTracking_131 (ret,path,s,0,s.size()-1);
	return ret;
}
void BackTracking_93(vector<string>&ret,vector<string>&path,const string& s,int begin,int end){
	if(path.size()>4)return;
	if(begin>end&&path.size()==4){
		string tmp;
		for(auto& e:path){
			tmp+=(e+'.');
		}
		tmp.pop_back();
		ret.push_back (tmp);
		return;
	}
	for(int i=begin;i<=std::min(begin+2,int(s.size()-1));++i){
		if(path.size()==4)break;
		if(s.size()-i>3*(4-path.size()))continue;
		if(s[begin]=='0'&&i!=begin)break;
		if(stoi(s.substr (begin,i-begin+1))>255)continue;
		path.push_back (s.substr (begin,i-begin+1));
		BackTracking_93 (ret,path,s,i+1,end);
		path.pop_back();
	}
}
vector<string> restoreIpAddresses(string s) {
	vector<string>ret;
	vector<string>path;
	BackTracking_93 (ret,path,s,0,s.size()-1);
	return ret;
}
void BackTracking_78(vector<vector<int>>&ret,vector<int>&path,const vector<int>&nums,int begin){
	ret.push_back (path);
	if(path.size()==nums.size()){
		return;
	}
	for(int i=begin;i<nums.size();++i){
		path.push_back (nums[i]);
		BackTracking_78 (ret,path,nums,i+1);
		path.pop_back();
	}
}
vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>>ret;
	vector<int>path;
	BackTracking_78(ret,path,nums,0);
	return ret;
}
void BackTracking_90(vector<vector<int>>&ret,vector<int>&path,const vector<int>&nums,int begin){
	ret.push_back (path);
	if(path.size()==nums.size()){
		return;
	}
	for(int i=begin;i<nums.size();){
		path.push_back (nums[i]);
		BackTracking_90 (ret,path,nums,i+1);
		while(i<nums.size()&&nums[i]==path.back())++i;
		path.pop_back();
		
	}
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	vector<vector<int>>ret;
	vector<int>path;
	BackTracking_90(ret,path,nums,0);
	return ret;
}
struct HashFunc_t {
	size_t operator() (const vector<int> &key) const {
		std::hash<int> hasher;
		size_t seed = 0;
		for ( int i: key ) {
			seed ^= hasher (i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}
};
//void BackTracking_491(vector<vector<int>>&ret,vector<int>&path,const vector<int>&nums,int begin,unordered_map<vector<int>,bool, HashFunc_t>&mp){
//	if(path.size()>=2&&!mp[path]) { ret.push_back (path); mp[path]=true;}
//	for(int i=begin;i<nums.size();++i){
//		if(!path.empty()&&nums[i]<path.back())continue;
//		path.push_back (nums[i]);
//		BackTracking_491(ret,path,nums,i+1,mp);
//
//		path.pop_back();
//	}
//}
//
//vector<vector<int>> findSubsequences(vector<int>& nums) {
//	vector<vector<int>>ret;
//	vector<int>path;
//	unordered_map<vector<int>,bool,HashFunc_t>mp;
//	BackTracking_491 (ret,path,nums,0,mp);
//	return ret;
//}

void BackTracking_491(vector<vector<int>>&ret,vector<int>&path,const vector<int>&nums,int begin){
	if(path.size()>=2)ret.push_back (path);
	unordered_set<int>s;
	for(int i=begin;i<nums.size();++i){
		if(!path.empty()&&nums[i]<path.back()||s.find(nums[i])!=s.end())continue;
		path.push_back (nums[i]);
		s.insert (nums[i]);
		BackTracking_491(ret,path,nums,i+1);
		path.pop_back();
	}
}
vector<vector<int>> findSubsequences(vector<int>& nums) {
	vector<vector<int>>ret;
	vector<int>path;
	BackTracking_491 (ret,path,nums,0);
	return ret;
}
void BackTracking_46(vector<vector<int>>&ret,vector<int>&path,vector<int>&nums,vector<bool>&used){
	if(path.size()==nums.size()){
		ret.push_back (path);
		return;
	}
	for(int i=0;i<nums.size();++i){
		if(used[i])continue;
		path.push_back (nums[i]);
		used[i]=true;
		BackTracking_46 (ret,path,nums,used);
		path.pop_back();
		used[i]=false;
	}
	
}
vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>>ret;
	vector<int>path;
	vector<bool>used(nums.size(),false);
	BackTracking_46 (ret,path,nums,used);
	return ret;
}


//vector<vector<int>> permute(vector<int>& nums) {
//	sort(nums.begin(),nums.end());
//	vector<vector<int>>ret;
//	do{
//		ret.push_back(nums);
//	}while((next_permutation (nums.begin(),nums.end())));
//	return ret;
//}
void BackTracking_47(vector<vector<int>>&ret,vector<int>&path,vector<int>&nums,vector<bool>&used){
	if(path.size()==nums.size()){
		ret.push_back (path);
		return;
	}
	for(int i=0;i<nums.size();){
		while(i<nums.size()&&used[i])++i;
		if(i>=nums.size())return;
		path.push_back (nums[i]);
		used[i]=true;
		BackTracking_47 (ret,path,nums,used);
		used[i]=false;
		while(i<nums.size()&&path.back()==nums[i])++i;
		path.pop_back();
		
		
	}
	
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>>ret;
	vector<int>path;
	vector<bool>used(nums.size(),false);
	sort(nums.begin(),nums.end());
	BackTracking_47 (ret,path,nums,used);
	return ret;
}
int main(){
	auto ret= restoreIpAddresses ("25525511135");
	int a;
}