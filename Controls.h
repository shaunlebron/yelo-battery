// Controls.h
// Interface to retrieve control settings and simulate input.

#pragma once

#include "ControlTypes.h"

namespace Controls
{
	// user friendly functions
	int GetState(ControlLabel control);
	void SetState(ControlLabel,int state);

	bool IsKeyboard(ControlLabel control);
	bool IsMouse(ControlLabel control);
	bool IsJoystick(ControlLabel control);

	short GetDevice(ControlLabel control);
	short GetType(ControlLabel control);
	short GetIndex(ControlLabel control);
	short GetDirection(ControlLabel control);

	int GetState(short device,short type,short index,short direction);
	void SetState(short device,short type,short index,int state);

	char GetKeyState(Key key);

	char GetMouseButtonState(MouseButton button);
	long GetMouseAxisState(MouseAxis axis);

	char GetJoyButtonState(JoyButton button);
	char GetJoyAxisState(JoyAxis axis);
	long GetJoyDPadState(JoyDPad dpad);

	void SetKeyState(Key key,char state);

	void SetMouseButtonState(MouseButton button,char state);
	void SetMouseAxisState(MouseAxis axis,long state);

	void SetJoyButtonState(JoyButton button,char state);
	void SetJoyAxisState(JoyAxis axis,char state);
	void SetJoyDPadState(JoyDPad dpad,long state);
}