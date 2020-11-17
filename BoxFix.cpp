#include "BoxFix.h"

int BoxFix::FixCursorY(float CursorY)
{
	CursorY = CursorY - (640 - BoxFix::Ysize);
	// 터치 좌표 - (640 - 프레임 크기)
	return CursorY;
}