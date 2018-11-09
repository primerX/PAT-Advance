#include<iostream>
using namespace std;

const int MAXN = 1010;

int main()
{
	int k, index;
	double value;
	double ans[MAXN];
	fill(ans, ans + MAXN, 0);	//初始全部设置为 0 
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		scanf("%d %lf", &index, &value);
		ans[index] = value;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		scanf("%d %lf", &index, &value);
		ans[index] += value;
	}
	int cnt = 0;
	for(int i = 0; i < MAXN; i++){
		if(ans[i] != 0) cnt++;
	}
	printf("%d", cnt);
	for(int i = MAXN-1; i >= 0; i--){
		if(ans[i] != 0){
			printf(" %d %.1lf", i, ans[i]);
		}
	}
	return 0;
}
