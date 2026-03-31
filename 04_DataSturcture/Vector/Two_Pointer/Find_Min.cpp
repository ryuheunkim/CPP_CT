/*
핵심 : 인덱스와 값으로 나누어서 생각해야 함

입력되는 값의 value(first) 값이 크면 버리고, 새로 들어오는 값을 추가,
이전에 있던 값 deque.front()의 index가 유효기간(i-L)보다 작으면, (i-L+1)미만이란 뜻, 제거해야 하고
*/

/*  D의 인덱스 확인용 코드
    
    int N, L;
    cin >> N >> L;
    
    for (int i = 1; i < N; i++){
        cout << i << "번째 일 때" << endl;
        for (int j = i-L+1; j <= i; j++){
            if (j <= 0){
                continue;
            }
            cout << j << ",";
        }
        cout << endl;
    }
    
*/

# include<iostream>
# include<deque>
# include <utility>
using namespace std;
typedef pair<int,int> Node;

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    deque <Node> dq;

    for (int i = 0; i < N; i++){ //문제의 조건의 A_{1}은 A_{0}이니, N회 순회 시킬 것
        int now;
        cin >> now;
        // now 값을 dq에 더할 때
        while (dq.size() && (dq.back().second > now)){
            dq.pop_back(); //기존 값들 중 now 보다 큰값들을 다 버림
        }
        dq.push_back(Node(i,now)); // 앞에 값들이 now 보다 작다면 남아있을 수 있음

        // 인덱스 범위를 넘어간 min값 제외
        if (dq.front().first <= i-L){
            dq.pop_front();
        }

        cout << dq.front().second << " ";
    }
}