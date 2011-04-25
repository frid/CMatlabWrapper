#include <iostream>
#include <ctime>
using namespace std;

#include "MatlabWrapper.h"

#define row 2
#define col 3

void PutDoubleMatrix( CMatlabWrapper *CM );
void PutDoubleScalar( CMatlabWrapper *CM );
void PutDoubleVector( CMatlabWrapper *CM );
void PutUint8Vector ( CMatlabWrapper *CM );
void PutUint16Vector( CMatlabWrapper *CM );
void PutUint8Matrix ( CMatlabWrapper *CM );
void PutUint16Matrix( CMatlabWrapper *CM );
void EvaluateMATLABString( CMatlabWrapper *CM );

int main( void ) {

	CMatlabWrapper *CM = new CMatlabWrapper;
	bool a = CM->EngOpen();

	//Evaluate MATLAB CMD String
	EvaluateMATLABString(CM);

	//Put 1D Vector
	// -- Double
	//	PutDoubleVector(CM);
	// -- UINT8
	//	PutUint8Vector(CM);
	// -- UINT16
	//	PutUint16Vector(CM);

	//Put 2D Matrix Test 
	// -- Double
	//	PutDoubleMatrix(CM);
	// -- Uint8
	//	PutUint8Matrix(CM);
	// -- Uint16
	//	PutUint16Matrix(CM);


	//Put Scalar Test
	// -- Double
	//PutDoubleScalar(CM);

	system("PAUSE");
	CM->EngClose();
	delete(CM);



	return 0;
}

//Implement
void PutUint16Vector( CMatlabWrapper *CM ) {
	//Uint16 = unsigned short
	unsigned short Vec[3] = {1, 2, 3};
	CM->Put1DVectorUint16("VectorName", 3, &Vec[0]);
}

void PutUint8Vector ( CMatlabWrapper *CM ) {
	//Uint8 = unsigned char
	unsigned char Vec[3] = {1, 2, 3};
	CM->Put1DVectorUint8("VectorName", 3, &Vec[0]);

}

void PutDoubleVector( CMatlabWrapper *CM ) {

	double Vec[3] = {1, 2, 3};
	CM->Put1DVectorDouble("VectorName", 3, &Vec[0]);

}

void PutDoubleScalar( CMatlabWrapper *CM ) {
	double Scalar = 10.1234;

	CM->PutScalarDouble("ScalarName",Scalar);

}

void PutDoubleMatrix( CMatlabWrapper *CM )
{
	double Array[row][col] = {{1, 2, 3}, {4, 5, 6}};

	for (int i = 0 ; i < row ; i++)
	{
		for (int j = 0 ; j < col ; j++) 
			cout<<"row: "<<i<<", Col: "<<j <<"= "<<Array[i][j]<<endl;
		//cout<<endl;
	}

	CM->Put2DMatrixDouble("Array", 2, 3, &Array[0][0]);
}

void PutUint8Matrix ( CMatlabWrapper *CM )
{
	//Uint8 = unsigned char
	unsigned char Array[row][col] = {{1, 2, 3}, {4, 5, 6}};
	CM->Put2DMatrixUint8("Array", 2, 3, &Array[0][0]);
}

void PutUint16Matrix( CMatlabWrapper *CM )
{
	//Uint16 = unsigned short
	unsigned short Array[row][col] = {{1, 2, 3}, {4, 5, 6}};
	CM->Put2DMatrixUint16("Array", 2, 3, &Array[0][0]);
}

void EvaluateMATLABString( CMatlabWrapper *CM )
{
	CM->EvalString("t = 0:0.1:pi;");
	CM->EvalString("amp = sin(t);");
	CM->EvalString("plot(t, amp);");
	CM->EvalString("title('ccc')");
}