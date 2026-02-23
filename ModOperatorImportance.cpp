# include<iostream>
using namespace std;

/* 1부터 50까지의 숫자를 곱한 수에 10007를 나누었을 때의 나머지 구하기*/
void wrong_ver1(){ //이 로직은
    long long Mulsum = 1; // long long의 값 범위는?
    long long DivSum = 0;
    for (int i=1; i<51; i++){
        Mulsum = Mulsum * i;
        /* 각 단계별 나머지의 값을 Accumulate...*/
        DivSum = DivSum + (Mulsum % 10007); //괄호를 잘못 쳤었음
        //std::cout << DivSum << "\n";
    }
    cout << DivSum << "\n";
}

void answer(){
    long long Mulsum = 1; // long long의 값 범위는?
    for (int i=1; i<51; i++){
        Mulsum = (Mulsum * i) % 10007; 
        /*곱이 10007를 넘어가는 순간, 말도 안되는 값이 산출될 거 같으나 ...
        나머지값의 곱셈의 분배로, 나머지의 곱셈은 분배가 되므로 위와 같은 로직이 가능하다고 여겨짐(이해는 안됨) 
        수학적 원리로 이해 나머지의 곱셈은 분배가 되므로*/
    }
    cout << Mulsum << "\n";

}

int main(){
    answer();
    wrong_ver1();
}