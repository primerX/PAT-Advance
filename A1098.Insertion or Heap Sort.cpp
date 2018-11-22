#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;
// 原始数组，原始数组备份，改变后的数组 
int origin[N], tempOri[N], changed[N];
int n;	// 数组个数

// 判断两个数组是否相等 
bool isSame(int A[], int B[])
{
	for(int i = 1; i <= n; i++){
		if(A[i] != B[i]) return false;
	}
	return true;
}

// 输出数组
void showArray(int A[])
{
	for(int i = 1; i <= n; i++){
		printf("%d", A[i]);
		if(i < n) printf(" ");
	}
	printf(" ");
}

// 判断是否是插入排序 
bool insertSort()
{
	bool flag = false;
	for(int i = 2; i <= n; i++){
		if(i != 2 && isSame(tempOri, changed)){
			//中间步骤与目标相同，且不是初始序列
			flag = true; 
		}
		// 插入部分直接用 sort 代替
		sort(tempOri + 1, tempOri + i + 1);
		if(flag == true){
			return true;
		}
	}
	return false;
}

// 对 heap 数组在[low, high] 进行调整
// 其中 low 表示欲调整结点的数组下标，high 为堆最后一个元素的数组下标
void downAdjust(int low, int high)
{
	int i = low, j = i * 2;
	while(j <= high)
	{
		// 如果右孩子存在，且右孩子结点的值大于左孩子结点的值
		if(j + 1 <= high && tempOri[j+1] > tempOri[j]){
			j = j + 1;		// 让 j 存储右孩子结点的下标 
		}
		// 如果孩子结点中的权值比父节点大 
		if(tempOri[j] > tempOri[i]){
			swap(tempOri[j], tempOri[i]);
			i = j;
			j = i * 2;
		}else{
			break;		// 孩子结点的权值比父亲的小，调整结束 
		}
	}
}

// 堆排序 
void HeapSort()
{
	bool flag = false;
	for(int i = n/2; i >= 1; i--){
		downAdjust(i, n);	// 建立堆 
	}
	for(int i = n; i >= 1; i--){
		if(i != n && isSame(tempOri, changed)){
			// 中间步骤与目标步骤相同，且不是初始序列
			flag = true; 
		}
		swap(tempOri[i], tempOri[1]);	// 交换heap[i] 与堆顶
		downAdjust(1, i-1);		// 调整堆顶
		if(false == true){
			showArray(tempOri);
			return;
		} 
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &origin[i]);	// 起始数组
		tempOri[i] = origin[i];		// tempOri 为初始数组备份 
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &changed[i]);	// 目标数组 
	}
	if(insertSort()){
		printf("Insertion Sort\n");
		showArray(tempOri);
	}else{		// 是堆排序 
		printf("Heap Sort\n");
		for(int i = 1; i <= n; i++){
			tempOri[i] = origin[i];		// 还原 tempOri 数组 
		}
		HeapSort();		// 进行堆排序 
	}
	return 0;
}
