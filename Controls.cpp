// Controls.cpp
//

#include "Controls.h"
#include "Addresses.h"


namespace Controls
{	
	ControlSettings* settings = (ControlSettings*)ADDR_CONTROL_DEFS;

	char* keyState = (char*)ADDR_KEYS;
	char* mouseButtonState = (char*)ADDR_MOUSE_BUTTONS;
	long* mouseAxisState = (long*)ADDR_MOUSE_AXES;
	char* joyButtonState = (char*)ADDR_JOY_BUTTONS;
	JoyAxisState* joyAxisState = (JoyAxisState*)ADDR_JOY_AXES;
	long* joyDPadState = (long*)ADDR_JOY_DPADS;

	int GetState(ControlLabel control)
	{
		return GetState(
					GetDevice(control),
					GetType(control),
					GetIndex(control),
					GetDirection(control));
	}

	void SetState(ControlLabel control,int state)
	{
		SetState(
			GetDevice(control),
			GetType(control),
			GetIndex(control),
			state);
	}

	bool IsKeyboard(ControlLabel control)		{ return (GetDevice(control) == Keyboard); }
	bool IsMouse(ControlLabel control)		{ return (GetDevice(control) == Mouse); }
	bool IsJoystick(ControlLabel control)		{ return (GetDevice(control) == Joystick); }

	int GetState(short device,short type,short index,short direction)
	{
		int state = 0;

		if (device == 0)
		{
			state = 0;
		}
		else if (device == Keyboard)
		{
			state = GetKeyState((Key)index);
		}
		else if (device == Mouse)
		{
			if (type == Button)
				state = GetMouseButtonState((MouseButton)index);
			else if (type == Axis)
				state = GetMouseAxisState((MouseAxis)index);
		}	
		else if (device == Joystick)
		{
			if (type == Button)
				state = GetJoyButtonState((JoyButton)index);
			else if (type == Axis)
				state = GetJoyAxisState((JoyAxis)index);
			else if (type == DPad)
				state = GetJoyDPadState((JoyDPad)index);
		}
		
		// Check if direction matches setting
		if (type == Axis && direction != 0 && state != (direction>0)?1:2)
			state = 0;
		else if (type == DPad && state != direction)
			state = 0;	

		return state;
	}

	void SetState(short device,short type,short index,int state)
	{
		if (device == 0)
		{
		}
		else if (device == Keyboard)
		{
			SetKeyState((Key)index,state);
		}
		else if (device == Mouse)
		{
			if (type == Button)
				SetMouseButtonState((MouseButton)index,state);
			else if (type == Axis)
				SetMouseAxisState((MouseAxis)index,state);
		}	
		else if (device == Joystick)
		{
			if (type == Button)
				SetJoyButtonState((JoyButton)index,state);
			else if (type == Axis)
				SetJoyAxisState((JoyAxis)index,state);
			else if (type == DPad)
				SetJoyDPadState((JoyDPad)index,state);
		}

	}

	short GetDevice(ControlLabel control)					{ return settings[control].device; }
	short GetType(ControlLabel control)						{ return settings[control].type; }
	short GetIndex(ControlLabel control)					{ return settings[control].index; }
	short GetDirection(ControlLabel control)				{ return settings[control].direction; }

	char GetKeyState(Key key)								{ return keyState[key]; }
	void SetKeyState(Key key,char state)					{ keyState[key] = state; }

	char GetMouseButtonState(MouseButton button)			{ return mouseButtonState[button]; }
	void SetMouseButtonState(MouseButton button,char state)	{ mouseButtonState[button] = state; }

	long GetMouseAxisState(MouseAxis axis)					{ return mouseAxisState[axis]; }
	void SetMouseAxisState(MouseAxis axis,long state)		{ mouseAxisState[axis] = state; }

	char GetJoyButtonState(JoyButton button)				{ return joyButtonState[button]; }
	void SetJoyButtonState(JoyButton button,char state)		{ joyButtonState[button] = state; }

	char GetJoyAxisState(JoyAxis axis)						{ return joyAxisState[axis].direction; }
	void SetJoyAxisState(JoyAxis axis,char state)			{ joyAxisState[axis].direction = state; joyAxisState[axis].speed = 0; }

	long GetJoyDPadState(JoyDPad dpad)						{ return joyDPadState[dpad]; }
	void SetJoyDPadState(JoyDPad dpad,long state)			{ joyDPadState[dpad] = state; }
}