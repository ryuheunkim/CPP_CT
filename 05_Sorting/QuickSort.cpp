// 백준 110004번 
/* 문풀
기본 내장함수 정렬 후 인덱싱하면 끝 이지만, 퀵 정렬을 구현 해보자
*/

/* 예제
배경 : 
  - 퀵소트 : "분할" 정복 방법 (배열 분할, pivot, 투포인터, Swap)
    1. pivot을 선출(Pivot 선출로 인한 성능 영향이 있다.)
        만일 pivot을 배열에서 가장 큰 수이거나, 가장 작은 수이면 부분 배열의 크기는 1이며, 
        분할되지 아니함
    2. 투 포인터(start, end)로 순회
        (내림차순 정렬 기준 "작 --> 큰")
        start의 경우 pivot보다 큰 수가 나오면 멈춤
        end의 경우 pivot보다 작은 수가 나오면 멈춤
    3. swap
        start와 end의 위치를 변경함
    4. pivot 삽입
        start와 end가 만나면, 해당 인덱스의 값과 정렬 기준에 따라 pivot을 삽입함
            내림차순의 경우 ( pivot < 인덱스 < pivot)
    5. 집합이 두개로 분리된다(왼, 오...)
        각 부분집합에서 pivot을 다시 선정하여 (1~4)을 반복한다.
    ...
    분리 집합의 원소가 1개가 될 때까지 위 과정을 반복한다.

파악 : 
구상 : ==배열 정렬에서 k번째를 구하는 것은, k번째 pivot을 구하는 것==과 동의
    왜냐면, pivot이 k번째에 위치했다는 건 이미, 정렬이 완료 됐고, 양 옆 부분집합의 순서는 모르겠으나,
    일단은 pivot의 위치는 정렬됬기 때문임

    - 부분 배열 : 재귀 호출
    - piovt 삽입은 swap의 일종으로 구현하면 된다...
    - quick sort 함수(커스텀 구상...)
         배열, 시작 인덱스, 끝 인덱스를 받는다. (재귀 호출을 위하여...)
         piovt을 선정한다
         시작(끝) 인덱스를 순회하고, piovt와 비교하여 작으(크)면 멈춘다. (인덱스를 담아둔다)
         swap 한다 ... 
         start와 end가 만날 때까지 반복한다. ---> start와 end가 만날 때까지 (순회)
*/

# include <iostream>
# include <vector>
using namespace std;

void quickSort(vector<int> &A, int S, int E, int K);
int partition(vector<int> &A, int S, int E, int K);
void swap(vector<int> &A, int i, int j);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 데이터 입력
    int N, K;
    cin >> N >> K;

    vector<int> A(N,0);

    for (int i = 0; i < N; i++){
        int ele;
        cin >> ele;

        A[i] = ele;
    }

    // 퀵소트 시작
    // 직관적으로 퀵 소트를 작성하게되면, 아래와 같겠지
}

void quickSort(vector<int> &A, int S, int E, int K){
    int pivot = partition(A, S ,E);
    if (pivot == K) {
        return;
    }
    else if (K < pivot){
        quickSort(A, S, pivot -1, K);
    }
    else {
        quickSort(A, pivot + 1, E, K);
    }
}


int partition(vector<int> &A, int S, int E) {
    if (S+1==E){ // 부분집합의 길이가 2일 때
        if (A[S] > A[E]){ // Start index와 End index가 교차할 때에
            swap(A, S, E); // 두개의 위치를 바꾸어줌...
        }
        return E; // E가 pivot임 (왜?)
    }

    // Pivot 설정
    int M = (S+E) / 2;
    swap(A, S, M); // 배열의 시작값과 중앙값을 바꿔침 (피벗값을 격리하는 것)
    int pivot = A[S]; // 피벗값 설정
    int i = S + 1, j = E;

    // 투포인터 순회
    while (i <= j){ // 교차하기 전까지, 포인터를 순회한다
        while (j >= S+1 && pivot < A[i]){ // End 포인터가 Start 포인터와 교차하지 않고, 피벗 값이 Start 값보다 작을 때
            j--; // 피벗보다 작은수가 나올 때까지, End 포인터의 값을 줄여나감 (왼쪽으로 이동)
        }
        while (i <= E && pivot > A[i]){ 
            i++; // 피벗보다 큰 수가 나올 때 까지, Start 포인터를 증가시킴
        }
        if (i < j){
            swap(A, i++, j--); // i와 j를 교환 ...
        }
        else{
            break;
        }
    }
}

void swap(vector<int> &A, int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}