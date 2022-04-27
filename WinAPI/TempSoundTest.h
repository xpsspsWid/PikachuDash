#pragma once
#include "Stdafx.h"
#include "GameNode.h"

class TempSoundTest:public GameNode
{
public:
	HRESULT init(void);
	void update(void);

		TempSoundTest(){}
		~TempSoundTest(){}
		
};

