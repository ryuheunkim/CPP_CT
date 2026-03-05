# include <iostream>
# include <cmath>
using namespace std;

int main() {
// 1. N값 설정 (N = 10^6)
    long long N = 1000000; 

    // 2. N log2 N 계산
    // log2(N)은 double을 반환하므로 명시적 형변환을 해줍니다.
    double logN = log2((double)N);
    long long total_ops = (long long)(N * logN);

    // 3. 시간 기준 (1초당 1억 번 연산)
    const long long ONE_SECOND_OPS = 100000000; 

    // 4. 예상 소요 시간 (초 단위)
    double expected_time = (double)total_ops / ONE_SECOND_OPS;
    cout << expected_time << "\n";
}