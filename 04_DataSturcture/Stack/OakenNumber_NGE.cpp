# include <iostream>
# include <vector>
# include <stack>

/* 최초 접근
## 익힌 풀이법의 목록 중에, 하나를 적용하는 식으로 하고 있음
## 발상
    옆으로 순회(반복문 사용)해가면서, 구하는 건 최악의 경우 n^2 이므로 시간 초과함
    투 포인터 = 적정한 "두수의 합" 이므로, 해당되지 아니함
*/

/* 문제 풀이 분석

수열의 digit들을 스택에 쌓을 때에, 새로 들어오는 수가 top 보다 크면,
그수가 oaken수가 됨
오큰수가 존재하지 않는 숫자는 -1를 출력

중간 스택 : index를 순서대로 push 하고서 
3,5,2,7 일 때에 오큰수는 5, 7, 7, -1 임
왼쪽에 있는 수들 중 나보다 크고, 가장 왼쪽에 있는 수

오큰수는, A[index] > A[top] 인 수임
*/

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 데이터 입력 및 자료형 선언
    int N; // 수열의 길이
    cin >> N;
    vector<int> A(N,0); // 수열
    vector<int> ans(N,0); // 오크수(NGE)를 담아둘 스택
    
    for (int i = 0; i < N; i++){
        cin >> A[i];
    } // 수열의 ele 입력 받음

    stack<int> myStack;
    myStack.push(0); // 인덱스 스택

    // 스택에 새로 들어오는 수가 top에 존재하는 수를 찾자
    for (int i = 1; i < N; i++){
        // 스택에 새로 들어오는 수 A[i]
        // top에 존재하는 수 A[myStack.top()]
        // i=1 일때, top = 0 이고, A[1]은 새로들어올 숫자...
            // 예), int A[4] = {3, 5, 2, 7}; 일 때에,
            // 아래 while 문 조건식을 충족하면 자신보단 크고, "그 중에 제일 왼쪽에 있는 수" 임
        // 스택이 비어있지 않고, 인덱스 수열[스택 최상단]이, 현재 수열 보다 작을 때에
        while (!myStack.empty() && A[myStack.top()] < A[i]){
            ans[myStack.top()] = A[i]; // 오큰수 저장
            myStack.pop();
        }
        myStack.push(i);
        // 현재 수열이 스택 top 위치 값보다 작다.(오큰수가 아니다.)
    }
    // 빌 때까지 순회하며 -1 값을 할당한다.
    while (!myStack.empty()){
        ans[myStack.top()]=-1;
        myStack.pop();
    }
    for (int i = 0; i<N; i++){
        cout << ans[i] << " ";
    }

}