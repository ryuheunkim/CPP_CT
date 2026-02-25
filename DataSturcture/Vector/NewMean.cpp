#include <iostream>
#include <algorithm>
using namespace std;

/*
점수의 최대값에 백을 곱한 값을 나눔
*/

/* SudoCode */
// 점수를 배열로 입력 받기 (배열의 크기, 배열의 점수를 입력 받기)
// 최대값을 구해서
// 해당 최대값을 배열에 문제의 기준은 M*100 으로 나누어줌
// 그리고 평균값을 구하기 ...

void wrongver1() { // 모르는 것 : string 배열을 입력 받았을 때에 공백 기준으로 나누어주는 함수
    int len = 0;
    cin >> len;

    // 입력 받은 길이의 원소를 입력 받기
    int scores[len] = {0};
    int ele = 0;
    for(int i = 0; i < len; i++){ //Serial하게 int ele을 입력 받는 로직
        cin >> ele;
        scores[i] = ele;
    }
    //공백을 기준으로 입력 받기
    //공백을 기준으로 split 하기

    string raw_ele;
    // 공백 기준으로 배열로 만드는 함수가 필요...

    // 최대값 구하기 
    sort(scores, scores+len, greater<int>());
    int maxvalue = 0;
    int DivValue = 0; // 변수선언은 1번, data reuse가 len 길이만큼
    maxvalue = scores[0];
    DivValue = maxvalue*100; // 만일 바로 나누어줄 경우, maxvalue data에 *100 하는 MUL 연산을 len만큼 더 해야 함

    //순회하여 각 원소에 나누어 주기 (순회 - 원소값 변경)
    for(int i = 0; i < len; i++){

        scores[i] = ele;
    }
    // 출력하기

}

int wrong_answer2() {
    // 길이만큼 입력 받고
    // 길이만큼 순회하면서 점수를 입력 받음 (string으로 한줄로 입력 -> 각 ele 마다 int로 변환 -> 합산) 과정이 아님
    // 최대값은 함수가 아니라 간단한 순회 로직으로 구현 (입력 값이 적기 때문)

    //길이 입력 받고, 그 길이 만큼 순회하며 원소 입력 받음
    int len = 0;
    cin >> len;

    int Score[len] = {0}; // 동적으로 원소값 입력 받음 <--> 답지는 배열을 고정된 형태로 만들었음(실행시간에 차이가 없기 때문 아마도?)
    int ele = 0;
    for (int i = 0; i < len; i++){
        cin >> ele;
        Score[i] = ele;
    }

    long Max = 0;
    //최대값 찾기 --> 구현 못했었음 (Outer 변수와 비교해서 산정하는 방법...)
    for (int i = 0; i < len; i++){
        /* 잘못된 max 찾기 로직
        if (Score[i] > Score[i-1]) // 그냥 단순 비교하면 OutofIndex 나올 거 같은데?
        if (i==0)
            pass; // 건너뛰기 로직?
        elif (Score[i] > Score[i-1]) */
        if (Score[i] > Max){
            Max = Score[i];}
             
    }
    // 최대값에 100을 곱한수를 나누어 주기
        // 내 발상 : 순회해서 원소 한땀한땀 나누어 주자 -->
        // 답지를 보고 난 후 : 분배의 법칙으로, 총점에서 나눈 후, 길이만큼 나누면 평균이 될 듯?
        // 혹은, 평균... (a+b+c / 3) 이니까, (a+b+c)/ 100*M /3 이잖슴?
        // 근데 어짜피 평균은 구하긶 해야 하는 거니까, 평균을 구할 때에 
        
    // 원소 순회하며 총합 구하기
    int sum = 0;
    for (int i = 0; i < len; i++){
        sum = sum + Score[i];
    }
    sum = (sum/Max*100)/len;
    return sum;

    // 자료형이 틀렸고,
}

int main() {
    int result = 0;
    result = wrong_answer2();
    cout << "result : " << result;
}