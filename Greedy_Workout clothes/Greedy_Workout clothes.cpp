// Greedy_Workout clothes.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <bits/stdc++.h>
using namespace std;
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    //찾을때 자기 앞뒤 찾으므로 자기 앞 1칸 여유,뒤 1칸 여유 index위해 +2 크기만큼생성
    vector<int> haveStudent(n+2, 1);

    //도난당한사람 -1해서 0으로
    //주의 lost와 reserve의 번호는 해당 학생의 실제 번호이다 따라서 실제 변하는 haveStudent의 위치는
    //i+1위치이다 예를들어 lost의 번호가 2이면 haveStudent[3]의 번호가 바뀌는 것임을 유의하라
    for (int i : lost)
    {
        haveStudent[i] -- ;
    }
    //여분 가져온 사람 +1
    for (int i : reserve)
    {
        haveStudent[i]++;
    }

    //haveStudent vector순회하면서 수정하기
    for (int i = 1; i <= n; i++)
    {
        if (haveStudent[i] < 1)
        {
            if (haveStudent[i - 1] == 2)
            {
                haveStudent[i]++;
                haveStudent[i-1]--;
            }
            else if (haveStudent[i + 1] == 2)
            {
                haveStudent[i]++;
                haveStudent[i + 1]--;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (haveStudent[i] >= 1)
        {
            answer++;
        }
    }
    return answer;
}

int main()
{
    
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
