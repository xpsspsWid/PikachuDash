#pragma once
//===========================================================
// # commomMacroFunction # (필요한 함수는 직접 만들어 추가하자)
//===========================================================

inline POINT PointMake(int x, int y)
{
	POINT pt = { x, y };
	return pt;
}

inline void LineMake(HDC hdc, int startX, int startY, int endX, int endY)
{
	MoveToEx(hdc, startX, startY, NULL);
	LineTo(hdc, endX, endY);
}

inline RECT RectMake(int x, int y, int width, int height)
{
	RECT rc = { x, y, x + width, y + height };
	return rc;
}

inline RECT RectMakeCenter(int x, int y, int width, int height)
{
	RECT rc = { x - width / 2, y - height / 2, x + width / 2, y + height / 2 };
	return rc;
}

inline void RectangleMake(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x, y, x + width, y + height);
}

inline void EllipseMake(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x, y, x + width, y + height);
}

inline void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
}

/*
실습 1. 종스크롤 슈팅 게임(세로)

-플레이어 체력바 설정( 적과 충돌하면 체력 감소)

-플레이어가 발사한 총알로 적 제거
--------------------------------------------------
과제1. 1 vs 1 횡스크롤 슈팅 게임(가로)

-왼쪽에 1p, 오른쪽에 2p 배치

-체력 바는 대전 게임처럼 중알을 기준으로 좌우로 배치

-공격을 당한쪽은 체력 감소

-체력 상태에 따라 체력바의 색상 변경 (녹, 노, 빨)

-필수: 스킬 6개 = 3 + 3= 6개
*/

/*
월, 화 부재
-과제 5개

과제1. 포신의 각도에 따라 총알 발사

-쏘면 되고 추가로 자동 포탑
========================================================
과제2. 발사된 총알끼리 서로 충돌

-총알 끼리 충돌이 발생하면 자연스럽게 팅겨 나가야 한다.
일자로 쏴보면서 테스트
========================================================
과제3. 발사한 총알에 중력 적용

※발사된 총알 예외 처리
-3번 과제 제외
-발사된 총알은 화면밖으로 나갈 수 없다.
-주의사항: 발사된 총알이 화면 끝점에 닿아 팅겨 나올때 각도에 신경쓴다.
====================================================================
과제4. 지렁이 만들기

+ 아이템 까지
=======================================================================
과제5. 충돌

과제 5-1. 원 -> 사각 충돌

-원을 마우스로 선택해 드래그로 움직일 수 있다.

-현재 움직이고 있는 원이 사각형과 충돌이 발생하면 사각형을 밀어낸다.

과제 5-2. 사각 -> 원 충돌

5-1의 반대
*/

/*
과제1. 사과 나무 서리
포쏴서 사과나무에 사과가 맞고 사과가 날라가야한다 포 는 곡선

과제2. 두더지
-이미지 입혀온다.
*/

/*
과제1. 슬라이드
-치트 필수

-화면 왼쪽에 원본 출력 ,화면 오른쪽에는 9등분된 이미지 출력

-퍼즐이 완성되면 알파블렌딩 효과로 이미지가 나타난다.

-조작 방식은 2개 다 해온다 (마우스, 키보드)

과제2.미니맵 만들기
-플레이어의 움직임을 미니맵에서도 확인 가능해야 한다.

*/

/*
과제1. 이미지 편집 연습
-시작 씬 + 게임 씬
-게임씬에서는 아래의 이미지를 프레임 렌더로 돌린다.
-필수 이미지: 배경, 대기, 이동 (좌 + 우), 찌르기(좌 + 우), 대각선 찌르기, 연속 찌르기( 좌 +우), 원 돌리기, 승리 포즈 (옷 던지기)

과제2. 틀린 그림 찾기
-이미지는 왠만하면 포토샵
-스테이지는 총2개 (틀린곳은 다섯 곳 이상)
-게임이 시작되면 타임 게이지가 점점 줄어들고 잘못 클릭하면 시간 감소
-틀린곳을 맞추면 시간 증가
-타임 게이지가 소진되면 게임 오버 화면을 띄우며 게임 종료

과제3. 플레이어 체력 관리 (플레이어 -> 당신)
-대기 상태에서 편안한 휴식을 하면 체력이 회복된다 (+++)
*/

/*
과제1. 캐릭터 벽잡기
-이미지 필수 (배경, 벽, 캐릭터: 대기, 이동(좌 + 우), 점프(상승 + 하강),
벽을 잡고 있는 모션)

-기본적으로 벽을 잡을때는 가장 위쪽 모서리를 잡는다. (홀드)
	ㄴ벽 중간을 잡으면 천천히 지면으로 내려간다.

-캐릭터가 벽을 잡고 있는 상태에서 위또는 아래 방향키를 누르면 올라가거나 내려갈 수 있어야
한다.

-캐릭터가 벽 위로 올라선 다음 다시 아래로 점프하면 캐릭터는 지면에 착지 할 수 있어야 한다.

-캐릭터 점프 높이의 지형이 있고 캐릭터는 지형 밑에서 점프로 지형위로 올라 갈수 있다.

-캐릭터는 지형에 올라선 상태에서 지면으로 닷 ㅣ내려올수 있으면 OK
*/
/*
조건: 총원 -> 25명 -> 20명
과제1. 레이싱 게임

-종스크롤

-이미지 필수 (배경 + 자동차 (플레이어 + 적) + 계기판)

-계기판은 반드시 있어야 한다.

-계기판은 차 속력에 따라 변화한다.

-속도감이 생명


-플레이어와 적이 충돌화면 폭파 이펙트가 터지면서 게임 종료
*/
