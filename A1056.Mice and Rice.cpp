#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int MAXN = 1010;

struct Mouse{
	int order, weight;		//排名,重量 
}mouse[MAXN];

int main()
{
	int np, ng;
	cin >> np >> ng;
	for(int i = 0; i < np; i++){	//每只老鼠的重量 
		cin >> mouse[i].weight; 
	}
	int order;		//顺序
	queue<int> q;	//队列 q 用来储存比赛顺序 
	for(int i = 0; i < np; i++){
		cin >> order;
		q.push(order); 
	}
	int temp = np;
	int group;		//每一组的个数
	while(q.size() != 1)
	{
		if(temp % ng == 0) group = temp / ng;
		else group = temp / ng + 1;
		for(int i = 0; i < group; i++){		//枚举每一组 
			int k = q.front(); 				// k 用来存放该组老鼠中质量最大的标号 
			for(int j = 0; j < ng; j++){	//枚举每一组的参赛者 
				// 在最后一组老鼠数不足 ng 时起作用，退出循环
				if(i * ng + j >= temp) break; 
				int first = q.front();
				mouse[first].order = group + 1;
				q.pop();
				if(mouse[first].weight > mouse[k].weight){
					k = first;
				}
			}
			q.push(k);
		}
		temp = group;		//一轮比赛结束后，更新总比赛人数	
	}
	int first = q.front();
	mouse[first].order = 1;
	for(int i = 0; i < np; i++){
		printf("%d", mouse[i].order);
		if(i < np-1) printf(" ");
	}
	return 0;
}
