# include <iostream>
# include <vector>
using namespace std;

/*
파악 : 구간합 구하기, 크기는 10^5 이며 이를 단순하게 이중 for문으로 순회한다면 10^10 으로 시간초과니까
그냥 시작점이랑 끝점 입력 받고, 그 안에서만 순회하면서 더해주기
구상 : 
데이터 갯수, 질의 갯수(3개가 아님!) 입력 (이중 for문...)
질의 갯수에 따라 해당 범위의 합만 출력
*/


int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    // vector<int> A(N,0); // 동적배열 선언
    int A[1000001] = {0};

    // 배열 원소 입력
    for (int i = 1; i <= N; i++){ // N+1이 아님
        int E;
        cin>> E;
        A[i] = E + A[i-1];
    }

    //이중 for문으로 돌면, 시간초과... "구간합"을 구해야 함
    for (int i = 0; i < Q; i++){
        int start, end;
        cin >> start >> end; // cin을 두개이상 받을 때에는, 꼭 >>로 구분할 것
        cout << A[end] - A[start-1] << "\n"; // 
    }

}