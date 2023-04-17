#include <bits/stdc++.h>
using namespace std;
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
int main () {
	string s;
	cin>>s;
	cout<<decodeString(s);
	return 0;
}