#pragma once
#include "gameNode.h"
#include "objectManager.h"
#include "tile.h"
#define DUNTILEX 32
#define DUNTILEY 18

class spaStage : public gameNode
{
	class player*     _player;
	Image*            _mapImg;

	DWORD             _attribute[DUNTILEX * DUNTILEY];
	tagTile			  _tile[DUNTILEX * DUNTILEY];
	objectManager*    _objectManager;

	int               _spaCount;    // 회복 카운트

public:
	spaStage() {}
	~spaStage() {}
public:

	HRESULT init();
	void render();
	void update();
	void release();

	void setPlayerLink(player* player) { _player = player; };
	void loadMap();
	void renderMap();
};

