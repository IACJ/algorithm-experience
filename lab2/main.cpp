#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

const bool FILE_INPUT = true;            // 是否文件输入数据（否则手动输入数据）
const bool DEBUG = false;                    // 是否打印出过程

int a[100];
long long maxDP[101][101];
long long minDP[101][101];
long long sum[101][101];


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
			for (int i = 0; i < n; i++){
				fin >> a[i];
			}
			// Data init
			for (int i = 0; i < n; i++) {
				sum[i][0] = 0;
				for (int j = 1; j <= n; j++) {

					sum[i][j] = sum[i][j-1] + a[(i+j -1)%n];
				}
			}
			// DP init
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j <= n; j++) {
					maxDP[i][j] = 0;
					minDP[i][j] = 65535;
				}
			}
			for (int i = 0; i < n; i++) {
				maxDP[i][1] = 0;
				minDP[i][1] = 0;
			}
			// DP 
			for (int i = 2; i <= n; i++) {
				for (int j = 0; j < n; j++) {
					for (int k = 1; k <= i - 1; k++) {
						maxDP[j][i] = max(maxDP[j][i], maxDP[j][k] + maxDP[(j + k) % n][i - k] + sum[j][i]);
						minDP[j][i] = min(minDP[j][i], minDP[j][k] + minDP[(j + k) % n][i - k] + sum[j][i]);
					}
				}
			}
			if (DEBUG) {
				cout << endl;
				cout << endl << "SUM:" << endl;
				for (int j = 1; j <= n; j++) {
					for (int i = 0; i < n; i++) {
						cout << sum[i][j] << '\t';
					}
					cout << endl;
				}
				cout << endl << "maxDP:" << endl;
				for (int j = 1; j <= n; j++) {
					for (int i = 0; i < n; i++){
						cout << maxDP[i][j] << '\t';
					}
					cout << endl;
				}
				cout << endl << "minDP:" << endl;
				for (int j = 1; j <= n; j++) {
					for (int i = 0; i < n; i++) {
						cout << minDP[i][j] << '\t';
					}
					cout << endl;
				}
				cout << endl;
				cout << "ans:" << endl;
			}
			//计算答案
			long long ansMax = maxDP[0][n];
			for (int i = 1; i < n; i++) {
				ansMax = max(ansMax, maxDP[i][n]);
			}

			long long ansMin = minDP[0][n];
			for (int i = 1; i < n; i++) {
				ansMin = min(ansMin, minDP[i][n]);
			}
			//输出答案 
			cout << ansMin << ' ' << ansMax << endl;
		}
		
	}

}