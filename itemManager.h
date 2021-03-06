#pragma once
#include "gameNode.h"
#include "item.h"

class itemManager :	public gameNode
{
private:
	vector<item*> _vItem;

public:
	itemManager() {}
	~itemManager() {}

	HRESULT init();
	void release();
	void update(player* player);
	void render();

	void setItem(ITEMBUNDLE bundle, float x, float y);
	void popItem(ITEMTYPE type, float x, float y);
	void erase(int arrNum);
	vector<item*> getVItem() { return _vItem; }
};