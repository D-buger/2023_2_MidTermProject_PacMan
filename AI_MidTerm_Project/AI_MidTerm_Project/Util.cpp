#include "Util.h"

COORD MakeCoord(int x, int y)
{
	COORD c = { x, y };
	return c;
}

const COORD operator+(const COORD& ca, const COORD& cb)
{
	COORD c = { ca.X, ca.Y };
	c.X += cb.X;
	c.Y += cb.Y;
	return c;
}

const COORD operator-(const COORD& ca, const COORD& cb)
{
	COORD c = { ca.X, ca.Y };
	c.X -= cb.X;
	c.Y -= cb.Y;
	return c;
}

const bool operator<(const COORD& ca, const COORD& cb)
{
	return (ca.X + ca.Y < cb.X + cb.Y);
}

const bool operator==(const COORD& ca, const COORD& cb)
{
	return (ca.X == cb.X) && (ca.Y == cb.Y);
}
