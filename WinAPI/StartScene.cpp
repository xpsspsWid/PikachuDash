#include "Stdafx.h"
#include "StartScene.h"

HRESULT StartScene::init(void)
{
	IMAGEMANAGER->addImage("시작화면", "Resources/BackGround/Main.bmp", WINSIZEX, WINSIZEY);

	_alpha = _bgAlpha = 0;
	_isAlphaIncrease = false;

	return E_NOTIMPL;
}

void StartScene::release(void)
{
}

void StartScene::update(void)
{
	_bgAlpha += 1.0f;
	if (_bgAlpha >= 255) _bgAlpha = 255;
	if (_alpha == 0 || _alpha == 255) _isAlphaIncrease = !_isAlphaIncrease;
	if (_isAlphaIncrease) _alpha += 1.0f; else _alpha -= 1.5f;
}

void StartScene::render(void)
{
	IMAGEMANAGER->alphaRender("시작화면", getMemDC(), 0, 0, _bgAlpha);
	if (_bgAlpha >= 160)
	{
	}
}
