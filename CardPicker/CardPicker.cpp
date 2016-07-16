#include "stdafx.h"
#include "Main.h"
#include "WindowUtil.h"
#include "EnvironmentDirectX.h"

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(nCmdShow);

	const std::wstring strClassName = L"CardPicker";

	if(false == light::WindowUtil::register_class(strClassName, CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW, ::LoadIcon(GetModuleHandle(NULL), NULL)) )
		return FALSE;

	RECT rect = {0, 0, 1024, 768};

	std::wstring strArg;
	if( 0 < strlen(lpCmdLine) )
	{
		strArg = CHAR_TO_WCHAR(lpCmdLine);
	}

	RUN_MAIN_DIRECTX_ARG(Main, strClassName, strArg, strClassName, rect);
	return 0;
}
