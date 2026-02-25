// 구간합을 구할 땐, 구간합 배열을 생성해야 함


/* 
자연수의 갯수가 정해져 있다면, 그 크기만큼만의 배열을 생성
==주어진 수의 구간합 배열을 생성==
주어진 i와 j값에 따라 구간합을 구함
*/
 
#include <iostream>
using namespace std;

int main(){
    /*속도 때문에 iostream 끊기 등 사용해야 함*/
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Len, Range; // int가 10^5을 받을 수 있는지?
    cin >> Len >> Range; // cin >> Len, Range 이렇게 하면 안됨
    int Sum[1000001] = {0}; //정적 배열 선언

    // 여기서, 입력을 순회하며 받을 생각을 해야 함
    for(int i = 1; i <= Len; i++){ // 이렇게 하면, 평행하게 받아야 하네
        int tmp;
        cin >> tmp;
        Sum[i] = Sum[i-1] + tmp; // 구간 합 배열 Sum[i] = Sum[i] + tmp
    }

    for(int i =0; i < Range; i++){
        int start, end;
        // cout << "숫자를 입력하세요" <<"\n";
        cin >> start >> end;
        cout <<Sum[end] - Sum[start-1] <<"\n"; // Sum[end] - Sum[start-1] 해주어야 함
    }

}