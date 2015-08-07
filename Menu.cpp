#include "Menu.h"
#include "TextBlock.h"
#include "Fov.h"
#include "Controls.h"

#define SAFE_RELEASE(x) if( x ) { (x)->Release(); (x) = NULL; }

namespace Menu
{
	TextBlock *menu;

	void Initialize(IDirect3DDevice9 *pDevice,D3DPRESENT_PARAMETERS *pPP)
	{
		menu = new TextBlock(pDevice,pPP);

		menu->SetFont("Courier New",16,FW_NORMAL,false,5);
		menu->SetTextColor(D3DXCOLOR(1,1,1,1));
		menu->SetBlockColor(D3DXCOLOR(0,0,0,0.6f));
		menu->SetBlockSize(160,0);
		menu->SetTextPadding(5);
		menu->AttachBlock(ATTACH_TOP_CENTER,0,0,0,0);
		menu->SetTextFormat(DT_LEFT);

		menu->SetText("1. FOV\n2. Perspective\n3. Spectate\n4. Team Colors\n5. Weapon Position\n6. Stats\n\n0: Hide/Show\n\n\n");
		menu->CalculateBlock();
	}

	void Draw()
	{
		menu->Draw();
	}

	void OnResetDevice(D3DPRESENT_PARAMETERS *pPP)
	{
		menu->OnResetDevice(pPP);
		menu->CalculateBlock();
	}

	void OnLostDevice()
	{
		menu->OnLostDevice();
	}

	void Release()
	{
		SAFE_RELEASE( menu );
	}
}