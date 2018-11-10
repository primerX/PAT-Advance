#include<iostream>
using namespace std;

int main()
{
	string s;
	// words数组用来储存数字对应的单词 
	string words[10] = {"zero", "one", "two", "three", "four",
						"five", "six", "seven", "eight", "nine"};
	cin >> s;
	int sum = 0;
	for(int i = 0; i < s.length(); i++){
		sum += (s[i] - '0');
	}
	string ans = to_string(sum);	//将sum 转换成字符串
	for(int i = 0; i < ans.length(); i++){
		cout << words[ans[i] - '0'];
		if(i < ans.length() - 1) printf(" ");
	} 
	return 0;
}
