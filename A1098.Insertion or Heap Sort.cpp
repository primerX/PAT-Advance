#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;
// ԭʼ���飬ԭʼ���鱸�ݣ��ı������� 
int origin[N], tempOri[N], changed[N];
int n;	// �������

// �ж����������Ƿ���� 
bool isSame(int A[], int B[])
{
	for(int i = 1; i <= n; i++){
		if(A[i] != B[i]) return false;
	}
	return true;
}

// �������
void showArray(int A[])
{
	for(int i = 1; i <= n; i++){
		printf("%d", A[i]);
		if(i < n) printf(" ");
	}
	printf(" ");
}

// �ж��Ƿ��ǲ������� 
bool insertSort()
{
	bool flag = false;
	for(int i = 2; i <= n; i++){
		if(i != 2 && isSame(tempOri, changed)){
			//�м䲽����Ŀ����ͬ���Ҳ��ǳ�ʼ����
			flag = true; 
		}
		// ���벿��ֱ���� sort ����
		sort(tempOri + 1, tempOri + i + 1);
		if(flag == true){
			return true;
		}
	}
	return false;
}

// �� heap ������[low, high] ���е���
// ���� low ��ʾ���������������±꣬high Ϊ�����һ��Ԫ�ص������±�
void downAdjust(int low, int high)
{
	int i = low, j = i * 2;
	while(j <= high)
	{
		// ����Һ��Ӵ��ڣ����Һ��ӽ���ֵ�������ӽ���ֵ
		if(j + 1 <= high && tempOri[j+1] > tempOri[j]){
			j = j + 1;		// �� j �洢�Һ��ӽ����±� 
		}
		// ������ӽ���е�Ȩֵ�ȸ��ڵ�� 
		if(tempOri[j] > tempOri[i]){
			swap(tempOri[j], tempOri[i]);
			i = j;
			j = i * 2;
		}else{
			break;		// ���ӽ���Ȩֵ�ȸ��׵�С���������� 
		}
	}
}

// ������ 
void HeapSort()
{
	bool flag = false;
	for(int i = n/2; i >= 1; i--){
		downAdjust(i, n);	// ������ 
	}
	for(int i = n; i >= 1; i--){
		if(i != n && isSame(tempOri, changed)){
			// �м䲽����Ŀ�경����ͬ���Ҳ��ǳ�ʼ����
			flag = true; 
		}
		swap(tempOri[i], tempOri[1]);	// ����heap[i] ��Ѷ�
		downAdjust(1, i-1);		// �����Ѷ�
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
		scanf("%d", &origin[i]);	// ��ʼ����
		tempOri[i] = origin[i];		// tempOri Ϊ��ʼ���鱸�� 
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &changed[i]);	// Ŀ������ 
	}
	if(insertSort()){
		printf("Insertion Sort\n");
		showArray(tempOri);
	}else{		// �Ƕ����� 
		printf("Heap Sort\n");
		for(int i = 1; i <= n; i++){
			tempOri[i] = origin[i];		// ��ԭ tempOri ���� 
		}
		HeapSort();		// ���ж����� 
	}
	return 0;
}
