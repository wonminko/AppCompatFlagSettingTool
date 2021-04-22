#include "pch.h"
#include "FileCompatibilityManager.h"


FileCompatibilityManager::FileCompatibilityManager()
{

}

int FileCompatibilityManager::SetCompatibilityData(CString strExeFilePath, int nChekFlag, osMode _osMode, colorMode _colorMode)
{
	int nResult = 0;

	if (_taccess(strExeFilePath, 0) != 0)
	{
		TRACE(_T("���������� �������� �ʽ��ϴ�."));
		return -1;
	}

	CString strRegData = _T("~");

	if (nChekFlag & _check_restart)
	{
		strRegData = strRegData + _T(" ") + DF_REGSTR_RESTART;
	}

	if (nChekFlag & _check_runasadmin)
	{
		strRegData = strRegData + _T(" ") + DF_REGSTR_RUNAADMIN;
	}

	if (nChekFlag & _check_notfullscreen)
	{
		strRegData = strRegData + _T(" ") + DF_REGSTR_NOTUSEFULLSCREEN;
	}

	if (nChekFlag & _check_resolution)
	{
		strRegData = strRegData + _T(" ") + DF_REGSTR_RESOLUTION;
	}

	if (nChekFlag & _check_colormode)
	{
		if(_colorMode == _color8bit)
			strRegData = strRegData + _T(" ") + DF_REGSTR_COLOR8BIT;
		else
			strRegData = strRegData + _T(" ") + DF_REGSTR_COLOR16BIT;
	}

	if (nChekFlag & _check_compatibility)
	{
		switch (_osMode)
		{
			
		
		case _win95:
		case _win98Me:
		case _winXPSP2:
			strRegData = strRegData + _T(" ") + DF_REGSTR_XPSP2;
			break;
		case _winXPSP3:
			strRegData = strRegData + _T(" ") + DF_REGSTR_XPSP3;
			break;
		case _vista:
			strRegData = strRegData + _T(" ") + DF_REGSTR_VISTA;
			break;
		case _vistaSP1:
			strRegData = strRegData + _T(" ") + DF_REGSTR_VISTASP1;
			break;
		case _vistaSP2:
			strRegData = strRegData + _T(" ") + DF_REGSTR_VISTASP2;
			break;
		case _win7:
			strRegData = strRegData + _T(" ") + DF_REGSTR_WIN7;
			break;
		case _win8:
			strRegData = strRegData + _T(" ") + DF_REGSTR_WIN8;
			break;
		}
		
	}

	if (strRegData.GetLength() < 2)
	{
		TRACE(_T("������ �÷��װ� �����ϴ�."));
		return -2;
	}

	nResult = WriteDataToRegistry(strExeFilePath, strRegData);

	if (nResult != 0)
	{
		TRACE(_T("������Ʈ�� ��� ����"));
		return -3;
	}

	return 0;
}

int	FileCompatibilityManager::WriteDataToRegistry(CString strExeFilePath, CString strRegData)
{
	
	HKEY hChildKey;
	DWORD dwDisposition = 0;

	if (RegCreateKeyEx(HKEY_CURRENT_USER, DE_REG_PATH_APPCOMPATFLAG, 0, NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_CREATE_SUB_KEY | KEY_ALL_ACCESS,
		NULL, &hChildKey, &dwDisposition) != ERROR_SUCCESS) {
		// Ű�� ���� �� ����
		return -1;
	}

	if (RegSetValueEx(hChildKey, (LPCTSTR)strExeFilePath, 0, REG_SZ,
		(const BYTE*)(LPCTSTR)strRegData,
		(DWORD)strRegData.GetLength() * 2) != ERROR_SUCCESS) {
		// ������Ʈ���� ���� ������ �� ����
		RegCloseKey(hChildKey);
		return -2;
	}

	RegCloseKey(hChildKey);

	return 0;
	
}