// Copyright 2023, Solieyagai15409. All Rights Reserved.

#include "ColorPickerBPLibrary.h"
#include "ColorPicker.h"
#include "windows/AllowWindowsPlatformTypes.h"

UColorPickerBPLibrary::UColorPickerBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}



FColor UColorPickerBPLibrary::PickerColorsInMouse()
{
	HDC hDC = ::GetDC(NULL);
	/*CPoint pt;*/
	POINT pt1;
	GetCursorPos(&pt1);
	COLORREF clr = ::GetPixel(hDC, pt1.x, pt1.y);
	uint8 R = GetRValue(clr);
	uint8 G = GetGValue(clr);
	uint8 B = GetBValue(clr);
	::ReleaseDC(NULL, hDC);

	FColor Color;
	
	Color.R = R;
	Color.G = G;
	Color.B = B;
	Color.A = 255;
	return Color;
}


