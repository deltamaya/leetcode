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

//int lengthOfLIS(vector<int>& nums) {
//	vector<int>len;
//	int ret;
//	for(int i=0;i<nums.size();++i){
//		int j=i;
//		int maxlen=1;
//		while(j>=0){
//			if(nums[i]>nums[j]){
//				maxlen=max(maxlen,len[j]+1);
//
//			}
//			ret=max(maxlen,ret);
//			--j;
//		}
//		len.push_back (maxlen);
//	}
//	return ret;
//}
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
//ostream& operator<<(ostream&os,const vector<int>&v){
//	for(auto e:v){
//		os<<e<<' ';
//	}
//	os<<endl;
//	return os;
//}
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
//void rec(vector<string>&ret,string path,TreeNode*root){
//	path+="->";
//	path+= to_string (root->val);
//	if(!root->left&&!root->right) {
//		ret.push_back (path);
//		return;
//	}
//	if(root->left)rec(ret,path,root->left);
//	if(root->right)rec(ret,path,root->right);
//}
//vector<string> binaryTreePaths(TreeNode* root) {
//	string path;
//	vector<string>ret;
//	path+= to_string (root->val);
//	if(!root->left&&!root->right) {
//		ret.push_back (path);
//	}
//	if(root->left)rec(ret,path,root->left);
//	if(root->right)rec(ret,path,root->right);
//	return ret;
//}
void rec(vector<string>&ret,vector<int>& path,TreeNode*root){
	path.push_back(root->val);
	if(root->left){
		rec(ret,path,root->left);
	}
	if(root->right){
		rec(ret,path,root->right);
	}
	
	if(!root->left&&!root->right){
		string tmp;
		tmp+=to_string(path[0]);
		for(int i=1;i<path.size();++i){
			tmp+="->";
			tmp+=to_string(path[i]);
		}
		ret.push_back (tmp);
	}
	path.pop_back();
}
vector<string> binaryTreePaths(TreeNode* root) {
	vector<int> path;
	vector<string>ret;
	rec(ret,path,root);
	return ret;
}
int sumOfLeftLeaves(TreeNode* root) {
	int ret=0;
	if(!root)return 0;
	if(root->left&&!root->left->left&&!root->left->right)return root->left->val+sumOfLeftLeaves(root->right);
	else{
		return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
	}
}
//迭代法
//int findBottomLeftValue(TreeNode* root) {
//	int ret=0;int maxh=0;
//	queue<pair<TreeNode*,int>>q;
//	q.push({root,1});
//	while(!q.empty()){
//		auto e=q.front();q.pop();
//		auto p=e.first;int h=e.second;
//		if(h>maxh) { ret = p->val;maxh=h; }
//		if(p->left)q.push({p->left,h+1});
//		if(p->right)q.push({p->right,h+1});
//	}
//	return ret;
//}
//递归法
void rec(TreeNode*root,int height,int&val,int&val_h){
	if(root->left){
		rec(root->left,height+1,val,val_h);
	}
	if(root->right){
		rec(root->right,height+1,val,val_h);
	}
	if(height>val_h){
		val_h=height;
		val=root->val;
	}
}
int findBottomLeftValue(TreeNode* root) {
	int val=root->val;
	int val_h=1;
	rec(root,1,val,val_h);
	return val;
}

bool rec(TreeNode*root,int targetSum,int&sum){
	sum+=root->val;
	bool ret=false;
	if(root->left){
		ret= rec (root->left, targetSum, sum);
	}
	if(root->right){
		ret=ret||rec(root->right,targetSum,sum);
	}
	if(!root->left&&!root->right&&sum==targetSum)return true;
	sum-=root->val;
	return ret;
}
bool hasPathSum(TreeNode* root, int targetSum) {
	if(!root)return false;
	int sum=0;
	return rec(root,targetSum,sum);
}
TreeNode* rec(vector<int>& inorder, vector<int>& postorder,int in_begin,int in_end,int post_begin,int post_end){
	if(in_begin>in_end||post_begin>post_end)return nullptr;
	auto root=new TreeNode(postorder[post_end]);
	int i=0;
	for(i=0;i<=in_end-in_begin;++i){
		if(inorder[in_begin+i]==postorder[post_end]) {
			root->left=rec(inorder,postorder,in_begin,in_begin+i-1,post_begin,post_begin+i-1);
			root->right=rec(inorder,postorder,in_begin+i+1,in_end,post_begin+i,post_end-1);
			root->val=inorder[in_begin+i];
			return root;
		}
	}
	return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	return rec(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
}

//20230425

//递归解法TC=O(N^2)
//TreeNode* rec(vector<int>&nums,int begin,int end){
//	if(begin>end)return nullptr;
//	int max_idx=begin;
//	int max_value=nums[begin];
//	for(int i=begin;i<=end;++i){
//		if(nums[i]>=max_value){
//			max_idx=i;
//			max_value=nums[i];
//		}
//	}
//	auto root=new TreeNode(max_value);
//	root->left=rec(nums,begin,max_idx-1);
//	root->right=rec(nums,max_idx+1,end);
//	return root;
//}
//TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//	return rec(nums,0,nums.size()-1);
//}

//单调栈解法TC=O(N)
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
	stack<TreeNode*>stk;
	for(auto e:nums){
		auto node=new TreeNode(e);
		while(!stk.empty()&&stk.top()->val<e){
			auto t=stk.top();
			stk.pop();
			node->left=t;
		}
		if(!stk.empty()&&stk.top()->val>e){
			stk.top()->right=node;
			
		}
		stk.push(node);
	}
	while(stk.size()>1)stk.pop();
	return stk.top();
}

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
	if(!root1&&!root2)return nullptr;
	auto p=new TreeNode(0);
	if(root1)p->val+=root1->val;
	if(root2)p->val+=root2->val;
	TreeNode* r1l,*r2l,*r1r,*r2r;
	if(!root1){r1l=nullptr;r1r=nullptr;}else{r1l=root1->left;r1r=root1->right;}
	if(!root2){r2r=nullptr;r2l=nullptr;}else{r2l=root2->left;r2r=root2->right;}
	p->left= mergeTrees (r1l,r2l);
	p->right   = mergeTrees (r1r,r2r);
	return p;
}
TreeNode* searchBST(TreeNode* root, int val) {
	while(root){
		if(root->val>val){
			return searchBST (root->left,val);
		}else if(root->val<val){
			return searchBST (root->right,val);
		}else{
			return root;
		}
	}
	return nullptr;
}
void Traversal(TreeNode*root,vector<int>&vec){
	if(!root)return;
	Traversal (root->left,vec);
	vec.push_back(root->val);
	Traversal (root->right,vec);
}
int getMinimumDifference(TreeNode* root) {
	vector<int>vec;
	Traversal(root,vec);
	int gap=INT_MAX;
	for(int i=1;i<vec.size();++i){
		gap=min(gap,abs(vec[i]-vec[i-1]));
	}
	return gap;
	
}
bool isValidBST(TreeNode* root) {
	vector<int>vec;
	Traversal(root,vec);
	for(int i=1;i<vec.size();++i){
		if(vec[i]<=vec[i-1])return false;
	}
	return true;
}
//void rec_501(unordered_map<int,int>&table,TreeNode*root){
//	if(!root)return;
//	table[root->val]++;
//	rec_501 (table,root->left);
//	rec_501 (table,root->right);
//
//}
//vector<int> findMode(TreeNode* root) {
//	unordered_map<int,int>table;
//	vector<int>ret;
//	rec_501(table,root);
//	int times=0;
//	for(auto e:table){
//		times=max(times,e.second);
//	}
//	for(auto e:table){
//		if(times==e.second){
//			ret.push_back (e.first);
//		}
//	}
//	return ret;
//}


//双指针遍历二叉树，遇到二叉搜索树就像中序遍历是升序序列
void rec_501(TreeNode*cur,TreeNode*&pre,int& max_count,int& count,vector<int>&ret){
	if(!cur)return;
	//left
	rec_501(cur->left,pre,max_count,count,ret);
	//mid
	if(!pre||pre->val!=cur->val){
		pre=cur;
		count=1;
	}
	else if(pre->val==cur->val){
		++count;
	}
	if(count==max_count){
		ret.push_back (cur->val);
	}else if(count>max_count){
		ret.clear();
		ret.push_back (cur->val);
		max_count=count;
	}
	//right
	rec_501(cur->right,pre,max_count,count,ret);
}
vector<int> findMode(TreeNode* root) {
	vector<int>ret;
	int max_count=0;
	int count=0;
	TreeNode*pre= nullptr;
	rec_501(root, pre,max_count,count,ret);
	return ret;
}
TreeNode* rec_236(TreeNode*root,TreeNode*p,TreeNode*q,TreeNode*&ret){
	if(!root||ret)return nullptr;
	auto l=rec_236(root->left,p,q,ret);
	auto r=rec_236(root->right,p,q,ret);
	if(ret)return nullptr;
	if(root->val==p->val||root->val==q->val){
		if(l||r) {
			ret=root;
			return nullptr;
		}
		return root;
	}
	if(l&&r){
		ret=root;
	}
	if(l||r)return root;
	return nullptr;
	
}
TreeNode* lowestCommonAncestor_nonBST(TreeNode* root, TreeNode* p, TreeNode* q) {
	TreeNode*ret= nullptr;
	rec_236 (root,p,q,ret);
	return ret;
}
void rec_235(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode*&ret){
	if(root->val>q->val&&root->val>p->val){
		rec_235(root->left,p,q,ret);
	}else if(root->val<q->val&&root->val<p->val){
		rec_235(root->right,p,q,ret);
	}
	else ret=root;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	TreeNode*ret= nullptr;
	rec_235(root,p,q,ret);
	return ret;
}
string convertToTitle(int columnNumber) {
	string ret;
	int i=0;
	while(columnNumber>0){
		auto tmp=columnNumber%26;
		if(tmp!=0) {
			ret += char ('A' - 1 + tmp);
			columnNumber/=26;
		}
		else{
			columnNumber/=26;
			--columnNumber;
			ret+='Z'
				;}
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
void rec_701(TreeNode*root,int val){
	if(root->val<val){
		if(!root->right){
			root->right=new TreeNode(val);
			return;
		}
		rec_701(root->right,val);
	}else if(root->val>val){
		if(!root->left){
			root->left=new TreeNode(val);
			return;
		}
		rec_701(root->left,val);
	}
}
TreeNode* insertIntoBST(TreeNode* root, int val) {
	if(!root){
		root=new TreeNode(val);
		return root;
	}
	rec_701(root,val);
	return root;
}
class AClass{
public:
	int x_;
	int y_;
	string* p_;
	//对于内置类型，c++不做初始化
	//对于自定义类型，c++自动调用默认初始化（无参）
	
	//什么时候需要写构造函数：一般都需要写
	// 什么时候可以不写构造：1.只有内置类型，且所有内置类型成员都有缺省值2.之后自定义类型，且每个类的默认构造都符合预期
	//内置类型成员会调用浅拷贝，自定义类型成员会调用自己的拷贝构造函数
	AClass(string p="",int x=0,int y=0):
		x_(x),
		y_(y)
		{
			p_=new string(p) ;
		};
	
	//什么时候需要写拷贝构造：需要深拷贝的时候（类中有动态申请的内存）
	//否则编译器将默认进行值拷贝/浅拷贝
	AClass(const AClass& another){//***拷贝构造函数只能传递引用，否则会造成无限递归***
		x_=another.x_;
		y_=another.y_;
		p_=new string(*(another.p_));
		//p_=another.p_;//错误的，浅拷贝会导致1.两次释放内存2.修改一个另一个也会变
	}
	
	
	//什么时候需要写析构：类动态申请内存时
	//不需要：1.类型全都是内置类型2.类中的自定义类型都实现了析构
	~AClass(){
		cout<<"destruction\n";
		delete p_;
	}
	bool operator==(const AClass& another)const{
		return x_==another.x_&&y_==another.y_&&(*p_)==*(another.p_);
	}
};
class Date {

	int yy_=1;
	int mm_=1;
	int dd_=1;
public:

// 获取某年某月的天数
	
	int GetMonthDay (int year, int month){
	if(month==2&&(year%400==0||year%4==0&&year%100==0))return 29;
	static const int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	return months[month-1];
}

	// 全缺省的构造函数
	
	Date (int year = 1900, int month = 1, int day = 1):
		yy_(year),
		mm_(month),
		dd_(day){};
	// 拷贝构造函数

// d2(d1)
	
	Date (const Date &d):
		yy_(d.yy_),
		mm_(d.mm_),
		dd_(d.dd_){};
	// 赋值运算符重载

// d2 = d3 -> d2.operator=(&d2, d3)
	Date &operator= (const Date &d){
		yy_=d.yy_;
		mm_=d.mm_;
		dd_=d.dd_;
		return *this;
	}
	// 析构函数
	
	~Date ()=default;
	//日期+=天数
	
	Date &operator+= (int day){
		dd_+=day;
		while(dd_> GetMonthDay (yy_,mm_)){
			dd_-= GetMonthDay (yy_,mm_);
			if(++mm_>12){
				++yy_;
				mm_=1;
			}
		}
		return *this;
	}
	// 日期+天数
	
	Date operator+ (int day){
		Date tmp(*this);
		tmp+=day;
		return tmp;
	}
	// 日期-天数
	
	Date& operator-= (int day){
		dd_-=day;
		if(dd_>0)return *this;
		while(dd_<0){
			if(!(--mm_)){
				--yy_;
				mm_=12;
			}
			dd_+= GetMonthDay (yy_,mm_);
		}
		return *this;
	}
	// 日期-=天数
	
	Date operator- (int day){
		Date tmp(*this);
		tmp-=day;
		return tmp;
	}
	// 前置++
	
	Date &operator++ (){
		if(++dd_> GetMonthDay (yy_,mm_)){
			dd_=1;
			if(++mm_>12){
				++yy_;mm_=1;
			}
		}
		return *this;
	}
	// 后置++
	
	Date operator++ (int){
		Date tmp(*this);
		(*this)+=1;
		return tmp;
	}
	// 后置--
	
	Date operator-- (int){
		Date tmp(*this);
		if(!(--dd_)){
			if(!--mm_){
				mm_=12;
				--yy_;
			}
			dd_= GetMonthDay (yy_,mm_);
		}
		return tmp;
	}
	// 前置--
	
	Date &operator-- (){
		if(!(--dd_)){
			if(!--mm_){
				mm_=12;
				--yy_;
			}
			dd_= GetMonthDay (yy_,mm_);
		}
		return *this;
	}
	
	bool operator>(const Date& d) const{
		if(yy_>=d.yy_&&mm_>=d.mm_&&dd_>d.dd_){
			return true;
		}
		return false;
	}
	
	bool operator==(const Date& d) const{
		return (yy_==d.yy_&&mm_==d.mm_&&dd_==d.dd_);
	}
	// >=运算符重载
	bool operator >= (const Date& d)const{
		return *this>d||*this==d;
	}
	// <运算符重载
	bool operator< (const Date& d)const{
		return !(*this>=d);
	}
	// <=运算符重载
	bool operator<= (const Date& d)const{
		return (*this<d)||(*this==d);
	}
	// !=运算符重载
	bool operator != (const Date& d)const{
		return !(*this==d);
	}
	// 日期-日期 返回天数
	int operator-(const Date& d){
		int ret=0;
		Date tmp(d);
		if(*this>d){
			
			while(*this>tmp){
				++ret;++tmp;
			}
		}else{
			while(*this<tmp){
				--ret;--tmp;
			}
		}
		return ret;
	}
};

TreeNode* deleteNode(TreeNode* root, int key) {
	auto p=root;
	TreeNode* pre= nullptr;
	TreeNode*newroot= nullptr;
	while(p){
		if(p->val>key){
			pre=p;
			p=p->left;
		}else if(p->val==key){
			break;
		}else{
			pre=p;
			p=p->right;
		}
	}
	if(p==root){
		newroot =new TreeNode(INT_MAX,root, nullptr);
		pre=newroot;
	}
	if(!p)return root;
	if(!p->left&&!p->right){
		delete p;
		if(pre->val>key)pre->left= nullptr;
		else pre->right= nullptr;
	}
	else if(p->left&&!p->right){
		if(pre->val>key)pre->left=p->left;
		else pre->right=p->left;
		delete p;
	}else if(p->right&&!p->left){
		if(pre->val>key)pre->left=p->right;
		else pre->right=p->right;
		delete p;
	}else{
		//下面注释掉的可以通过题目，但是我自己写的逻辑也没错但是过不了
//		if(pre->val>key){
//			pre->left=p->right;
//		}
//		else pre->right=p->right;
//		auto pm=p->right;
//		while(pm->left)pm=pm->left;
//		pm->left=p->left;
//		delete p;
		auto pm=p->right;
		while(pm->left){
			pre=pm;
			pm=pm->left;
		}
		swap(p->val,pm->val);
		if(pm!=p->right)pre->left= pm->right;
		else p->right=pm->right;
		delete pm;
	}
	if(!newroot)return root;
	auto ret=newroot->left;
	delete newroot;
	return ret;
}
TreeNode* rec_669(TreeNode*root,int low,int high){
	if(!root)return nullptr;
	if(root->val==low){
		root->left= nullptr;
		root->right= rec_669 (root->right,low, high);
	}else if(root->val<low){
		auto p=root;
		while(p&&p->val<low)p=p->right;
		return rec_669(p,low,high);
	}else if(root->val==high){
		root->right= nullptr;
		root->left=rec_669(root->left,low,high);
	}else if(root->val>high){
		auto p=root;
		while(p&&p->val>high)p=p->left;
		return rec_669(p,low,high);
	}else{
		root->left=rec_669(root->left,low,high);
		root->right=rec_669(root->right,low,high);
	}return root;
}
TreeNode* trimBST(TreeNode* root, int low, int high) {
	return rec_669(root,low,high);
}
TreeNode* rec_108(vector<int>&nums,int l,int r){
	if(l>r)return nullptr;
	int m=(l+r)/2;
	auto root=new TreeNode(nums[m]);
	root->left=rec_108(nums,l,m-1);
	root->right=rec_108(nums,m+1,r);
	return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
	return rec_108(nums,0,nums.size()-1);
}
void rec_538_1(TreeNode*root,vector<int>&traversal){
	if(!root)return;
	rec_538_1(root->left,traversal);
	traversal.push_back (root->val);
	rec_538_1(root->right,traversal);
}
void rec_538_2(TreeNode*root,const vector<int>&traversal,int& idx){
	if(!root||idx==traversal.size())return;
	rec_538_2(root->left,traversal,idx);
	root->val=traversal[idx];
	++idx;
	rec_538_2(root->right,traversal,idx);
}
TreeNode* convertBST(TreeNode* root) {
	vector<int>traversal;
	rec_538_1(root,traversal);
	for(int i=traversal.size()-2;i>=0;--i){
		traversal[i]+=traversal[i+1];
	}
	int idx=0;
	rec_538_2(root,traversal,idx);
	return root;
}
//int main () {
//	Date d1=(2023,4,27);
//
//	return 0;
//}