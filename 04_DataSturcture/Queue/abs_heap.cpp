// 백준 11286번 https://www.acmicpc.net/problem/11286

/* 
파악 : 스택에 넣어놨다가, 0을 집어넣으면 절대값이 가장 작은 값을 출력하고 삭제(반복)
구상 : 동적 입력, 최소 최대값 비교 --> 우선순위 큐
  - "우선순위 큐"
  - 절대값 비교이므로, Custom 비교 함수 제작
계획
구현 
*/
# include <iostream>
# include <queue>
using namespace std;

struct compare {
    bool operator()(int o1, int o2){
        int first_abs = abs(o1);
        int second_abs = abs(o2);
        // 절대값이 같을 때는 음수 우선 정렬
        if (first_abs == second_abs) {
            return o1 > o2; // 두 값 중에 큰값의 우선순위를 낮춤
        }
        //절대값 기준으로 정렬
        else {
            return first_abs > second_abs;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // o1 > o2가 true일 때, o1, o2의 순서로 정렬한다
    priority_queue<int, vector<int>, compare> MyQueue; 

    // iterate 횟수 입력
    int N;
    cin >> N;

    for (int i = 0; i< N; i++){
        // 우선순위 큐 원소 입력
        int request;
        cin >> request;
        // 0이면 출력
        if (request == 0) {
            if (MyQueue.empty()){ // 0이고 아무것도 없어 0을 출력
                cout << "0\n";
            }
            else {
                int ele;
                ele = MyQueue.top(); // top 연산으로 Queue의 맨 위의 값 출력
                cout << ele << "\n"; 
                MyQueue.pop(); // pop 연산으로 해당 원소 삭제
            }
        }
        // 0이 아니면 큐에 입력
        else {
            MyQueue.push(request);
        }
    }
}

