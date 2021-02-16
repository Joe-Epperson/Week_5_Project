// Joe Epperson, IV
// jee4cf@umsystem.edu
// 2/15/2021
// CS201L Lab 05

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// declaring functions at the top for use in main
void GetVectorValues(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2);

void AddValues(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2);

void MultiplyValues(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2);

int main() {

	vector<vector<int>> firstMatrix;
	vector<vector<int>> secondMatrix;
	char usrInput = 'f';

	// while loop to ensure the program continues until the user inputs q
	while (usrInput != 'Q')
	{
		GetVectorValues(firstMatrix, secondMatrix);
		AddValues(firstMatrix, secondMatrix);
		MultiplyValues(firstMatrix, secondMatrix);
		cout << endl;
		cout << "Press Q to quit, selsect any other character to play again: " << endl;
		cin >> usrInput;
		usrInput = toupper(usrInput);
		cout << endl;
	}

	return 0;
}

void GetVectorValues(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2)
{
	int numRows1;
	int numCols1;
	int numRows2;
	int numCols2;
	int numVals1;
	int numVals2;
	int tempVal;

	// first matrix inputs
	cout << "Enter the number of rows in the first matrix: " << endl;
	cin >> numRows1;
	cout << endl;
	cout << "Enter the number of columns in the first matrix: " << endl;
	cin >> numCols1;
	cout << endl;
	numVals1 = numRows1 * numCols1;
	matrix1.resize(numRows1);
	for (int i = 0; i < matrix1.size(); ++i)
	{
		matrix1.at(i).resize(numCols1);
	}
	cout << "Please enter the values for the first matrix " << numRows1 << 'x' << numCols1 << " = " << numVals1 << " values: " << endl;
	// loop to input values for matrix 1
	for (int i = 0; i < numRows1; ++i)
	{
		for (int j = 0; j < numCols1; ++j)
		{
			cin >> tempVal;
			matrix1.at(i).at(j) = tempVal;
		}
	}
	cout << endl;
	cout << "You entered the first matrix as: " << endl;
	cout << endl;
	// loop to output values from matrix 1
	for (int i = 0; i < numRows1; ++i)
	{
		for (int j = 0; j < numCols1; ++j)
		{
			cout << matrix1.at(i).at(j) << ' ';
		}
		cout << endl;
	}
	cout << endl;

	// second matrix inputs
	cout << "Enter the number of rows in the second matrix: " << endl;
	cin >> numRows2;
	cout << endl;
	cout << "Enter the number of columns in the second matrix: " << endl;
	cin >> numCols2;
	cout << endl;
	numVals2 = numRows2 * numCols2;
	matrix2.resize(numRows2);
	for (int i = 0; i < matrix2.size(); ++i)
	{
		matrix2.at(i).resize(numCols2);
	}
	cout << "Please enter the values for the second matrix " << numRows2 << 'x' << numCols2 << " = " << numVals2 << " values: " << endl;
	// loop to input values for matrix 2
	for (int i = 0; i < numRows2; ++i)
	{
		for (int j = 0; j < numCols2; ++j)
		{
			cin >> tempVal;
			matrix2.at(i).at(j) = tempVal;
		}
	}
	cout << endl;
	cout << "You entered the second matrix as: " << endl;
	cout << endl;
	// loop to output values from matrix 2
	for (int i = 0; i < numRows2; ++i)
	{
		for (int j = 0; j < numCols2; ++j)
		{
			cout << matrix2.at(i).at(j) << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void AddValues(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2)
{
	int tempAdd;

	// if statements to determine whether or not the matrices are able to be added together
	if (matrix1.size() == matrix2.size())
	{
		if (matrix1.at(0).size() == matrix2.at(0).size())
		{
			// loops to add the matrices and output the corresponding sums
			cout << "The first matrix plus the second matrix is: " << endl;
			cout << endl;
			for (int i = 0; i < matrix1.size(); ++i)
			{
				for (int j = 0; j < matrix1.at(0).size(); ++j)
				{
					tempAdd = matrix1.at(i).at(j) + matrix2.at(i).at(j);
					cout << tempAdd << ' ';
				}
				cout << endl;
			}
			cout << endl;
		}
		else
		{
			cout << "You cannot add these because they are not the same number of rows and columns." << endl;
			cout << endl;
		}
	}
	else
	{
		cout << "You cannot add these because they are not the same number of rows and columns." << endl;
		cout << endl;
	}
}

void MultiplyValues(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2)
{
	int multVal = 0;
	// if statement to determine whether or not the matrices are able to be multiplied together
	if (matrix1.at(0).size() == matrix2.size())
	{
		// loop to multiply the matrices and output the multiplied values
		cout << "The first matrix multiplied by the second matrix is: " << endl;
		cout << endl;
		for (int j = 0; j < matrix1.size(); ++j)
		{
			for (int i = 0; i < matrix2.at(0).size(); ++i)
			{
				multVal = 0;
				for (int z = 0; z < matrix1.at(0).size(); ++z)
				{
					multVal += (matrix1.at(j).at(z) * matrix2.at(z).at(i));
				}
				cout << multVal << ' ';
			}
			cout << endl;
		}
	}
	else
	{
		cout << "You cannot multiply these because the columns in the first matrix does not equal the rows in the second matrix. " << endl;
		cout << endl;
	}
}