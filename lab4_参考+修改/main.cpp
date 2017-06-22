#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

const long maxorder = 35; // 最大订票量
const long maxsta = 35; // 最大车站数，包括首站
long cap, sta, order; // 分别表示火车的容量，车站数(不包括首站)和订票量
long down[maxsta]; // 第i站下车的人数，包括首站
long ans; // 最终结果

struct ticket
{
	long start, des, pass;
	bool operator < (const ticket & p) const {
		if (start == p.start) {
			return des < p.des;
		}
		return start < p.start;
	} // 按此规则排序
} ord[maxorder];

void dfs(long ord_num, long passe, long money);

int main()
{
		//打开文件
		ifstream fin("./test_data/input.txt");
		if (!fin) {
			cout << endl << "文件读取失败！！！ " << endl << endl;
			system("pause");
			exit(1);
		}
		
	//ios::sync_with_stdio(false);
		while (fin >> cap >> sta >> order && (cap || sta || order)) {
			for (int i = 0; i < order; i++) {
				fin >> ord[i].start >> ord[i].des >> ord[i].pass; // 订票信息
		}
		sort(ord, ord + order);

		ans = 0;
		for (int i = 0; i <= sta; i++){
			down[i] = 0;
		}
		dfs(0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}

void dfs(long ord_num, long passe, long money){
	// 订票量全部检查完毕
	if (ord_num == order) {
		ans = max(ans, money);
		return;
	}
	if (ord_num > 0) {
		for (int i = ord[ord_num - 1].start + 1; i <= ord[ord_num].start; ++i) {
			passe -= down[i]; // 减去下车人数，计算当前车内人数
		}
	}
	// 检查是否超载
	if (passe + ord[ord_num].pass <= cap) {
		down[ord[ord_num].des] += ord[ord_num].pass; // 不超载，接受订票
		dfs(ord_num + 1, passe + ord[ord_num].pass, money + ord[ord_num].pass*(ord[ord_num].des - ord[ord_num].start));
		down[ord[ord_num].des] -= ord[ord_num].pass; // 恢复现场，回溯
	}
	dfs(ord_num + 1, passe, money); // 不接受订票
}