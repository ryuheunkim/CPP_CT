/*
문제명 : 숫자의 합 구하기
난이도 : 브론즈4
시간제한 : 1초
백준온라인 저지 : 11720번
*/

# include<iostream>
using namespace std;;
# include<string>

/*
// 접근 : 숫자의 갯수만큼의 벡터를 생성하고, 그 벡터를 순회하면서 합을 구하면 될듯
// 너무 "벡터"를 의식해서, 간단한 풀이인데도 작성하지 못하였음 ...

void wrongver1() { //250223
    //값 입력
    cout << "숫자의 갯수를 입력하세요: " << "\n";
    int NumLen;
    cin >> NumLen;
    
    cout << "공백없는 N개의 숫자를 입력하세요" << "\n";
    str NumSeries; //숫자형으로 입력 받기
    cin >> NumSeries;
    //벡터 생성
    vector<int> NumVec;
    Numvec[NumLen];

    int Sum = 0;
    //벡터 순회하며 합 구하기
    for (int i = 0; i < NumLen; i++){
        Sum = Sum + NumSeries[i]; //str --> to type 변환 필요
        // if 형 변환 없이 할 수 있는 방법이 있는지??
        // 비트연산자로, 비트 슬라이싱 해서 각 자릿수를 치환하는 방법?...
        
    }
    
    cout << "result : " << Sum << "\n";
}
*/

// 핵심 : 형변환
int answer(){
    // 값 입력 받기
    int Number;
    string NumberSer;
    cin >> Number;
    cin >> NumberSer;

    int sum = 0;
    // 순회 및 형변환
    for (int i = 0; i < Number; i++){
        int Digit = NumberSer[i] - '0'; //핵심!, 형변환 표로 만들어서 기억할 것 ...
        sum = sum + Digit;
    }

    return sum;

}

void type_transfer_prac(){
    string num = "456";
    string num_float = "889.244";

    int numToint = stoi(num);
    float numTofloat = stof(num_float);

    string num_floatTostring = to_string(numTofloat);
    
    cout << num << "\n";
    cout << num_float << "\n";
    cout << numToint << "\n";
    cout << num_floatTostring << "\n";
}

int main(){
    // int sum = answer();
    // cout << sum <<"\n";
    type_transfer_prac();
}