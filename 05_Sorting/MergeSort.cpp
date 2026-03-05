// 백준 2751번
/* 내 생각으로 구현
파악 : 입력 배열의 크기가 10^6 이므로, 
log N은 6*3.3 = 20 정도로, 2 * 10^7 의 연산으로 대략 0.2초 ~ 0.5초 정도 걸림 (가능한 자료형 및 알고리즘 : 인덱스 정렬, 퀵정렬, 병합정렬)

구상 : 병합 정렬은, 다른 두개의 부분 집합을 비교하며 병합하는 것.
    두개의 부분집합으로 나누는 것 : 재귀 호출 (순회 --> 비교 --> 다른 배열에 집어넣기 (X))
        부분집합의 길이가 1이면, 멈춘다 ...

비교 : 투포인터 순회 비교로, 정렬 순서에 따라, 더 작은(큰) 수를 배열에 집어 넣는다
    위와 같은 투포인터 비교는 복사된 배열위에서 이루어져야 한다(기존 배열은 지속적으로 원소의 갱신이 일어나서 아니됨)

구현 (슈도 코드)
// 데이터 입력 및 배열 선언
// 재귀 호출 (분할과정)
// 투포인터 순회로 비교하고 병합 (정복과정)
    기능 : "부분 배열" 2개를 동시에 "순회" 하면서 "비교" 기존 배열 "갱신"
*/

# include <iostream>
# include <vector>
using namespace std;

// void MergeSort(vector &arr, int S, int E, int M); <-- 나는 배열이랑, 시작, 끝, 분할지점을 인자로 넘겨주어야 한다고 생각했는데 ... ?
/* 구현해야할 것 : 가장 작은 부분집합으로 나뉘어질 때까지 분할하여 호출하는 것이 필요
배열을 받아서, 시작, 끝 인덱스의 중간을 나눈다 ---> 1이 되면 그만 나눈다...(?)
배열을 받아 작은 배열로 나누어 반환하게 되면, 그건 메모리 낭비일 거 같다.
벡터를 S, E --> S, M / M + 1 , E  --> */

void MergeSort(int S, int E); 

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 배열 크기 입력
    int N;
    cin >> N;

    //배열 동적 선언
    vector <int> A(N+1, 0);
    vector <int> tmp(N+1, 0);

    //배열 원소 입력
    for (int i = 0; i < N; i++){
        int ele;
        cin >> ele;
        A[i] = ele;
    }

    // 병합정렬(배열 분할을 재귀적으로 호출하는 것이 필요)
    MergeSort(1, N); // <-- 왜 start = 1인지?

    //출력하기
    for (int i = 0; i < N; i++){
        cout << A[i] << "\n";
    }

}

// 논리적 물리적(주소상)으로 분할하지 않고, 인덱스로 분할 하였음
void MergeSort(int S, int E){
    // 재귀 호출
    if ( E - S < 1){
        return; // 인덱스가 1이면 각 부분집합이 원소가 1이므로 재귀호출 종료
    }

    int M = (E+S) / 2;
    MergeSort(S, M);
    MergeSort(M+1, E);

    // 분할된 두 배열 병합
    // 임시배열 복사
    for (int i = S; i < E; i++){
        tmp[i] = A[i];
    }

    int K = S; //원본 배열의 인덱스
    int tmp_S = S; // 분할된 임시 배열의 인덱스
    int tmp_E = E; // 분할된 임시 배열의 인덱스

    // 병합과정
    // 투 포인터로 분할 순회 하고, 각 부분 집합의 원소 비교로, 병합 실행
    while (tmp_S <= M && tmp_E <= E){
        if (tmp[tmp_S] > tmp(tmp_E)){
            A[S] = tmp(tmp_E);
            K++;
            tmp_E++;
        }
        else {
            A[S] = tmp[tmp_S];
            K++;
            tmp_S++;
        }
    }
    
    // 병합 후 남은 원소 배치
    while (tmp_S <= M){
        A[K] = tmp[tmp_S];
        K++;
        tmp_S++;
    }
    while (tmp_E <= E){
        A[K] = tmp[tmp_E];
        K++;
        tmp_E++;
    }
}