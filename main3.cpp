#include <bits/stdc++.h>
using namespace std;
int divide(int a, int b) {
	
	assert(b != 0); // 断言除数不能为0 否则下面while会死循环
	bool flag = !((a>>31)^(b>>31)); // flag为true表示最终答案为正
	
	// 把a b先转为无符号整数 负数位移会计算错
	unsigned _a = a < 0 ? ~a + 1U : a; // 负数是补码形式 取反+1得到相反数
	unsigned _b = b < 0 ? ~b + 1U : b;
	unsigned ret = 0U;
	int pos = 31; // b不能为0 a右移32位必定为0 必定小于b 所以pos初始为31
	
	// 该循环执行位运算乘法的逆运算
	while (_a >= _b) {
		while ((_a >> pos) < _b) pos--;
		_a -= (_b << pos);
		ret |= (1U << pos);
	}
	
	// 判断是否溢出
	if (ret > INT_MAX) {
		return flag ? INT_MAX : INT_MIN;
	}
	
	return flag ? (int)ret : -(int)ret;
}
int  multiply(int a,int b){
	int temp=0;
	while(b>1){
		if(b&1){
			temp+=a;
			b-=1;
		}
		else{
			a<<=1;
			b>>=1;
		}
	}
	return a+temp;
}
string addBinary(string a, string b) {
	if(a=="0")return b;
	if(b=="0")return a;
	string ret;
	bool carry=false;
	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());
	int i=0;
	for(i=0;i<min(a.size(),b.size());++i){
		ret.push_back('0'+((a[i]=='1')^(b[i]=='1')^carry));
		carry=((a[i]=='1')+(b[i]=='1')+int(carry))>1;
	}
	while(i<a.size()){
		ret.push_back('0'+((a[i]=='1')^carry));
		carry=((a[i]=='1')+int(carry))>1;
		++i;
	}
	while(i<b.size()){
		ret.push_back('0'+((b[i]=='1')^carry));
		carry=((b[i]=='1')+int(carry))>1;
		++i;
	}
	if(carry)ret.push_back('1');
	std::reverse(ret.begin(), ret.end());
	return ret;
}
vector<int>&& countBits(int n) {
	int cnt=0;
	int meet=1;
	vector<int>ret(n+1);
	ret[0]=0;
	for(int i=1;i<=n;++i){
		ret[i]=ret[i-meet]+1;
		if(++cnt==meet){
			cnt=0;
			meet*=2;
		}
	}
	return std::move(ret);
}
int count(int a){
	int cnt=0;
	while(a){
		++cnt;
		a=a&(a-1);
	}
	return cnt;
}
//int singleNumber(vector<int>& nums) {
//	unordered_map<int,int>mp;
//	for(auto &&e:nums){
//		mp[e]++;
//	}
//	for(auto &&[k,v]:mp){
//		if(v==1)return k;
//	}
//	return -1;
//}
int singleNumber(vector<int>& nums) {
	array<int,32>arr{0};
	for(auto &&e:nums){
		for(int off=0;off<32;++off){
			arr[off]+=(e>>off)&1;
		}
	}
	int ret=0;
	for(int off=0;off<32;++off){
		if(arr[off]%3){
			ret|=1<<off;
		}
	}
	return ret;
}
int maxProduct(vector<string>& words) {
	int ret=0;
	for(int i=0;i<words.size();++i){
		for(int j=i+1;j<words.size();++j){
			if(words[i].find_first_of(words[j])==-1){
				ret=max(ret,int(size(words[i])*size(words[j])));
			}
		}
	}
	return ret;
}
vector<int> twoSum(vector<int>& numbers, int target) {
	int l=0,r=size(numbers)-1;
	while(l<r){
		int sum=numbers[l]+numbers[r];
		if(sum==target)return {l,r};
		if(sum>target)--r;
		else ++l;
	}
	return {-1,-1};
}
inline int BinarySearch(const vector<int>&v,int target,int begin){
	int l=begin,r=v.size()-1,m;
	while(l<=r){
		m=(l+r)/2;
		if(v[m]>target){
			r=m-1;
		}else if(v[m]<target){
			l=m+1;
		}else{
			return m;
		}
	}
	return -1;
}
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>>ret;
	sort(nums.begin(),nums.end());
	for(int l=0;l<nums.size();++l){
		if(nums[l]>0)break;
		for(int m=l+1;m<nums.size();++m){
			int sum=-(nums[l]+nums[m]);
			if(sum<nums[m])break;
			if(auto temp=BinarySearch(nums,sum,m+1);temp!=-1){
				ret.emplace_back(vector<int>{nums[l],nums[m],nums[temp]});
				
			}
			while(m+1<nums.size()&&nums[m+1]==nums[m])++m;
		}
		while(l+1<nums.size()&&nums[l+1]==nums[l])++l;
	}
	return std::move(ret);
}
template<typename T>
ostream& operator<<(ostream&os,const vector<T>&v){
	for(auto&&e:v){
		os<<e<<' ';
	}
	os<<endl;
	return os;
}
int minSubArrayLen(int target, vector<int>& nums) {
	int l=0,r=0;
	int sum=nums[0];
	int length=INT_MAX;
	while(1){
		while(r+1<nums.size()&&sum<target){
			sum+=nums[++r];
		}
		while(l<=r&&sum>=target){
			length=min(length,r-l+1);
			sum-=nums[l++];
		}
		if(r==nums.size()-1)break;
	}
	return length==INT_MAX?0:length;
}
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
	int l=0,r=0,sum=nums[0],cnt=0;
	while(1){
		while(r+1<size(nums)&&sum<k){
			cnt+=(r-l+1);
			sum*=nums[++r];
		}
		while(l<=r&&sum>=k){
			sum/=nums[l++];
		}
		if(l>r){
			sum=nums[++r];
		}
		if(r==nums.size()-1){
			if(sum<k)cnt+=(r-l+1);
			break;
		}
	}
	return cnt;
}
int findMaxLength(vector<int>& nums) {
	unordered_map<int,int>mp;
	mp[0]=-1;
	int ret=0,cnt=0;
	for(int i=0;i<nums.size();++i){
		if(nums[i])++cnt;
		else --cnt;
		if(mp.count(cnt)){
			ret=max(ret,i-mp[cnt]);
		}else mp[cnt]=i;
	}
	return ret;
}



int main(){
	vector<int>temp{0,0,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,0,0,1,0,1,1,0,0,0,0,0,0};
	std::cout<<findMaxLength(temp);
	return 0;
}