#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
string reverseWords(string s) {
	reverse(s.begin(),s.end());
	int fast,slow;fast=slow=0;
	while(fast<s.size()){
		while(fast<s.size()&&s[fast]==' '){
			++fast;
		}
		if(slow&&fast!=s.size())s[slow++]=' ';
		int tmp=slow;
		while(fast<s.size()&&s[fast]!=' ') {
			s[ slow++ ] = s[ fast++ ];
		}
		reverse(s.begin()+tmp,s.begin()+slow);
	}
	s.resize(slow);
	return s;
}
vector<int> twoSum(vector<int>& nums, int target) {
	std::unordered_map<int, int> m;
	for ( int i = 0; i < nums.size (); ++i ) {
		auto iter = m.find (target - nums[ i ]);
		if ( iter != m.end ()) {
			return {i, iter->second};
		}
		m.insert ({nums[ i ], i});
	}
	return {};
}
struct cmp{
	bool operator()(pair<int,int>a,pair<int,int>b){
		return a.second<b.second;
	}
};
vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int,int>m;
	for(auto e:nums)m[e]++;
	priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>s;
	for(auto iter=m.begin();iter!=m.end();++iter){
		s.push({iter->first,iter->second});
	}
	vector<int>ret;
	while(k--){
		ret.push_back (s.top().first);
		s.pop();
	}
	return ret;
	
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int row=0,col=matrix[0].size()-1;
	while(col>=0&&row<matrix.size()){
		if(matrix[row][col]>target){
			--col;
		}else if(matrix[row][col]<target){
			++row;
		}else{
			return true;
		}
	}
	return false;
}
string rec(const int times,string& s,int begin){
    string ret;
    for(int i=begin;i<s.size();++i){
        if(s[i]>='0'&&s[i]<='9'){
			string n;
			while(s[i]>='0'&&s[i]<='9'){
				n+=s[i];
				++i;
			}
            ret+=rec(stoi(n),s,i+1);
			int cnt=0;
			do{
				if(s[i]=='[')++cnt;
				if(s[i]==']')--cnt;
				if(cnt)++i;
			}while(cnt);
        }else if(s[i]==']'){
			string tmp;
			for(int j=0;j<times;++j){
				tmp+=ret;
			}
			return tmp;
		}else{
			ret+=s[i];
		}
    }
	return ret;
}
string decodeString(string s) {
    return  rec(1,s,0);
}
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int>ret(nums.size()),pre(nums.size()),last(nums.size());
	int m=1;
	for(int i=0;i<nums.size();++i){
		m*=nums[i];
		pre[i]=m;
	}
	m=1;
	for(int i=nums.size()-1;i>=0;--i){
		m*=nums[i];
		last[i]=m;
	}
	for(int i=1;i<nums.size()-1;++i){
		ret[i]=pre[i-1]*last[i+1];
	}
	ret[0]=last[1];ret[nums.size()-1]=pre[nums.size()-2];
	return ret;
}
int lengthOfLIS(vector<int>& nums) {
	vector<int>len;
	int ret;
	for(int i=0;i<nums.size();++i){
		int j=i;
		int maxlen=1;
		while(j>=0){
			if(nums[i]>nums[j]){
				maxlen=max(maxlen,len[j]+1);
				
			}
			ret=max(maxlen,ret);
			--j;
		}
		len.push_back (maxlen);
	}
	return ret;
}
int coinChange(vector<int>& coins, int amount) {
	vector<int>ret(amount+1);
	sort(coins.begin(),coins.end());
	for(auto& e:ret)e=INT_MAX;
	ret[0]=0;
	for(auto c:coins){
		ret[c]=1;
	}
	for(int i=1;i<=amount;++i){
		for(int j=0;j<coins.size();++j){
			if(i-coins[j]<=0)break;
			ret[i]=min(ret[i],ret[i-coins[j]]+1);
		}
	}
	return ret[amount];
}
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
	sort(people.begin(),people.end(),[](const vector<int>& x,const vector<int>&y){return x[0]>y[0]||x[0]==y[0]&&x[1]<y[1];});
	vector<vector<int>>ret;
	for(const auto&p:people){
		ret.insert (ret.begin()+p[1],p);
	}
	return ret;
}
#define MAdd(x,y) (((x)+(y))*10)
int FAdd(int x,int y){
	return (x+y)*10;
}
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
	unordered_map<int,int>sum_1_2,sum_3_4;
	for(auto e1:nums1){
		for(auto e2:nums2){
			sum_1_2[e1+e2]++;
		}
	}
	for(auto e3:nums3){
		for(auto e4:nums4){
			sum_3_4[e3+e4]++;
		}
	}
	int cnt=0;
	for(auto e1:sum_1_2){
		for(auto e2:sum_3_4){
			if(e1.first+e2.first==0)cnt+=(e1.second*e2.second);
		}
	}
	return cnt;
	
}
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>>ret;
	sort(nums.begin(),nums.end());
	int i,j,r,l;
	for(i=0;i<nums.size();++i){
		if(i&&nums[i]==nums[i-1])continue;
		for(j=i+1;j<nums.size();++j){
			if(j!=i+1&&nums[j]==nums[j-1])continue;
			l=j+1;r=nums.size()-1;
			if(l>=r)continue;
			if(target>=0&&nums[i]>target/4||nums[r]<target/4||nums[i]+nums[j]>target/2)continue;
			while(l<r){
				if(l!=j+1&&nums[l]==nums[l-1]){
					++l;
					continue;
				}
				if(r!=nums.size()-1&&nums[r]==nums[r+1]){
					--r;
					continue;
				}
				if(nums[l]+nums[r]<target/2){
					++l;
					continue;
				}
				int sum=int(((long long)nums[i]+nums[j]+nums[l]+nums[r])%INT_MAX);
				if(sum==target){
					ret.push_back ({nums[i],nums[j],nums[l],nums[r]});
					++l;--r;
				}else if(sum>target){
					--r;
				}else{
					++l;
				}
			}
		}
	}
	return ret;
}
ostream& operator<<(ostream&os,const vector<int>&v){
	for(auto e:v){
		os<<e<<' ';
	}
	os<<endl;
	return os;
}
int KMP(const string& str,const string& target){
	vector<int>next;
	for(int i=0;i<target.size();++i){
		int cnt=0;
		int len=1;
		int j=0;
		while(j+len<=i){
			if(target[j]==target[j+len]){
				++cnt;
				++j;
			}else{
				++len;
				cnt=0;
				j=0;
			}
		}
		next.push_back (cnt);
	}
	int i=0,f=0,begin=0;
	while(i<str.size()){
		if(str[i]!=target[f]){
			if(f)f=next[f-1];
			else{
				++i;
			}
			continue;
		}
		while(str[i]==target[f]){
			if(f==target.size()-1){
				return i-f;
			}
			if(i==str.size()-1){
				return -1;
			}
			++i;++f;
		}
		if(f)f=next[f-1];
	}
	return -1;
}
bool repeatedSubstringPattern(string s) {
	string tmp=s+s;
	tmp.pop_back();
	return tmp.find(s,1)!=-1;
}
int evalRPN(vector<string>& tokens) {
	stack<int>num;
	int ret=0;
	for(auto e:tokens){
		if(e[0]>='0'&&e[0]<='9'||e[0]=='-'&&e[1]>='0'&&e[1]<='9'){
			num.push(stoi (e));
		}else{
			int n1,n2;
			switch (e[0]){
				case '+':
					n2=num.top();num.pop();
					n1=num.top();num.pop();
					num.push(n1+n2);
					break;
				case '-':
					n2=num.top();num.pop();
					n1=num.top();num.pop();
					num.push(n1-n2);
					break;
				case '*':
					n2=num.top();num.pop();
					n1=num.top();num.pop();
					num.push(n1*n2);
					break;
				case '/':
					n2=num.top();num.pop();
					n1=num.top();num.pop();
					num.push(n1/n2);
					break;
				
			}
		}
	}
	return num.top();
}
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int>ret;
	deque<int>q;
	for(int i=0;i<k;++i){
		while(!q.empty()&&nums[i]>=q.back()){
			q.pop_back();
		}
		q.push_back (i);
	}
	for(int i=0;i+k<nums.size();++i){
		ret.push_back (nums[q.front()]);
		if(q.front()==i){
			q.pop_front();
		}
		while(!q.empty()&&nums[i+k]>=q.back()){
			q.pop_back();
		}
		q.push_back (i+k);
	}
	ret.push_back (q.front());
	return ret;
}
int rec(TreeNode*root){
    if(!root)return INT_MAX;
    if(!root->left&&!root->right)return 1;
    return min(rec(root->left),rec(root->right))+1;
}
int minDepth(TreeNode* root) {
    if(!root)return 0;
    return rec(root);
}
int countNodes(TreeNode* root) {
	auto p=root;
	int maxDepth=0;
	int depth=0;
	while(p){
		++maxDepth;
		p=p->left;
	}
	p=root;
	while(p){
		++depth;
		p=p->right;
	}
	if(depth==maxDepth){
		return (1<<depth)-1;
	}
	else{
		return countNodes(root->left)+countNodes(root->right)+1;
	}
}
int h(TreeNode*root){
	if(!root)return 0;
	return max(h(root->left),h(root->right))+1;
}
bool isBalanced(TreeNode* root) {
	if(!root)return true;
	return abs(h(root->left)-h(root->right))<2&&isBalanced(root->left)&&isBalanced(root->right);
}
int main () {
	vector<string>v={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
	cout<<evalRPN(v);
	return 0;
}