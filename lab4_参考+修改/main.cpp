#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

const long maxorder = 35; // ���Ʊ��
const long maxsta = 35; // ���վ����������վ
long cap, sta, order; // �ֱ��ʾ�𳵵���������վ��(��������վ)�Ͷ�Ʊ��
long down[maxsta]; // ��iվ�³���������������վ
long ans; // ���ս��

struct ticket
{
	long start, des, pass;
	bool operator < (const ticket & p) const {
		if (start == p.start) {
			return des < p.des;
		}
		return start < p.start;
	} // ���˹�������
} ord[maxorder];

void dfs(long ord_num, long passe, long money);

int main()
{
		//���ļ�
		ifstream fin("./test_data/input.txt");
		if (!fin) {
			cout << endl << "�ļ���ȡʧ�ܣ����� " << endl << endl;
			system("pause");
			exit(1);
		}
		
	//ios::sync_with_stdio(false);
		while (fin >> cap >> sta >> order && (cap || sta || order)) {
			for (int i = 0; i < order; i++) {
				fin >> ord[i].start >> ord[i].des >> ord[i].pass; // ��Ʊ��Ϣ
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
	// ��Ʊ��ȫ��������
	if (ord_num == order) {
		ans = max(ans, money);
		return;
	}
	if (ord_num > 0) {
		for (int i = ord[ord_num - 1].start + 1; i <= ord[ord_num].start; ++i) {
			passe -= down[i]; // ��ȥ�³����������㵱ǰ��������
		}
	}
	// ����Ƿ���
	if (passe + ord[ord_num].pass <= cap) {
		down[ord[ord_num].des] += ord[ord_num].pass; // �����أ����ܶ�Ʊ
		dfs(ord_num + 1, passe + ord[ord_num].pass, money + ord[ord_num].pass*(ord[ord_num].des - ord[ord_num].start));
		down[ord[ord_num].des] -= ord[ord_num].pass; // �ָ��ֳ�������
	}
	dfs(ord_num + 1, passe, money); // �����ܶ�Ʊ
}