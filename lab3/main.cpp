#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

const bool FILE_INPUT = true;            // �Ƿ��ļ��������ݣ������ֶ��������ݣ�
const bool DEBUG = false;                    // �Ƿ��ӡ������

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

		//���ļ�
		ifstream fin("./test_data/input.txt");
		if (!fin) {
			cout << endl << "�ļ���ȡʧ�ܣ����� " << endl << endl;
			system("pause");
			exit(1);
		}

		while (fin >> n) {
			if (n == 0) {
				exit(0);
			}
			// ����
			for (int i = 0; i < n; i++) {
				fin >> a[i];
			}
			// ����������
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
			// ������С����
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
			// �����
			cout << ansMax <<' ' <<ansMin<< endl;
		}
	}
}