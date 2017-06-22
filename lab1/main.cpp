#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

const bool FILE_INPUT = true;            // �Ƿ��ļ��������ݣ������ֶ��������ݣ�
const bool DEBUG = false;                    // �Ƿ��ӡ������

struct Coordinate
{
	int x;
	int y;
}coordinate[10000];

bool comp(const Coordinate& c1, const Coordinate& c2) {
	return c1.y < c2.y;
}

int main() {
	// ����
	int n;
	if (!FILE_INPUT) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> coordinate[i].x >> coordinate[i].y;
		}
	}else {
		ifstream fin("./test_data/input.txt");
		if (!fin) {
			cout << endl << "�ļ���ȡʧ�ܣ����� " << endl << endl;
			system("pause");
			exit(21);
		}
		fin >> n;
		for (int i = 0; i < n; i++) {
			fin >> coordinate[i].x >> coordinate[i].y;
		}
	}

	//���š�����
	sort(coordinate, coordinate + n, comp);
	int midY = coordinate[n / 2].y;
	long long ans = 0;
	for (int i = 0; i < n; i++){
		ans += abs(coordinate[i].y - midY);
	}

	//����м����
	if (DEBUG){
		for (int i = 0; i < n; i++) {
			cout << coordinate[i].x << '\t' << coordinate[i].y << endl;
		}
	}

	//�����
	cout << ans << endl;
}