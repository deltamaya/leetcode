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
template<typename T>
ostream& operator<<(ostream&os ,const vector<T>&v){
	for(auto e:v){
		//os<<e<<' ';
		os<<e<<' ';
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
int findLengthOfLCIS(vector<int>& nums) {
	int len=1,ret=1;
	for(int i=1;i<nums.size();++i){
		if(nums[i]>nums[i-1]){
			++len;
		}else{
			ret=max(ret,len);
			len=1;
		}
	}
	return max(ret,len);
}
//int findLength(vector<int>& nums1, vector<int>& nums2) {
//	int n=nums1.size(),m=nums2.size();
//	int ret=0;
//	vector<vector<int>>dp(n,vector<int>(m,0));
//	for(int i=0;i<n;++i){
//		for(int j=0;j<m;++j){
//			if(nums1[i]==nums2[j])dp[i][j]=1;
//			ret=max(ret,dp[i][j]);
//		}
//	}
////	cout<<dp<<endl;
//	for(int i=1;i<n;++i){
//		for(int j=1;j<m;++j){
//			if(nums1[i]==nums2[j])dp[i][j]=dp[i-1][j-1]+1;
//			ret=max(ret,dp[i][j]);
//		}
//	}
////	cout<<dp<<endl;
//	return ret;
//}

int findLength(vector<int>&A,vector<int>&B){
	int n=A.size(),m=B.size();
	int ret=0;
	for(int offset=-(n-1);offset<m;++offset){
		int a_begin,b_begin,len;
		a_begin=max(0,-offset);
		b_begin=max(offset,0);
		len=min(n-a_begin,m-b_begin);
		int cnt=0;
		for(int i=0;i<len;++i){
			cnt=A[a_begin+i]==B[b_begin+i]?cnt+1:0;
			ret=max(ret,cnt);
		}
	}
	return ret;
}
int longestCommonSubsequence(string s1, string s2) {
	vector<vector<int>>dp(s1.size(),vector<int>(s2.size(),0));
	dp[0][0]=s1[0]==s2[0];
	for(int i=1;i<s1.size();++i){
		if(s1[i]==s2[0]) dp[i][0]=1;
		else dp[i][0]=dp[i-1][0];
	}
	for(int i=1;i<s2.size();++i){
		if(s2[i]==s1[0])dp[0][i]=1;
		else dp[0][i]=dp[0][i-1];
	}
	cout<<dp<<endl;
	for(int i=1;i<s1.size();++i){
		for(int j=1;j<s2.size();++j){
			dp[i][j]=dp[i-1][j-1];
			if(s1[i]==s2[j])++dp[i][j];
			dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i][j-1]});
		}
	}
	cout<<dp<<endl;
	return dp.back().back();
}
class OnlyOnHeap{
	int val_;
	OnlyOnHeap(){
	
	}
public:
	OnlyOnHeap* getObj(){
		auto ret=new OnlyOnHeap;
		return ret;
	}
};
class OnlyOnStack{
	int val_;
	void* operator new(size_t){
	
	}
	void operator delete(void*){}
};
int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
	int n=nums1.size(),m=nums2.size();
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	dp[1][1]=nums1[0]==nums2[0];
	for(int i=1;i<n+1;++i){
		for(int j=1;j<m+1;++j){
			if(nums1[i-1]==nums2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp<<endl;
	return dp.back().back();
}
//int maxSubArray(vector<int>& nums) {
//	int ret=nums[0];
//	vector<int>dp(nums.size());
//	dp[0]=nums[0];
//	for(int i=1;i<nums.size();++i){
//		dp[i]=max(dp[i-1]+nums[i],nums[i]);
//		ret=max(ret,dp[i]);
//	}
//	return ret;
//}

//lower efficiency than above,idk y
int maxSubArray(vector<int>& nums) {
	int sum,ret;
	sum=ret=nums[0];
	for(int i=1;i<nums.size();++i){
		sum=max(nums[i],sum+nums[i]);
		ret=max(ret,sum);
	}
	return ret;
}

bool isSubsequence(string s, string t) {
	int i=0;
	for(auto ch:s){
		while(i<t.size()&&ch!=t[i])++i;
		if(i<t.size()&&ch==t[i])++i;
		else return false;
	}
	return true;
}
int numDistinct(string s, string t) {
	vector<vector<unsigned long long>>dp(s.size(),vector<unsigned long long>(t.size(),0));
	//dp[i][j] -> how many methods from s[i-1] to t[j-1]
	dp[0][0]=s[0]==t[0];
	for(int i=1;i<s.size();++i){
		dp[i][0]=dp[i-1][0]+(s[i]==t[0]?1:0);
	}
	for(int i=1;i<s.size();++i){
		for(int j=1;j<t.size();++j){
			if(j>i)continue;
			if(s[i]==t[j]){
				dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
			}else{
				if(i==j)dp[i][j]=0;
				else dp[i][j]=dp[i-1][j];
			}
		}
	}
//	cout<<dp<<endl;
	return dp.back().back();
}
//int minDistance(string word1, string word2) {
//	vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
//	for(int i=1;i<word1.size()+1;++i){
//		for(int j=1;j<word2.size()+1;++j){
//			if(word1[i-1]==word2[j-1]){
//				dp[i][j]=dp[i-1][j-1]+1;
//			}else{
//				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//			}
//		}
//	}
////	cout<<dp<<endl;
//	return word1.size()+word2.size()-2*dp.back().back();
//}
int minDistance(string wd1, string wd2) {
	int l1=wd1.size(),l2=wd2.size();
	if(!l1||!l2)return max(l1,l2);
	vector<vector<int>>dp(l1,vector<int>(l2,0));
	dp[0][0]=wd1[0]!=wd2[0];
	for(int i=1;i<l1;++i){
		if(wd1[i]==wd2[0])dp[i][0]=i;
		else dp[i][0]=dp[i-1][0]+1;
	}
	for(int j=1;j<l2;++j){
		if(wd2[j]==wd1[0])dp[0][j]=j;
		else dp[0][j]=dp[0][j-1]+1;
	}
	for(int i=1;i<l1;++i){
		for(int j=1;j<l2;++j){
			if(wd1[i]==wd2[j]){
				dp[i][j]=dp[i-1][j-1];
			}else{
				dp[i][j]=min({dp[i-1][j-1]+1,dp[i-1][j]+1,dp[i][j-1]+1});
			}
		}
	}
	cout<<dp<<endl;
	return dp.back().back();
}


//best answer!!100/88

//int countSubstrings(string s) {
//	int l=0,r=0;
//	int ret=0;
//	for(int i=0;i<s.size();++i){
//		l=i;r=i;
//		while(l>=0&&r<=s.size()&&s[l]==s[r]){
//			++ret;--l;++r;
//		}
//		l=i-1;r=i;
//		while(l>=0&&r<=s.size()&&s[l]==s[r]){
//			++ret;--l;++r;
//		}
//	}
//	return ret;
//
//}


int longestPalindromeSubseq(string s) {
	vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
	for(int i=0;i<s.size();++i)dp[i][i]=1;
	for(int i=s.size()-1;i>=0;--i){
		for(int j=0;j<s.size();++j){
			if(i>=j)continue;
			if(s[i]==s[j])dp[i][j]=dp[i+1][j-1]+2;
			else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
		}
	}
//	cout<<dp;
	return dp[0].back();
}
class Animal{
public:
	bool alive_;
	double weight_;
	Animal(bool alive=true,double weight=-1):
		alive_(alive),weight_(weight){};
	void die(){
		alive_=false;
	}
	virtual void makeSound()const{
		cout<<"make some sound\n";
	}
};
class Fish:public Animal{
public:
	void makeSound()const override{
		cout<<"gulugulu\n";
	}
};
class Bird:public Animal{

public:
	bool can_fly_;
	Bird(bool can_fly=true):Animal(),can_fly_(can_fly){};
	void makeSound()const override{
		cout<<"zhazha\n";
	}
};
class Pig:public Animal{
public:
	void makeSound()const override{
		cout<<"D R E\n";
	}
};
vector<int> dailyTemperatures(vector<int>& temperatures) {
	stack<int>st;
	vector<int>ret(temperatures.size(),0);
	for(int i=0;i<temperatures.size();++i){
		if(st.empty()||!st.empty()&&temperatures[st.top()]>=temperatures[i]){
			st.push(i);
		}else{
			while(!st.empty()&&temperatures[i]>temperatures[st.top()]){
				ret[st.top()]=i-st.top();
				st.pop();
			}
			st.push(i);
		}
	}
	return ret;
}
//int main(){
//	Animal a1;
//	Bird b1;
//	a1.makeSound();
//	b1.makeSound();
//	b1.die();
//	Animal* pa=&a1;
//	pa=&b1;
//	pa->makeSound();
//	pa->die();
//
//	Bird* pb=&b1;
//	b1.makeSound();
//	pb= dynamic_cast<Bird *>(&a1);
//	//cout<<pb->can_fly_;//crashed
//	//pb->makeSound();//crashed
//	return 0;
//}


vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int,int>mp;
	stack<int>st;
	for(int i=0;i<nums2.size();++i){
		if(st.empty()||st.top()>=nums2[i]){
			st.push(nums2[i]);
		}else{
			while(!st.empty()&&st.top()<nums2[i]){
				mp[st.top()]=nums2[i];
				st.pop();
			}
			st.push(nums2[i]);
		}
	}
	for(auto& e:nums1){
		if(mp.find(e)!=mp.end()){
			e=mp[e];
		}else{
			e=-1;
		}
	}
	return nums1;
}
vector<int> nextGreaterElements(vector<int>& nums) {
	auto n=nums.size();
	vector<int>ret(2*n,-1);
	stack<int>st;
	nums.insert(nums.end(),nums.begin(),nums.end());
	for(int i=0;i<nums.size();++i){
		if(st.empty()||nums[st.top()]>=nums[i]){
			st.push(i);
		}else{
			while(!st.empty()&&nums[st.top()]<nums[i]){
				ret[st.top()]=nums[i];
				st.pop();
			}
			st.push(i);
		}
		//cout<<ret;
	}
	ret.erase(ret.begin()+n,ret.end());
	return ret;
}
//int trap(vector<int>& height) {
//	vector<int>pre(height.size(),-1);
//	vector<int>next(height.size(),-1);
//	stack<int>st;
//	for(int i=0;i<height.size();++i){
//		if(st.empty()||height[st.top()]>height[i]){
//			st.push(i);
//		}else{
//			while(!st.empty()&&height[st.top()]<=height[i]){
//				next[st.top()]=i;
//				st.pop();
//			}
//			st.push(i);
//		}
//	}
//	while(!st.empty())st.pop();
//	for(int i=height.size()-1;i>=0;--i){
//		if(st.empty()||height[st.top()]>=height[i]){
//			st.push(i);
//		}else{
//			while(!st.empty()&&height[st.top()]<height[i]){
//				pre[st.top()]=i;
//				st.pop();
//			}
//			st.push(i);
//		}
//	}
//	cout<<height;
//	cout<<next;
//	cout<<pre;
//	int ret=0;
//	int i=0;
//	int last=0;
//	while(i<height.size()){
//		int begin=pre[i];
//		int end=next[i];
//		if(begin!=-1&&begin>=last&&begin<i-1){
//			int h=height[i];
//			for(int j=begin+1;j<i;++j){
//				ret+=h-height[j];
//			}
//		}
//		if(end!=-1&&end>i+1){
//			int h=height[i];
//			for(int j=i+1;j<end;++j){
//				ret+=h-height[j];
//			}
//			last=i;
//			i=end;
//		}else{
//
//			++i;
//		}
//
//		cout<<ret<<' ';
//
//	}
//	cout<<endl;
//	return ret;
//}
//int trap(vector<int>& height) {
//	int ret=0;
//	int i=0;
//	int max_right=0;
//	while(i<height.size()-1){
//		max_right=i+1;
//		for(int j=i+1;j<height.size();++j){
//			if(height[j]>=height[max_right]){
//				max_right=j;
//			}
//		}
//		int h=min(height[i],height[max_right]);
//		while(++i<max_right){
//			ret+=h-height[i];
//		}
//	}
//	return ret;
//}
//int trap(vector<int>& height) {
//	stack<int>st;
//	int ret=0;
//	for(int i=0;i<height.size();++i){
//		if(st.empty()||height[st.top()]>=height[i]){
//			st.push(i);
//		}else{
//			int top=st.top();
//			int left=-1;
//			while(!st.empty()&&height[st.top()]<height[i]){
//				top=st.top();
//				st.pop();
//				if(st.empty())break;
//				left=st.top();
//				int h=min(height[i],height[left])-height[top];
//				ret+=h*(i-left-1);
//			}
//
//			st.push(i);
//			//cout<<ret<<' ';
//		}
//	}
////	cout<<endl;
//	return ret;
//}

int trap(vector<int>& height) {
	stack<int>st;
	int ret=0;
	for(int i=0;i<height.size();++i){
		while(!st.empty()&&height[st.top()]<height[i]){
			int top=st.top();
			st.pop();
			if(st.empty())break;
			int left=st.top();
			int h=min(height[left],height[i])-height[top];
			ret+=h*(i-left-1);
		}
		st.push(i);
	}
	return ret;
}
//int largestRectangleArea(vector<int>& heights) {
//	int ret=heights[0];
//	for(int i=0;i<heights.size();++i){
//		int left=i;
//		while(left>=0&&heights[left]>=heights[i])--left;
//		int right=i;
//		while(right<heights.size()&&heights[right]>=heights[i])++right;
//		ret=max(ret,(right-left-1)*heights[i]);
//	}
//	return ret;
//}
int largestRectangleArea(vector<int>& heights) {
	stack<int>st;
	int ret=0;
	heights.insert(heights.begin(),0);
	heights.push_back(0);
	for(int i=0;i<heights.size();++i){
		while(!st.empty()&&heights[st.top()]>heights[i]){
			int top=st.top();
			st.pop();
			if(st.empty()){
				ret=max(ret,heights[top]*(top-1));
			}else{
				ret=max(ret,heights[top]*(i-st.top()-1));
			}
		}
		st.push(i);
		//cout<<ret<<' ';
	}
	//cout<<endl;
	return ret;
}

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ostream& operator<<(ostream&os,vector<ListNode*>&v){
	for(auto head:v){
		auto p=head;
		while(p){
			os<<p->val<<' ';
			p=p->next;
		}
		cout<<endl;
	}
	return os;
}ostream& operator<<(ostream&os,ListNode*&v){
	auto p=v;
	while(p){
		os<<p->val<<' ';
		p=p->next;
	}
	cout<<endl;
	return os;
}
//ListNode* mergeKLists(vector<ListNode*>& lists) {
//	unique_ptr<ListNode>newhead(new ListNode);
//	bool ok=false;
//	auto pre=newhead.get();
//	vector<ListNode*>ptrs(lists.begin(),lists.end());
//	while(!ok){
//		int min_i=-1;
//		ok=true;
//		int min_value=INT_MAX;
//		for(int i=0;i<ptrs.size();++i){
//			if(!ptrs[i])continue;
//			ok=false;
//			if(ptrs[i]->val<min_value){
//				min_i=i;
//				min_value=ptrs[i]->val;
//			}
//		}
//		if(min_i==-1)break;
//		pre->next=ptrs[min_i];
//		pre=pre->next;
//		ptrs[min_i]=ptrs[min_i]->next;
//	}
//	//cout<<newhead->next;
//	return newhead->next;
//}
ListNode* mergeKLists(vector<ListNode*>& lists) {
	map<int,int>mp;
	unique_ptr<ListNode>newhead(new ListNode);
	ListNode*p=newhead.get();
	for(auto head:lists){
		while(head){
			mp[head->val]++;
			head=head->next;
		}
	}
	for(auto num:mp){
		while(num.second--){
			p->next=new ListNode(num.first);
			p=p->next;
		}
	}
	return newhead->next;
}

//time limit exceeded
//string minWindow(string str, string t) {
//	string s=str;
//	if(s.size()<t.size())return "";
//	vector<int>idx(t.size(),-1);
//	bool ok=false;
//	int begin=-1,len=INT_MAX;
//	for(int i=0;i<t.size();++i){
//		int j=idx[i]+1;
//		while(j<s.size()&&s[j]!=t[i])++j;
//		if(j<s.size()){
//			s[j]='!';
//			idx[i]=j;
//		}else{
//			return "";
//		}
//	}
//	int max_idx=max_element(idx.begin(),idx.end())-idx.begin();
//	int min_idx=min_element(idx.begin(),idx.end())-idx.begin();
//	begin=idx[min_idx];
//	len=idx[max_idx]-idx[min_idx]+1;
//	while(!ok){
//		ok=true;
//		int i=min_idx;
//		int j=idx[i]+1;
//		while(j<s.size()&&s[j]!=t[i])++j;
//		if(j<s.size()){
//			s[j]='!';
//
//			idx[i]=j;
//			max_idx=max_element(idx.begin(),idx.end())-idx.begin();
//			min_idx=min_element(idx.begin(),idx.end())-idx.begin();
//			ok=false;
//			if(idx[max_idx]-idx[min_idx]+1<len){
//				begin=idx[min_idx];
//				len=idx[max_idx]-idx[min_idx]+1;
//			}
//		}
//
//	}
//	return str.substr(begin,len);
//}

unordered_map <char, int> ori, cnt;

bool check() {
	for (const auto &p: ori) {
		if (cnt[p.first] < p.second) {
			return false;
		}
	}
	return true;
}

string minWindow(string s, string t) {
	for (const auto &c: t) {
		++ori[c];
	}
	
	int l = 0, r = -1;
	int len = INT_MAX, ansL = -1, ansR = -1;
	
	while (r < int(s.size())) {
		if (ori.find(s[++r]) != ori.end()) {
			++cnt[s[r]];
		}
		while (check() && l <= r) {
			if (r - l + 1 < len) {
				len = r - l + 1;
				ansL = l;
			}
			if (ori.find(s[l]) != ori.end()) {
				--cnt[s[l]];
			}
			++l;
		}
	}
	
	return ansL == -1 ? string() : s.substr(ansL, len);
}
#include <cmath>
string addStrings(string num1, string num2) {
	string ret;
	reverse(num1.begin(),num1.end());
	reverse(num2.begin(),num2.end());
	int carry=0;
	int sub=abs(int(num1.size())-int(num2.size()));
	if(num1.size()<num2.size())while(sub--)num1.push_back('0');
	else while(sub--)num2.push_back('0');
	for(int i=0;i<num1.size();++i){
		int sum=carry+num1[i]-'0'+num2[i]-'0';
		carry=sum/10;
		ret.push_back('0'+sum%10);
	}
	if(carry)ret.push_back('0'+carry%10);
	reverse(ret.begin(),ret.end());
	return ret;
}
void reverseString(vector<char>& s) {
	reverse(s.begin(),s.end());
}
int firstUniqChar(string s) {
	vector<int>mp(26,-1);
	for(int i=0;i<s.size();++i){
		if(mp[s[i]-'a']==-1)mp[s[i]-'a']=i;
		else if(mp[s[i]-'a']>=0)mp[s[i]-'a']=-2;
		else continue;
	}
	int ret=INT_MAX;
	for(int i=0;i<26;++i){
		if(mp[i]<0)continue;
		else ret=min(ret,mp[i]);
	}
	return ret==INT_MAX?-1:ret;
}
int maximalRectangle(vector<vector<char>>& matrix) {
	auto m=matrix.size(),n=matrix[0].size();
	vector<vector<int>>row(m,vector<int>(n,0)),col(m,vector<int>(n,0));
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			if(matrix[i][j]!='0'){
				if(j)row[i][j]=row[i][j-1]+1;
				else row[i][j]=1;
				if(i)col[i][j]=col[i-1][j]+1;
				else col[i][j]=1;
			}else{
				col[i][j]=0;
				row[i][j]=0;
			}
		}
	}
	int ret=0;
	stack<int>st;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			if(matrix[i][j]=='0')continue;
			vector<int>tmp;
			for(int k=0;k<col[i][j];++k)tmp.push_back(row[i-k][j]);
			ret=max(ret, largestRectangleArea(tmp));
		}
	}
	return ret;
}
string largestNumber(vector<int>& nums) {
	vector<string>tmp;
	for(auto e:nums){
		tmp.push_back(to_string(e));
	}
	sort(tmp.rbegin(),tmp.rend(),[](const string&a,const string&b){
		return a+b<b+a;
	});
	string ret;
	if(tmp[0][0]=='0')return "0";
	for(auto& e:tmp){
		ret+=e;
	}
	return ret;
}
int find_depth(TreeNode*root){
	if(!root)return 0;
	return max(find_depth(root->left), find_depth(root->right))+1;
}
void rec_543(TreeNode*root,int&ret){
	if(!root)return;
	int left=find_depth(root->left);
	int right=find_depth(root->right);
	ret=max(ret,left+right);
	rec_543(root->left,ret);
	rec_543(root->right,ret);
}
int diameterOfBinaryTree(TreeNode* root) {
    if(!root)return 0;
    int ret=0;
	rec_543(root,ret);
    return ret;
}

#include <semaphore>

class Foo {
public:
	condition_variable cv;
	mutex mtx;
	int k=0;
	Foo() {
	
	}
	
	void first(function<void()> printFirst) {
		unique_lock<mutex>lock(mtx);
		// printFirst() outputs "first". Do not change or remove this line.
		while(k!=0)cv.wait(lock);
		printFirst();
		k=1;
		cv.notify_all();
	}
	
	void second(function<void()> printSecond) {
		unique_lock<mutex>lock(mtx);
		// printSecond() outputs "second". Do not change or remove this line.
		while(k!=1)cv.wait(lock);
		printSecond();
		k=2;
		cv.notify_all();
	}
	
	void third(function<void()> printThird) {
		unique_lock<mutex>lock(mtx);
		// printThird() outputs "third". Do not change or remove this line.
		while(k!=2)cv.wait(lock);
		printThird();
		cv.notify_all();
	}
};

int maxCoins(vector<int>& nums) {
	vector<vector<int>>dp(nums.size()+2,vector<int>(nums.size()+2,0));
	vector<int>val(nums.size()+2,0);
	val.front()=val.back()=1;
	for(int i=0;i<nums.size();++i){
		val[i+1]=nums[i];
	}
	for(int begin=nums.size()-1;begin>=0;--begin){
		for(int end=begin+2;end<=nums.size()+1;++end){
			for(int k=begin+1;k<end;++k){
				dp[begin][end]=max(dp[begin][end],dp[begin][k]+dp[k][end]+val[begin]*val[end]*val[k]);
			}
		}
	}
	return dp[0].back();
}
//())())(()()())())(()(
//110110111111111100110
int longestValidParentheses(string s) {
	vector<bool>valid(s.size(),false);
	vector<int>idx;
	for(int i=0;i<s.size();++i){
		if(!idx.empty()&&s[i]==')'&&s[idx.back()]=='('){
			valid[i]=true;
			valid[idx.back()]=true;
			idx.pop_back();
		}else{
			idx.push_back(i);
		}
	}
	int cnt=0;
	int ret=0;
	for(int i=0;i<valid.size();++i){
		if(!valid[i]){
			ret=max(ret,cnt);
			cnt=0;
		}else{
			++cnt;
		}
	}
	ret=max(ret,cnt);
	return ret;
}


//time limit exceeded
//int subarraySum(vector<int>& nums, int k) {
//	auto [sum,cnt,begin,len]=std::make_tuple(0,0,0,1);
//	while(len<=nums.size()){
//		for(int i=begin;i<len;++i)sum+=nums[i];
//		while(begin+len-1<nums.size()){
//			if(sum==k)++cnt;
//			sum-=nums[begin];
//			++begin;
//			if(begin+len-1==nums.size())break;
//			sum+=nums[begin+len-1];
//		}
//		++len;
//		begin=0;
//		sum=0;
//	}
//	return cnt;
//}


//memory limit exceeded
//int subarraySum(vector<int>& nums, int k) {
//	auto n=nums.size();
//	auto cnt=0;
//	vector<vector<int>>dp(n,vector<int>(n,0));
//	dp[0][0]=nums[0];
//	for(auto begin=0;begin<n;++begin){
//		for(auto end=begin;end<n;++end){
//			if(end)dp[begin][end]=dp[begin][end-1]+nums[end];
//			if(dp[begin][end]==k)++cnt;
//		}
//	}
//	return cnt;
//}


//time limit exceeded
//int subarraySum(vector<int>& nums, int k) {
//	vector<int>tmp;
//	tmp.push_back(0);
//	for(auto &e:nums){
//		tmp.push_back(tmp.back()+e);
//	}
//	auto [cnt,sum,left,right]=std::make_tuple(0,0,0,0);
//	for(left=0;left<=nums.size();++left){
//		for(right=left+1;right<=nums.size();++right){
//			if(tmp[right]-tmp[left]==k)++cnt;
//		}
//	}
//	return cnt;
//}


int subarraySum(vector<int>& nums, int k) {
	unordered_map<int,int>mp;
	mp[0]=1;
	auto [pre,cnt]=std::make_tuple(0,0);
	for(auto&&e :nums){
		pre+=e;
		if(mp.find(pre-k)!=mp.end())cnt+=mp[pre-k];
		mp[pre]++;
	}
	return cnt;
}
int rec_124(TreeNode*root,int sum,int&ret){
	if(!root)return 0;
	sum+=root->val;
	auto [l,r]=std::make_tuple(rec_124(root->left,0,ret),rec_124(root->right,0,ret));
	sum+=max((l>0?l:0),(r>0?r:0));
	ret=max(ret,(l>0?l:0)+(r>0?r:0)+root->val);
	return sum;
}
int maxPathSum(TreeNode* root) {
	int ret=root->val;
	rec_124(root,0,ret);
	return ret;
}
//s is target string, p is regex expression
//bool isMatch(string s, string p) {
//	int j=0;
//
//	for( int i = 0; i < p.size(); ++i ){
//		if(j==s.size())return false;
//		if( p[i] == '*' )continue;
//		if( p[i] != '.' ){
//			if( i + 1 < p.size() && p[i + 1] == '*' ){
//				while( j < s.size() && s[j] == p[i] )++j;
//				if(j== s.size());
//			}else{
//				if( s[j] != p[i] )break;
//				++j;
//			}
//		}else{
//			if( i + 1 < p.size() && p[i + 1] == '*' ){
//				if(i+2<p.size()){
//					while(j<s.size()&&s[j]!=p[i+2])++j;
//					if(j==s.size())return false;
//					++i;
//				}else{
//					j=s.size();
//					break;
//				}
//			}else{
//				++j;
//			}
//
//		}
//	}
//	if(j==s.size())return true;
//	return false;
//}
vector<string> removeInvalidParentheses(string s) {

}

class Trie {
	std::unordered_set<std::string>mp_;
public:
	Trie() {
	
	}
	
	void insert(string word) {
		mp_.insert(static_cast<std::string&&>(word));
	}
	
	bool search(string word) {
		return ( mp_.find(static_cast<std::string&&>(word)) != mp_.end());
	}
	bool rec_trie(const std::string& element,const std::string& prefix,int index){
		if(index==prefix.size())return true;
		if(index==element.size())return false;
		if(prefix[index]==element[index])return rec_trie(element,prefix,index+1);
		else return false;
	}
	bool startsWith(string prefix) {
		bool ret=false;
		for(auto&& element:mp_){
			if(ret)break;
			if(element[0]==prefix[0]){
				ret=rec_trie(element,prefix,1);
			}
		}
		return ret;
	}
};
class Codec {
public:
	
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		std::queue<TreeNode*>q;
		q.push(root);
		std::string ret;
		while(!q.empty()){
			auto node=q.front();
			q.pop();
			if(node)ret+=std::to_string(node->val)+',';
			else ret+="null,";
			if(node){
				q.push(node->left);
				q.push(node->right);
			}
		}
		return ret;
	}
	
	// Decodes your encoded data to tree.
	TreeNode* deserialize(const std::string& data) {
		int i=0;
		int quota=data.find(',');
		if(data.substr(0,quota)=="null")return nullptr;
		auto root=new TreeNode;
		root->val=stoi(data.substr(0,quota));
		i=quota+1;
		std::queue<TreeNode*>q;
		q.push(root);
		while(!q.empty()){
			auto node=q.front();
			q.pop();
			if(i>=data.size()){
				break;
			}
			quota=data.find(',',i);
			if(data.substr(i,quota-i)!="null"){
				node->left=new TreeNode(stoi(data.substr(i,quota-i)));
				q.push(node->left);
			}
			i=quota+1;
			if(i>=data.size()){
				break;
			}
			quota=data.find(',',i);
			if(data.substr(i,quota-i)!="null"){
				node->right=new TreeNode(stoi(data.substr(i,quota-i)));
				q.push(node->right);
			}
			i=quota+1;
		}
		return root;
	}
};
bool check(const std::unordered_map<char,int>&mp,const std::string&s){
	unordered_map<char,int>tmp;
	for(auto ch:s){
		tmp[ch]++;
	}
	return (tmp==mp);
}
vector<int> findAnagrams(string s, string p) {
	vector<int>ret;
	int begin=0;
	unordered_map<char,int>dict;
	for(auto ch:p){
		dict[ch]++;
	}
	while(begin+p.size()<=s.size()){
		while(begin+p.size()<=s.size()&&dict.find(s[begin])==dict.end()){
			++begin;
		}
		if(begin+p.size()<=s.size()&&check(dict,s.substr(begin,p.size()))){
			ret.push_back(begin);
		}
		++begin;
	}
	return ret;
}
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
	vector<double>ret;
	unordered_map<string,double>exist;
	for(int i=0;i<equations.size();++i){
		if(exist.find(equations[i][0])==exist.end()){
		
		}
	}
	
}
unordered_map<long long, int> prefix;
using i64 =int64_t;
int dfs(TreeNode *root, i64 curr, int targetSum) {
	if (!root) {
		return 0;
	}
	
	int ret = 0;
	curr += root->val;
	if (prefix.count(curr - targetSum)) {
		ret = prefix[curr - targetSum];
	}
	
	prefix[curr]++;
	ret += dfs(root->left, curr, targetSum);
	ret += dfs(root->right, curr, targetSum);
	prefix[curr]--;
	
	return ret;
}

int pathSum(TreeNode* root, int targetSum) {
	prefix[0] = 1;
	return dfs(root, 0, targetSum);
}
vector<int> twoSum(vector<int>& numbers, int target) {
	int left=0,right=numbers.size()-1;
	while(left<right){
		while(numbers[left]+numbers[right]>target){
			--right;
		}
		while(numbers[left]+numbers[right]<target){
			++left;
		}
		if(numbers[left]+numbers[right]==target){
			return {left+1,right+1};
		}
	}
	return {0,0};
}
bool judgeSquareSum(int c) {
	if(c<10){
		if(c==7||c==3||c==6)return false;
		return true;
	}
	unsigned left=0,right=sqrt(c);
	while(left<=right){
		if(left*left+right*right>c){
			--right;
		}else if(left*left+right*right<c){
			++left;
		}else{
			return true;
		}
	}
	return false;
}
string reverseVowels(string s) {
	string vowels="aeiouAEIOU";
	int left=0,right=s.size()-1;
	while(left<right){
		while(left<right&&vowels.find(s[left])==-1){
			++left;
		}
		while(left<right&&vowels.find(s[right])==-1){
			--right;
		}
		swap(s[left],s[right]);
		++left;--right;
	}
	return s;
}
int isLessOrEqual(int x, int y) {
	int sub=((y+(~x+1))>>31)&1;//0 is y>=x, 1 is y<x
	int x_min=!(x^(1<<31));
	int y_min=!(y^(1<<31));
	return (!sub&!y_min)|x_min;
}
unsigned floatScale2(unsigned uf) {
  unsigned ret=0;
  unsigned exponent=(uf&0x7f800000)>>23;
  //printf("%u",exponent);
  unsigned significant=uf&0x007fffff;
  if(exponent==255)return uf;
  else{
    return (uf&0x80000000)+((exponent+1)<<23)+significant;
  }
}
bool isValid(const string&s,int left,int right){
	while(left<right&&s[left]==s[right]){
		++left;--right;
	}
	return left>=right;
}
bool validPalindrome(string s) {
	int left=0,right=s.size()-1;
	while(left<right&&s[left]==s[right]){
		++left;--right;
	}
	if(left>=right)return true;
	else{
		return isValid(s,left+1,right)||isValid(s,left,right-1);
	}
}
string findLongestWord(string s, vector<string>& dictionary) {
	string ret;
	for(auto &&word:dictionary){
		int ps=0,pw=0;
		while(ps<s.size()&&pw<word.size()){
			if(s[ps]==word[pw]){
				++pw;
			}
			++ps;
		}
		if(pw==word.size()){
			if(ret.size()<word.size()){
				ret=word;
			}else if(ret.size()==word.size()&&ret>word){
				ret=word;
			}
		}
	}
	return ret;
}
int findKthLargest(vector<int>& nums, int k) {
	priority_queue<int,vector<int>,greater<>>hp;
	for(auto &&e:nums){
		if(hp.size()<k)hp.push(e);
		else{
			if(e>hp.top()){
				hp.pop();
				hp.push(e);
			}
		}
	}
	return hp.top();
}
bool isPalindrome(string s) {
	string temp;
	for(auto &&ch:s){
		if(ch>='0'&&ch<='9'||ch>='a'&&ch<='z')temp.push_back(ch);
		else if(ch>='A'&&ch<='Z')temp.push_back(tolower(ch));
		else continue;
	}
	int left=0,right=temp.size()-1;
	while(left<right&&temp[left]==temp[right]){
		++left;--right;
	}
	return left>=right;
}
void Reverse(string&s ,int left,int right){
	while(left<right){
		swap(s[left++],s[right--]);
	}
}
//string reverseWords(string s) {
//	int pre=0,pos=0;
//	while((pos=s.find(' ',pos))!=-1){
//		Reverse(s,pre,pos-1);
//		pre=++pos;
//	}
//	Reverse(s,pre,s.size()-1);
//	return s;
//}
string multiply(string num1, string num2) {
	if(num1[0]=='0'||num2[0]=='0')return "0";
	std::reverse(num1.begin(), num1.end());
	std::reverse(num2.begin(), num2.end());
	int i=0,mult=0,carry=0,sum=0;
	string ret(num1.size()+num2.size(),'0');
	string&less=num1;
	string&greater=num2;
	if(num1.size()>num2.size())swap(less,greater);
	for(i=0;i<less.size();++i){
		int j;
		for(j=0;j<greater.size();++j){
			mult=(less[i]-'0')*(greater[j]-'0')+carry+ret[i+j]-'0';
			ret[i+j]='0'+mult%10;
			carry=mult/10;
		}
		while(carry>0){
			sum=carry+ret[i+j]-'0';
			ret[i+j]='0'+sum%10;
			carry=sum/10;
			++j;
		}
	}
	while(ret.back()=='0')ret.pop_back();
	std::reverse(ret.begin(), ret.end());
	return ret;
}
vector<int> spiralOrder(vector<vector<int>> matrix) {
	vector<int>ret;
	int n=matrix.size(),m=matrix[0].size();
	int l=0,u=0,r=m-1,d=n-1;
	while(1){
		for(int i=l;i<=r;++i)ret.push_back(matrix[u][i]);
		if(++u>d)break;
		for(int j=u;j<=d;++j)ret.push_back(matrix[j][r]);
		if(--r<l)break;
		for(int i=r;i>=l;--i)ret.push_back(matrix[d][i]);
		if(--d<u)break;
		for(int j=d;j>=u;--j)ret.push_back(matrix[j][l]);
		if(++l>r)break;
	}
	return ret;
}
TreeNode* BuildTreeRec(vector<int>&preorder,int pre_left,int pre_right,vector<int>&inorder,int in_left,int in_right){
	if(pre_left>pre_right||in_left>in_right)return nullptr;
	int i=in_left;
	auto node=new TreeNode(preorder[pre_left]);
	while(inorder[i]!=preorder[pre_left])++i;
	i-=in_left;
	node->left=BuildTreeRec(preorder,pre_left+1,pre_left+i,inorder,in_left,in_left+i-1);
	node->right= BuildTreeRec(preorder,pre_left+i+1,pre_right,inorder,in_left+i+1,in_right);
	return node;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if(!preorder.size()||!inorder.size())return nullptr;
	auto root= BuildTreeRec(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
	return root;
}

double QuickPower(double  base,long long  power){
	int ret=1;
	while(power>1){
		if(power%2){
			ret*=base;
			--power;
		}else{
			base*=base;
			power>>=1;
		}
	}
	return ret*base;
}
//int cuttingRope(int n) {
//	const int MOD=1e9+7;
//	if(n<=3)return n-1;
//	if(n==4)return 4;
//	long long ret=1;
//	while(n>4){
//		ret=(ret*3)%MOD;
//		n-=3;
//	}
//	return int((ret*n)%MOD);
//}
std::string cuttingRope(int n) {
	const int MOD=1e9+7;
	if(n<=3)return to_string(n-1);
	if(n==4)return to_string(4);
	string ret="1";
	while(n>4){
		ret= multiply(ret,"3");
		n-=3;
	}
	std::cout<<ret;
	return ret;
}
bool IsInteger(const string& s){
	if(s.size()==0)return false;
	if(s[0]=='+'||s[0]=='-'||s[0]>='0'&&s[0]<='9'){
		auto ret=s.find_last_not_of("1234567890");
		return (ret==0||ret==-1)&&(s.find_first_of("1234567890")!=-1);
	}
	else
		return false;
}
bool IsFloat(const string& s){
	if(s.size()==0)return false;
	int idx=s.find('.');
	if(idx!=-1){
		if(idx==s.size()-1&&idx!=((s[0]=='+'||s[0]=='-')?1:0))return IsInteger(s.substr((s[0]=='+'||s[0]=='-')?1:0,idx-((s[0]=='+'||s[0]=='-')?1:0)));
		else if(idx==((s[0]=='+'||s[0]=='-')?1:0))return IsInteger(s.substr(idx+1,s.size()-idx-1))&&(s[idx+1]!='+'&&s[idx+1]!='-');
		else return IsInteger(s.substr((s[0]=='+'||s[0]=='-')?1:0,idx))&&(s[idx+1]!='+'&&s[idx+1]!='-')&&IsInteger(s.substr(idx+1,s.size()-idx-1));
	}
	else
		return false;
}
bool isNumber(string s) {
	string temp;
	int i=0;
	for(i=0;i<s.size()&&s[i]==' ';++i);
	int j=0;
	for(j=s.size()-1;j>=i&&s[j]==' ';--j);
	if(i>j)return false;
	temp=s.substr(i,j-i+1);
	for(;i<j;++i)if(s[i]==' ')return false;
	if(auto idx=temp.find_first_of("eE");idx!=-1){
		return (IsFloat(temp.substr(0,idx))|| IsInteger(temp.substr(0,idx)))&&IsInteger(temp.substr(idx+1,temp.size()-idx-1));
	}
	return IsFloat(temp)|| IsInteger(temp);
}
bool VerifyPostorderRec(vector<int>&postorder,int begin,int end){
	if(begin>=end)return true;
	int right=begin;
	while(right<end&&postorder[right]<postorder[end])
		++right;
	for(int temp=right;temp<end;++temp)if(postorder[temp]<=postorder[end])return false;
	return VerifyPostorderRec(postorder,begin,right-1)&& VerifyPostorderRec(postorder,right,end-1);
	
}
bool verifyPostorder(vector<int>& postorder){
	return VerifyPostorderRec(postorder,0,postorder.size()-1);
}
class Node {
public:
	int val;
	Node* left;
	Node* right;
	
	Node() {}
	
	Node(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}
	
	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};
//if it's a left child:
//  left -> parent's parent
//  right -> parent(if !right)
//if it's a right child:
//  left -> parent(if !left)
//  right ->parent's parent if(!right)
Node*pre,*head;
void TreeToDoublyListTraversal(Node*cur){
	if(!cur)return;
	auto l=cur->left,r=cur->right;
	TreeToDoublyListTraversal(l);
	if(pre)pre->right=cur;
	else head=cur;
	cur->left=pre;
	pre=cur;
	TreeToDoublyListTraversal(r);
}
Node* treeToDoublyList(Node* root) {
	if(!root) return nullptr;
	TreeToDoublyListTraversal(root);
	head->left = pre;
	pre->right = head;
	return head;
}
void BackTracking(vector<string>&ret,string&s,string&path){
	if(path.size()==s.size()){
		ret.push_back(path);
		return;
	}
	for(int i=0;i<s.size();){
		if(s[i]==' '){i++;continue;}
		auto temp=s[i];
		path.push_back(s[i]);
		s[i]=' ';
		BackTracking(ret,s,path);
		s[i]=temp;
		while(i<s.size()&&(s[i]==path.back()||s[i]==' '))++i;
		path.pop_back();
	}
}
vector<string> permutation(string s) {
	sort(s.begin(),s.end());
	vector<string>ret;
	string path;
	BackTracking(ret,s,path);
	return ret;
}
int findNthDigit(int n) {

	if(n<10)return n;
	n-=1;
	int i=8;
	int x=0;
	for(int j=1;j<=8;++j)x+=pow(10,j-1)*j*9;
	while(n<x)x-=i*pow(10,--i)*9;
	int sub=n-x;
	string temp=std::to_string(int(pow(10,i))+sub/(i+1));
	return temp[sub%(i+1)]-'0';
}
void BackTrackingNthUglyNumber(int num,int i,int limit,vector<int>&ret,int begin){
	if(ret.size()>=1690)return;
	if(i==limit){
		ret.push_back(num);
		return;
	}
	array<int,3>temp{2,3,5};
	for(int j=begin;j<3;++j){
		if((long long)num*temp[j]>INT_MAX)return;
		num*=temp[j];
		BackTrackingNthUglyNumber(num,i+1,limit,ret,j);
		num/=temp[j];
	}
}
//int nthUglyNumber(int n) {
//	vector<int>ret;
//	for(int i=0;ret.size()<1690;++i){
//		BackTrackingNthUglyNumber(1,0,i,ret,0);
//	}
//	std::sort(ret.begin(), ret.end());
//	return ret[n-1];
//
//}

int nthUglyNumber(int n){
	vector<int>dp(n,0);
	int mult2=0,mult3=0,mult5=0;
	dp[0]=1;
	for(int i=1;i<n;++i){
		vector<int>temp{dp[mult2]*2,dp[mult3]*3,dp[mult5]*5};
		int  mini=0;
		for(int j=0;j<3;++j)if(temp[j]<temp[mini])mini=j;
		dp[i]=temp[mini];
		if(dp[mult2]*2==temp[mini])++mult2;
		if(dp[mult3]*3==temp[mini])++mult3;
		if(dp[mult5]*5==temp[mini])++mult5;
	}
	return dp.back();
}
int GetMaxOneUptoSigAndIdx(int sig,int idx){
	if(idx<0)return 0;
	if(!sig)return (idx>=0?1:0);
	return pow(10,sig-1)*sig+(idx==1?pow(10,sig):0)+ GetMaxOneUptoSigAndIdx(sig,idx-1);
}
int countDigitOne(int n) {
	int temp=n;
	int cnt=0;
	int sig=log10(n);
	while(sig>=0){
		int idx=(n/(int(pow(10,sig))))%10-1;
		cnt+= GetMaxOneUptoSigAndIdx(sig,idx);
		temp-=(idx+1)*pow(10,sig);
		if(!idx&&sig)cnt+=temp+1;
		--sig;
	}
	return cnt;
}
//this is preorder traversal recursion solution, it's time and memory cost is much higher than layer order (line 1193 in this file)
//class Codecc {
//public:
//
//	void SerializeTraversal(TreeNode*root,string&ret){
//		if(!root){
//			ret+="null,";
//			return;
//		}else{
//			ret+=to_string(root->val);
//			ret+=",";
//			SerializeTraversal(root->left,ret);
//			SerializeTraversal(root->right,ret);
//		}
//	}
//	// Encodes a tree to a single string.
//	string serialize(TreeNode* root) {
//		string ret;
//		SerializeTraversal(root,ret);
//		return ret;
//	}
//	TreeNode* DeserializeTraversal(string data,int& pos){
//		if(pos>=data.size())return nullptr;
//		int next=data.find(",",pos);
//		auto result=data.substr(pos,next-pos);
//		pos=next+1;
//		if(result=="null")return nullptr;
//		auto node=new TreeNode(stoi(result));
//
//		node->left=DeserializeTraversal(data,pos);
//		node->right=DeserializeTraversal(data,pos);
//		return node;
//	}
//	// Decodes your encoded data to tree.
//	TreeNode* deserialize(string data) {
//		if(data=="null,")return nullptr;
//		int pos=0;
//		return DeserializeTraversal(data,pos);
//	}
//};
class Codecc {
public:
	
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string ret;
		stack<TreeNode*>st;
		st.push(root);
		while(!st.empty()){
			auto node=st.top();
			st.pop();
			if(!node){
				ret+="null,";
				continue;
			}
			ret+=(to_string(node->val)+',');
			st.push(node->right);
			st.push(node->left);
		}
		return ret;
	}
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if(data=="null,")return nullptr;
		int pos=data.find(',');
		int pre=0;
		auto root=new TreeNode(stoi(data.substr(0,pos)));
		pre=++pos;
		stack<TreeNode*>st;
		st.push(root);
		string result;
		while(!st.empty()){
			l:
			if(pos==data.size())break;
			auto node=st.top();
			if(node->left||node->right)goto r;
			pos=data.find(",",pos);
			result=data.substr(pre,pos-pre);
			pre=++pos;
			if(result=="null"){
				goto r;
			}
			node->left=new TreeNode(stoi(result));
			st.push(node->left);
			goto l;
			r:
			if(pos==data.size())break;
			node=st.top();
			if(node->right){
				st.pop();
				continue;
			}
			pos=data.find(",",pos);
			result=data.substr(pre,pos-pre);
			pre=++pos;
			if(result=="null"){
				st.pop();
				continue;
			}
			node->right=new TreeNode(stoi(result));
			st.push(node->right);
		}
		return root;
	}
};
class MedianFinder {
	priority_queue<int,vector<int>,less<>>left;
	priority_queue<int,vector<int>,greater<>>right;
public:
	
	/** initialize your data structure here. */
	MedianFinder() {
	}
	
	void addNum(int num) {
		left.push(num);
		right.push(left.top());
		left.pop();
		if(left.size()<right.size()){
			left.push(right.top());
			right.pop();
		}
	}
	
	double findMedian() {
		if(left.size()>right.size()){
			return left.top();
		}
		return (double(left.top())+right.top())/2;
	}
};
vector<int> singleNumbers(vector<int>& nums) {
	int temp=0;
	for(auto&&e:nums){
		temp^=e;
	}
	int div=1;
	while(!(div&temp))div<<=1;
	int x=0,y=0;
	for(auto &&e:nums){
		if(e&div){
			x^=e;
		}else{
			y^=e;
		}
	}
	return vector<int>{x,y};
}
int singleNumber(vector<int>& nums) {
	unordered_map<int,int>mp;
	for(auto &&e:nums){
		mp[e]++;
	}
	for(auto &&e:mp){
		if(e.second==1)return e.first;
	}
	return 0;
}
vector<int> GetVec(int begin,int end){
	vector<int>ret;
	for(int i=begin;i<=end;++i){
		ret.push_back(i);
	}
	return std::move(ret);
}
vector<vector<int>> findContinuousSequence(int target) {
	vector<vector<int>>ret;
	int begin=1,sum=0;
	int i=begin;
	while(sum<target){
		sum+=i++;
	}
	while(begin<=target/2){
		if(sum==target){
			ret.push_back(GetVec(begin,i-1));
		}
		if(sum<=target){
			sum+=i++;
		}
		while(sum>target&&begin<=target/2){
			sum-=begin++;
		}

	}
	return std::move(ret);
}
//vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//	vector<int>ret;
//	deque<int>q;
//	for(int i=0;i<k;++i){
//		while(!q.empty()&&nums[i]>=nums[q.back()]){
//			q.pop_back();
//		}
//		q.push_back (i);
//	}
//	for(int i=0;i+k<nums.size();++i){
//		ret.push_back (nums[q.front()]);
//		if(q.front()==i){
//			q.pop_front();
//		}
//		while(!q.empty()&&nums[i+k]>=nums[q.back()]){
//			q.pop_back();
//		}
//		q.push_back (i+k);
//	}
//	ret.push_back (nums[q.front()]);
//	return ret;
//}
//TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//	if(!root||root==p||root==q)return root;
//	auto lhs= lowestCommonAncestor(root->left,p,q);
//	auto rhs= lowestCommonAncestor(root->right,p,q);
//	if(lhs&&rhs)return root;
//	if(lhs)return lhs;
//	if(rhs)return rhs;
//	return nullptr;
//}
int strToInt(string str) {
	int i=0;
	while(i<str.size()&&str[i]==' ')++i;
	if(i==str.size())return 0;
	int sign=1;
	if(str[i]=='+'||str[i]=='-'){
		if(str[i]=='-')sign=-1;
		++i;
	}
	while(i<str.size()&&str[i]=='0')++i;
	if(i==str.size())return 0;
	if(str[i]>='0'&&str[i]<='9'){
		int j=i;
		while(j<str.size()&&str[j]>='0'&&str[j]<='9')++j;
		if((j-i==10&&str.substr(i,j-i)>"2147483647")||j-i>10){
			if(sign==1)return INT_MAX;
			else return INT_MIN;
		}else{
			int ret=0;
			while(i<j){
				ret*=10;
				ret+=str[i]-'0';
				++i;
			}
			return ret*sign;
		}
	}else{
		return 0;
	}
}
vector<int> constructArr(vector<int>& a) {
	if(a.size()<1)return {};
	vector<int>ret(a),ltor(a),rtol(a);
	for(int i=1;i<ltor.size();++i){
		ltor[i]=ltor[i-1]*a[i];
	}
	for(int i=rtol.size()-2;i>=0;--i){
		rtol[i]=rtol[i+1]*a[i];
	}
	ret[0]=rtol[1];
	for(int i=1;i<a.size()-1;++i){
		ret[i]=ltor[i-1]*rtol[i+1];
	}
	ret.back()=ltor[ltor.size()-2];
	return std::move(ret);
}
vector<double> dicesProbability(int n) {
	vector<double>ret(6+(n-1)*5,0);
	auto temp=ret;
	for(int i=0;i<6;++i){
		ret[i]=1.0/6;
	}
	for(int dice_cnt=2;dice_cnt<=n;++dice_cnt){
		for(int i=0;i<6+(dice_cnt-1)*5;++i){
			for(int j=0;j<=min(i,5);++j){
				temp[i]+=ret[i-j]/6;
			}
		}
		ret=temp;
		temp.assign(temp.size(),0);
	}
	return std::move(ret);
}
class MaxQueue {
	size_t sz;
	queue<int>input_;
	deque<int>maxes_;
public:
	MaxQueue() {
		sz=0;
	}
	
	int max_value() {
		if(sz==0)return -1;
		return maxes_.front();
	}
	
	void push_back(int value) {
		++sz;
		input_.push(value);
		while(!maxes_.empty()&&maxes_.back()<value){
			maxes_.pop_back();
		}
		maxes_.push_back(value);
	}
	
	int pop_front() {
		if(sz==0)return -1;
		auto ret=input_.front();
		input_.pop();
		if(ret==maxes_.front()){
			maxes_.pop_front();
		}
		--sz;
		return ret;
	}
};
int main(){
	auto ret= dicesProbability(3);
	cout<<ret;
}