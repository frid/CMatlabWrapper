#pragma once

//Setup Step
// 1.	add include path ex: C:\Program Files\MATLAB\R2010a\extern\include 
//		path can be generated from MATLAB commend:
//			>> fullfile(matlabroot, 'extern', 'include')
// 2.	add dynamic link library(*.dll) folder path ex: C:\Program Files\MATLAB\R2010a\bin\win32
//		path can be found by following MATLAB commend:
//			>> fullfile(matlabroot,'bin',computer('arch'))
// 3.	add library file(*.lib) folder path ex: C:\Program Files\MATLAB\R2010a\extern\lib\win32\microsoft
//		path can be generate by following MATLAB commend(for VC++):
//			>> fullfile(matlabroot,'extern','lib',computer('arch'), 'microsoft')
// 4.	add following external library name in the project configuration:
//			libeng.lib, libmx.lib, libmat.lib
// 5.	If want to use exist MATLAB session, do following procedure
//
//		(1)	Shut down any MATLAB sessions.
//		(2)	From the Start button on the Windows menu bar, click Run.
//		(3) In the Open field, type:
//				d:\matlab\bin\win32\matlab.exe /Automation
//  		or:
//				d:\matlab\bin\win64\matlab.exe /Automation
//			where d:\matlab\bin\win32 or d:\matlab\bin\win64 represents the path to the MATLAB executable.
//		(4) Click OK. This starts MATLAB.
//		(5) In MATLAB, change directories to matlabroot/extern/examples/eng_mat.
//		(6)	Compile the engwindemo.c example.
//		(7)	Run the engwindemo program by typing at the MATLAB prompt:
//				!engwindemo
//			This does not start another MATLAB session, but rather uses the MATLAB session that is already open.

#include <string>
using namespace std;

#include <engine.h>

typedef unsigned char  UINT8;
typedef unsigned short UINT16;
typedef unsigned int   UINT32;



class CMatlabWrapper
{
public:
	CMatlabWrapper(void);
	~CMatlabWrapper(void);

public: //Engine control
	//Open MATLAB 
	bool EngOpen( void );

	//Close MATLAB
	void EngClose( void );

	//Evaluate MATLAB cmd string
	bool EvalString(const char *Cmd);

	// Set MATLAB visibility(0: visible, 1: invisible) 
	bool SetVisiable(bool Cmd);

	// Put 1D Vector
	// At C++    : Array[dim1]
	// At MATLAB : Array[1][dim1]
	//  兩個之間是transpose 的關係 (不過幫你轉了)
	bool Put1DVectorDouble (const char* name, int Dim1Size, double *pArray);
	bool Put1DVectorUint8  (const char* name, int Dim1Size, UINT8  *pArray);
	bool Put1DVectorUint16 (const char* name, int Dim1Size, UINT16 *pArray);

	// Put 2D Matrix 
	// At C++    : Array[row][col], row: Dim1Size, col:Dim2Size
	// At MATLAB : Array[row][col], row: Dim1Size, col:Dim2Size
	// 兩個之間是transpose 的關係(進Matlab 記得轉一次)
	//             -----> Colume
	//        .-----------------------.
	//    |   | (1,1) | (1,2) | (1,3) |
	//    |   | (2,1) | (2,2) | (2,3) |
	//    v   | (3,1) | (3,2) | (3,3) |
	//   row  .-----------------------.
	//
	bool Put2DMatrixDouble(const char* name, int Dim1Size, int Dim2Size, double *pArray);
	bool Put2DMatrixUint8 (const char* name, int Dim1Size, int Dim2Size, UINT8  *pArray);
	bool Put2DMatrixUint16(const char* name, int Dim1Size, int Dim2Size, UINT16 *pArray);

	bool PutScalarDouble(const char* name, double Scalar);

private:
	Engine * ep;
};

