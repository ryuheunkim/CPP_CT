// 백준 1874번, 스택으로 수열 만들기

/*
## 발상
- 자연수 스택, 중간 스택, 결과 기록 스택 (push, pop 순서만 저장)
  자연수 스택은 필요 없고, 단지 오름차순이기에 ++만 해주면 된다.
- DataFlow : 자연수 스택 ->(push) 중간 스택 -> (pop)
    1. 중간 스택의 top이 현재 수열의 digit 보다 작으면 (NULL도 작다고 친다), 같아질 때까지 push 한다.
    2. 중간 스택의 top이 현재 수열의 digit과 같으면 pop 한다.
    3. 중간 스택의 top이 현재 수열보다 크면, 수열을 만들 수 없다 (종료)
## sudo 코드...
*/

# include <iostream>
# include <vector>
using namespace std;

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector <int> S; // 출력전 스택
    vector <char> P; // 정답 출력 스택
    bool result = true;

    int num = 1; //오름차순으로 시작하는 자연수(Stack에 집어넣을 수)
    
    // 배열 입력
    for (int i = 0; i < N; i++){
        int E;
        cin >> E;
        
        while (num <= E){ // top에 입력값이 들어올 때까지 자연수값을 오름차순으로 push
            S.push_back(num);
            P.push_back('+');
            num++;
        }

        int top = S.size()-1;

        if (S[top] == E){ //top = S.size()-1
            S.pop_back();
            P.push_back('-');
        }

        else if (S[top] > E){
            result = false;
        }
        //while문으로 인해 S[top]가 E보다 작은 경우는 없다.
    }

    if (result == true){
        for (int i = 0; i <P.size(); i++){
            cout << P[i] << "\n";
        }
    }
    else if(result == false){ // 중간에 입력이 끊기면 안돼서 for-문 밖에서 출력
        cout << "NO" << "\n";
    }
}