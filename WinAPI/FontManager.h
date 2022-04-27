#pragma once
#include "Stdafx.h"
#include "SingletonBase.h"


class FontManager : public SingletonBase <FontManager>
{

public:
	void drawText(HDC hdc, int destX, int destY, char* fileName, char* fontName, int fontsize,
		int fontWidth, char* printString, int length, COLORREF color);

	void drawText(HDC hdc, int destX, int destY, char* fontName, int fontsize, int fontWidth,
		char* printString, int length, COLORREF color);

	//LPCWSTR(W) -> wide char -> UniCode
	void drawText(HDC hdc, int destX, int destY, char* fontName, int fontsize, int fontWidth,
		LPCWSTR printString, int length, COLORREF color);
	
	void drawText(HDC hdc, int destX, int destY, char* fontName, int fontsize, int fontWidth,
		LPCWSTR* printStringArr, int length, COLORREF color);


	FontManager() {}
	~FontManager() {}
};

