# include <iostream>
# include <algorithm>
using namespace std;
// 접근법
/*10^10 개여서, 1회만 순회해도 안됨 이에 반해 입력 가능한 숫자의 범위는 2,000 이므로
입력과 동시에 count 배열을 만들고,
그 count 배열의 < 2,000 개의 숫자를 정렬,
해당 count 배열에서 두 숫자로 표현가능한 숫자의 조합이 있는지 확인하고, count * i 하자  
*/

// 문제를 제대로 읽을 것, 숫자는 총 2000개 이며, 10억이란 단순히 값의 범위임



void trial_1(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S[2001] = {0};

    // 10^10 개의 원소 입력 받기, 근데 입력 받는 로직은 시간복잡도 계산을 안하는지?
    int N;
    for (int i = 0; i < N; i++){
        int ele;
        cin >> ele;
        S[ele] = S[ele] + 1;
    }
    // 정렬하기
    sort(S, S+N);

    // 투-포인트 로직으로 count 계산하기 ...

}

void trial_2() {
    /*
    접근법 : 다른 두수의 조합 -> "투 포인터"
    조합의 기준 합을 동적으로 주어야 하기에, 순회하고 : n
        그 순회 안에서 이전 배열에 대해 합을 산출 해낸다 (투포인터) : n 
    제약 : 수의 범위가 2,000까지이기에, 
     */
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    // 배열 생성 및 원소 입력, 값의 범위는 절대값 10억이므로 int로 가능
    int S[2001] = {0};
    for (int i = 0; i < N; i++){
        int ele;
        cin >> ele;
        S[i] = ele;
    }

    // 배열 정렬
    sort(S, S+N);

    int result = 0;
    // 기준 값 순회 = N time spent
    for (int i = 0; i < N; i++){
        int Creteria;
        Creteria = S[i];
    
    // 투 포인터 로직
        int start = 0;
        // int end = N-1; // 틀림!) 얘는 i 값을 넘어가면 안되지...
        int end = i;
        int count = 0;
        result = result + count;

        while (start < end){
            int Combi = S[start]+S[end];
            if (Combi == Creteria){
                start ++;
                end --;
                count ++; // 질문 : 왜 count가 안쌓이지?
                // break; // 어짜피 break 없어도 자동으로 되는 거 아닌지? ...
            }
            else if (Combi < Creteria){
                start ++;
            }
            else {
                end --;
            }
        }
    }

    cout << result << "\n";
}