#include "stdafx.h"
#include "enemyManager.h"
#include "player.h"
#include "boss.h"
#include "itemManager.h"

enemyManager::enemyManager()
{
}

enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init(vector<POINT> unMoveTile)
{
	_unMoveTile = unMoveTile;
	_x = _player->getX();
	_y = _player->getY();
	_rc = _player->getPlayerRc();
	_bulletDelay = 0;
	_bulletWait = 0;
	_bulletTimer = 0;
	_index = 0;
	_bossHit = false;
	_bullet = new bullet;
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		if (_vEnemy[i]->getEnemyType() == ENEMY_POT)
		{
			_bulletDis = 260;
			_bullet->init("bullet");
		}
		if (_vEnemy[i]->getEnemyType() == ENEMY_BOSS)
		{
			_bulletDis = 1500;
			_bullet->init("bossBullet");
		}
	}
	_playerStop = false;


	return S_OK;
}

void enemyManager::release()
{
	SAFE_DELETE(_bullet);
	//SOUNDMANAGER->release();
}

void enemyManager::update()
{
	//cout << _bossHit << endl;
	_x = _player->getX();
	_y = _player->getY();
	//EFFECTMANAGER->play("bossTornadoEffect", _player->getX(), _player->getY());
	_rc = _player->getPlayerRc();
	_bulletDelay++;
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		_vEnemy[i]->update();
		_vEnemy[i]->playerCheck(_x, _y, _rc, _player->getPlayerMoveTrap());

	}
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		_angle = getAngle(_player->getX(), _player->getY(), _vEnemy[i]->getX(), _vEnemy[i]->getY());
		_bulletAngle = getAngle(_vEnemy[i]->getX(), _vEnemy[i]->getY(), _player->getX(), _player->getY());
		RECT temp;
		if (_vEnemy[i]->getEnemyType() == ENEMY_RED_SLIME && _vEnemy[i]->getState() == _vEnemy[i]->getAttack() && _player->getCurrectState() != _player->getRollState())
		{
			if (IntersectRect(&temp, &_vEnemy[i]->getEnemyAttackRect().GetRect(), &_player->getPlayerRc().GetRect()) && !_vEnemy[i]->getIsCol())
			{
				_vEnemy[i]->setIsCol(true);
				_player->setPlayerMoveTrap(true);
			}
			if (_vEnemy[i]->getIsCol())
			{
				if (!_player->getPlayerMoveTrap())
				{
					_vEnemy[i]->setIsCol(false);
				}
			}

		}

		if (_vEnemy[i]->getEnemyType() == ENEMY_POT)
		{
			_bulletWait = 90;
		}
		if (_vEnemy[i]->getEnemyType() == ENEMY_BOSS)
		{
			if (_vEnemy[i]->getBossPattern() == BOSS_BULLET_FIRE)
			{
				_bulletWait = 40;
			}
			if (_vEnemy[i]->getBossPattern() == BOSS_BULLET_PFIRE)
			{
				_bulletWait = 30;
			}
		}
	}
	_bullet->update(_bulletDis);
	if (_bulletDelay > _bulletWait)
	{
		potBullet();
	}
	playerCol();
	bulletCol();
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		if (_vEnemy[i]->getRealDead())
		{
			switch (_vEnemy[i]->getEnemyType())
			{
			case ENEMY_RED_SLIME:
				_itemManager->setItem(ITEMBUNDLE::SLIME_RED, _vEnemy[i]->getX(), _vEnemy[i]->getY());
				enemyDead(i);
				break;
			case ENEMY_BLUE_SLIME:
				_itemManager->setItem(ITEMBUNDLE::SLIME_BLUE, _vEnemy[i]->getX(), _vEnemy[i]->getY());
				enemyDead(i);
				break;
			case ENEMY_YELLOW_SLIME:
				_itemManager->setItem(ITEMBUNDLE::SLIME_YELLOW, _vEnemy[i]->getX(), _vEnemy[i]->getY());
				enemyDead(i);
				break;
			case ENEMY_GOLEM:
				_itemManager->setItem(ITEMBUNDLE::GOLEM_KNIGHT, _vEnemy[i]->getX(), _vEnemy[i]->getY());
				enemyDead(i);
				break;
			case ENEMY_POT:
				_itemManager->setItem(ITEMBUNDLE::GOLEM_POT, _vEnemy[i]->getX(), _vEnemy[i]->getY());
				enemyDead(i);
				break;
			case ENEMY_BOSS:
				_itemManager->setItem(ITEMBUNDLE::GOLEM_KING, _vEnemy[i]->getX(), _vEnemy[i]->getY() + 200);
				_vEnemy[i]->setRealDead(false);
				break;
			}
			break;
		}
	}
	EFFECTMANAGER->update();
}

void enemyManager::render()
{
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		_vEnemy[i]->render();
		if (_vEnemy[i]->getEnemyType() == ENEMY_POT)
		{
			_bullet->potRender();
		}
		if (_vEnemy[i]->getEnemyType() == ENEMY_BOSS)
		{
			_bullet->bossRender();
		}
	}

	//CAMERAMANAGER->fillRectangle(_rc, D2D1::ColorF::DimGray, 1.0);
	//D2DRenderer::GetInstance()->DrawRectangle(_rc, D2DRenderer::DefaultBrush::Black, 1.f);
	ImageManager::GetInstance()->FindImage("bulletCollision")->SetScale(1.5f);
	EFFECTMANAGER->render();
}

void enemyManager::setEnemy1(vector<POINT> unMoveTile)
{
	enemy* gol1;
	gol1 = new golem;
	//gol1->playerCheck(_x, _y, _rc);
	gol1->init(100, 100, 80, 100, ENEMY_GOLEM, unMoveTile);
	_vEnemy.push_back(gol1);

	enemy* gol12;
	gol12 = new golem;
	//gol12->playerCheck(_x, _y, _rc);
	gol12->init(100, 700, 80, 100, ENEMY_GOLEM, unMoveTile);
	_vEnemy.push_back(gol12);

	enemy* pot1;
	pot1 = new pot;
	//pot1->playerCheck(_x, _y, _rc);
	pot1->init(475, 600, 50, 50, ENEMY_POT, unMoveTile);
	pot1->setPotDirection(POT_BOTTOM);
	_vEnemy.push_back(pot1);

	enemy* pot22;
	pot22 = new pot;
	//pot22->playerCheck(_x, _y, _rc);
	pot22->init(1070, 600, 50, 50, ENEMY_POT, unMoveTile);
	pot22->setPotDirection(POT_BOTTOM);
	_vEnemy.push_back(pot22);



	enemy* pot2;
	pot2 = new pot;
	//pot2->playerCheck(_x, _y, _rc);
	pot2->init(475, 280, 50, 50, ENEMY_POT, unMoveTile);
	pot2->setPotDirection(POT_TOP);
	_vEnemy.push_back(pot2);

	enemy* pot3;
	pot3 = new pot;
	//pot2->playerCheck(_x, _y, _rc);
	pot3->init(1070, 280, 50, 50, ENEMY_POT, unMoveTile);
	pot3->setPotDirection(POT_TOP);
	_vEnemy.push_back(pot3);

	//enemy* gost;
	//gost = new pot;
	////gost->playerCheck(_x, _y, _rc);
	//gost->init(-300, -300, 50, 50, ENEMY_POT);
	//gost->setPotDirection(POT_RIGHT);
	//_vEnemy.push_back(gost);


}

void enemyManager::setEnemy2(vector<POINT> unMoveTile)
{



	enemy* redS1;
	redS1 = new redSlime;
	//redS1->playerCheck(_x, _y, _rc);
	redS1->init(800, 200, 70, 70, ENEMY_RED_SLIME, unMoveTile);
	_vEnemy.push_back(redS1);

	enemy* redS2;
	redS2 = new redSlime;
	//redS1->playerCheck(_x, _y, _rc);
	redS2->init(800, 600, 70, 70, ENEMY_RED_SLIME, unMoveTile);
	_vEnemy.push_back(redS2);


	enemy* yelS1;
	yelS1 = new anotherSlime;
	//yelS1->playerCheck(_x, _y, _rc);
	yelS1->init(500, 500, 30, 30, ENEMY_YELLOW_SLIME, unMoveTile);
	_vEnemy.push_back(yelS1);


	enemy* bleS1;
	bleS1 = new anotherSlime;
	//bleS1->playerCheck(_x, _y, _rc);
	bleS1->init(500, 700, 30, 30, ENEMY_BLUE_SLIME, unMoveTile);
	_vEnemy.push_back(bleS1);

	enemy* yelS2;
	yelS2 = new anotherSlime;
	//yelS1->playerCheck(_x, _y, _rc);
	yelS2->init(1500, 600, 30, 30, ENEMY_YELLOW_SLIME, unMoveTile);
	_vEnemy.push_back(yelS2);


	enemy* bleS3;
	bleS3 = new anotherSlime;
	//bleS1->playerCheck(_x, _y, _rc);
	bleS3->init(1000, 700, 30, 30, ENEMY_BLUE_SLIME, unMoveTile);
	_vEnemy.push_back(bleS3);

	enemy* yelS3;
	yelS3 = new anotherSlime;
	//yelS1->playerCheck(_x, _y, _rc);
	yelS3->init(900, 200, 30, 30, ENEMY_YELLOW_SLIME, unMoveTile);
	_vEnemy.push_back(yelS3);


	enemy* bleS2;
	bleS2 = new anotherSlime;
	//bleS1->playerCheck(_x, _y, _rc);
	bleS2->init(1500, 450, 30, 30, ENEMY_BLUE_SLIME, unMoveTile);
	_vEnemy.push_back(bleS2);


}

void enemyManager::setBoss()
{
	enemy* boss1;
	boss1 = new boss;
	//boss1->playerCheck(_x, _y, _rc);
	boss1->init(1360, 300, 590, 650, ENEMY_BOSS, _unMoveTile);
	_vEnemy.push_back(boss1);
}

void enemyManager::potBullet()
{
	_bulletDelay = 0;
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		if (_vEnemy[i]->getEnemyType() == ENEMY_POT && _vEnemy[i]->getState() != _vEnemy[i]->getDead())
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
			SOUNDMANAGER->play("�Ѿ˽��", 1.0f);
		}
		//cout << _bulletTimer << endl;
		if (_vEnemy[i]->getEnemyType() == ENEMY_BOSS && _vEnemy[i]->getState() == _vEnemy[i]->getAttack())
		{
			if (_vEnemy[i]->getBossPattern() == BOSS_BULLET_FIRE)
			{
				float random = RND->getFromFloatTo(2.5, 3.8);
				_bullet->manyFire(_vEnemy[i]->getX(), _vEnemy[i]->getY(), random, 5.f, 10);
				_bulletTimer++;
				SOUNDMANAGER->play("���彽���Ӱ���", 1.0f);
				if (_bulletTimer > 10)
				{
					_bullet->getVBullet().clear();
					//cout << " = ==" << endl;
					//b->setPatternCheck(false);
					_vEnemy[i]->setPatternCheck(false);
					_vEnemy[i]->setState(_vEnemy[i]->getIdle());
					_vEnemy[i]->setAttackDelay(0);
					_bulletTimer = 0;
				}
			}
			if (_vEnemy[i]->getBossPattern() == BOSS_BULLET_PFIRE)
			{
				_bullet->fire(_vEnemy[i]->getX(), _vEnemy[i]->getY(), _bulletAngle, 10.0f);
				_bulletTimer++;
				SOUNDMANAGER->play("���彽���Ӱ���", 1.0f);
				if (_bulletTimer > 20)
				{
					_bullet->getVBullet().clear();
					//b->setPatternCheck(false);
					_vEnemy[i]->setPatternCheck(false);
					_vEnemy[i]->setState(_vEnemy[i]->getIdle());
					_vEnemy[i]->setAttackDelay(0);
					_bulletTimer = 0;
				}
			}
		}


	}
}

void enemyManager::playerCol()
{
	RECT temp;

	if (_player->getplayerCurrentHp() <= 0)
	{
		_player->setPlayerCurrentHp(0);
	}
	//���浹
	for (int i = 0; i < _vEnemy.size(); ++i)
	{
		if (IntersectRect(&temp, &_vEnemy[i]->getEnemyRect().GetRect(), &_player->getPlayerAttackRc().GetRect()))
		{
			EFFECTMANAGER->play("swordEffect1", (temp.left + temp.right) / 2, ((temp.top + temp.bottom) / 2) + 10);
			_vEnemy[i]->setEnemyAttack(30);
			//	CAMERAMANAGER->shakeCamera(5, 10);
			_player->setAttackRc(0, 0, 0, 0);
			if (_vEnemy[i]->getEnemyType() == ENEMY_BLUE_SLIME || _vEnemy[i]->getEnemyType() == ENEMY_RED_SLIME || _vEnemy[i]->getEnemyType() == ENEMY_YELLOW_SLIME)
			{
				SOUNDMANAGER->play("�����Ӹ���", 1.0f);
			}
			if (_vEnemy[i]->getEnemyType() == ENEMY_GOLEM)
			{
				SOUNDMANAGER->play("�񷽸���", 1.0f);
			}
			if (_vEnemy[i]->getEnemyType() == ENEMY_POT)
			{
				SOUNDMANAGER->play("�Ѿ�����", 1.0f);
			}
			if (_vEnemy[i]->getEnemyType() == ENEMY_BOSS)
			{
				if (!SOUNDMANAGER->isPlaySound("��������"))
					SOUNDMANAGER->play("��������", 1.0f);
			}
		}

		//Ȱ�浹

		for (int j = 0; j < _player->getArrow()->getVArrow().size(); ++j)
		{
	
			if (IntersectRect(&temp, &_vEnemy[i]->getEnemyRect().GetRect(), &_player->getArrow()->getVArrow()[j].rc.GetRect()) && !_vEnemy[i]->getIsPowerShot())
			{
				SOUNDMANAGER->play("bow_Attack", 1.0f);
				if (_player->getArrow()->getVArrow()[j].isPowerShot)
				{
					_vEnemy[i]->setEnemyAttack(_player->getArrow()->getVArrow()[j].arrowDamage);
					_vEnemy[i]->setIsPowerShot(true);
					break;
				}
				else
				{
					_vEnemy[i]->setEnemyAttack(_player->getArrow()->getVArrow()[j].arrowDamage);
					_player->getArrow()->playerRemoveArrow(j);
					break;
				}

				if (_vEnemy[i]->getEnemyType() == ENEMY_BLUE_SLIME || _vEnemy[i]->getEnemyType() == ENEMY_RED_SLIME || _vEnemy[i]->getEnemyType() == ENEMY_YELLOW_SLIME)
				{
					SOUNDMANAGER->play("�����Ӹ���", 1.0f);
				}
				if (_vEnemy[i]->getEnemyType() == ENEMY_GOLEM)
				{
					SOUNDMANAGER->play("�񷽸���", 1.0f);
				}
				if (_vEnemy[i]->getEnemyType() == ENEMY_POT)
				{
					SOUNDMANAGER->play("�Ѿ�����", 1.0f);
				}
				if (_vEnemy[i]->getEnemyType() == ENEMY_BOSS)
				{
					_bossHit = true;
					SOUNDMANAGER->play("��������", 1.0f);
				}
				break;
			}
			else
			{
				_bossHit = false;
			}
		}
		if (IntersectRect(&temp, &_vEnemy[i]->getEnemyAttackRect().GetRect(), &_player->getPlayerRc().GetRect()) && 
			_vEnemy[i]->getState() == _vEnemy[i]->getAttack()
			&& _player->getCurrectState() != _player->getRollState()
			&& _player->getCurrectState() != _player->getDieState())
		{
			_vEnemy[i]->setIsPlayerHit(true);

			if (_player->getCurrectState() == _player->getShieldState())
			{
				_player->setPlayerCurrentHp(_player->getplayerCurrentHp() - 5);
			}
			else
			{
				_player->setPlayerCurrentHp(_player->getplayerCurrentHp() - 10);
			}


			_player->setEnemyCol(true);

			_vEnemy[i]->setAttackRect(0, 0, 0, 0);
		}
		if (_vEnemy[i]->getIsPull())
		{

			_player->setX(_player->getX() + cosf(_angle) * 10);
			_player->setY(_player->getY() - sinf(_angle) * 10);
			_player->setShadowX(_player->getShadowX() + cosf(_angle) * 10);
			_player->setShadowY(_player->getShadowY() - sinf(_angle) * 10);
		}
		if (_vEnemy[i]->getIsPush())
		{

			_player->setX(_player->getX() + cosf(_bulletAngle) * 10);
			_player->setY(_player->getY() - sinf(_bulletAngle) * 10);
			_player->setShadowX(_player->getShadowX() + cosf(_bulletAngle) * 10);
			_player->setShadowY(_player->getShadowY() - sinf(_bulletAngle) * 10);
		}


		boss* b = dynamic_cast<boss*>(_vEnemy[i]);
		if (b == NULL) continue;
		//cout << b->playerCol() << endl;
		if (b->playerCol() && _vEnemy[i]->getState() == _vEnemy[i]->getAttack()
			&& _player->getCurrectState() != _player->getRollState()
			&& _player->getCurrectState() != _player->getDieState())
		{
			if (_player->getCurrectState() == _player->getShieldState())
			{
				_player->setPlayerCurrentHp(_player->getplayerCurrentHp() - 10);
			}
			else
			{
				_player->setPlayerCurrentHp(_player->getplayerCurrentHp() - 20);
			}


			_player->setEnemyCol(true);
		}
		RECT tempRc = _player->getShadowRc().GetRect();

		//cout<< _vEnemy[i]->getIsRockBottom() << endl;
		if (b->playerStop(tempRc) && !_vEnemy[i]->getIsRockBottom() && 
			_vEnemy[i]->getState() == _vEnemy[i]->getAttack())
		{
			float x = (tempRc.right + tempRc.left) * 0.5f;
			float y = (tempRc.bottom + tempRc.top) * 0.5f;
			_player->setPlayerPos(x, y);

		}

	}

}

void enemyManager::bulletCol()
{
	RECT temp;


	for (int j = 0; j < _vEnemy.size(); ++j)
	{
		if ((_vEnemy[j]->getEnemyType() == ENEMY_POT))
		{
			for (int i = 0; i < _bullet->getVBullet().size(); ++i)
			{
				if (IntersectRect(&temp, &_player->getPlayerRc().GetRect(), &_bullet->getVBullet()[i].rc.GetRect())
					&& _player->getCurrectState() != _player->getRollState()
					&& _player->getCurrectState() != _player->getDieState())
				{
					ImageManager::GetInstance()->FindImage("bulletCollision")->SetScale(1.5f);
					EFFECTMANAGER->play("bulletCollision", (temp.left + temp.right) / 2, ((temp.top + temp.bottom) / 2) + 10);
					_player->setEnemyCol(true);
					SOUNDMANAGER->play("�Ѿ�����", 1.0f);

					if (_player->getCurrectState() == _player->getShieldState())
					{
						_player->setPlayerCurrentHp(_player->getplayerCurrentHp() - 5);
					}
					else
					{
						_player->setPlayerCurrentHp(_player->getplayerCurrentHp() - 10);
					}

					_bullet->remove(i);
					break;
				}
			}
		}

		if (_vEnemy[j]->getEnemyType() == ENEMY_BOSS)
		{
			for (int i = 0; i < _bullet->getVBullet().size(); ++i)
			{
				if (IntersectRect(&temp, &_player->getPlayerRc().GetRect(), &_bullet->getVBullet()[i].rc.GetRect())
					&& _player->getCurrectState() != _player->getRollState()
					&& _player->getCurrectState() != _player->getDieState())
				{
					SOUNDMANAGER->play("�Ѿ�����", 1.0f);
					if (_player->getCurrectState() == _player->getShieldState())
					{
						_player->setPlayerCurrentHp(_player->getplayerCurrentHp() - 10);
					}
					else
					{
						_player->setPlayerCurrentHp(_player->getplayerCurrentHp() - 20);
					}


					_player->setEnemyCol(true);
					_bullet->remove(i);
					break;
				}
			}
		}

	}

}

void enemyManager::enemyDead(int arr)
{
	_vEnemy[arr]->release();
	_vEnemy.erase(_vEnemy.begin() + arr);
}
