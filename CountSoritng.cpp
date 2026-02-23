# include<iostream>
//# using namespace std 

/* 첫번째 오답 
void SortLargeNaturalNumber(){
    int Count[1001] = {0}; // 각 숫자의 출현횟수 저장
    std::cin >> N;
    // 전체 숫자 배열을 순회해서 숫자별 출현횟수 카운팅
    for (int i = 0; i < N; i++){
        Count[i]++;
    }
    // 전체 카운트 후엔 ... 순회하며 출력 
    for(int i =1; i<1001; i++){
        for(int i=0; i<Count[i]; i++){
            std::cout<<Count[i] <<",";
        }
    }
} */

/* 1,000보다 작은 자연수 10,000,000개 1초안에 Ascending 정렬 */
void CountSorting(){
    int count[1001] = {0}; // 자연수 1,000개를  담는 count 배열 선언
    int N; // 자연수의 총 갯수
    std::cin >> N; // 자연수의 총 갯수를 입력 받음

    // 순회하면서 count 배열 인덱스에 총 몇개가 들어있는지 세어봄
    for (int i =0; i < N; i++){ // 0 ~ N까지의 숫자를 순회
        int num;
        std::cin >> num; //숫자 입력 로직, 실제 코드에 활용하려면 배열을 순회하며 받아야 함
        count[num]++; // 계수 배열에 해당 숫자의 count를 증가
    }    
    
    // 순회하며 출력
    for (int i = 0; i < N; i++){
        if(count[i] != 0){
            for(int j=0; j<count[i]; j++)
                std::cout<< i << "\n";
        }
    }
}

int main() {
    CountSorting();
}