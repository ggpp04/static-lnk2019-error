#include "BoxFix.h"

int BoxFix::FixCursorY(float CursorY)
{
	CursorY = CursorY - (640 - BoxFix::Ysize);
	// ��ġ ��ǥ - (640 - ������ ũ��)
	return CursorY;
}