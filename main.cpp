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
int main () {
	string s;
	getline(cin,s);
	cout<<reverseWords(s);
	return 0;
}