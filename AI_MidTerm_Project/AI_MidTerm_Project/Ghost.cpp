#include "Ghost.h"
#include "State.h"

#include "HuntedState.h"
Ghost::Ghost(COORD _pos) : GameObject(_pos)
{
	currentState = HuntedState().Instance();
}

Ghost::~Ghost()
{

}

eMap Ghost::GetType()
{
    return eMap::E_MAP_GHOST;
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
