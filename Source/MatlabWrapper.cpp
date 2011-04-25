#include "MatlabWrapper.h"


CMatlabWrapper::CMatlabWrapper(void)
{
}


CMatlabWrapper::~CMatlabWrapper(void)
{
}

//Open Matlab Engine 
bool CMatlabWrapper::EngOpen( void ) {
	ep = engOpen("\0");
	if (!ep) {
		return 1;
	} else {
		return 0;
	}
}

//Close Matlab Engine
void CMatlabWrapper::EngClose( void ) {
	if (ep)
		engClose(ep);
}


bool CMatlabWrapper::EvalString( const char *Cmd )
{
	bool RetVal = static_cast<bool>(engEvalString(ep,Cmd));

	return RetVal;
}

bool CMatlabWrapper::SetVisiable( bool Cmd )
{
	bool RetVal = static_cast<bool>(engSetVisible(ep,Cmd));

	return RetVal;
}

bool CMatlabWrapper::Put1DVectorDouble( const char* name, int Dim1Size, double *pArray )
{
	mxArray *pMatArray = mxCreateDoubleMatrix(1, Dim1Size, mxREAL);

	memcpy((void *)mxGetPr(pMatArray), (void *)pArray, Dim1Size*sizeof(double));

	bool RetVal = static_cast<bool>(engPutVariable(ep, name, pMatArray));

	return RetVal;
}

bool CMatlabWrapper::Put2DMatrixDouble( const char* name, int Dim1Size, int Dim2Size, double *pArray )
{
	mxArray *pMatArray = mxCreateDoubleMatrix(Dim2Size, Dim1Size, mxREAL);

	memcpy((void *)mxGetPr(pMatArray), (void *)pArray, Dim2Size*Dim1Size*sizeof(double));
	bool RetVal = static_cast<bool>(engPutVariable(ep, name, pMatArray));

	return RetVal;
}

bool CMatlabWrapper::Put2DMatrixUint8( const char* name, int Dim1Size, int Dim2Size, UINT8 *pArray )
{
	const int NDim = 2;
	const mwSize dims[2]={Dim2Size, Dim1Size};

	mxArray *pMatArray = mxCreateNumericArray(NDim, dims, mxUINT8_CLASS, mxREAL);

	size_t ByteToCopy = Dim2Size * Dim1Size * sizeof(UINT8);
	memcpy((void *)mxGetPr(pMatArray), (void *)pArray, ByteToCopy);

	bool RetVal = static_cast<bool>(engPutVariable(ep, name, pMatArray));

	return RetVal;	
}

bool CMatlabWrapper::Put2DMatrixUint16( const char* name, int Dim1Size, int Dim2Size, UINT16 *pArray )
{
	const int NDim = 2;
	const mwSize dims[2]={Dim2Size, Dim1Size};

	mxArray *pMatArray = mxCreateNumericArray(NDim, dims, mxUINT16_CLASS, mxREAL);

	size_t ByteToCopy = Dim2Size * Dim1Size * sizeof(UINT16);
	memcpy((void *)mxGetPr(pMatArray), (void *)pArray, ByteToCopy);

	bool RetVal = static_cast<bool>(engPutVariable(ep, name, pMatArray));

	return RetVal;	
}

bool CMatlabWrapper::PutScalarDouble( const char* name, double Scalar )
{
	mxArray *pMatScalar = mxCreateDoubleScalar(Scalar);

	bool RetVal = static_cast<bool>(engPutVariable(ep, name, pMatScalar));

	return RetVal;
}


bool CMatlabWrapper::Put1DVectorUint8( const char* name, int Dim1Size, UINT8 *pArray )
{
	const int NDim = 2;
	const mwSize dims[2]={1, Dim1Size};

	mxArray *pMatArray = mxCreateNumericArray(NDim, dims, mxUINT8_CLASS, mxREAL);

	size_t ByteToCopy = Dim1Size * sizeof(UINT8);
	memcpy((void *)mxGetPr(pMatArray), (void *)pArray, ByteToCopy);

	bool RetVal = static_cast<bool>(engPutVariable(ep, name, pMatArray));

	return RetVal;

}

bool CMatlabWrapper::Put1DVectorUint16( const char* name, int Dim1Size, UINT16 *pArray )
{
	const int NDim = 2;
	const mwSize dims[2]={1, Dim1Size};

	mxArray *pMatArray = mxCreateNumericArray(NDim, dims, mxUINT16_CLASS, mxREAL);

	size_t ByteToCopy = Dim1Size * sizeof(UINT16);
	memcpy((void *)mxGetPr(pMatArray), (void *)pArray, ByteToCopy);

	bool RetVal = static_cast<bool>(engPutVariable(ep, name, pMatArray));

	return RetVal;
	
}


