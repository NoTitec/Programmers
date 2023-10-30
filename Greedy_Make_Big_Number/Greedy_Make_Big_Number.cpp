// Greedy_Make_Big_Number.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;
//앞 숫자부터 가능한한 큰 숫자를 골라야함
string solution(string number, int k) {
    string answer = "";
    //답변 숫자 길이
    int returnsize = number.size() - k;
    //탐색 시작 index, 초기값은 0
    int startindex = 0;
    //returnsize 만큼 반복하며 answer넣을 문자 1개씩 추출
    for (int i = 0; i < returnsize; i++)
    {
        //최대문자 1개 추출
        char maxchar = number[startindex];
        //max 숫자index 저장
        int maxindex = startindex;
        //0~k index까지의 숫자중 가장큰수 추출, 한번 for문돌때마다 startidx~k+1 범위에서 추출
        //이유 : 앞에서부터 가능한한 큰 수 들을 뽑아내야 하는데 그러러면 뽑아낸 수 뒤쪽에 k-i개의 숫자가 남아있어야
        //최종 숫자길이 k개를 구성할 수있다
        // k+i 범위 뒤쪽의 숫자를 추출해버리면 이 후 k길이 숫자를 만들어 낼 수 가 없게 된다
        for (int j = startindex; j <= k + i; j++) { // startidx부터 k+i까지 확인해서 max값 찾음 -k
            if (maxchar < number[j])
            {
                maxchar = number[i];
                maxindex = j;
            }
        }
        //다음 탐색 시작 index
        startindex = maxindex+1;
        answer += maxchar;
    }
    return answer;
}
int main()
{
    
    cout << solution("",3 );
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
