/*
파악 :
  - 함정 : 0과 자기자신을 더하는 경우는 제외해야 함
        **N을 서로 다른 두 수의 합으로 나타낸다**라는 점,
        0이 포함될 수도 있다는 점

배열을 순회하면서 SUM값 마다 투포인터 순회로 두가지 조합을 찾자
  - 배열 순회에 n, SUM값 마다 투포인터 순회하므로
  - 시간복잡도는 n^2 인데 N=2,000 이므로 시간제약 (2*10^8) 이내
  
  수의 위치가 다르면, 값이 같아도 다른 수이다
    -> 배열의 원소의 중복을 허용한다는 의미로 파악

숫자의 범위가 10^12 이므로, 4byte를 초과하여, long형으로 선언
구상 : 
구현 : 
// 배열 입력 받음
// 배열 순회로 sum 값 마다 투포인터 순회
// 결과 출력
*/

# include<iostream>
# include<algorithm>
# include<vector>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<long> A(N,0);

    // 배열 입력 받기
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    // 배열 정렬하기
    sort(A.begin(), A.end());

    int result = 0;

    // 배열 순회하며 원소별 투포인터 순회
    for (int i =0; i < N; i++){
        long find; // creteria
        // A[i] = C; <-- 이렇게 하면, 배열의 값을 바꾸게 되므로 ... , long 값의 초기화 값이 계속 들어갔었었음
        find = A[i];

        int S = 0;
        // start_index = -25568(왜?) --> 밑에 순회 조건에서 엉뚱하게 인덱스를 조작하였었음
        // 왜 loop를 돌 때에, 배열의 값에 영향을 주는지?
        int E = N-1;
        // end_index = 12318 값으로 나옴(왜?), 밑에 순회 조건에서 엉뚱하게 인덱스를 조작하였었음

        // 투포인터 순회
            // 0이 포함될 경우에, 자기자신의 인덱스와 0의 합으로 나타내어 지므로, 
            // N개의 수 중에서 어떤 수가 다른 두 수의 합으로 나타낼 수 있다면 그 수를 '좋다(GOOD)'고 한다.
        while (S < E){
            if((A[S]+A[E])==find){
                // C와 다른 수인지 확인하는 로직
                if (S != i && E != i){
                    S ++;
                    E --;
                    result ++;
                    break;
                }
                else if(S == i){
                    S++;
                }
                else if(E == i){
                    E--;
                }

            }
            else if((A[S]+A[E]) > find){
                E--;
            }
            else if((A[S]+A[E]) < find){
                S++;
            }
        }
    }

    cout << result << "\n";
}