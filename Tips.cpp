#include <iostream>
using namespace std;
int main(){
    cout<<"Hello, world!"<<endl;
    /*Speed up Skills*/
    cout<<"Hello, wolrd!"<<"\n"; //enl;은 flush out 버퍼를 강제로 실행해서 실행시간을 잡아먹음
    ios::sync_with_stdio(false); // C의 stdio와 C++의 iostream간의 동기화를 끊어버림
    cin.tie(NULL); // cin과 cout의 연결을 끊어버림
}