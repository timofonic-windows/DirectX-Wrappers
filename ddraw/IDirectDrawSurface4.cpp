/**
* Copyright (C) 2017 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*/

#include "ddraw.h"

HRESULT m_IDirectDrawSurface4::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
	if ((riid == IID_IDirectDrawSurface4 || riid == IID_IUnknown) && ppvObj)
	{
		AddRef();

		*ppvObj = this;

		return S_OK;
	}

	HRESULT hr = ProxyInterface->QueryInterface(riid, ppvObj);

	if (SUCCEEDED(hr))
	{
		genericQueryInterface(riid, ppvObj);
	}

	return hr;
}

ULONG m_IDirectDrawSurface4::AddRef()
{
	return ProxyInterface->AddRef();
}

ULONG m_IDirectDrawSurface4::Release()
{
	ULONG x = ProxyInterface->Release();

	if (x == 0)
	{
		delete this;
	}

	return x;
}

HRESULT m_IDirectDrawSurface4::AddAttachedSurface(LPDIRECTDRAWSURFACE4 a)
{
	if (a)
	{
		a = static_cast<m_IDirectDrawSurface4 *>(a)->GetProxyInterface();
	}

	return ProxyInterface->AddAttachedSurface(a);
}

HRESULT m_IDirectDrawSurface4::AddOverlayDirtyRect(LPRECT a)
{
	return ProxyInterface->AddOverlayDirtyRect(a);
}

HRESULT m_IDirectDrawSurface4::Blt(LPRECT a, LPDIRECTDRAWSURFACE4 b, LPRECT c, DWORD d, LPDDBLTFX e)
{
	if (b)
	{
		b = static_cast<m_IDirectDrawSurface4 *>(b)->GetProxyInterface();
	}

	return ProxyInterface->Blt(a, b, c, d, e);
}

HRESULT m_IDirectDrawSurface4::BltBatch(LPDDBLTBATCH a, DWORD b, DWORD c)
{
	if (a && a->lpDDSSrc)
	{
		a->lpDDSSrc = static_cast<m_IDirectDrawSurface *>(a->lpDDSSrc)->GetProxyInterface();
	}

	return ProxyInterface->BltBatch(a, b, c);
}

HRESULT m_IDirectDrawSurface4::BltFast(DWORD a, DWORD b, LPDIRECTDRAWSURFACE4 c, LPRECT d, DWORD e)
{
	if (c)
	{
		c = static_cast<m_IDirectDrawSurface4 *>(c)->GetProxyInterface();
	}

	return ProxyInterface->BltFast(a, b, c, d, e);
}

HRESULT m_IDirectDrawSurface4::DeleteAttachedSurface(DWORD a, LPDIRECTDRAWSURFACE4 b)
{
	if (b)
	{
		b = static_cast<m_IDirectDrawSurface4 *>(b)->GetProxyInterface();
	}

	return ProxyInterface->DeleteAttachedSurface(a, b);
}

HRESULT m_IDirectDrawSurface4::EnumAttachedSurfaces(LPVOID a, LPDDENUMSURFACESCALLBACK2 b)
{
	ENUMSURFACE2 CallbackContext;
	CallbackContext.lpContext = a;
	CallbackContext.lpCallback = b;

	return ProxyInterface->EnumAttachedSurfaces(&CallbackContext, m_IDirectDrawEnumSurface2::EnumSurface2Callback);
}

HRESULT m_IDirectDrawSurface4::EnumOverlayZOrders(DWORD a, LPVOID b, LPDDENUMSURFACESCALLBACK2 c)
{
	ENUMSURFACE2 CallbackContext;
	CallbackContext.lpContext = b;
	CallbackContext.lpCallback = c;

	return ProxyInterface->EnumOverlayZOrders(a, &CallbackContext, m_IDirectDrawEnumSurface2::EnumSurface2Callback);
}

HRESULT m_IDirectDrawSurface4::Flip(LPDIRECTDRAWSURFACE4 a, DWORD b)
{
	if (a)
	{
		a = static_cast<m_IDirectDrawSurface4 *>(a)->GetProxyInterface();
	}

	return ProxyInterface->Flip(a, b);
}

HRESULT m_IDirectDrawSurface4::GetAttachedSurface(LPDDSCAPS2 a, LPDIRECTDRAWSURFACE4 FAR * b)
{
	HRESULT hr = ProxyInterface->GetAttachedSurface(a, b);

	if (SUCCEEDED(hr))
	{
		*b = ProxyAddressLookupTable.FindAddress<m_IDirectDrawSurface4>(*b);
	}

	return hr;
}

HRESULT m_IDirectDrawSurface4::GetBltStatus(DWORD a)
{
	return ProxyInterface->GetBltStatus(a);
}

HRESULT m_IDirectDrawSurface4::GetCaps(LPDDSCAPS2 a)
{
	return ProxyInterface->GetCaps(a);
}

HRESULT m_IDirectDrawSurface4::GetClipper(LPDIRECTDRAWCLIPPER FAR * a)
{
	HRESULT hr = ProxyInterface->GetClipper(a);

	if (SUCCEEDED(hr))
	{
		*a = ProxyAddressLookupTable.FindAddress<m_IDirectDrawClipper>(*a);
	}

	return hr;
}

HRESULT m_IDirectDrawSurface4::GetColorKey(DWORD a, LPDDCOLORKEY b)
{
	return ProxyInterface->GetColorKey(a, b);
}

HRESULT m_IDirectDrawSurface4::GetDC(HDC FAR * a)
{
	return ProxyInterface->GetDC(a);
}

HRESULT m_IDirectDrawSurface4::GetFlipStatus(DWORD a)
{
	return ProxyInterface->GetFlipStatus(a);
}

HRESULT m_IDirectDrawSurface4::GetOverlayPosition(LPLONG a, LPLONG b)
{
	return ProxyInterface->GetOverlayPosition(a, b);
}

HRESULT m_IDirectDrawSurface4::GetPalette(LPDIRECTDRAWPALETTE FAR * a)
{
	HRESULT hr = ProxyInterface->GetPalette(a);

	if (SUCCEEDED(hr))
	{
		*a = ProxyAddressLookupTable.FindAddress<m_IDirectDrawPalette>(*a);
	}

	return hr;
}

HRESULT m_IDirectDrawSurface4::GetPixelFormat(LPDDPIXELFORMAT a)
{
	return ProxyInterface->GetPixelFormat(a);
}

HRESULT m_IDirectDrawSurface4::GetSurfaceDesc(LPDDSURFACEDESC2 a)
{
	return ProxyInterface->GetSurfaceDesc(a);
}

HRESULT m_IDirectDrawSurface4::Initialize(LPDIRECTDRAW a, LPDDSURFACEDESC2 b)
{
	if (a)
	{
		a = static_cast<m_IDirectDraw *>(a)->GetProxyInterface();
	}

	return ProxyInterface->Initialize(a, b);
}

HRESULT m_IDirectDrawSurface4::IsLost()
{
	return ProxyInterface->IsLost();
}

HRESULT m_IDirectDrawSurface4::Lock(LPRECT a, LPDDSURFACEDESC2 b, DWORD c, HANDLE d)
{
	return ProxyInterface->Lock(a, b, c, d);
}

HRESULT m_IDirectDrawSurface4::ReleaseDC(HDC a)
{
	return ProxyInterface->ReleaseDC(a);
}

HRESULT m_IDirectDrawSurface4::Restore()
{
	return ProxyInterface->Restore();
}

HRESULT m_IDirectDrawSurface4::SetClipper(LPDIRECTDRAWCLIPPER a)
{
	if (a)
	{
		a = static_cast<m_IDirectDrawClipper *>(a)->GetProxyInterface();
	}

	return ProxyInterface->SetClipper(a);
}

HRESULT m_IDirectDrawSurface4::SetColorKey(DWORD a, LPDDCOLORKEY b)
{
	return ProxyInterface->SetColorKey(a, b);
}

HRESULT m_IDirectDrawSurface4::SetOverlayPosition(LONG a, LONG b)
{
	return ProxyInterface->SetOverlayPosition(a, b);
}

HRESULT m_IDirectDrawSurface4::SetPalette(LPDIRECTDRAWPALETTE a)
{
	if (a)
	{
		a = static_cast<m_IDirectDrawPalette *>(a)->GetProxyInterface();
	}

	return ProxyInterface->SetPalette(a);
}

HRESULT m_IDirectDrawSurface4::Unlock(LPRECT a)
{
	return ProxyInterface->Unlock(a);
}

HRESULT m_IDirectDrawSurface4::UpdateOverlay(LPRECT a, LPDIRECTDRAWSURFACE4 b, LPRECT c, DWORD d, LPDDOVERLAYFX e)
{
	if (b)
	{
		b = static_cast<m_IDirectDrawSurface4 *>(b)->GetProxyInterface();
	}

	return ProxyInterface->UpdateOverlay(a, b, c, d, e);
}

HRESULT m_IDirectDrawSurface4::UpdateOverlayDisplay(DWORD a)
{
	return ProxyInterface->UpdateOverlayDisplay(a);
}

HRESULT m_IDirectDrawSurface4::UpdateOverlayZOrder(DWORD a, LPDIRECTDRAWSURFACE4 b)
{
	if (b)
	{
		b = static_cast<m_IDirectDrawSurface4 *>(b)->GetProxyInterface();
	}

	return ProxyInterface->UpdateOverlayZOrder(a, b);
}

HRESULT m_IDirectDrawSurface4::GetDDInterface(LPVOID FAR * a)
{
	HRESULT hr = ProxyInterface->GetDDInterface(a);

	if (SUCCEEDED(hr))
	{
		*a = ProxyAddressLookupTable.FindAddress<m_IDirectDraw4>(*a);
	}

	return hr;
}

HRESULT m_IDirectDrawSurface4::PageLock(DWORD a)
{
	return ProxyInterface->PageLock(a);
}

HRESULT m_IDirectDrawSurface4::PageUnlock(DWORD a)
{
	return ProxyInterface->PageUnlock(a);
}

HRESULT m_IDirectDrawSurface4::SetSurfaceDesc(LPDDSURFACEDESC2 a, DWORD b)
{
	return ProxyInterface->SetSurfaceDesc(a, b);
}

HRESULT m_IDirectDrawSurface4::SetPrivateData(REFGUID a, LPVOID b, DWORD c, DWORD d)
{
	return ProxyInterface->SetPrivateData(a, b, c, d);
}

HRESULT m_IDirectDrawSurface4::GetPrivateData(REFGUID a, LPVOID b, LPDWORD c)
{
	return ProxyInterface->GetPrivateData(a, b, c);
}

HRESULT m_IDirectDrawSurface4::FreePrivateData(REFGUID a)
{
	return ProxyInterface->FreePrivateData(a);
}

HRESULT m_IDirectDrawSurface4::GetUniquenessValue(LPDWORD a)
{
	return ProxyInterface->GetUniquenessValue(a);
}

HRESULT m_IDirectDrawSurface4::ChangeUniquenessValue()
{
	return ProxyInterface->ChangeUniquenessValue();
}
