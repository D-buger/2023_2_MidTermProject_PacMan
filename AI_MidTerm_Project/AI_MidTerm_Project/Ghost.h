#pragma once

#include "Util.h"
#include "GameObject.h"
#include "AStar.h"

class State;
class Player;

const static float END_TIME_OF_HUNTED = 150;	//Hunted 상태가 끝나는 시간
const static float END_TIME_OF_INBOX = 20;	//In-Box 상태가 끝나는 시간

const int RECOGNIZE_PLAYER = 15;				//플레이어 인식 거리

class Ghost : public GameObject
{
private:
	State* currentState;

	bool isPacManEatsPill = false;			//플레이어가 알약을 먹었는지
	bool isCollisionPacMan = false;			//플레이어와 부딪쳤는지
	bool isCollisionGhostBox = false;		//GhostBox 안에 들어왔는지

	AStar path;

	Player* target = nullptr;

	bool canMove = true;
public:
	const byte oriColor;

	Ghost(COORD _pos, byte _color, int _startTime);
	~Ghost();

	void SetTargetToNULL();
	void SetTarget(MapLogic* _map, Player* _player);

	bool GetIsPacManEatsPill() { return isPacManEatsPill; }
	void SetIsPacManEatsPill(bool _isEat) { isPacManEatsPill = _isEat; }
	bool GetIsCollisionPacMan() { return isCollisionPacMan; }
	void SetIsCollisionPacMan(bool _isCollision) { isCollisionPacMan = _isCollision; }
	bool GetIsCollisionGhostBox() { return isCollisionGhostBox; }
	void SetIsCollisionGhostBox(bool _isCollision) { isCollisionGhostBox = _isCollision; }
	bool GetCanMove() { return canMove; }
	void SetCanMove(bool _canMove) { canMove = _canMove; }

	// GameObject을(를) 통해 상속됨
	eMap GetType() override;

	void CheckState(MapLogic* _map, Player* _player);

	void Update(MapLogic* _map, eDirection _moveDir) override;

	void Move(MapLogic* _map, eDirection _moveDir) override;	

	void StateUpdate() override;
	void SetState(eDirection _dir) override;
	void ChangeState(State* _pNewState);
};

