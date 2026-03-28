/* 
백준 12891번 (DNA 비밀번호)
핵심 : Counting Array + TwoPointer(Silding)
*/


# include<iostream>
using namespace std;

void Update(char ele, int countArr[], bool isAdd){
    int val = isAdd ? 1:-1;

    switch (ele){
        case 'A' : countArr[0] += val; break;
        case 'C' : countArr[1] += val; break;
        case 'G' : countArr[2] += val; break;
        case 'T' : countArr[3] += val; break;
    }

}

int CheckSeq(int condition[], int countArr[]){
    
    for (int i = 0; i <4; i++){
        if (countArr[i] < condition[i]) {
            return 0;
        }
    } 

    return 1;

}

int main(){
    //입출력 속도 향상
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //데이터 입력
    int S, P;
    cin >> S >> P;

    string DNA;
    cin >> DNA;

    int condition[4] = {0};
    for (int i = 0; i < 4; i++){
        cin >> condition[i];
    }

    int countArr[4] = {0}; // 부분 계수 배열
    int DNASeqCount = 0;

    // (P)artArray(부분배열 최초 1회 순회)
    for (int i = 0; i < P; i++){ //4가 아니라, 부분배열만큼 돌려야 함...
        char ele = DNA[i];
        Update(ele, countArr, true);
    }

    // 초기 계수 배열 조건 확인
    int Check = CheckSeq(condition, countArr);
    DNASeqCount += Check;

    // 전체 DNA 시퀀스 순회
    // start가 0일 때, end는 1(start+p-1), start가 1일 때 end는 2, start가 2일때에는 end는 3...
    int start = 0;
    int end = start + P;

    while (end < S){
        Update(DNA[start], countArr, false); // 1이 빠지는게 아니라, 0이 빠져야 함
        Update(DNA[end], countArr, true);
        int Check = CheckSeq(condition, countArr);
        DNASeqCount += Check;
        start++;
        end++;
    }

    cout << DNASeqCount << "\n";
}