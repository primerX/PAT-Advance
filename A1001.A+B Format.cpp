#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	string sum = to_string(a + b);
	for(int i = 0; i < sum.length(); i++){
		cout << sum[i];
		if(sum[i] == '-') continue;		//如果为负数
		if((i+1) % 3 == sum.length() % 3 && i != sum.length() -1){
			cout << ',';
		} 
	}
	return 0;
} 
