// Alien_Dictionary.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 0;
    //spell 크기
    int spelllength = spell.size();
    //현재 dic 문자열 길이담을 변수
    int curdiclength = 0;
    //spell 원소 사전순 정렬
    sort(spell.begin(), spell.end());

    //dic 길이만큼 순회
    for (int i = 0; i < dic.size(); i++)
    {
        //현재 순회의 dic 문자열 1개
        string curdic = dic[i];
        //spell 크기랑 현재 dic 문자열 길이 같으면
        if (spelllength == curdic.size())
        {
            //dic문자열 사전순 정렬
            if (!curdic.empty()) {
                sort(curdic.begin(), curdic.end());
            }
            string sortedcurdic = curdic;
            //spell vector 원소 합쳐서 1개 string만들기(정렬은 위에서 사전에 1번 수행)
            string sortedspell;
            for (const auto& s : spell)
            {
                sortedspell += s;
            }
            //정렬한 dic 문자열과 정렬하고합친 spell 문자열 동일하면 return 1
            if (sortedcurdic.compare(sortedspell) == 0)
            {
                return 1;
            }
        }
        else
        {
            continue;
        }
    }
    answer = 2;
    return answer;
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
