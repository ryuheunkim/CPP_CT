# include <iostream>
# include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int S[15001] = {0}; // 1.5mb * 8byte ==> 14mb 정도
    int N, M;
    cin >> N >> M;
    // 15,000개의 숫자 입력
    for (int i = 0; i < N; i++){
        int ele;
        cin >> ele;
        S[i] = ele; // 하나하나 비교하는 것보다, 알고리즘 라이브러리의 sort를 쓰는게 나음
    }

    // 정렬
    sort(S, S+N); // 0 값으로 초기화 하였으니, 당연히 0들이 앞으로 옴 --> 고로 N 까지만 sort할 것 ...

    // 투 포인터로 찾기
    int start = 0; 
    int end = N-1;
    int count = 0;
    //for (int i = 0; i < N; i++) // 이 로직대로면, start가 end 보다 커져서, 중복으로 구해짐
    while (start < end){
        if (S[start] + S[end] == M){
            count++;
            start++;
            end --;
        }
        else if (S[start] + S[end] < M){
            start++;
        }
        else {
            end--;
        }
    }
    cout << count << "\n";
}