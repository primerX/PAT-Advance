#include<iostream>
using namespace std;

int main()
{
	string s;
	// words���������������ֶ�Ӧ�ĵ��� 
	string words[10] = {"zero", "one", "two", "three", "four",
						"five", "six", "seven", "eight", "nine"};
	cin >> s;
	int sum = 0;
	for(int i = 0; i < s.length(); i++){
		sum += (s[i] - '0');
	}
	string ans = to_string(sum);	//��sum ת�����ַ���
	for(int i = 0; i < ans.length(); i++){
		cout << words[ans[i] - '0'];
		if(i < ans.length() - 1) printf(" ");
	} 
	return 0;
}
