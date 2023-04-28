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
int main(){
	auto ret= letterCombinations ("23");
}