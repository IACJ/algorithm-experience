#include<iostream>
#include<math.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

const bool DEBUG = true;                    // 是否打印出动态规划过程矩阵
const bool FILE_INPUT = false;            // 是否文件输入数据（否则手动输入数据）
struct Goods
{
	double value;
	int weight;
};

// 手动 INPUT 数据
void  manual_input(int&n,int&m, Goods*& goods) {
	cout << "请输入物品数量n，背包容量m" << endl;
	cin >> n >> m;
	goods = new Goods[n + 1];
	cout << "请输入每个物品的重量、价值" << endl;
	for (int i = 1; i <= n; i++) {
		cin >> goods[i].weight >> goods[i].value;
	}
}

// 文件 INPUT 数据
void  file_input(int&n, int&m, Goods*& goods) {
	cout << "请确认文件名( ./input.txt  )" << endl;
	ifstream fin("./input.txt");
	if (!fin) {
		cout << endl << "文件读取失败！！！ " << endl << endl;
		system("pause");
		exit(21);
	}else {
		cout << "读取成功" << endl;
	}
	fin >> n >> m;
	goods = new Goods[n + 1];
	for (int i = 1; i <= n; i++) {
		fin >> goods[i].weight >> goods[i].value;
	}
}

///____main____
int main() {
	// 输入数据
	int n, m;
	Goods* goods;
	if (FILE_INPUT) {
		file_input(n, m, goods);
	}else{
		manual_input(n, m, goods);
	}

	// 初始化动规数组
	double** DP = new double*[n+1];
	for (int i = 0; i <= n; i++){
		DP[i] = new double[m+1];
		for (int j = 0; j <= m; j++) {
			DP[i][j] = 0;
		}
	}

	// 进行DP
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			DP[i][j] = fmax(DP[i][j - 1], DP[i - 1][j]);
			if (j >= goods[i].weight) {
				DP[i][j] = fmax(DP[i][j], DP[i - 1][j- goods[i].weight] + goods[i].value);
			}
		}
	}
	
	// DEBUG：输出DP数组
	if (DEBUG) {
		cout << endl << "DP数组如下：" << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << DP[i][j] << '\t';
			}
			cout << endl;
		}
	}

	//输出答案
	cout << endl << "最终结果：" << endl;
	cout << DP[n][m] << endl << endl;
	system("pause");
	return 0;
}