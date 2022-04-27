#pragma once
#include "GameNode.h"
#include "TempSoundTest.h"

#define MAX_KETCHUP 10

struct Player
{
	RECT rc;
	float speed;
	float gravity;
	bool jump;
};

struct Object
{
	RECT rc;
	float speed;
};

class SecondScene : public GameNode
{

private:

	Player pikachu;
	Object ketchup[MAX_KETCHUP];
	int count;
	int index1;
	int ground;

	RECT temp;
	int Pikachuspeed;

	int score;

	TempSoundTest* _tempSound;

	int _offsetX, _offsetY;
	int _bgSpeed;
	
	int _textBufferCnt;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	int jumpcount;

	void playerMove();
	void jumpStart();

	SecondScene() {}
	~SecondScene() {}
};

