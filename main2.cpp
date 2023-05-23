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
	int ret=0;
	vector<vector<pair<int,int>>>dp(matrix.size(),vector<pair<int,int>>(matrix.size(),{0,0}));
	if(matrix[0][0]){
		dp[0][0]={0,0};
	}else{
		dp[0][0]={-1,-1};
	}
	for(int i=1;i<matrix.size();++i){
		if(matrix[i][0])dp[i][0]={min(dp[i-1][0].first,i),0};
		else dp[i][0]={-1,-1};
	}
	for(int j=1;j<matrix[0].size();++j){
		if(matrix[0][j])dp[0][j]={0,min(dp[0][j-1].second,j)};
		else dp[0][j]={-1,-1};
	}
	for(int i=1;i<matrix.size();++i){
		for(int j=1;j<matrix[0].size();++j){
			if(matrix[i][j]){
				
				ret=max(ret,(i-dp[i][j].first)*(j-dp[i][j].second));
			}
			else dp[i][j]={-1,-1};
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
int main(){
	
	cout<<firstUniqChar("leetcode");
	return 0;
}