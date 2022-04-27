#include "Stdafx.h"
#include "SecondScene.h"

HRESULT SecondScene::init(void)
{
	IMAGEMANAGER->addImage("¹è°æ", "Resources/BackGround/BI.bmp", WINSIZEX, WINSIZEY);

	IMAGEMANAGER->addFrameImage("ÇÇÄ«Ãò", "Resources/Images/RunPika.bmp", WINSIZEX, WINSIZEY,
		220, 40, 4, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("ÄÉÂý", "Resources/Images/Ketchup.bmp", 20, 50, true, RGB(255, 0, 255));

	pikachu.rc = RectMakeCenter(WINSIZEX / 2 - 350, WINSIZEY / 2 + 210, 64, 40);

	for (int i = 0; i < MAX_KETCHUP; i++)
	{
		ketchup[i].rc = RectMake(RND->getFromFloatTo(WINSIZEX, WINSIZEX + 1200), 400, 20, 50);
		ketchup[i].speed = 5;
	}

	_tempSound = new TempSoundTest;
	_tempSound->init();

	_offsetX = _offsetY = 0;

	_bgSpeed = 0;

	count = index1 = 0;

	Pikachuspeed = 5;

	jumpcount = 0;

	score = 0;

	ground = WINSIZEY - 70;
	pikachu.jump = false;

	_textBufferCnt = 0;

	return S_OK;
}

void SecondScene::release(void)
{
}

void SecondScene::update(void)
{
	_tempSound->update();

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE) &&! jumpcount)
	{
		TEMPSOUNDMANAGER->playEffectSoundWave("Resources/Music/Pikaaaa.wav");
		int n = 0;
		jumpStart();
	}

	playerMove();

	_bgSpeed += 3;

	count++;
	if (count % 8 == 0)
	{
		index1++;
		if (index1 > 4)
		{
			index1 = 0;
		}
	}

	for (int i = 0; i < MAX_KETCHUP; i++)
	{
		ketchup[i].rc.right -= ketchup[i].speed;
		ketchup[i].rc.left -= ketchup[i].speed;

		if (ketchup[i].rc.right < 0)
		{
			ketchup[i].rc = RectMake(1000, 300, 20, 50);
		}
	}

	for (int i = 0; i < MAX_KETCHUP; i++)
	{
		if (IntersectRect(&temp, &pikachu.rc, &ketchup[i].rc))
		{
			ketchup[i].rc = RectMake(RND->getFromFloatTo(WINSIZEX + 300, WINSIZEX),
				400, 20, 50);
			score += 100;
		}
	}
}

void SecondScene::render(void)
{
	cout << ground << endl;
	IMAGEMANAGER->loopRender("¹è°æ", getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), _bgSpeed, 0);
	IMAGEMANAGER->frameRender("ÇÇÄ«Ãò", getMemDC(), pikachu.rc.left, pikachu.rc.top, index1, 0);
	for (int i = 0; i < MAX_KETCHUP; i++)
	{
		IMAGEMANAGER->render("ÄÉÂý", getMemDC(), ketchup[i].rc.left, ketchup[i].rc.top);
	}

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), pikachu.rc.left, pikachu.rc.top, pikachu.rc.right, pikachu.rc.bottom);

		for (int i = 0; i < MAX_KETCHUP; i++)
		{
			Rectangle(getMemDC(), ketchup[i].rc.left, ketchup[i].rc.top, ketchup[i].rc.right, ketchup[i].rc.bottom);
		}
	}
	
	char strscore[128];
	wsprintf(strscore, "SCORE: %d", score);
	TextOut(getMemDC(), 30, 20, strscore, strlen(strscore));

}

void SecondScene::playerMove()
{
	if (pikachu.jump)
	{
		pikachu.rc.bottom -= pikachu.speed + pikachu.gravity;
		pikachu.rc.top -= pikachu.speed + pikachu.gravity;
		pikachu.gravity -= 0.4;
	}

	if (pikachu.rc.bottom > ground)
	{
		pikachu.rc.bottom -= 10;
		pikachu.rc.top -= 10;
		pikachu.jump = false;
		jumpcount = 0;
	}
}

void SecondScene::jumpStart()
{
	pikachu.jump = true;
	pikachu.speed = 8.0f;
	pikachu.gravity = 0.0f;
	jumpcount++;
}
