#pragma once
#include "GameNode.h"

class StartScene : public GameNode
{
private:
	float _alpha;
	float _bgAlpha;

	bool _isAlphaIncrease;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);


	StartScene() {}
	~StartScene() {}

};

