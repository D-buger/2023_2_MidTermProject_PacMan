#pragma once

#include "Util.h"
#include "GameObject.h"
#include "AStar.h"

class State;
class Player;

const static float END_TIME_OF_HUNTED = 50;	//Hunted ���°� ������ �ð�
const static float END_TIME_OF_INBOX = 20;	//In-Box ���°� ������ �ð�

const int RANDOM_DISTANCE = 5;				//�����ϰ� ���ƴٴϴ� �Ÿ�
const int RECOGNIZE_PLAYER = 8;				//�÷��̾� �ν� �Ÿ�

class Ghost : public GameObject
{
private:
	State* currentState;

	bool isPacManEatsPill = false;			//�÷��̾ �˾��� �Ծ�����
	bool isCollisionPacMan = false;			//�÷��̾�� �ε��ƴ���
	bool isCollisionGhostBox = false;		//GhostBox �ȿ� ���Դ���

	AStar path;

	Player* target = nullptr;
public:
	Ghost(COORD _pos, byte _color);
	~Ghost();

	void SetTargetToNULL();
	void SetTarget(MapLogic* _map, Player* _player);

	bool GetIsPacManEatsPill() { return isPacManEatsPill; }
	void SetIsPacManEatsPill(bool _isEat) { isPacManEatsPill = _isEat; }
	bool GetIsCollisionPacMan() { return isCollisionPacMan; }
	void SetIsCollisionPacMan(bool _isCollision) { isCollisionPacMan = _isCollision; }
	bool GetIsCollisionGhostBox() { return isCollisionGhostBox; }
	void SetIsCollisionGhostBox(bool _isCollision) { isCollisionGhostBox = _isCollision; }

	// GameObject��(��) ���� ��ӵ�
	eMap GetType() override;

	void CheckState(MapLogic* _map, Player* _player);

	void Update(MapLogic* _map, eDirection _moveDir) override;

	void Move(MapLogic* _map, eDirection _moveDir) override;	

	void StateUpdate() override;
	void SetState(eDirection _dir) override;
	void ChangeState(State* _pNewState);
};

