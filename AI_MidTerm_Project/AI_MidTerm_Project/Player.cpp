#include "Player.h"

eMap Player::GetType()
{
    return (eMap)(playerState + playerAnimState);
}

void Player::Move(MapLogic* _map, eDirection _moveDir)
{
    GameObject::Move(_map, _moveDir);
}

void Player::CheckInMap(MapLogic* _map)
{
    

}

void Player::StateUpdate()
{
    playerAnimState = playerAnimState + 1 >= PLAYER_ANIM_END ? 0 : playerAnimState + 1;
}

void Player::SetState(eDirection _dir)
{
    switch (_dir)
    {
    case E_NULL:
        break;
    case E_UP:
        playerState = E_PLAYER_UP;
        break;
    case E_LEFT:
        playerState = E_PLAYER_LEFT;
        break;
    case E_RIGHT:
        playerState = E_PLAYER_RIGHT;
        break;
    case E_DOWN:
        playerState = E_PLAYER_DOWN;
        break;
    default:
        break;
    }
}
