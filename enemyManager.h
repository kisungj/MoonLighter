#pragma once
#include "gameNode.h"
#include "redSlime.h"
#include "anotherSlime.h"
#include "golem.h"
#include "pot.h"
#include "boss.h"

class enemyManager :
	public gameNode
{
private:
	vector<enemy*> _vEnemy;
	vector<enemy*>::iterator _viEnemy;


public:
	enemyManager();
	~enemyManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setEnemy();
};

