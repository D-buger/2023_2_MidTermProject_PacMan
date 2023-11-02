#include "Ghost.h"
#include "State.h"
#include "Player.h"
#include "MapLogic.h"

#include "HuntedState.h"
Ghost::Ghost(COORD _pos, byte _color) : GameObject(_pos, _color)
{
	stateIcon = E_GHOST_HUNTER;
	currentState = HuntedState().Instance();
}

Ghost::~Ghost()
{

}

void Ghost::SetTargetToNULL()
{
	target = nullptr;
}

void Ghost::SetTarget(MapLogic* _map, Player* _player)
{
	isCollisionPacMan = (this->pos == _player->pos);
	isCollisionGhostBox = (this->pos == COORD({GHOSTBOX_X, GHOSTBOX_Y}));

	target = _player;
}

eMap Ghost::GetType()
{
    return (eMap)stateIcon;
}

void Ghost::CheckState(MapLogic* _map, Player* _player) {

}

//Hunter (NULL) : random move
//Hunter (player) : A* to player
//Hunted (player) : A* to opposite player
//Eaten (any) : A* to GhostBox 
void Ghost::Update(MapLogic* _map, eDirection _moveDir)
{
	currentState->Execute(this);

	if (target != nullptr) {
		path.FindPath(_map, this->pos, target->pos);	//�ſ� ���ſ�
		
		if (isPacManEatsPill) {											//�÷��̾ �˾��� �Ծ��� ��
			moveDir = MapLogic::OppositeDir(path.GetDirection());
		}
		else if (path.GetDist() <= RECOGNIZE_PLAYER) {					//�÷��̾ Ž�� ���� �ȿ� ������ ��
			moveDir = path.GetDirection();
		}
		else if(moveDir == E_NULL){										//������ ������ ���������� ���� ��
			moveDir = (eDirection)(rand() % 4 + 1);
		}
		else if(_map->GetMap(this->pos + MapLogic::DirToPos(moveDir)) == E_MAP_WALL){	//������ ������ ������ �� ���� ���� ��
			moveDir = E_NULL;
		}
	}
	else {
		path.FindPath(_map, this->pos, COORD({GHOSTBOX_X, GHOSTBOX_Y}));
	}


	GameObject::Update(_map, moveDir);
}

void Ghost::Move(MapLogic* _map, eDirection _moveDir)
{
    GameObject::Move(_map, _moveDir);
}

void Ghost::StateUpdate()
{
}

void Ghost::SetState(eDirection _dir)
{

}

void Ghost::ChangeState(State* _pNewState)
{
	currentState->Exit(this);
	currentState = _pNewState;
	currentState->Enter(this);
	currentState->Execute(this);
}
