#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

const bool FILE_INPUT = true;            // 是否文件输入数据（否则手动输入数据）
const bool DEBUG = false;                    // 是否打印出过程

long long a[1005];
long long maxHeap[1005];
long long minHeap[1005];


long long  max(long long a, long long b) {
	return a < b;
}
long long  min(long long a, long long b) {
	return a > b;
}

int main() {
	int n;
	if (FILE_INPUT) {

		//打开文件
		ifstream fin("./test_data/input.txt");
		if (!fin) {
			cout << endl << "文件读取失败！！！ " << endl << endl;
			system("pause");
			exit(1);
		}

		while (fin >> n) {
			if (n == 0) {
				exit(0);
			}
			// 输入
			for (int i = 0; i < n; i++) {
				fin >> a[i];
			}
			// 计算最大代价
			for (int i = 0; i < n; i++){
				maxHeap[i] = a[i];
			}
			make_heap(maxHeap, maxHeap + n,max);
			long long ansMax = 0;
			int i = n ;
			while (i > 1) {
				pop_heap(maxHeap, maxHeap + i--,max);
				pop_heap(maxHeap, maxHeap + i--,max);
				ansMax += maxHeap[i] + maxHeap[i + 1]-1;
				maxHeap[i] = maxHeap[i] + maxHeap[i + 1];
				push_heap(maxHeap, maxHeap + (++i),max);
			}
			// 计算最小代价
			for (int i = 0; i < n; i++) {
				minHeap[i] = a[i];
			}
			make_heap(minHeap, minHeap + n, min);
			long long ansMin = 0;
			i = n;
			while (i > 1) {
				pop_heap(minHeap, minHeap + i--, min);
				pop_heap(minHeap, minHeap + i--, min);
				ansMin += minHeap[i] + minHeap[i + 1] - 1;
				minHeap[i] = minHeap[i] + minHeap[i + 1];
				push_heap(minHeap, minHeap + (++i), min);
			}
			// 输出答案
			cout << ansMax <<' ' <<ansMin<< endl;
		}
	}
}