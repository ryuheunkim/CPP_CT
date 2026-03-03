// 백준 1377번 https://www.acmicpc.net/problem/1377

/* 풀이
파악
    10^6 이므로, 영식이의 버블 정렬 프로그램과 같이 구현하면 시간 초과함
    목적은 정답은 출력한다 인데, 그러기 위해선 영식이의 코드를 살펴볼 필요가 있다.
    정상적으로 작동한다면 1, 2, 3, 5, 10 이 출력돼야 하는데
    바꾸지 않아도 될 때에만, 값을 출력하게 된다.
    버블 정렬을 그대로 구현하면 시간초과 10^12 이 걸리게 됨
    그저 지나간 알고리즘들을 순서대로 돌이켜보는 건 도움되지 않음
구상

*/

/* 정답
구상 : 이중 for문에서 swap이 일어나지 않은 것은 정렬이 끝났다는 의미,
하지만 이중 for문을 위 문제에서 돌리면 시간이 초과함
==데이터의 정렬전 index와 정렬 후 index를 비교해, 왼쪽으로 가장 많이 이동한 값이 swap이 일어나지 않는 값==
    - 데이터 정렬은 sort로 하여 정렬 후 index를 얻음
swap이 일어나지 않아 반복문이 한번 더 실행되는 것을 감안해 최대값에 +1를 함
*/

# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> A(N); // pair <int, int> : 정수 두개를 한쌍으로 묶음

    for (int i = 0; i < N; i++){
        cin >> A[i].first; // 값(value)
        A[i].second = i; // 인덱스(key)
        // cout << "현재" << i << "번째 순회" << "\n";
        // cout << "배열의 first값" << A[i].first << "\n";
        // cout << "배열의 second값" << A[i].second << "\n";
    // sort 함수는 first를 먼저 비교하고, first가 같으면 second를 비교하게 됨
    }

    // 정렬
    sort(A.begin(), A.end());

    // 원래 인덱스 값(A[i].second)에서 정렬된 인덱스 값 i를 빼서 가장 큰 값을 찾음
    int Max = 0;

    for (int i = 0; i <  N; i++){
        if (Max < A[i].second - i){
            Max = A[i].second - i;
            cout << "현재" << i << "번째 순회" << "\n";
            cout << "배열의 second값" << A[i].second << "\n";
            cout << "Max 값 :"<< Max << "\n";
        }
    }
    
    cout << Max + 1 << "\n"; //swap이 일어나지 않는 반복문이 한번 더 실행되는 것을 감안해 +1

    
}