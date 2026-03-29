/*
핵심 : 인덱스와 값으로 나누어서 생각해야 함

입력되는 값의 value(first) 값이 크면 버리고, 새로 들어오는 값을 추가,
이전에 있던 값 deque.front()의 index가 유효기간(i-L)보다 작으면, (i-L+1)미만이란 뜻, 제거해야 하고
*/

# include <iostream>
# include <vector>
# include <deque>
typedef pair<int, int> Node;
using namespace std;

int main() {
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    deque<Node> dq;

    for (int i = 0; i < N; i++){
        long now; // -10^9 ~ 10^9 이기 때문
        cin >> now;
        // dequq의 뒤의 ele가 현재 입력값보다 크면 --> 제거
        while (!dq.empty()&& dq.back().value >= now){
            dq.pop_back();
        }

        // 값 입력
        dq.push_back({now, i});

        //윈도우를 벗어나는 첫번째 값 삭제
        if (dq.front().index < i-L){
            dq.pop_front();
        }

        cout << dq.front().value <<"\n";

    }

}