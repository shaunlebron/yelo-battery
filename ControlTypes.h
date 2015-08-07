#pragma once

struct ControlSettings
{
	short pad1;
	short device;	// enum ControlDevice
	short pad2;
	short type;		// enum ControlType
	short index;	// enum Key / JoyButton / JoyAxis / MouseButton / MouseAxis
	short direction;// enum JoyAxisDirection / JoyDPadDirection / MouseAxisDirection
};

enum ControlLabel
{
	Jump,
	SwitchGrenade,
	Action,
	SwitchWeapon,
	Melee,
	Flashlight,
	ThrowGrenade,
	Fire,
	//  8 is unknown
	//  9 is unknown
	Crouch = 10,
	ScopeZoom,
	//  12 is unknown
	Reload = 13,
	Pickup,
	Say,
	SayToTeam,
	SayToVehicle,
	//  18 is unknown
	MoveForward = 19,
	MoveBackward,
	MoveLeft,
	MoveRight,
	LookUp,
	LookDown,
	LookLeft,
	LookRight
};

enum ControlDevice
{
	Undefined,
	Keyboard,
	Mouse,
	Joystick
};

enum ControlType
{
	Button,
	Axis,
	DPad
};

enum JoyButton
{
	JoyButton1,
	JoyButton2,
	JoyButton3,
	JoyButton4,
	JoyButton5,
	JoyButton6,
	JoyButton7,
	JoyButton8,
	JoyButton9,
	JoyButton10,
	JoyButton11,
	JoyButton12,
	JoyButton13,
	JoyButton14,
	JoyButton15,
	JoyButton16,
	JoyButton17,
	JoyButton18,
	JoyButton19,
	JoyButton20,
	JoyButton21,
	JoyButton22,
	JoyButton23,
	JoyButton24,
	JoyButton25,
	JoyButton26,
	JoyButton27,
	JoyButton28,
	JoyButton29,
	JoyButton30,
	JoyButton31,
	JoyButton32
};
enum JoyAxis
{
	RightJoyAxisY,
	RightJoyAxisX,
	LeftJoyAxisY,
	LeftJoyAxisX,
};
enum JoyDPad
{
	JoyDPad1,
	JoyDPad2,
	JoyDPad3,
	JoyDPad4
};
enum JoyAxisDirection
{
	JoyNoDirection,
	JoyDown,
	JoyRight = JoyDown,
	JoyUp,
	JoyLeft = JoyUp
};
enum JoyDPadDirection
{
	JoyNorth,
	JoyNorthEast,
	JoyEast,
	JoySouthEast,
	JoySouth,
	JoySouthWest,
	JoyWest,
	JoyNorthWest,
	JoyNorth2
};

struct JoyAxisState
{
	char speed;		// 0 to 255, but it's not even used
	char direction; // -16 to 16, screen coordinate system
};

// Mouse Codes
enum MouseButton
{
	MouseButton1,	// Left
	MouseButton2,	// Middle
	MouseButton3,	// Right
	MouseButton4,	// Side Back
	MouseButton5,	// Side Forward
	MouseButton6,
	MouseButton7,
	MouseButton8
};
enum MouseAxis
{
	MouseAxisX,
	MouseAxisY,
	MouseWheel
};
enum MouseAxisDirection
{	
	MouseNoDirection,
	MouseUp,
	MouseRight = MouseUp,
	MouseDown,
	MouseLeft = MouseDown
};

// Keyboard Codes
enum Key
{
	KeyEsc,
	KeyF1,
	KeyF2,
	KeyF3,
	KeyF4,
	KeyF5,
	KeyF6,
	KeyF7,
	KeyF8,
	KeyF9,
	KeyF10,
	KeyF11,
	KeyF12,
	KeyPrntScrn,
	KeyScrollLock,
	KeyPause,
	KeyTidle,
	Key1,
	Key2,
	Key3,
	Key4,
	Key5,
	Key6,
	Key7,
	Key8,
	Key9,
	Key0,
	KeyMinus,
	KeyPlus,
	KeyBackspace,
	KeyTab,
	KeyQ,
	KeyW,
	KeyE,
	KeyR,
	KeyT,
	KeyY,
	KeyU,
	KeyI,
	KeyO,
	KeyP,
	KeyLBracket,
	KeyRBracket,
	KeyPipe,
	KeyCaps,
	KeyA,
	KeyS,
	KeyD,
	KeyF,
	KeyG,
	KeyH,
	KeyJ,
	KeyK,
	KeyL,
	KeyColon,
	KeyQuote,
	KeyEnter,
	KeyLShift,
	KeyZ,
	KeyX,
	KeyC,
	KeyV,
	KeyB,
	KeyN,
	KeyM,
	KeyComma,
	KeyPeriod,
	KeySlash,
	KeyRShift,
	KeyLCtrl,
	KeyLWin,
	KeyLAlt,
	KeySpace,
	KeyRAlt,
	KeyRWin,
	KeyAppsMenu,
	KeyRCtrl,
	KeyUp,
	KeyDown,
	KeyLeft,
	KeyRight,
	KeyInsert,
	KeyHome,
	KeyPgUp,
	KeyDelete,
	KeyEnd,
	KeyPgDown,
	KeyNumsLock,
	KeyNumDivide,
	KeyNumMultiply,
	KeyNum0,
	KeyNum1,
	KeyNum2,
	KeyNum3,
	KeyNum4,
	KeyNum5,
	KeyNum6,
	KeyNum7,
	KeyNum8,
	KeyNum9,
	KeyNumMinus,
	KeyNumAdd,
	KeyNumEnter,
	KeyNumDot
};
