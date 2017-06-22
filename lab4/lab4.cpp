#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

struct Ticket {
	long from;
	long to;
	long num;
	bool operator < (const Ticket & p) const {
		if ( from == p.from) {
			return to < p.to;
		}
		return from < p.from;
	} 
}ticket[35];

long down[35];
long ans;
int n, m, t;

void DFS(int i, long  nowPass, long  nowAns);

int main() {
		//���ļ�
		ifstream fin("./test_data/input.txt");
		if (!fin) {
			cout << endl << "�ļ���ȡʧ�ܣ����� " << endl << endl;
			system("pause");
			exit(1);
		}

		while (fin >> n >> m >> t) {
			if (n == 0 && m==0 && t==0) {
				exit(1);
			}
			// ����
			for (int i = 0; i < t; i++) {
				fin >> ticket[i].from >> ticket[i].to >> ticket[i].num;
			}
			sort(ticket, ticket + t);
			//DFS
			ans = 0;
			for (int i = 0; i <= m; i++){
				down[i] = 0;
			}
			DFS(0, 0, 0);
			//�����
			cout << ans << endl;
		}
}

void DFS(int ord_num, long nowPass, long nowAns) {
	//��������
	if (ord_num == t) {
		if (ans < nowAns){
			ans = nowAns;
		}
		return;
	}
	if (ord_num > 0) {
		for (int i = ticket[ord_num - 1].from + 1; i <= ticket[ord_num].from; i++) {
			nowPass -= down[i];
		}
	}
	if (nowPass + ticket[ord_num].num <= n) {
		down[ticket[ord_num].to] += ticket[ord_num].num;
		DFS(ord_num + 1, nowPass + ticket[ord_num].num, nowAns + (ticket[ord_num].to - ticket[ord_num].from)*ticket[ord_num].num);
		down[ticket[ord_num].to] -= ticket[ord_num].num;
	}
	// �ղ�������
	DFS(ord_num + 1, nowPass, nowAns);
}