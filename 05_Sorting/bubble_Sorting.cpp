// 백준 2750번
/* sort를 활용한 접근
파악 : 배열이 10^3 이므로, sort함수로도 구현이 가능, N^2   
구상 : 
- 정적 배열 크기 선언(메모리 크기가 작으므로), 원소 입력, 원소의
갯수만큼만 정렬(아니면 0이 전부 앞으로 오게 되므로)
- 정렬 구현은 sort 함수로 가능 (n log n)
계획(의사코드)
  - 정적 배열 선언
  - 배열의 크기 N 만큼만 정렬(sort)
  - 출력
*/

# include <iostream>
# include <algorithm> // sort 함수 사용을 위해
using namespace std;

// sort를 활용한 접근
void using_sort() {
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 정적 배열 선언
    int Arr[1001] = {0};

    int N;
    cin >> N;
    // 원소 입력
    for (int i = 0; i < N; i++){
        int ele;
        cin >> ele;
        Arr[i] = ele;
    }

    // 배열의 크기 N만큼만 정렬
    // int len = sizeof(Arr)/sizeof(Arr[0]); // <-- 이건 전체 정렬임
    sort(Arr, Arr+N); //sort 안에 Arr[0]을 집어넣으면 오류 발생

    for (int i = 0; i < N; i++){
        cout<<Arr[i]<<"\n";
    }

}

/*
버블 접근 구현
    마지막 값은 이미 정렬된 값.  
    순회, 비교, 위치 변경.
    순회의 값 N을 -1 해나감 --> for (int j == 0 ; j < N -1 -i;  i++)
*/

# include <vector>

void bubble_sort(){
    // 출력 속도 기본 세팅
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N, 0); //동적 배열 선언

    // 배열 원소 입력
    for (int i = 0; i < N; i ++){
        cin >> A[i];
    }

    for (int i = 0; i < N -1 ; i++){ // 버블 정렬은, 맨끝의 수가 정렬 완료이므로 -1 해야 함
        for (int j = 0; j < N -1 -i; j++){
            // 배열의 오른쪽 수가 더 클 때(인덱스가 더 작은 수가 클 때에), 두 자리를 바꿔치기
            if (A[j] > A[j+1]){
                int tmp;
                tmp = A[j+1];
                A[j+1] = A[j];
                A[j] = tmp;
            }
        }
    }

    for (int i = 0; i < N; i++){
        cout << A[i] << "\n";
    }
    
}

int main(){
    bubble_sort();
}