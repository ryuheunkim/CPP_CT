/*
백준 12891번
파악 : 계수 정렬 활용(갯수 조건이므로...)
  (n-p+1) * p 의 시간복잡도를 가지므로, 이중 for 문을 돌리더라도 O(n)의 시간복잡도(실제 2n)임
  - 하지만 투포인터로 계수 정렬을 옮기며 S를 -- 하고, E를 ++ 하면 O(n)의 시간복잡도(실제 n)를 가질 수 있음
구상 : 
  - 이중 for 문으로 S, E 포인터를 지정하여 순회,
  - 투포인터로 S--, E++ 하여 계수정렬도 최적화...
구현 :
// 문자열 받기(핵심)
// 배열입력
// 배열 순회 (이중 or 투포인터)
// 조합갯수 출력
*/

# include <iostream>
# include <vector>
using namespace std;

int main(){
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 배열 입력 받기 ...
    int N, P;
    cin >> N >> P;

    string dna;
    cin >> dna; // 문자열 입력

    int required[4];
    for (int i = 0; i < 4; i++){
        cin >> required[i];
    }

    int count = 0;

    // 배열 순회 (단순 이중 순회)
    for (int i = 0; i < N; i++){
        int contained[4] = {0};
        int S = i;
        int E = S + P - 1;

        while ( E <= N-1){
            // dna S, E 만큼 순회
            for (int j = S; j <= E; j++){
                if (dna[j] == 'A'){
                    contained[0]++;
                    }
                else if (dna[j] == 'C'){
                    contained[1]++;
                    }
                else if (dna[j] == 'G'){
                    contained[2]++;
                    }
                else if (dna[j] == 'T'){
                    contained[3]++;
                    }
                }
            
            // required contained 비교로 count++;
            int compare = 0;
            for (int k = 0; k < 4; k++){
                if ((required[k] - contained[k]) < 0){
                    compare = -1;
                    break;
                }
            }
            if (compare == 0){
                count++;
            }
            
            E++;

        }
    }

    cout << count << "\n";

    }

