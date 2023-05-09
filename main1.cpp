#include <bits/stdc++.h>
#define private public
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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

bool check_queen(vector<string>&board,int row,int col){
	for(auto & i : board){
		if(i[col]=='Q')return false;
	}
	int i=row,j=col;
	while(i>0&&j>0){
		--i;--j;
	}
	while(i>=0&&i<board.size()&&j>=0&&j<board[0].size()){
		if(board[i][j]=='Q')return false;
		++i;++j;
	}
	i=row;j=col;
	while(i>0&&j<board[0].size()-1){
		--i;++j;
	}
	while(i>=0&&i<board.size()&&j>=0&&j<board[0].size()){
		if(board[i][j]=='Q')return false;
		++i;--j;
	}
	return true;
}
void NQueens(vector<vector<string>>&ret,vector<string>&board,int line){
	if(line==board.size()){
		ret.push_back (board);
		return;
	}
	for(int i=0;i<board[line].size();++i){
		if(!check_queen(board,line,i))continue;
		board[line][i]='Q';
		NQueens (ret,board,line+1);
		board[line][i]='.';
	}
}
vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>>ret;
	vector<string>board(n,string(n,'.'));
	NQueens (ret,board,0);
	return ret;
}


bool check_ok(vector<vector<char>>&board,int row,int col,int value){
	for(int i=0;i<board.size();++i){
		if(board[i][col]=='0'+value)return false;
	}
	for(int j=0;j<board[0].size();++j){
		if(board[row][j]=='0'+value)return false;
	}
	int left=col/3,top=row/3;
	for(int i=0;i<=2;++i){
		for(int j=0;j<=2;++j){
			if(board[top*3+i][left*3+j]=='0'+value)return false;
		}
	}
	return true;
}
void Sudoku(vector<vector<char>>&ret,vector<vector<char>>&board,int row,int col){
	int next_row=row,next_col=col;
	for(int i=1;i<=9;++i){
		if( !check_ok (board,row,col,i))continue;
		board[row][col]='0'+i;
		while(next_row<board.size()&&next_col<board[0].size()&&board[next_row][next_col]!='.'){
			next_col++;
			if(next_col>=board[0].size()){
				next_row++;
				next_col-=board[0].size();
			}
		}
		if(next_row==board.size()){
			ret=board;
			return;
		}
		Sudoku(ret,board,next_row,next_col);
		board[row][col]='.';
	}
}
void solveSudoku(vector<vector<char>>& board) {
	auto tmp=board;
	int row=0,col=0;
	while(row<board.size()&&col<board[0].size()&&board[row][col]!='.'){
		col++;
		if(col>=board[0].size()){
			row++;
			col-=board[0].size();
		}
	}
	Sudoku (board,tmp,row,col);
}
//int main(){
//	vector<vector<char>>board(9,vector<char>(9,'.'));
//	solveSudoku (board);
//}
long long solve(int n){
	if(n<2)return 1;
	long long  pre=0,cur=1,next=0;
	for(int i=0;i<n;++i){
		next=pre+cur;
		pre=cur;
		cur=next;
	}
	return next;
}
string toHex(int num) {
	if(!num)return "";
	string ret;
	unsigned int u_num=num;
	while(u_num){
		int tmp=u_num%16;
		if(tmp<10){
			ret.push_back ('0'+tmp);
		}else{
			ret.push_back ('a'+tmp-10);
		}
		u_num/=16;
	}
	reverse(ret.begin (),ret.end());
	return ret;

}
int findContentChildren(vector<int>& g, vector<int>& s) {
	sort(s.rbegin(),s.rend());
	sort(g.rbegin(),g.rend());
	int cnt=0;
	int i=0;
	for(auto cookie:s){
		while(i<g.size()){
			if(cookie>=g[i++]){
				++cnt;
				break;
			}
		}
	}
	return cnt;
}
int wiggleMaxLength(vector<int>& nums) {
	if(nums.size()<2)return nums.size();
	for(int i=1;i<nums.size();++i){
		nums[i-1]-=nums[i];
	}
	nums.pop_back();
	int begin=0;
	for(begin=0;begin<nums.size();++begin){
		if(nums[begin]!=0){
			break;
		}
	}
	if(begin==nums.size())return 1;
	bool negative=nums[begin]<0;
	int cnt=1;
	for(int i=begin+1;i<nums.size();++i){
		if(negative){
			if(nums[i]>0){
				negative=false;
				++cnt;
			}else{
				continue;
			}
		}else{
			if(nums[i]<0){
				negative=true;
				++cnt;
			}else{
				continue;
			}
		}
	}
	return ++cnt;
	
}
int maxSubArray(vector<int>& nums) {
	int ret=nums[0];
	int sum=0;
	for(int i=0;i<nums.size();++i){
		sum+=nums[i];
		if(sum<0){
			sum=0;
		}else{
			ret=max(ret,sum);
		}
		ret=max(ret,nums[i]);
	}
	return ret;
}
int maxProfit(vector<int>& prices) {
	int ret=0;
	for(int i=1;i<prices.size();++i){
		if(prices[i]-prices[i-1]>0){
			ret+=prices[i]-prices[i-1];
		}
	}
	return ret;
}
bool canJump(vector<int>& nums) {
	int cover=0;
	for(int i=0;i<=cover;++i){
		cover=max(cover,i+nums[i]);
		if(cover>=nums.size())return true;
	}
	return false;
}
int jump(vector<int>& nums) {
	if(nums.size()<2)return nums.size()-1;
	int cnt=0;
	int i=0;
	while(i<nums.size()){
		int j=1;
		int maxi=i+j;
		if(i+nums[i]>=nums.size()-1){
			++cnt;
			break;
		}
		for(j=1;i+j<nums.size()&&j<=nums[i];++j){
			if(i+j+nums[i+j]>=maxi+nums[maxi])maxi=i+j;
		}
		i=maxi;
		++cnt;
	}
	return cnt;
}
int largestSumAfterKNegations(vector<int>& nums, int k) {
	sort(nums.begin(),nums.end());
	for(int i=0;k&&i<nums.size();++i){
		if(nums[i]<0){
			nums[i]=-nums[i];
			--k;
		}
	}
	
	if(k) {
		k%=2;
		sort(nums.begin(),nums.end());
		for(int i=0;i<k;++i){
			nums[i]=-nums[i];
		}
	}
	int sum=0;
	for(auto &e:nums){
		sum+=e;
	}
	return sum;
}
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	if( accumulate (gas.begin(),gas.end(),0)< accumulate (cost.begin(),cost.end(),0))return -1;
	int begin=0;
	int has=0;
	int cur=0;
	for(begin=0;begin<gas.size();++begin){
		has=gas[begin];
		cur=begin;
		while(has>0&&has>=cost[cur]){
			has-=cost[cur];
			cur++;
			if(cur>=gas.size())cur-=gas.size();
			if(cur==begin)return begin;
			has+=gas[cur];
		}
		begin=cur;
	}
	return -1;
}
int candy(vector<int>& ratings) {
	vector<int>candies(ratings.size(),1);
	for(int i=1;i<candies.size();++i){
		if(ratings[i]> ratings[i-1]){
			candies[i]=candies[i-1]+1;
		}
	}
	for(int i=candies.size()-2;i>=0;--i){
		if(ratings[i]>ratings[i+1]){
			candies[i]=max(candies[i+1]+1,candies[i]);
		}
	}
	return accumulate (candies.begin(),candies.end(),0);
}
bool lemonadeChange(vector<int>& bills) {
//	unordered_map<int ,int>change;
int ten=0,five=0;
	for(auto e:bills){
		if(e==5){
			++five;
		}else if(e==10){
			if(five--){
				ten++;
			}else return false;
		}else{
			if(ten>0&&five>0){
				ten--;five--;
			}else if(five>=3){
				five-=3;
			}else{
				return false;
			}
			
		}
	}
	return true;
}
//vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//	sort(people.begin(),people.end(),[&](const vector<int>&a,const vector<int>&b){return a[0]>b[0]||(a[0]==b[0]&&a[1]<b[1]);});
//	vector<vector<int>> ans;
//	for (const vector<int>& person: people) {
//		ans.insert(ans.begin() + person[1], person);
//	}
//	return ans;
//}
int findMinArrowShots(vector<vector<int>>& points) {
	int cnt=1;
	sort(points.begin(),points.end(),[&](const vector<int>&a,const vector<int>&b){return a[0]<b[0];});
	int end;
	end=points[0][1];
	for(int i=0;i<points.size();++i){
		if(points[i][0]>end){
			++cnt;
			end=points[i][1];
		}
		end=min(end,points[i][1]);
	}
	return cnt;
	
}
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	sort(intervals.begin(),intervals.end());
	int begin=intervals[0][0],end=intervals[0][1];
	int cnt=0;
	int i=1;
	while(i<intervals.size()){
		while(i<intervals.size()&&intervals[i][0]<end){
			++cnt;
			end=min(end,intervals[i][1]);
			++i;
		}
		if(i<intervals.size()){
			begin=intervals[i][0];
			end=intervals[i][1];
		}
		++i;
	}
	return cnt;
}
string convert(const string&s){
	string ret;
	for(auto e:s){
		if(e=='['){
			ret.push_back ('{');
		}else if(e==']'){
			ret.push_back ('}');
		}else{
			ret.push_back (e);
		}
	}
	cout<<ret;
	return ret;
}

vector<int> partitionLabels(string s) {
	vector<pair<int,int>>be(26,{-1,-1});
	for(int i=0;i<s.size();++i){
		if(be[s[i]-'a'].first==-1){
			be[s[i]-'a'].first=i;
		}
		be[s[i]-'a'].second=i;
	}
	vector<int>ret;
	sort(be.begin(),be.end());
	int begin,end;
	int i=0;
	while(be[i].first==-1)++i;
	begin=be[i].first;end=be[i].second;
	while(i<26){
		if(be[i].first>end){
			ret.push_back (end-begin+1);
			begin=be[i].first;
		}
		end=max(end,be[i].second);
		++i;
	}
	ret.push_back (end-begin+1);
	return ret;
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
	sort(intervals.begin(),intervals.end());
	int begin=intervals[0][0],end=intervals[0][1];
	int i=0;
	vector<vector<int>>ret;
	while(i<intervals.size()){
		if(intervals[i][0]>end){
			ret.push_back ({begin,end});
			begin=intervals[i][0];
		}
		end=max(end,intervals[i][1]);
		++i;
	}
	ret.push_back ({begin, end});
	return ret;
}
int monotoneIncreasingDigits(int n) {
	string raw=to_string(n);
	bool ok=true;
	int i=0;
	for(i=0;i<raw.size()-1;++i){
		if(raw[i]>raw[i+1]){
			ok=false;
			break;
		}
	}
	if(ok)return n;
	while(i>0&&raw[i-1]==raw[i]){
		--i;
	}
	--raw[i];
	++i;
	while(i<raw.size()){
		raw[i++]='9';
	}
	if(raw[0]=='0')raw.erase(0,1);
	return stoi(raw);
}
void rec_968(TreeNode*root,int&cnt){
	if(!root||(!root->left&&!root->right))return;
	rec_968 (root->left,cnt);
	rec_968 (root->right,cnt);
	
	if(root->left&&root->left->val==1&&root->right&&root->right->val==1){
		return;
	}
	if((root->left&&root->left->val==2)||(root->right&&root->right->val==2)){
		root->val=1;
	}
	if((root->left&&root->left->val==0)||(root->right&&root->right->val==0)){
		root->val=2;
		++cnt;
	}
	
}
int minCameraCover(TreeNode* root) {
	if(!root->left&&!root->right)return 1;
	int cnt=0;
	rec_968 (root,cnt);
	if(root->val==0)++cnt;
	return cnt;
}
int minCostClimbingStairs(vector<int>& cost) {
	vector<int>dp(cost.size()+1,0);
	for(int i=2;i<dp.size();++i){
		dp[i]=min(dp[i-2]+cost[i-2],dp[i-1]+cost[i-1]);
	}
	return dp.back();
}
int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m,vector<int>(n,0));
	for(int i=0;i<m;++i){
		dp[i][0]=1;
	}
	for(int i=0;i<n;++i){
		dp[0][i]=1;
	}
	for(int i=1;i<m;++i){
		for(int j=1;j<n;++j){
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	return dp.back().back();
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	if(obstacleGrid.back().back()||obstacleGrid[0][0])return 0;
	for(int i=0;i<obstacleGrid.size();++i){
		for(int j=0;j<obstacleGrid[0].size();++j){
			if(obstacleGrid[i][j]==1){
				obstacleGrid[i][j]=-1;
			}
		}
	}
	auto &dp=obstacleGrid;
	dp[0][0]=1;
	for(int i=1;i<dp.size();++i){
		if(dp[i][0]==-1)continue;
		if(dp[i-1][0]!=-1){
			dp[i][0]=1;
		}else{
			dp[i][0]=-1;
		}
	}
	for(int j=1;j<dp[0].size();++j){
		if(dp[0][j]==-1)continue;
		if(dp[0][j-1]!=-1){
			dp[0][j]=1;
		}else{
			dp[0][j]=-1;
		}
	}
	for(int i=1;i<dp.size();++i){
		for(int j=1;j<dp[0].size();++j){
			if(dp[i][j]==-1)continue;
			int value=0;
			if(dp[i-1][j]!=-1)value+=dp[i-1][j];
			if(dp[i][j-1]!=-1)value+=dp[i][j-1];
			dp[i][j]=value;
		}
	}
	return max(dp.back().back(),0);
}
//void BackTracking(int k,int n,int& sum,int& mult,int&ret){
//	if(k>=n)return;
//	if(sum==n&&k>=2){
//		ret=max(mult,ret);
//	}
//	if(sum>=n)return;
//	for(int i=1;i<n;++i){
//		sum+=i;
//		mult*=i;
//		BackTracking(k+1,n,sum,mult,ret);
//		sum-=i;
//		mult/=i;
//	}
//}
//int integerBreak(int n) {
//	if(n<3)return 1;
//	int mult=1,ret=0,sum=0;
//	BackTracking(0,n,sum,mult,ret);
//	return ret;
//}
//int integerBreak(int n) {
//	if(n<3)return 1;
//	if(n==3)return 2;
//	int mod=n%3;
//	int k=n/3;
//	if(mod==1){
//		return pow(3,k-1)*4;
//	}else if(mod==2){
//		return pow(3,k)*mod;
//	}else{
//		return pow(3,k);
//	}
//}


int integerBreak(int n) {
	vector<int>dp(n+3);
	dp[0]=dp[1]=dp[2]=1;
	dp[3]=2;
	for(int i=4;i<=n;++i){
		for(int k=2;k<i;++k){
			int mod=n%k;
			int div=n/k;
			if(mod==1){
				dp[i]=max(dp[i],int(pow(k,div-1)*(k+1)));
			}else if(mod==0){
				dp[i]=max(dp[i],int(pow(k,div)));
			}else{
				dp[i]=max(dp[i],int(pow(k,div)*mod));
			}
		}
	}
	dp.push_back (1);
	return dp[n];
}
//void BackTracking_416(vector<int>&nums,int target,int& sum,int begin,bool& ret){
//	if(ret)return;
//	for(int i=begin;i>=0;--i){
//		sum+=nums[i];
//		if(sum==target){
//			ret=true;
//			return;
//		}else if(sum>target){
//			sum-=nums[i];
//			continue;
//		}
//		BackTracking_416 (nums,target,sum,i-1,ret);
//		sum-=nums[i];
//	}
//}
//bool canPartition(vector<int>& nums) {
//	auto total=accumulate(nums.begin(), nums.end(), 0);
//	if( total % 2 == 1)return false;
//	vector<int>dp(nums.size());
//	sort(nums.begin(),nums.end());
//	int sum=0;
//	bool ret=false;
//	BackTracking_416 (nums,total/2,sum,nums.size()-1,ret);
//	return ret;
//}
//


bool canPartition(vector<int>& nums) {
	int total= accumulate(nums.begin(),nums.end(),0);
	if(total%2)return false;
	vector<int>dp(total/2+1,0);
	for(auto e:nums){
		for( int j= dp.size() - 1; j >=e; --j){
			dp[j]=max(dp[j - e] + e, dp[j]);
			if(dp[j]==total/2)return true;
		}
	}
	return false;
}

ostream& operator<<(ostream&os ,const vector<int>&v){
	for(auto e:v){
		os<<e<<' ';
	}
	os<<endl;
	return os;
}
int lastStoneWeightII(vector<int>& stones) {
	int sum=accumulate(stones.begin(),stones.end(),0);
	vector<int>dp(sum/2+2,0);
	int total=sum;
	sum=0;
	for(auto stone:stones){
		for(int j=dp.size()-1;j>stone;--j){
			dp[j]=max(dp[j-stone]+stone,dp[j]);
			sum=max(dp[j],sum);
		}
	}
	return total-sum-sum;
}
int findTargetSumWays(vector<int>& nums, int target) {
	int cnt=0;
	int total= accumulate(nums.begin(),nums.end(),0);
	if(total<target||(total-target)%2)return 0;
	vector<int>dp((total-target)/2+1,0);
	dp[0]=1;
	for(auto e:nums){
		for(int j=dp.size()-1;j>=e;--j){
			dp[j]+=dp[j-e];
		}
		cout<<dp;
	}
	return dp.back();
}
int findMaxForm(vector<string>& strs, int m, int n) {
	vector<pair<int,int>>nums;
	for(auto &s:strs){
		int m=0,n=0;
		for(auto c:s){
			if(c=='0')++m;
			if(c=='1')++n;
		}
		nums.push_back({m,n});
	}
	vector<vector<int>>dp(m+1,vector<int>(n+1,0));
	for(auto e:nums){
		for(int i=m;i>=0;--i){
			for(int j=n;j>=0;--j){
				if(i-e.first<0||j-e.second<0){
					continue;
				}
				dp[i][j]=max(dp[i][j],dp[i-e.first][j-e.second]+1);
			}
		}
//		for(auto &n:dp){
//			cout<<n;
//		}
//		cout<<"---------------------------------------\n";
	}
	
	return dp.back().back();
}
int main(){
	//convert("[\"10\",\"0001\",\"111001\",\"1\",\"0\"]");
	vector<string>nums={"10","0001","111001","1","0"};
	cout<< findMaxForm(nums,5,3);
}