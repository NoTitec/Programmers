// 12_Lock_and_Key.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//2차원 리스트 회전 함수 구현
vector<vector<int>> rotateMatrix(vector<vector<int>> originMatrix)
{
    //행 길이
    int n = originMatrix.size();
    //열 길이
    int m = originMatrix[0].size();
    //회전 결과 담을 2차원 리스트
    vector<vector<int>> result(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[j][n - i - 1] = originMatrix[i][j];
        }
    }
    return result;
}
//확장 자물쇠의 가운데 부분이 모두 1인지 확인
bool check(vector<vector<int>>extendedlock)
{
    int keyn = extendedlock.size() / 3;
    //가운데 행범위만큼
    for (int i = keyn; i < keyn * 2; i++)
    {
        //가운데 열 범위만큼
        for (int j = keyn; j < keyn * 2; j++)
        {
            //모든 리스트값이 1이아니면 열쇠가 맞지 않는것
            if (extendedlock[i][j] != 1)
            {
                return false;
            }
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    //key 크기
    int m = key.size();
    //lock 크기
    int n = lock.size();
    //key를 회전뿐아니라 이동도 가능하므로 이동시키기위해 lock을 3배로 확장
    vector<vector<int>> extendedlock(n * 3, vector<int>(n * 3));
    //확장 lock의 중앙에 원래 lock값 복사
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            extendedlock[i + n][j + n] = lock[i][j];
        }
    }
    //4방향 모두 확인
    for (int rotate = 0; rotate < 4; rotate++)
    {
        key = rotateMatrix(key);
        //열쇠를 옮기기
        for (int x = 0; x < n * 2; x++)
        {
            for (int y = 0; y < n * 2; y++)
            {
                //현재 x,y 위치에서 열쇠 넣기 (왼쪽 상단부터 넣음)
                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        extendedlock[x + i][y + j] += key[i][j];
                    }
                }
                //열쇠가 딱 맞으면 true반환하고 종료
                if (check(extendedlock)) return true;
                //안맞으면 열쇠 안맞는 것이므로 열쇠 다시 빼기
                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        extendedlock[x + i][y + j] -= key[i][j];
                    }
                }
            }
        }
    }
    return answer;
}

int main()
{
    return 0;
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
