#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	int m, n, k;
	cin >> m >> n >> k;
	for(int i = 0; i < k; i++){
		bool flag = false;
		stack<int> st;
		vector<int> v(n+1);
		for(int j = 1; j <= n; j++){
			cin >> v[j];
		}
		int current = 1;
		for(int j = 1; j <= n; j++){
			st.push(j);
			if(st.size() > m) break;
			while(!st.empty() && st.top() == v[current]){
				st.pop();
				current++;
			}
		}
		if(current == n+1) flag = true;
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
