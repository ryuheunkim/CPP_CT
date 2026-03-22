/*
파악 : N = 10^7의 자연수를 나타낼 수 있는 하나이상의 자연수의 합 구하기
  - 단순순회: 가능한 숫자들을 1,2,3,4...의 조합으로 더해준다면? --> 시간초과 N/2 + N/3 + ... N/10^7 --> (N^2)의 시간복잡도
  - 단순순회로 if 조건문으로 해결할 수 있는 문제는 아님
구상 : 투 포인터(?),
  - 입력받은 값 N까지의 수 ...
  - end, start 포인터, 값의 범위가 작으면 start ++ , 값의 범위가 크면 end --
  - N이 나오면 result ++ 
  (투포인터로 어떻게 여러가지 숫자의 조합을 만들어낼 수 있지?)
  (단순한 투포인터는 ... )
구현 : 
*/

# include <iostream>
# include <vector>
using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    int count = 1;
    int S = 1;
    int E = 1;
    int sum = 1;

    while (E < N){
      // 루프 조건이 틀렸었음 -> (기존) for (int i=0; i < N; i++)
      // E가 N에 도달하면 탐색 종료 (어차피 E=N인 경우는 count=1로 셌으니까) 
      if (sum == N){
        count++;
        E++;
        sum = sum + E;
      }
      else if(sum > N){
        sum = sum - S;
        S++;
      }
      else if(sum < N){
        E++;
        sum = sum + E;

      }
    }

    cout << count << "\n";
    
}