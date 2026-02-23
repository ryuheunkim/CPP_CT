#include <iostream>
#include <vector>

using namespace std;

// 1. 간선 정보를 저장하기 위한 구조체 정의
struct Edge {
    int endNode; // 목적지 노드
    int value;   // 가중치 (비용, 거리 등)
};

int main() {
    // 2. 2차원 벡터 선언 (인접 리스트)
    // A[i]는 'i번 노드에서 출발하는 간선들의 리스트'를 담는 벡터가 됩니다.
    vector<vector<Edge>> A;

    int N, E; // N: 노드의 개수, E: 에지(간선)의 개수
    cin >> N >> E;

    // 3. 벡터 공간 확보 (N+1을 하는 이유)
    // 노드 번호가 1번부터 시작하는 경우가 많으므로, 
    // 인덱스 편의를 위해 N+1 크기로 리사이징하여 A[1]~A[N]을 사용합니다.
    A.resize(N + 1);

    // 4. 에지 데이터 입력 및 저장
    for (int i = 0; i < E; i++) {
        int s, e, v; // s: 시작 노드, e: 도착 노드, v: 가중치
        cin >> s >> e >> v;

        // A[s]라는 벡터(s번 노드의 리스트)에 새로운 간선 정보를 추가합니다.
        // {e, v}는 Edge 구조체의 생성자 형태로 데이터가 들어갑니다.
        A[s].push_back({ e, v });
    }

    // 5. 특정 노드(여기서는 1번 노드)에서 출발하는 데이터 가져오기
    // A[1]에 저장된 모든 Edge 객체들을 하나씩 꺼내어 순회합니다.
    for (Edge edge : A[1]) {
        int next = edge.endNode; // 1번 노드와 연결된 다음 노드
        int value = edge.value;   // 그 간선의 가중치

        cout << "도착노드: " << next << ", 가중치: " << value << '\n';
    }

    return 0;
}