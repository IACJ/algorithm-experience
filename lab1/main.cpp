#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

const bool FILE_INPUT = true;            // 是否文件输入数据（否则手动输入数据）
const bool DEBUG = false;                    // 是否打印出过程

struct Coordinate
{
	int x;
	int y;
}coordinate[10000];

bool comp(const Coordinate& c1, const Coordinate& c2) {
	return c1.y < c2.y;
}

int main() {
	// 输入
	int n;
	if (!FILE_INPUT) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> coordinate[i].x >> coordinate[i].y;
		}
	}else {
		ifstream fin("./test_data/input.txt");
		if (!fin) {
			cout << endl << "文件读取失败！！！ " << endl << endl;
			system("pause");
			exit(21);
		}
		fin >> n;
		for (int i = 0; i < n; i++) {
			fin >> coordinate[i].x >> coordinate[i].y;
		}
	}

	//快排、计算
	sort(coordinate, coordinate + n, comp);
	int midY = coordinate[n / 2].y;
	long long ans = 0;
	for (int i = 0; i < n; i++){
		ans += abs(coordinate[i].y - midY);
	}

	//输出中间过程
	if (DEBUG){
		for (int i = 0; i < n; i++) {
			cout << coordinate[i].x << '\t' << coordinate[i].y << endl;
		}
	}

	//输出答案
	cout << ans << endl;
}