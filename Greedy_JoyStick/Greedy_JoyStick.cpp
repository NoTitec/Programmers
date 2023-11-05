// Greedy_JoyStick.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include<bits/stdc++.h>
using namespace std;

int solution(string name) {
    int answer = 0;

    int length2 = 0;

    //이름 알파벳에 A가 한개도 없는경우 모든 문자들에대해 updown해야하므로 초기는 이름길이-1
    int leftright = name.size() - 1;

    int namelength = name.size();
    //알파뱃 1개씩 순회하며 조이스틱 전환 횟수 찾기
    for (int i = 0; i < name.size(); i++)
    {
        //현재 알파뱃1개를 A에서 원하는 알파뱃으로 전환하는 최소 조이스틱 조작 횟수
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);

        //현재 알파벳 위치+1에서부터 A가 아닌 index 찾기
        int idx2 = i + 1;
        while (idx2 < namelength)
        {
            if (name[idx2] == 'A') idx2++;
            else break;
        }
        //끝위치부터 A가아닌 idx2까지의 길이
        length2 = namelength - idx2;
        //현재상태에서 leftright 최소값은 현재까지의 계산 leftright 과 
        //0~현재 알파벳 위치까지 길이+length2+0~현재알파벳 위치까지 길이와 length2중 작은값
        //중에서 더 작은값
        leftright = min(leftright, i + length2 + min(i, length2));
    }
    return answer + leftright;
}

int main()
{
    cout << solution("JAN");
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
