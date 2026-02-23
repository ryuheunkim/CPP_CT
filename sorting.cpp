#include <iostream>
#include <algorithm>
using namespace std;

// 정렬 기초
// 오름차순
void Ascending(){
    int A[] = {5,4,3,2,1};
    int len = sizeof(A) / sizeof(A[0]);
    sort(A, A+len);
    /* sort는 인트로 정렬로 (퀵, 힙, 삽입의 혼합임)
      - 퀵 정렬 : 대부분 상황에서 실행
      - 힙 정렬 : 재귀 깊이가 너무 깊어지면, 퀵 --> 힙
      - 삽입 정렬 : 데이터의 갯수가 아주 적으면, 오버헤드가 적은 삽입정렬로 전환
    sort의 세번째 인자는 less<int>로 default임
    less<int> 첫번째 인자(위 경우엔 A(배열포인터)) 부터 두번째 인자(A+len(배열의 끝 포인터)) 까지 
    첫번째 < 두번째일 경우 true를 반환
    */
    for (int i =0; i<len; i++){
        cout << A[i] <<"";
    }
}
// 내림차순
void descending(){
    int A[] = {5,3,4,2,1};
    int len = sizeof(A) / sizeof(A[0]);
    sort(A, A+len, greater<int>()); // 
    for (int i=0; i < len; i++){
        cout << A[i] << "";
    }
}

/********************************************************************************/

struct Score{
    int english, math;
};
// 사용자 정의 비교 함수 (영어점수 기준 Descending)
bool compare(const Score& a, const Score& b){
/*
const: 읽기전용, 값을 바꾸지 않는다는 선언
 - const 없이 a.멤버 = 100을 하면, 값이 변경됨
Score& a : a라는 별칭을 부여 (주소만 복사됨) <--> Score a는 동일한 구조체를 만듦(메모리 낭비)
*/
    if (a.english != b.english)
        return a.english > b.english; // 영어 점수가 높은 순으로 정렬 (내림차순)
        // if문 안에 한줄만 있어서, 가독성 때문에 블록 생략함
    return a.math > b.math; // 영어 점수가 같다면 수학 점수가 높은 순으로 정렬
}

void custom_compare(){
    // Score 구조체의 test 구조를 만들어서, english와 math을 할당
    Score score[] = {{70, 50}, {80, 40}, {80, 30}, {90, 100}};
    // 선언한 테스트 구조체의 sort (배열 주소, 배열 끝 주소, compare)로
    int len = sizeof(score)/sizeof(score[0]);
    sort(score, score+len, compare);
    for (int i=0; i < len; i++){
        std::cout<<"English Score: "<<score[i].english<<"Math Score: "<<score[i].math<<"\n";
    }
    // 순회하며 출력
}

struct OverloadScore{
    int english, math;
    bool operator<(const OverloadScore& other) const{
    /* "<" 기호의 기능을 수정하게 해주는 operator(예약어)
    (리턴 타입) operator(연산자) (연산자가 받는 인자)
    상세한 설명 : 씹어먹는 c++ [https://modoocode.com/202]
    sort는 기본적으로 "왼쪽 < 오른쪽"이 true가 되도록 정렬합니다(오름차순).
    math > other.math는 큰 쪽이 앞쪽으로 옴으로 재정의하여서 내림차순으로 sort하게 하였음
    */
        if (math != other.math)
            return math > other.math;
        return english > other.english;
        
    }
};

void custom_compare_with_struct_overload(){
    OverloadScore score[] = {
        {70, 50},
        {80, 40},
        {80, 30},
        {90, 100},
    };
    int len = sizeof(score)/sizeof(score[0]);
    sort(score, score+len);
    for (int i=0; i < len; i++){
        std::cout<<" english :"<<score[i].english<<" math : "<<score[i].math<<"\n";
    }
}

int main(){
    custom_compare_with_struct_overload();
}