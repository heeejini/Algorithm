#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
// breath first search 
// 너비 우선 탐색 , 최적의 해를 구할 때 사용 , 최단거리 구할 때, 
// 경로의 특징을 저장해야되는 문제는 dfs 사용 

void bfs(int start, vector<int> graph[], bool check[]) {
	queue<int> q;

	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		printf("%d ", tmp);
		for (int i = 0; i < graph[tmp].size(); i++) {

			// 방문하지 않았다면
			if (check[graph[tmp][i]] == false) {
				// 큐에 넣어주고 방문했음을 표시한다.
				q.push(graph[tmp][i]);
				check[graph[tmp][i]] = true;
			}
		}
	}

}

// dfs에 들어오면 '방문'한거로 판단
// 해당 위치에 check true로 해준다.
void dfs(int start, vector<int> graph[], bool check[]) {
	check[start] = true;
	printf("%d ", start);

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		// 방문하지 않았다면
		if (check[next] == false) {
			// 재귀함수를 호출한다.
			dfs(next, graph, check);
		}
	}
}

int main() {

	int n, m, start;
	cin >> n >> m >> start;

	vector<int> graphDFS[1001];
	vector<int> graphBFS[1001];
	// Visual Studio의 경우
	/* 변수를 통해서 배열을 동적으로 생성할 때
	vector<int> * graph = new vector<int>[n+1];
	*/
	bool checkDFS[1001];
	bool checkBFS[1001];

	fill(checkDFS, checkDFS + n + 1, false);
	fill(checkBFS, checkBFS + n + 1, false);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graphBFS[u].push_back(v);
		graphBFS[v].push_back(u);

		graphDFS[u].push_back(v);
		graphDFS[v].push_back(u);
	}

	// Sorting은 왜 한거지?
	// 나중에 하나의 정점에서 다음을 탐색할 때 node 값에 순차적으로 접근해야하기 때문
	for (int i = 1; i <= n; i++) {
		sort(graphBFS[i].begin(), graphBFS[i].end());
		sort(graphDFS[i].begin(), graphDFS[i].end());

	}
	//dfs
	dfs(start, graphDFS, checkDFS);
	cout << "\n";
	//bfs
	bfs(start, graphBFS, checkBFS);
	cout << "\n";

	return 0;
}
