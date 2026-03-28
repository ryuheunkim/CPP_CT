/*
파악 : 불연속적인 숫자 N개에서 M을 만드는 두 조합을 고르기
구상 : N = 15,000이므로 (10^4), N^2 이여도 상관은 없을듯 하지만 ...
구현 : 
  내 앞의 원소와 더하고, 크면 S를 빼고, 작으면 E를 더하고는 정렬돼 있을 때에 성립함
  고로, 순서가 일정치 않는 경우에는 이중 for문으로 단순하게 조합을 구해도 되겠으나 이경우엔 N^2 이므로
  퀵 정렬 이후 투포인터를 쓰는것이 더 빠르긴 할 것임
  // 배열 퀵 정렬 10^7, int = 4byte, 배열 = 10^3 kb 10^6 mb, "40mb의 배열을 가지게 됨.""
잘못된 접근법임, 연속된 수가 아니며, 연속된 구간이 아니기에 적용할 수 없음

비연속적이며 K개의 조합으로 나타내는 경우는, S,E의 투포인터가 성립되지 않을 것으로 보임
투포인터의 이동하며 더해주는 기믹은 연속성이 전제돼야 하기 때문임

접근법은 옳았으며, 작으면 S++, 크면 E--, S<E일 때 동안 진행하면 됨 
*/

# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> A(N,0);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    sort(A.begin(),A.end()); // 이게아닌가?, 컴파일 오류 뜸, 아 sizeof로 해야 함 ...

    int S = 0;
    int E = N-1;
    int sum = 0;
    int count = 0;

    while (S < E){
        sum = A[S] + A[E];
        if(sum == M){
            count++;
            E--;
            S++;
        }
        else if(sum < M){
            S++;
        }
        else if(sum > M){
            E--; // while문에 의해 S == N일 경우, 자동 종료됨
        }
    }

    cout << count << "\n";

}