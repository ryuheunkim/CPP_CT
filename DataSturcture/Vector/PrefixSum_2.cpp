# include <iostream>
using namespace std;

int main() {
    // 원본 배열 선언
    int Matrix[1025][1025] = {0};
    int Num, Query = 0; // Num
    cin >> Num >> Query;

    // Num 횟수만큼 행, 열 원소 받기
    for (int i = 1; i <= Num; i++){
        for (int j = 1; j <= Num; j++){
            int ele;
            cin >> ele; // Num 횟수만큼 행, 열 원소 받기
            Matrix[i][j] = ele + Matrix[i][j-1] + Matrix[i-1][j] - Matrix[i-1][j-1]; 
            // 누적 배열 구하기 " - Matrix[i-1][j-1] " 이 부분을 놓쳤음. 
        }
    }
    // Query의 수만큼 부분합 구하기
    for (int i = 0; i < Query; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int result = 0;
        result = Matrix[x2][y2] - Matrix[x1-1][y2] - Matrix[x2][y1-1] + Matrix[x1-1][y1-1];
        cout << result <<"\n"; 
    }
}