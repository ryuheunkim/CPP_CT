// 카드게임 (큐문제) 백준 2164번
// 발상 : A[i]은 버리고 A[i+1]는 바닥에 넣기

#include<iostream>
#include<queue>
using namespace std;

int main() {
    // 카드 뭉치 숫자 입력 받기 입력 받기
    int N;
    cin >> N;
    queue<int> Q; //Queue에는 길이 설정 하지 않아도 됨
    for (int i = 1; i <= N; i ++){
        // Q[i] = i+1; 오답임, quque는 push 해주어야 함
        Q.push(i);
    }
    // 카드가 한장 남을 때까지, 반복하기
    while (Q.size() > 1){
        Q.pop(); // 첫장 버리고
        Q.push(Q.front()); // 두번째 장은 다시 집어넣고
        Q.pop(); // 두번째 장 버리고
    }
    // 출력
    cout << Q.front();
}
