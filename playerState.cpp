#include "stdafx.h"
#include "playerState.h"
#include "player.h"
#include "arrow.h"

HRESULT playerIdleState::init()
{
	_transForm = false;

	return S_OK;
}

//Idle 鼻鷓
void playerIdleState::update(player & player)
{
	_idleCount++;
	//嬴檜菟 鼻鷓 螃楚 雖樓腎賊 綿濠瑞韓л
	if (_idleCount >= 300)
	{
		player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerBroom"), ImageManager::GetInstance()->FindImage("playerBroom"));
		player.setCurrentState(player.getBroomState());
		_idleCount = 0;
	}

	if (!_transForm)
	{
		//務晦
		//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
		//嬪
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpWalk"), ImageManager::GetInstance()->FindImage("playerUpWalk"));
			player.setCurrentState(player.getWalkState());
		}
		//嬴楚 
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownWalk"), ImageManager::GetInstance()->FindImage("playerDownWalk"));
			player.setCurrentState(player.getWalkState());
		}
		//豭薹 
		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftWalk"), ImageManager::GetInstance()->FindImage("playerLeftWalk"));
			player.setCurrentState(player.getWalkState());
		}
		//螃艇薹 
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightWalk"), ImageManager::GetInstance()->FindImage("playerRightWalk"));
			player.setCurrentState(player.getWalkState());
		}
		//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
	}
	
	//Ы溯檜橫 掘腦晦
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (player.getDirection() == DIRECTION::RIGHT)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightRoll"), ImageManager::GetInstance()->FindImage("playerRightRoll"));
			player.setCurrentState(player.getRollState());
		}
		if (player.getDirection() == DIRECTION::LEFT)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftRoll"), ImageManager::GetInstance()->FindImage("playerLeftRoll"));
			player.setCurrentState(player.getRollState());
		}
		if (player.getDirection() == DIRECTION::DOWN)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownRoll"), ImageManager::GetInstance()->FindImage("playerDownRoll"));
			player.setCurrentState(player.getRollState());
		}
		if (player.getDirection() == DIRECTION::UP)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpRoll"), ImageManager::GetInstance()->FindImage("playerUpRoll"));
			player.setCurrentState(player.getRollState());
		}
	}
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天


	//Ы溯檜橫 餌蜂 <-- 歜衛
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
	if (KEYMANAGER->isOnceKeyDown('L'))
	{
		player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerBed"), ImageManager::GetInstance()->FindImage("playerBed"));
		player.setCurrentState(player.getDieState());
	}
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天

	//Ы溯檜橫 蔓萄
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
	if (KEYMANAGER->isOnceKeyDown('K'))
	{
		if (player.getDirection() == DIRECTION::RIGHT)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightShield"), ImageManager::GetInstance()->FindImage("playerRightShield"));
			player.setCurrentState(player.getShieldState());
		}
		if (player.getDirection() == DIRECTION::LEFT)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftShield"), ImageManager::GetInstance()->FindImage("playerLeftShield"));
			player.setCurrentState(player.getShieldState());
		}
		if (player.getDirection() == DIRECTION::DOWN)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownShield"), ImageManager::GetInstance()->FindImage("playerDownShield"));
			player.setCurrentState(player.getShieldState());
		}
		if (player.getDirection() == DIRECTION::UP)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpShield"), ImageManager::GetInstance()->FindImage("playerUpShield"));
			player.setCurrentState(player.getShieldState());
		}
	}
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天

	//Ы溯檜橫 熱艙 <-- 歜衛
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
	if (KEYMANAGER->isOnceKeyDown(VK_INSERT))
	{
		_transForm = true;
		player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownSwim"), ImageManager::GetInstance()->FindImage("playerDownSwim"));

		if (_transForm)
		{
			player.setCurrentState(player.getSwimState());
			player.setDirection(DIRECTION::DOWN);
		}
	}
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天

	//鼠晦 滲唳
	if (player.getWeaponChange())
	{
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			//�香鼒� 滲唳
			player.setWeaponChange(false);
			player.setCurrentState(player.getBowState());
		}
	}

	//鼠晦 滲唳
	if (!player.getWeaponChange())
	{
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			//匐戲煎 滲唳
			player.setWeaponChange(true);
			player.setCurrentState(player.getSwordState());
		}
	}

	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天

	//��
	if (player.getWeaponChange())
	{
		if (KEYMANAGER->isOnceKeyDown('J'))
		{
			if (player.getDirection() == DIRECTION::UP)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpBow"), ImageManager::GetInstance()->FindImage("playerUpBow"));
				player.setCurrentState(player.getBowState());
			}
			if (player.getDirection() == DIRECTION::DOWN)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownBow"), ImageManager::GetInstance()->FindImage("playerDownBow"));
				player.setCurrentState(player.getBowState());
			}
			if (player.getDirection() == DIRECTION::LEFT)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftBow"), ImageManager::GetInstance()->FindImage("playerLeftBow"));
				player.setCurrentState(player.getBowState());
			}
			if (player.getDirection() == DIRECTION::RIGHT)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightBow"), ImageManager::GetInstance()->FindImage("playerRightBow"));
				player.setCurrentState(player.getBowState());
			}
		}
	}

	//匐
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
	if (!player.getWeaponChange())
	{
		if (KEYMANAGER->isOnceKeyDown('J'))
		{
			player.setSwordAttack(true);
			player.setAttackRcbool(true);
			if (player.getDirection() == DIRECTION::UP)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpSword1"), ImageManager::GetInstance()->FindImage("playerUpSword1"));
				player.setCurrentState(player.getSwordState());
				player.setAttackRc(player.getX(), player.getY() - 50, 50, 60);
			}

			if (player.getDirection() == DIRECTION::DOWN)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownSword1"), ImageManager::GetInstance()->FindImage("playerDownSword1"));
				player.setCurrentState(player.getSwordState());
				player.setAttackRc(player.getX(), player.getY() + 50, 50, 60);
			}

			if (player.getDirection() == DIRECTION::LEFT)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftSword1"), ImageManager::GetInstance()->FindImage("playerLeftSword1"));
				player.setCurrentState(player.getSwordState());
				player.setAttackRc(player.getX() - 50, player.getY(), 60, 50);
			}

			if (player.getDirection() == DIRECTION::RIGHT)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightSword1"), ImageManager::GetInstance()->FindImage("playerRightSword1"));
				player.setCurrentState(player.getSwordState());
				player.setAttackRc(player.getX() + 50, player.getY(), 60, 50);
			}
		}
	}
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
}

//walk 鼻鷓
void playerWalkState::update(player & player)
{
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
	//嬪
	bool isMove = false;
	bool isbool = true;

	int x = 0;
	int y = 0;
	if (KEYMANAGER->isStayKeyDown('W') && player.getDirection() != DIRECTION::DOWN && player.getDirection() != DIRECTION::LEFT && player.getDirection() != DIRECTION::RIGHT)
	{
		if (player.getDirection() != DIRECTION::UP)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpWalk"), ImageManager::GetInstance()->FindImage("playerUpWalk"));
			player.setDirection(DIRECTION::UP);
		}

		//虜擒 嬴楚酈 援腦賊 嬪薹Idle 賅蝗戲煎 滲л
 
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			cout << "111" << endl;
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpIdle"), ImageManager::GetInstance()->FindImage("playerUpIdle"));
		}
		//嬪薹Idle 賅蝗戲煎 誇蹺晦
		else if (KEYMANAGER->isStayKeyDown('S'))
		{
			cout << "222" << endl;
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpIdle"), ImageManager::GetInstance()->FindImage("playerUpIdle"));
			player.setShadowY(player.getShadowY() - 0);
			player.setY(player.getY() - 0);
			return;
		}
		//嬴楚酈蒂 飲賊 嬪煎 棻衛 遺霜歜
		if (KEYMANAGER->isOnceKeyUp('S'))
		{
			cout << "333" << endl;
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpWalk"), ImageManager::GetInstance()->FindImage("playerUpWalk"));
			player.setCurrentState(player.getWalkState());
		}
		//虜擒 檜翕醞 掘腦晦 援腦賊
		if (!KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpRoll")->isPlay())
		{
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpRoll"), ImageManager::GetInstance()->FindImage("playerUpRoll"));

				player.setCurrentState(player.getRollState());
			}
		}
		
		isMove = true;
		y = -1;
		//player.setShadowY(player.getShadowY() - 5);
		//player.setY(player.getY() - 5);
	}
	if (KEYMANAGER->isStayKeyDown('S') && player.getDirection() != DIRECTION::UP && player.getDirection() != DIRECTION::LEFT && player.getDirection() != DIRECTION::RIGHT)
	{
		if (player.getDirection() != DIRECTION::DOWN)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownWalk"), ImageManager::GetInstance()->FindImage("playerDownWalk"));
			player.setDirection(DIRECTION::DOWN);
		}

		//虜擒 嬪薹酈 援腦賊 嬴楚 Idle 賅蝗戲煎 滲л
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			cout << "4444" << endl;
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownIdle"), ImageManager::GetInstance()->FindImage("playerDownIdle"));
		}
		//嬴楚Idle 賅蝗戲煎 誇蹺晦
		else if (KEYMANAGER->isStayKeyDown('W'))
		{
			cout << "5555" << endl;
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownIdle"), ImageManager::GetInstance()->FindImage("playerDownIdle"));
			player.setShadowY(player.getShadowY() + 0);
			player.setY(player.getY() + 0);
			return;
		}
		//嬪薹酈蒂 飲賊 嬴楚煎 棻衛 遺霜歜
		if (KEYMANAGER->isOnceKeyUp('W'))
		{
			cout << "6666" << endl;
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownWalk"), ImageManager::GetInstance()->FindImage("playerDownWalk"));
			player.setCurrentState(player.getWalkState());
		}


		//虜擒 檜翕醞 掘腦晦 援腦賊
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownRoll"), ImageManager::GetInstance()->FindImage("playerDownRoll"));
			player.setCurrentState(player.getRollState());
		}

		isMove = true;
		y = 1;
		//player.setShadowY(player.getShadowY() + 5);
		//player.setY(player.getY() + 5);
	}
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		if (player.getDirection() != DIRECTION::LEFT && !isMove)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftWalk"), ImageManager::GetInstance()->FindImage("playerLeftWalk"));
			player.setDirection(DIRECTION::LEFT);
		}

		//虜擒 螃艇薹酈 援腦賊 豭薹 Idle 賅蝗戲煎 滲л
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftIdle"), ImageManager::GetInstance()->FindImage("playerLeftIdle"));
		}
		//豭薹Idle 賅蝗戲煎 誇蹺晦
		else if (KEYMANAGER->isStayKeyDown('D'))
		{
			player.setShadowX(player.getShadowX() - 0);
			player.setX(player.getX() - 0);
			return;
		}
		//螃艇薹酈蒂 飲賊 豭薹戲煎 棻衛 遺霜歜
		else if (KEYMANAGER->isOnceKeyUp('D'))
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftWalk"), ImageManager::GetInstance()->FindImage("playerLeftWalk"));
			player.setCurrentState(player.getWalkState());
		}
		//虜擒 檜翕醞 掘腦晦 援腦賊
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftRoll"), ImageManager::GetInstance()->FindImage("playerLeftRoll"));
			player.setCurrentState(player.getRollState());
		}
		isMove = true;
		//player.setShadowX(player.getShadowX() - 5);
		//player.setX(player.getX() - 5);
		x = - 1;
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		if (player.getDirection() != DIRECTION::RIGHT && !isMove)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightWalk"), ImageManager::GetInstance()->FindImage("playerRightWalk"));
			player.setDirection(DIRECTION::RIGHT);
		}

		//虜擒 豭薹酈 援腦賊 螃艇薹 Idle 賅蝗戲煎 滲л
		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightIdle"), ImageManager::GetInstance()->FindImage("playerRightIdle"));
		}
		//螃艇薹Idle 賅蝗戲煎 誇蹺晦
		else if (KEYMANAGER->isStayKeyDown('A'))
		{
			player.setShadowX(player.getShadowX() + 0);
			player.setX(player.getX() + 0);
			return;
		}
		//豭薹酈蒂 飲賊 螃艇薹戲煎 棻衛 遺霜歜
		else if (KEYMANAGER->isOnceKeyUp('A'))
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightWalk"), ImageManager::GetInstance()->FindImage("playerRightWalk"));
			player.setCurrentState(player.getWalkState());
		}
		//虜擒 檜翕醞 掘腦晦 援腦賊
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightRoll"), ImageManager::GetInstance()->FindImage("playerRightRoll"));
			player.setCurrentState(player.getRollState());
		}
		isMove = true;
		//player.setShadowX(player.getShadowX() + 5);
		//player.setX(player.getX() + 5);
		x = 1;
		//Vector2(x, y).Normalize();
	}
	Vector2 vec(x, y);
	Vector2 diagonal = Vector2::Normalize(&vec);
	if (Vector2::Length(&vec) > 1) // 渠陝摹橾 陽
	{
		player.setShadowX(player.getShadowX() + (diagonal.x * MOVESPPED));
		player.setX(player.getX() + (diagonal.x * MOVESPPED));
		player.setShadowY(player.getShadowY() + (diagonal.y * MOVESPPED));
		player.setY(player.getY() + (diagonal.y * MOVESPPED));
	}
	else
	{
		//渠陝摹 嬴棍陽
		player.setShadowX(player.getShadowX() + (vec.x * MOVESPPED));
		player.setX(player.getX() + (vec.x * MOVESPPED));
		player.setShadowY(player.getShadowY() + (vec.y * MOVESPPED));
		player.setY(player.getY() + (vec.y * MOVESPPED));
	}


	if (!isMove)
	{
		// idle煎 給嬴陛啪
	}

	//嬪薹酈 飲賊
	if (KEYMANAGER->isOnceKeyUp('W'))
	{
		//嬴鼠酈紫 援艇鼻鷓陛 嬴棲賊 Idle 鼻鷓煎 
		if (KEYMANAGER->getKeyUp() == NULL)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpIdle"), ImageManager::GetInstance()->FindImage("playerUpIdle"));
			player.setCurrentState(player.getIdleState());
		}
		//嬴楚酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('S') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownWalk"), ImageManager::GetInstance()->FindImage("playerDownWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::DOWN);
		}
		//螃艇薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('D') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightWalk"), ImageManager::GetInstance()->FindImage("playerRightWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::RIGHT);
		}
		//豭薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('A') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftWalk"), ImageManager::GetInstance()->FindImage("playerLeftWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::LEFT);
		}
	}

	//嬴楚酈 飲賊
	if (KEYMANAGER->isOnceKeyUp('S'))
	{
		//嬴鼠酈紫 援艇鼻鷓陛 嬴棲賊 Idle 鼻鷓煎 
		if (KEYMANAGER->getKeyUp() == NULL)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownIdle"), ImageManager::GetInstance()->FindImage("playerDownIdle"));
			player.setCurrentState(player.getIdleState());
		}
		//嬪薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('W') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpWalk"), ImageManager::GetInstance()->FindImage("playerUpWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::UP);
		}
		//螃艇薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('D') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightWalk"), ImageManager::GetInstance()->FindImage("playerRightWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::RIGHT);
		}
		//豭薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('A') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftWalk"), ImageManager::GetInstance()->FindImage("playerLeftWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::LEFT);
		}
	}

	//豭薹酈 飲賊
	if (KEYMANAGER->isOnceKeyUp('A'))
	{
		//嬴鼠酈紫 援艇鼻鷓陛 嬴棲賊 Idle 鼻鷓煎 
		if (KEYMANAGER->getKeyUp() == NULL)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftIdle"), ImageManager::GetInstance()->FindImage("playerLeftIdle"));
			player.setCurrentState(player.getIdleState());
		}
		//螃艇薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('D') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightWalk"), ImageManager::GetInstance()->FindImage("playerRightWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::RIGHT);
		}
		//嬪薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('W') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpWalk"), ImageManager::GetInstance()->FindImage("playerUpWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::UP);
		}
		//嬴楚蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('S') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownWalk"), ImageManager::GetInstance()->FindImage("playerDownWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::DOWN);
		}
	}

	//螃艇薹酈 飲賊
	if (KEYMANAGER->isOnceKeyUp('D'))
	{
		//嬴鼠酈紫 援艇鼻鷓陛 嬴棲賊 Idle 鼻鷓煎 
		if (KEYMANAGER->getKeyUp() == NULL)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightIdle"), ImageManager::GetInstance()->FindImage("playerRightIdle"));
			player.setCurrentState(player.getIdleState());
		}
		//豭薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('A') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftWalk"), ImageManager::GetInstance()->FindImage("playerLeftWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::LEFT);
		}
		//嬪薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('W') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpWalk"), ImageManager::GetInstance()->FindImage("playerUpWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::UP);
		}
		//嬴楚蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('S') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownWalk"), ImageManager::GetInstance()->FindImage("playerDownWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::DOWN);
		}
	}
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天

	//Ы溯檜橫 掘腦晦
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (player.getDirection() == DIRECTION::RIGHT)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightRoll"), ImageManager::GetInstance()->FindImage("playerRightRoll"));
			player.setCurrentState(player.getRollState());
		}
		if (player.getDirection() == DIRECTION::LEFT)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftRoll"), ImageManager::GetInstance()->FindImage("playerLeftRoll"));
			player.setCurrentState(player.getRollState());
		}
		if (player.getDirection() == DIRECTION::DOWN)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownRoll"), ImageManager::GetInstance()->FindImage("playerDownRoll"));
			player.setCurrentState(player.getRollState());
		}
		if (player.getDirection() == DIRECTION::UP)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpRoll"), ImageManager::GetInstance()->FindImage("playerUpRoll"));
			player.setCurrentState(player.getRollState());
		}
	}
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天

	//Ы溯檜橫 蔓萄
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
	if (KEYMANAGER->isOnceKeyDown('K'))
	{
		if (player.getDirection() == DIRECTION::RIGHT)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightShield"), ImageManager::GetInstance()->FindImage("playerRightShield"));
			player.setCurrentState(player.getShieldState());
		}
		if (player.getDirection() == DIRECTION::LEFT)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftShield"), ImageManager::GetInstance()->FindImage("playerLeftShield"));
			player.setCurrentState(player.getShieldState());
		}
		if (player.getDirection() == DIRECTION::DOWN)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownShield"), ImageManager::GetInstance()->FindImage("playerDownShield"));
			player.setCurrentState(player.getShieldState());
		}
		if (player.getDirection() == DIRECTION::UP)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpShield"), ImageManager::GetInstance()->FindImage("playerUpShield"));
			player.setCurrentState(player.getShieldState());
		}
	}
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天

	//鼠晦 滲唳
	if (player.getWeaponChange())
	{
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			//�香鼒� 滲唳
			player.setWeaponChange(false);
			player.setCurrentState(player.getBowState());
		}
	}

	//鼠晦 滲唳
	if (!player.getWeaponChange())
	{
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			//匐戲煎 滲唳
			player.setWeaponChange(true);
			player.setCurrentState(player.getSwordState());
		}
	}

	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
	//��
	if (player.getWeaponChange())
	{
		if (KEYMANAGER->isOnceKeyDown('J'))
		{
			if (player.getDirection() == DIRECTION::UP)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpBow"), ImageManager::GetInstance()->FindImage("playerUpBow"));
				player.setCurrentState(player.getBowState());
			}
			if (player.getDirection() == DIRECTION::DOWN)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownBow"), ImageManager::GetInstance()->FindImage("playerDownBow"));
				player.setCurrentState(player.getBowState());
			}
			if (player.getDirection() == DIRECTION::LEFT)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftBow"), ImageManager::GetInstance()->FindImage("playerLeftBow"));
				player.setCurrentState(player.getBowState());
			}
			if (player.getDirection() == DIRECTION::RIGHT)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightBow"), ImageManager::GetInstance()->FindImage("playerRightBow"));
				player.setCurrentState(player.getBowState());
			}
		}
	}

	//匐
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
	if (!player.getWeaponChange())
	{
		if (KEYMANAGER->isOnceKeyDown('J'))
		{
			player.setSwordAttack(true);

			if (player.getDirection() == DIRECTION::UP)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpSword1"), ImageManager::GetInstance()->FindImage("playerUpSword1"));
				player.setCurrentState(player.getSwordState());
				player.setAttackRc(player.getX(), player.getY() - 50, 50, 60);
			}

			if (player.getDirection() == DIRECTION::DOWN)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownSword1"), ImageManager::GetInstance()->FindImage("playerDownSword1"));
				player.setCurrentState(player.getSwordState());
				player.setAttackRc(player.getX(), player.getY() + 50, 50, 60);
			}

			if (player.getDirection() == DIRECTION::LEFT)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftSword1"), ImageManager::GetInstance()->FindImage("playerLeftSword1"));
				player.setCurrentState(player.getSwordState());
				player.setAttackRc(player.getX() - 50, player.getY(), 60, 50);
			}

			if (player.getDirection() == DIRECTION::RIGHT)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightSword1"), ImageManager::GetInstance()->FindImage("playerRightSword1"));
				player.setCurrentState(player.getSwordState());
				player.setAttackRc(player.getX() + 50, player.getY(), 60, 50);
			}
		}
	}
	//天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天
}

//roll(掘腦晦) 鼻鷓
void playerRollState::update(player & player)
{
	//嬪煎 掘腦晦 
	if (player.getPlayerMotion() == KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpRoll"))
	{
		player.setShadowY(player.getShadowY() - 5);
		player.setY(player.getY() - 5);
	}
	//嬴楚煎 掘腦晦
	if (player.getPlayerMotion() == KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownRoll"))
	{
		player.setShadowY(player.getShadowY() + 5);
		player.setY(player.getY() + 5);
	}
	//豭薹戲煎 掘腦晦
	if (player.getPlayerMotion() == KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftRoll"))
	{
		player.setShadowX(player.getShadowX() - 5);
		player.setX(player.getX() - 5);
	}
	//螃艇薹戲煎 掘腦晦
	if (player.getPlayerMotion() == KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightRoll"))
	{
		player.setShadowX(player.getShadowX() + 5);
		player.setX(player.getX() + 5);
	}

	//擁棲詭檜暮 營儅檜 部釭賊 
	if(!KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpRoll")->isPlay() 
		&& !KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownRoll")->isPlay()
		&& !KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftRoll")->isPlay()
		&& !KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightRoll")->isPlay())
	{

		//嬪薹酈蒂 援腦賊 棻衛 檜翕ж啪
		if (GetAsyncKeyState('W') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpWalk"), ImageManager::GetInstance()->FindImage("playerUpWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::UP);
		}
		//嬴楚酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('S') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownWalk"), ImageManager::GetInstance()->FindImage("playerDownWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::DOWN);
		}
		//螃艇薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('D') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightWalk"), ImageManager::GetInstance()->FindImage("playerRightWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::RIGHT);
		}
		//豭薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('A') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftWalk"), ImageManager::GetInstance()->FindImage("playerLeftWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::LEFT);
		}
		//嬴鼠酈紫 援腦雖 彊堅氈戲賊 Idle 鼻鷓煎 瞪��
		else
		{
			if (player.getDirection() == DIRECTION::UP)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpIdle"), ImageManager::GetInstance()->FindImage("playerUpIdle"));
				player.setCurrentState(player.getIdleState());
			}

			if (player.getDirection() == DIRECTION::DOWN)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownIdle"), ImageManager::GetInstance()->FindImage("playerDownIdle"));
				player.setCurrentState(player.getIdleState());
			}

			if (player.getDirection() == DIRECTION::LEFT)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftIdle"), ImageManager::GetInstance()->FindImage("playerLeftIdle"));
				player.setCurrentState(player.getIdleState());
			}

			if (player.getDirection() == DIRECTION::RIGHT)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightIdle"), ImageManager::GetInstance()->FindImage("playerRightIdle"));
				player.setCurrentState(player.getIdleState());
			}
		}
	}
}

//die 鼻鷓
void playerDieState::update(player & player)
{
	//嬴鼠酈紫 寰援腦賊 Idle 鼻鷓煎 瞪��
	if (KEYMANAGER->isOnceKeyUp('L'))
	{
		if (KEYMANAGER->getKeyUp() == NULL)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpIdle"), ImageManager::GetInstance()->FindImage("playerUpIdle"));
			player.setCurrentState(player.getIdleState());
		}
		//嬴楚酈蒂 援腦賊 棻衛 檜翕
		else if (GetAsyncKeyState('S') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownWalk"), ImageManager::GetInstance()->FindImage("playerDownWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::DOWN);
		}
	}
}

//shield 鼻鷓
void playerShieldState::update(player & player)
{
	//Ы溯檜橫 蔓萄
	if (KEYMANAGER->isStayKeyDown('K') || KEYMANAGER->isOnceKeyUp('W') || KEYMANAGER->isOnceKeyUp('S') || KEYMANAGER->isOnceKeyUp('A') || KEYMANAGER->isOnceKeyUp('D'));
	{
		if (player.getDirection() == DIRECTION::RIGHT)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightShield"), ImageManager::GetInstance()->FindImage("playerRightShield"));
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightRoll"), ImageManager::GetInstance()->FindImage("playerRightRoll"));
				player.setCurrentState(player.getRollState());
			}
			if (KEYMANAGER->isStayKeyDown('D'))
			{
				player.setShadowX(player.getShadowX() + 1);
				player.setX(player.getX() + 1);
			}
			if (KEYMANAGER->isStayKeyDown('A'))
			{
				player.setShadowX(player.getShadowX() - 1);
				player.setX(player.getX() - 1);
			}
			if (KEYMANAGER->isStayKeyDown('S'))
			{
				player.setShadowY(player.getShadowY() + 1);
				player.setY(player.getY() + 1);
			}
			if (KEYMANAGER->isStayKeyDown('W'))
			{
				player.setShadowY(player.getShadowY() - 1);
				player.setY(player.getY() - 1);
			}
		}
		if (player.getDirection() == DIRECTION::LEFT)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftShield"), ImageManager::GetInstance()->FindImage("playerLeftShield"));
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftRoll"), ImageManager::GetInstance()->FindImage("playerLeftRoll"));
				player.setCurrentState(player.getRollState());
			}
			if (KEYMANAGER->isStayKeyDown('D'))
			{
				player.setShadowX(player.getShadowX() + 1);
				player.setX(player.getX() + 1);
			}
			if (KEYMANAGER->isStayKeyDown('A'))
			{
				player.setShadowX(player.getShadowX() - 1);
				player.setX(player.getX() - 1);
			}
			if (KEYMANAGER->isStayKeyDown('S'))
			{
				player.setShadowY(player.getShadowY() + 1);
				player.setY(player.getY() + 1);
			}
			if (KEYMANAGER->isStayKeyDown('W'))
			{
				player.setShadowY(player.getShadowY() - 1);
				player.setY(player.getY() - 1);
			}
		}
		if (player.getDirection() == DIRECTION::DOWN)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownShield"), ImageManager::GetInstance()->FindImage("playerDownShield"));
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownRoll"), ImageManager::GetInstance()->FindImage("playerDownRoll"));
				player.setCurrentState(player.getRollState());
			}
			if (KEYMANAGER->isStayKeyDown('D'))
			{
				player.setShadowX(player.getShadowX() + 1);
				player.setX(player.getX() + 1);
			}
			if (KEYMANAGER->isStayKeyDown('A'))
			{
				player.setShadowX(player.getShadowX() - 1);
				player.setX(player.getX() - 1);
			}
			if (KEYMANAGER->isStayKeyDown('S'))
			{
				player.setShadowY(player.getShadowY() + 1);
				player.setY(player.getY() + 1);
			}
			if (KEYMANAGER->isStayKeyDown('W'))
			{
				player.setShadowY(player.getShadowY() - 1);
				player.setY(player.getY() - 1);
			}
		}
		if (player.getDirection() == DIRECTION::UP)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpShield"), ImageManager::GetInstance()->FindImage("playerUpShield"));
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpRoll"), ImageManager::GetInstance()->FindImage("playerUpRoll"));
				player.setCurrentState(player.getRollState());
			}
			if (KEYMANAGER->isStayKeyDown('D'))
			{
				player.setShadowX(player.getShadowX() + 1);
				player.setX(player.getX() + 1);
			}
			if (KEYMANAGER->isStayKeyDown('A'))
			{
				player.setShadowX(player.getShadowX() - 1);
				player.setX(player.getX() - 1);
			}
			if (KEYMANAGER->isStayKeyDown('S'))
			{
				player.setShadowY(player.getShadowY() + 1);
				player.setY(player.getY() + 1);
			}
			if (KEYMANAGER->isStayKeyDown('W'))
			{
				player.setShadowY(player.getShadowY() - 1);
				player.setY(player.getY() - 1);
			}
		}
	}

	//蔓萄酈 飲賊
	if (KEYMANAGER->isOnceKeyUp('K'))
	{
		if (KEYMANAGER->getKeyUp() == NULL)
		{
			if (player.getDirection() == DIRECTION::RIGHT)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightIdle"), ImageManager::GetInstance()->FindImage("playerRightIdle"));
				player.setCurrentState(player.getIdleState());
			} 
			if (player.getDirection() == DIRECTION::LEFT)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftIdle"), ImageManager::GetInstance()->FindImage("playerLeftIdle"));
				player.setCurrentState(player.getIdleState());
			}
			if (player.getDirection() == DIRECTION::DOWN)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownIdle"), ImageManager::GetInstance()->FindImage("playerDownIdle"));
				player.setCurrentState(player.getIdleState());
			}
			if (player.getDirection() == DIRECTION::UP)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpIdle"), ImageManager::GetInstance()->FindImage("playerUpIdle"));
				player.setCurrentState(player.getIdleState());
			}
		}
		//螃艇薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('D') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightWalk"), ImageManager::GetInstance()->FindImage("playerRightWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::RIGHT);
		}
		//豭薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('A') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftWalk"), ImageManager::GetInstance()->FindImage("playerLeftWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::LEFT);
		}
		//嬪薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('W') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpWalk"), ImageManager::GetInstance()->FindImage("playerUpWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::UP);
		}
		//嬴楚酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('S') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownWalk"), ImageManager::GetInstance()->FindImage("playerDownWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::DOWN);
		}
	}	
}

//idleSwim 鼻鷓
void playerIdleSwimState::update(player & player)
{
	//嬪
	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpSwim"), ImageManager::GetInstance()->FindImage("playerUpSwim"));
		player.setCurrentState(player.getSwimState());
		player.setDirection(DIRECTION::UP);
	}

	//嬴楚
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownSwim"), ImageManager::GetInstance()->FindImage("playerDownSwim"));
		player.setCurrentState(player.getSwimState());
		player.setDirection(DIRECTION::DOWN);
	}

	//豭薹
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftSwim"), ImageManager::GetInstance()->FindImage("playerLeftSwim"));
		player.setCurrentState(player.getSwimState());
		player.setDirection(DIRECTION::LEFT);
	}

	//螃艇薹
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightSwim"), ImageManager::GetInstance()->FindImage("playerRightSwim"));
		player.setCurrentState(player.getSwimState());
		player.setDirection(DIRECTION::RIGHT);
	}
}


//swim 鼻鷓
void playerSwimState::update(player & player)
{
	//嬪 
	if (player.getDirection() == DIRECTION::UP)
	{
		if (KEYMANAGER->isStayKeyDown('W'))
		{
			//虜擒 嬴楚薹酈 援腦賊 嬪薹 idleSwim 賅蝗戲煎 滲л
			if (KEYMANAGER->isOnceKeyDown('S'))
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpIdleSwim"), ImageManager::GetInstance()->FindImage("playerUpIdleSwim"));
			}
			//嬪薹 idleSwim 賅蝗戲煎 誇蹺晦
			else if (KEYMANAGER->isStayKeyDown('S'))
			{
				player.setShadowY(player.getShadowY() - 0);
				player.setY(player.getY() - 0);
				return;
			}
			//酈 飲賊 棻衛 檜翕
			else if (KEYMANAGER->isOnceKeyUp('S'))
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpSwim"), ImageManager::GetInstance()->FindImage("playerUpSwim"));
				player.setCurrentState(player.getSwimState());
			}
			player.setShadowY(player.getShadowY() - 3);
			player.setY(player.getY() - 3);
		}
	}

	//嬪薹酈 飲賊
	if (KEYMANAGER->isOnceKeyUp('W'))
	{
		//嬴鼠酈紫 寰援腦賊 Idle 鼻鷓煎 瞪��
		if (KEYMANAGER->getKeyUp() == NULL)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpIdleSwim"), ImageManager::GetInstance()->FindImage("playerUpIdleSwim"));
			player.setCurrentState(player.getIdleSwimState());
		}
		//嬴楚酈蒂 援腦賊 棻衛 檜翕
		else if (GetAsyncKeyState('S') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownSwim"), ImageManager::GetInstance()->FindImage("playerDownSwim"));
			player.setCurrentState(player.getSwimState());
			player.setDirection(DIRECTION::DOWN);
		}
		//豭薹酈蒂 援腦賊 棻衛 檜翕
		else if (GetAsyncKeyState('A') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftSwim"), ImageManager::GetInstance()->FindImage("playerLeftSwim"));
			player.setCurrentState(player.getSwimState());
			player.setDirection(DIRECTION::LEFT);
		}
		//螃艇薹酈蒂 援腦賊 棻衛 檜翕
		else if (GetAsyncKeyState('D') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightSwim"), ImageManager::GetInstance()->FindImage("playerRightSwim"));
			player.setCurrentState(player.getSwimState());
			player.setDirection(DIRECTION::RIGHT);
		}
	}

	//嬴楚
	if (player.getDirection() == DIRECTION::DOWN)
	{
		if (KEYMANAGER->isStayKeyDown('S'))
		{
			//虜擒 嬪薹酈 援腦賊 嬴楚 idleSwim 賅蝗戲煎 滲л
			if (KEYMANAGER->isOnceKeyDown('W'))
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownIdleSwim"), ImageManager::GetInstance()->FindImage("playerDownIdleSwim"));
			}
			//嬴楚 idleSwim 賅蝗戲煎 誇蹺晦
			else if (KEYMANAGER->isStayKeyDown('W'))
			{
				player.setShadowY(player.getShadowY() + 0);
				player.setY(player.getY() + 0);
				return;
			}
			//酈 飲賊 棻衛 檜翕
			else if (KEYMANAGER->isOnceKeyUp('W'))
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownSwim"), ImageManager::GetInstance()->FindImage("playerDownSwim"));
				player.setCurrentState(player.getSwimState());
			}
			player.setShadowY(player.getShadowY() + 3);
			player.setY(player.getY() + 3);
		}
	}

	//嬴楚薹酈 飲賊
	if (KEYMANAGER->isOnceKeyUp('S'))
	{
		//嬴鼠酈紫 寰援腦賊 Idle 鼻鷓煎 瞪��
		if (KEYMANAGER->getKeyUp() == NULL)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownIdleSwim"), ImageManager::GetInstance()->FindImage("playerDownIdleSwim"));
			player.setCurrentState(player.getIdleSwimState());
		}
		//嬪薹酈蒂 援腦賊 棻衛 檜翕
		else if (GetAsyncKeyState('W') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpSwim"), ImageManager::GetInstance()->FindImage("playerUpSwim"));
			player.setCurrentState(player.getSwimState());
			player.setDirection(DIRECTION::UP);
		}
		//豭薹酈蒂 援腦賊 棻衛 檜翕
		else if (GetAsyncKeyState('A') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftSwim"), ImageManager::GetInstance()->FindImage("playerLeftSwim"));
			player.setCurrentState(player.getSwimState());
			player.setDirection(DIRECTION::LEFT);
		}
		//螃艇薹酈蒂 援腦賊 棻衛 檜翕
		else if (GetAsyncKeyState('D') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightSwim"), ImageManager::GetInstance()->FindImage("playerRightSwim"));
			player.setCurrentState(player.getSwimState());
			player.setDirection(DIRECTION::RIGHT);
		}
	}

	//豭薹
	if (player.getDirection() == DIRECTION::LEFT)
	{
		if (KEYMANAGER->isStayKeyDown('A'))
		{
			//虜擒 螃艇薹酈 援腦賊 豭薹 idleSwim 賅蝗戲煎 滲л
			if (KEYMANAGER->isOnceKeyDown('D'))
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftIdleSwim"), ImageManager::GetInstance()->FindImage("playerLeftIdleSwim"));
			}
			//豭薹 idleSwim 賅蝗戲煎 誇蹺晦
			else if (KEYMANAGER->isStayKeyDown('D'))
			{
				player.setShadowX(player.getShadowX() - 0);
				player.setX(player.getX() - 0);
				return;
			}
			//酈 飲賊 棻衛 檜翕
			else if (KEYMANAGER->isOnceKeyUp('D'))
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftSwim"), ImageManager::GetInstance()->FindImage("playerLeftSwim"));
				player.setCurrentState(player.getSwimState());
			}
			player.setShadowX(player.getShadowX() - 3);
			player.setX(player.getX() - 3);
		}
	}

	//豭薹酈 飲賊
	if (KEYMANAGER->isOnceKeyUp('A'))
	{
		//嬴鼠酈紫 寰援腦賊 Idle 鼻鷓煎 瞪��
		if (KEYMANAGER->getKeyUp() == NULL)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftIdleSwim"), ImageManager::GetInstance()->FindImage("playerLeftIdleSwim"));
			player.setCurrentState(player.getIdleSwimState());
		}
		//螃艇薹酈蒂 援腦賊 棻衛 檜翕
		else if (GetAsyncKeyState('D') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightSwim"), ImageManager::GetInstance()->FindImage("playerRightSwim"));
			player.setCurrentState(player.getSwimState());
			player.setDirection(DIRECTION::RIGHT);
		}
		//嬪薹酈蒂 援腦賊 棻衛 檜翕
		else if (GetAsyncKeyState('W') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpSwim"), ImageManager::GetInstance()->FindImage("playerUpSwim"));
			player.setCurrentState(player.getSwimState());
			player.setDirection(DIRECTION::UP);
		}
		//嬴楚酈蒂 援腦賊 棻衛 檜翕
		else if (GetAsyncKeyState('S') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownSwim"), ImageManager::GetInstance()->FindImage("playerDownSwim"));
			player.setCurrentState(player.getSwimState());
			player.setDirection(DIRECTION::DOWN);
		}
	}

	//螃艇薹
	if (player.getDirection() == DIRECTION::RIGHT)
	{
		if (KEYMANAGER->isStayKeyDown('D'))
		{
			//虜擒 豭薹酈 援腦賊 螃艇薹 idleSwim 賅蝗戲煎 滲л
			if (KEYMANAGER->isOnceKeyDown('A'))
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightIdleSwim"), ImageManager::GetInstance()->FindImage("playerRightIdleSwim"));
			}
			//螃艇薹 idleSwim 賅蝗戲煎 誇蹺晦
			else if (KEYMANAGER->isStayKeyDown('A'))
			{
				player.setShadowX(player.getShadowX() + 0);
				player.setX(player.getX() + 0);
				return;
			}
			//酈 飲賊 棻衛 檜翕
			else if (KEYMANAGER->isOnceKeyUp('A'))
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightSwim"), ImageManager::GetInstance()->FindImage("playerRightSwim"));
				player.setCurrentState(player.getSwimState());
			}
			player.setShadowX(player.getShadowX() + 3);
			player.setX(player.getX() + 3);
		}
	}

	//螃艇薹酈 飲賊
	if (KEYMANAGER->isOnceKeyUp('D'))
	{
		//嬴鼠酈紫 寰援腦賊 Idle 鼻鷓煎 瞪��
		if (KEYMANAGER->getKeyUp() == NULL)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightIdleSwim"), ImageManager::GetInstance()->FindImage("playerRightIdleSwim"));
			player.setCurrentState(player.getIdleSwimState());
		}
		//豭薹酈蒂 援腦賊 棻衛 檜翕
		else if (GetAsyncKeyState('A') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftSwim"), ImageManager::GetInstance()->FindImage("playerLeftSwim"));
			player.setCurrentState(player.getSwimState());
			player.setDirection(DIRECTION::LEFT);
		}
				//嬪薹酈蒂 援腦賊 棻衛 檜翕
		else if (GetAsyncKeyState('W') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpSwim"), ImageManager::GetInstance()->FindImage("playerUpSwim"));
			player.setCurrentState(player.getSwimState());
			player.setDirection(DIRECTION::UP);
		}
		//嬴楚酈蒂 援腦賊 棻衛 檜翕
		else if (GetAsyncKeyState('S') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownSwim"), ImageManager::GetInstance()->FindImage("playerDownSwim"));
			player.setCurrentState(player.getSwimState());
			player.setDirection(DIRECTION::DOWN);
		}
	}
}

HRESULT playerbowState::init()
{
	//_arrow  = new arrow;
	//_arrow->init();
	return S_OK;
}

void playerbowState::render()
{
	//_arrow->render();
}

void playerbowState::release()
{
	//_arrow->release();
}

//bow 鼻鷓
void playerbowState::update(player & player)
{
	//虜擒 擁棲詭檜暮 營儅 部釭賊
	if (!KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpBow")->isPlay() && !KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownBow")->isPlay()
		&& !KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftBow")->isPlay() && !KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightBow")->isPlay())
	{
		//嬴鼠酈紫 援腦雖彊戲賊 嬴檜菟 鼻鷓煎 瞪��
		if (KEYMANAGER->getKeyUp() == NULL || KEYMANAGER->isOnceKeyUp('W') || KEYMANAGER->isOnceKeyUp('S') || KEYMANAGER->isOnceKeyUp('A') || KEYMANAGER->isOnceKeyUp('D'))
		{
			if (player.getDirection() == DIRECTION::UP)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpIdle"), ImageManager::GetInstance()->FindImage("playerUpIdle"));
				player.setCurrentState(player.getIdleState());
				player.setDirection(DIRECTION::UP);
			}

			if (player.getDirection() == DIRECTION::DOWN)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownIdle"), ImageManager::GetInstance()->FindImage("playerDownIdle"));
				player.setCurrentState(player.getIdleState());
				player.setDirection(DIRECTION::DOWN);
			}

			if (player.getDirection() == DIRECTION::LEFT)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftIdle"), ImageManager::GetInstance()->FindImage("playerLeftIdle"));
				player.setCurrentState(player.getIdleState());
				player.setDirection(DIRECTION::LEFT);
			}

			if (player.getDirection() == DIRECTION::RIGHT)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightIdle"), ImageManager::GetInstance()->FindImage("playerRightIdle"));
				player.setCurrentState(player.getIdleState());
				player.setDirection(DIRECTION::RIGHT);
			}
		}

		//螃艇薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('D') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightWalk"), ImageManager::GetInstance()->FindImage("playerRightWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::RIGHT);
		}
		//豭薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('A') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftWalk"), ImageManager::GetInstance()->FindImage("playerLeftWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::LEFT);
		}
		//嬪薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('W') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpWalk"), ImageManager::GetInstance()->FindImage("playerUpWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::UP);
		}
		//嬴楚酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('S') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownWalk"), ImageManager::GetInstance()->FindImage("playerDownWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::DOWN);
		}
	}
}

//sword 鼻鷓
void playerSwordState::update(player & player)
{
	//1顫 奢問
	if (!player.getSwordAttackCombo())
	{
		if (KEYMANAGER->isOnceKeyDown('J'))
		{
			player.setSwrodAttackCombo(true);
		}
	}

	//奢問醞
	if (player.getSwordAttack())
	{
		if (player.getPlayerMotion() == KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpSword1")
			|| player.getPlayerMotion() == KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownSword1")
			|| player.getPlayerMotion() == KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftSword1")
			|| player.getPlayerMotion() == KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightSword1"))
		{
			//擁棲詭檜暮 營儅 部釭賊
			if (!KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpSword1")->isPlay() && !KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownSword1")->isPlay()
				&& !KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftSword1")->isPlay() && !KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightSword1")->isPlay())
			{
				player.setAttackRcbool(false);
				player.setAttackRc(player.getX(), player.getY(), 0, 0);
				//酈援腦賊 2顫煎 剩橫馬
				if (player.getSwordAttackCombo())
				{
					player.setSwordAttack(true);
					if (player.getDirection() == DIRECTION::UP)
					{
						player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpSword2"), ImageManager::GetInstance()->FindImage("playerUpSword2"));
						player.setAttackRc(player.getX(), player.getY() - 50, 50, 60);
					}
					if (player.getDirection() == DIRECTION::DOWN)
					{
						player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownSword2"), ImageManager::GetInstance()->FindImage("playerDownSword2"));
						player.setAttackRc(player.getX(), player.getY() + 50, 50, 60);
					}
					if (player.getDirection() == DIRECTION::LEFT)
					{
						player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftSword2"), ImageManager::GetInstance()->FindImage("playerLeftSword2"));
						player.setAttackRc(player.getX() - 50, player.getY(), 60, 50);
					}
					if (player.getDirection() == DIRECTION::RIGHT)
					{
						player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightSword2"), ImageManager::GetInstance()->FindImage("playerRightSword2"));
						player.setAttackRc(player.getX() + 50, player.getY(), 60, 50);
					}
					player.setSwrodAttackCombo(false);
				}
			}
		}
	}

	//虜擒 擁棲詭檜暮 營儅 部釭賊
	if (!KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpSword1")->isPlay() && !KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownSword1")->isPlay()
		&& !KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftSword1")->isPlay() && !KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightSword1")->isPlay()
		&& !KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpSword2")->isPlay() && !KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownSword2")->isPlay()
		&& !KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftSword2")->isPlay() && !KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightSword2")->isPlay())
	{
		player.setSwrodAttackCombo(false);
		player.setAttackRcbool(false);
		player.setAttackRc(player.getX(), player.getY(), 0, 0);

		//嬴鼠酈紫 援腦雖彊戲賊 嬴檜菟 鼻鷓煎 瞪��
		if (KEYMANAGER->getKeyUp() == NULL || KEYMANAGER->isOnceKeyUp('W') || KEYMANAGER->isOnceKeyUp('S') || KEYMANAGER->isOnceKeyUp('A') || KEYMANAGER->isOnceKeyUp('D'))
		{
			if (player.getDirection() == DIRECTION::UP)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpIdle"), ImageManager::GetInstance()->FindImage("playerUpIdle"));
				player.setCurrentState(player.getIdleState());
				player.setDirection(DIRECTION::UP);
			}

			if (player.getDirection() == DIRECTION::DOWN)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownIdle"), ImageManager::GetInstance()->FindImage("playerDownIdle"));
				player.setCurrentState(player.getIdleState());
				player.setDirection(DIRECTION::DOWN);
			}

			if (player.getDirection() == DIRECTION::LEFT)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftIdle"), ImageManager::GetInstance()->FindImage("playerLeftIdle"));
				player.setCurrentState(player.getIdleState());
				player.setDirection(DIRECTION::LEFT);
			}

			if (player.getDirection() == DIRECTION::RIGHT)
			{
				player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightIdle"), ImageManager::GetInstance()->FindImage("playerRightIdle"));
				player.setCurrentState(player.getIdleState());
				player.setDirection(DIRECTION::RIGHT);
			}
		}

		//螃艇薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('D') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightWalk"), ImageManager::GetInstance()->FindImage("playerRightWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::RIGHT);
		}
		//豭薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('A') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftWalk"), ImageManager::GetInstance()->FindImage("playerLeftWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::LEFT);
		}
		//嬪薹酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('W') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpWalk"), ImageManager::GetInstance()->FindImage("playerUpWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::UP);
		}
		//嬴楚酈蒂 援腦賊 棻衛 檜翕ж啪
		else if (GetAsyncKeyState('S') & 0x8000)
		{
			player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownWalk"), ImageManager::GetInstance()->FindImage("playerDownWalk"));
			player.setCurrentState(player.getWalkState());
			player.setDirection(DIRECTION::DOWN);
		}
	}
}

//綿濠瑞韓 
void playerBroomState::update(player & player)
{
	//嬪
	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerUpWalk"), ImageManager::GetInstance()->FindImage("playerUpWalk"));
		player.setCurrentState(player.getWalkState());
	}
	//嬴楚 
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownWalk"), ImageManager::GetInstance()->FindImage("playerDownWalk"));
		player.setCurrentState(player.getWalkState());
	}
	//豭薹 
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerLeftWalk"), ImageManager::GetInstance()->FindImage("playerLeftWalk"));
		player.setCurrentState(player.getWalkState());
	}
	//螃艇薹 
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerRightWalk"), ImageManager::GetInstance()->FindImage("playerRightWalk"));
		player.setCurrentState(player.getWalkState());
	}
}

//藹渠 鼻鷓
void playerBedState::update(player & player)
{
	//擁棲詭檜暮檜 部釭堅 霞ч
	if (!KEYANIMANAGER->findAnimation(player.getIndex(), "playerBed")->isPlay())
	{
		player.setShadowX(515);
		player.setShadowY(550);
		player.setX(player.getShadowX());
		player.setY(player.getShadowY()- 50);

		player.setPlayerMotion(KEYANIMANAGER->findAnimation(player.getIndex(), "playerDownIdle"), ImageManager::GetInstance()->FindImage("playerDownIdle"));
		player.setCurrentState(player.getIdleState());
	}
}
