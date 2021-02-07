#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int graph[26][26];
int cnt = 0; int num = 0;
vector <int> numOfhouse;
int dfs(int i, int j, int n, int numb) {
	//���� �ۿ� ��� ��� �Լ� �ٷ� ����
	if (i <= -1 || j <= -1 || i >= n || j >= n)
		return 0;
	//�湮 ���� ���, �����¿� ����
	if (graph[i][j] == 1) {
		graph[i][j] = 0;//�湮üũ
		dfs(i - 1, j, n, numb);
		dfs(i + 1, j, n, numb);
		dfs(i, j + 1, n, numb);
		dfs(i, j - 1, n, numb);
		num++;//����� �� ��������� ���� ����
		return 1;//����� ��� ��� �湮 ��
	}

	return 0;//�湮 �� ���
}

int main() {
	int n;
	cin >> n;
	//2���� �迭 �׷��� �����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	//��� ��忡 ���� dfs
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//cout << graph[i][j] << " ";
			if (dfs(i, j, n, num)) {
				cnt++;
				numOfhouse.push_back(num);//vector,���� ���� �̿��ؼ� �� ���� ���� �� ���ϱ�
				num = 0;//���������� �ٽ� 0����
			}
		}
		//cout << endl << endl;
	}

	//�������� sort
	sort(numOfhouse.begin(), numOfhouse.end());

	//���
	cout << cnt << endl;
	for (auto p = numOfhouse.begin(); p != numOfhouse.end(); p++) {
		cout << *p << endl;
	}

}