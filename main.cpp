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
int main () {
	string s;
	getline(cin,s);
	cout<<reverseWords(s);
	return 0;
}