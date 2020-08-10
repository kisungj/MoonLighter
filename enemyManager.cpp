#include "stdafx.h"
#include "enemyManager.h"

enemyManager::enemyManager()
{
}

enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init()
{
	_x = 600;
	_y = 300;
	_rc = RectMakePivot(Vector2(_x, _y), Vector2(50, 50), Pivot::Center);
	_bulletDelay = 0;
	setEnemy();

	_bullet = new bullet;
	_bullet->init();
	


	return S_OK;
}

void enemyManager::release()
{
	SAFE_DELETE(_bullet);
}

void enemyManager::update()
{
	_bulletDelay++;
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		_vEnemy[i]->update();
		_vEnemy[i]->playerCheck(_x, _y);	//나중에 여기에 플레이어 위치 넣어주셈
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_y -= 2;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_y += 2;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= 2;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += 2;
	}

	if (_bulletDelay > 90)
	{
		potBullet();

	}
	_bullet->update();
	//cout << _testCount << endl;
	_rc = RectMakePivot(Vector2(_x, _y), Vector2(50, 50), Pivot::Center);
}

void enemyManager::render()
{
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		_vEnemy[i]->render();
	}
	_bullet->render();

	D2DRenderer::GetInstance()->DrawRectangle(_rc, D2DRenderer::DefaultBrush::Black, 1.f);
}

void enemyManager::setEnemy()
{
	int i = 0;

	enemy* redS1;
	redS1 = new redSlime;
	redS1->playerCheck(_x, _y);
	redS1->init(i, 200, 200, 70, 70, ENEMY_RED_SLIME);
	_vEnemy.push_back(redS1);

	i++;

	enemy* gol1;
	gol1 = new golem;
	gol1->playerCheck(_x, _y);
	gol1->init(i, 700, 500, 80 , 100, ENEMY_GOLEM);
	_vEnemy.push_back(gol1);

	i++;

	enemy* pot1;
	pot1 = new pot;
	pot1->playerCheck(_x, _y);
	pot1->init(i , 1200, 500, 50, 50, ENEMY_POT);
	_vEnemy.push_back(pot1);

	
	i++;


	enemy* pot2;
	pot2 = new pot;
	pot2->playerCheck(_x, _y);
	pot2->init(i, 200, 300, 50, 50, ENEMY_POT);
	pot2->setPotDirection(POT_RIGHT);
	_vEnemy.push_back(pot2);

	
	i++;

	enemy* yelS1;
	yelS1 = new anotherSlime;
	yelS1->playerCheck(_x, _y);
	yelS1->init(i , 200, 100, 50, 50, ENEMY_YELLOW_SLIME);
	_vEnemy.push_back(yelS1);

	i++;

	enemy* bleS1;
	bleS1 = new anotherSlime;
	bleS1->playerCheck(_x, _y);
	bleS1->init(i, 400, 100, 50, 50, ENEMY_BLUE_SLIME);
	_vEnemy.push_back(bleS1);



}

void enemyManager::potBullet()
{
	_bulletDelay = 0;
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		if (_vEnemy[i]->getEnemyType() == ENEMY_POT)
		{
			if (_vEnemy[i]->getPotDirection() == POT_LEFT)
			{
				_bullet->fire(_vEnemy[i]->getX(), _vEnemy[i]->getY(), PI, 3.f);
			}
			if (_vEnemy[i]->getPotDirection() == POT_RIGHT)
			{
				_bullet->fire(_vEnemy[i]->getX(), _vEnemy[i]->getY(), PI2, 3.f);
			}
			if (_vEnemy[i]->getPotDirection() == POT_TOP)
			{
				_bullet->fire(_vEnemy[i]->getX(), _vEnemy[i]->getY(), PI * 2.5, 3.f);
			}
			if (_vEnemy[i]->getPotDirection() == POT_BOTTOM)
			{
				_bullet->fire(_vEnemy[i]->getX(), _vEnemy[i]->getY(), PI *3.5, 3.f);
			}

		}
	}
}
