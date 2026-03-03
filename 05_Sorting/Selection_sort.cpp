// 백준 1427번 https://www.acmicpc.net/problem/1427

/* 문풀
파악 : 자연수가 1,000,000,000 이면 시간복잡도가 10^10 이라고 착각함
구상 : 선택정렬 
*/

/* 예제(해설)
파악 : 자릿수를 분해하여 정렬하므로 10개의 숫자를 정렬 하는 문제임
선택정렬로 하여도 문제 없음(시간제한 2초...)
*/

# include <iostream>
# include <vector>
# include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    vector<int> A(str.size(), 0); // 0으로 원소값을 초기화

    // 자릿수별로 int값으로 변환
    for (int i = 0; i < str.size(); i++){
        A[i] = stoi(str.substr(i,1));
        //stoi(str, pos, base) 위 경우, str = str.substr(i,1)
        //substr(pos, len) : pos(시작위치 인덱스로부터) len(몇글자씩)자를 건지
        //혹은 A[i] = A[i] - '0' (근데 이경우엔, 숫자 int형에만 적용됨)
    }

    // 자릿수 정렬(선택 정렬)
    for (int i = 0; i < str.length(); i++){
        // Max 값 찾기
        int Max = i;
        for (int j = i+1; j < str.length(); j++){ // i+1은 정렬이 끝났으므로, 제외하고 순회
            if (A[j] > A[Max]) { // 내림차순임으로 최대값을 찾음 ">"
                Max = j; 
            }
        // swap
        }
        if (A[i] < A[Max]){ // 내림차순임으로, Max보다 작은 값과 swap
            int temp = A[i];
            A[i] = A[Max];
            A[Max] = temp;
        }
    }

    // 결과값 출력
    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
    }
}