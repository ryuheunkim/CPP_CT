//백준 11399번
/* 문풀
파악 : 각 원소들의 조합의 누적합 중 최소값을 찾는 문제
구상
  - 정렬해가면서, 각 순서의 인출 총합시간을 구해서 그 중에서 또 최소값을 순회해가면서 얻는 건가???
*/

/* 해설
파악 : 누적 최소합 = "그리디", 인출 시간을 기준으로 값을 정렬 (정렬 후 누적합)
구상 
  - 누적합 배열 : 앞사람들의 인출 시간의 합 + 자신의 인출 시간
  - 삽입 정렬 구현
  - 실전에선 sort로 구현하여도 될듯?
*/

# include <iostream>
# include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 벡터 배열 선언
    int N;
    cin >> N;
    vector<int> A(N,0);
    vector<int> S(N,0);

    // 원소 입력
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    // 삽입 정렬
    for (int i = 1; i < N; i++){
        int insert_point = i;
        int insert_value = A[i];
        // 삽입 위치 검사(들어갈 자리 찾기)
        for (int j = i-1; j >= 0; j--){
            // j는 현재 순회 위치의 A[i]의 바로 왼쪽으로 시작해 역순(0번 인덱스 방향)으로 검사
            // i = 1 이면, j = 0 검사, i = 2 이면, j = 0, 1 검사
            if (A[j] < A[i]) {
                insert_point = j + 1; // 내가 i 보다 작으면, j+1이 들어갈 자리임
                break;
            }
            if (j==0){
                insert_point = 0; // 끝까지 갔는데도, 나보다 작은게 없으면, 내가 가장 작은 값임
            }
        }
        // 공간 만들기(shift)
        for (int j = i; j > insert_point; j--){ // 현재 인덱스로부터 들어갈 자리(insert_point) 앞까지 역순으로 진행            A[j] = A[j-1];
            A[j] = A[j-1]; // 정렬 중간에 숫자를 넣으려면 그 자리에 있던 숫자들을 한칸씩 뒤로 밂(shift) 연산
        }
    }

    // 합배열 만들기
    S[0] = A[0];
    for (int i = 1; i < N; i++){
        S[i] = S[i-1] + A[i];
    }

    // 합 배열 총합 구하기
    int sum = 0;

    for (int i = 0; i < N; i++){
        sum = sum + S[i];
    }

    cout << sum;
    
}