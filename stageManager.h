#pragma once
#include "gameNode.h"
#include "UI.h"
#include "itemManager.h"

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

class stageManager : public gameNode
{
private:
	UI* _ui;
	itemManager* _itemMg;

	bool _isInven;

public:
	stageManager() {}
	~stageManager() {}

public:
	HRESULT init();
	void render();
	void update();
	void release();
};

