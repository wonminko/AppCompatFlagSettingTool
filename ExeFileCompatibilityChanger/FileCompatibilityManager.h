#pragma once



enum checkOption
{
	_check_compatibility = 1,
	_check_colormode = 2,
	_check_resolution = 4,
	_check_notfullscreen = 8,
	_check_runasadmin = 16,
	_check_restart = 32
};

enum osMode
{
	_win95,
	_win98Me,
	_winXPSP2,
	_winXPSP3,
	_vista,
	_vistaSP1,
	_vistaSP2,
	_win7,
	_win8
};

enum colorMode
{
	_color8bit,
	_color16bit
};

#define DF_REGSTR_WIN8			_T("WIN8RTM")
#define DF_REGSTR_WIN7			_T("WIN7RTM")
#define DF_REGSTR_VISTASP2		_T("VISTASP2")
#define DF_REGSTR_VISTASP1		_T("VISTASP1")
#define DF_REGSTR_VISTA			_T("VISTARTM")
#define DF_REGSTR_XPSP3			_T("WINXPSP3")
#define DF_REGSTR_XPSP2			_T("WINXPSP2")

#define DF_REGSTR_COLOR8BIT		_T("256COLOR")
#define DF_REGSTR_COLOR16BIT	_T("16BITCOLOR")

#define DF_REGSTR_RESOLUTION	_T("640X480")
#define DF_REGSTR_NOTUSEFULLSCREEN		_T("DISABLEDXMAXIMIZEDWINDOWEDMODE")
#define DF_REGSTR_RUNAADMIN		_T("RUNASADMIN")
#define DF_REGSTR_RESTART		_T("REGISTERAPPRESTART")	


#define	DE_REG_PATH_APPCOMPATFLAG		_T( "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\Layers" )

class FileCompatibilityManager
{
public:
	FileCompatibilityManager();


	int		SetCompatibilityData(CString strExeFilePath, int nChekFlag, osMode _osMode, colorMode _colorMode);

protected:
	int		WriteDataToRegistry(CString strExeFilePath, CString strRegData);
};

