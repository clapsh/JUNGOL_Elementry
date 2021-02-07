#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int graph[26][26];
int cnt = 0; int num = 0;
vector <int> numOfhouse;
int dfs(int i, int j, int n, int numb) {
	//범위 밖에 벗어날 경우 함수 바로 종료
	if (i <= -1 || j <= -1 || i >= n || j >= n)
		return 0;
	//방문 안한 노드, 상하좌우 연결
	if (graph[i][j] == 1) {
		graph[i][j] = 0;//방문체크
		dfs(i - 1, j, n, numb);
		dfs(i + 1, j, n, numb);
		dfs(i, j + 1, n, numb);
		dfs(i, j - 1, n, numb);
		num++;//연결된 각 집덩어리마다 개수 세기
		return 1;//연결된 모든 노드 방문 후
	}

	return 0;//방문 한 노드
}

int main() {
	int n;
	cin >> n;
	//2차원 배열 그래프 만들기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	//모든 노드에 대해 dfs
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//cout << graph[i][j] << " ";
			if (dfs(i, j, n, num)) {
				cnt++;
				numOfhouse.push_back(num);//vector,전역 변수 이용해서 집 개수 저장 및 구하기
				num = 0;//전역변수는 다시 0으로
			}
		}
		//cout << endl << endl;
	}

	//오름차순 sort
	sort(numOfhouse.begin(), numOfhouse.end());

	//출력
	cout << cnt << endl;
	for (auto p = numOfhouse.begin(); p != numOfhouse.end(); p++) {
		cout << *p << endl;
	}

}