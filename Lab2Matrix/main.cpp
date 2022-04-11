#include "matrix.h"
using namespace std;



/* 2 матрицы - результат конкатенация*/


Matrix Conc(Matrix matr1, Matrix matr2) { //проверка на высоту 1=2

	Matrix result(matr1.getWidth() + matr2.getWidth(), matr1.getHeight());
	if (matr1.getHeight() == matr2.getHeight()) {
		for (int i = 0;  i < matr1.getHeight(); i++) {
			for (int j = 0; j < matr1.getWidth() + matr2.getWidth(); j++) {
				if(j <matr1.getWidth())
				{
					result.setElement(i, j, matr1.getElement(i, j));

				}
				else 
				{    
					result.setElement(i, j, matr2.getElement(i, j-matr1.getWidth()));
				}
				

			}
		}
	}
	else {
		std::cout << "ERROR! ";
		
	}
	return result;

}



int main()
{
    Matrix matrixA;
    matrixA.getMatrixFromFile("input.txt");
	std::cout << "Matrix A: \n"; //проверка вывода матрицы А
	matrixA.print();
	std::cout << "_________\n";

	std::cout << "Width of matrix A: "; //получаем ширину матрицы
	matrixA.getWidth();
	
	std::cout << "Height of matrix A: "; //получаем высоту матрицы
	matrixA.getHeight();

	std::cout << "Get [0][0] element: "; //получаем 1 элемент матрицы
	std::cout << matrixA.getElement(0, 0) << std::endl;;
	std::cout << "_________\n";

	Matrix matrixB;
	matrixB.getMatrixFromFile("input2.txt"); //выводим 2 матрицу
	std::cout << "Matrix B: \n";
	matrixB.print();
	std::cout << "_________\n";

	Matrix matrixC; //только одного размера сложение матриц
	matrixC = matrixA + matrixB;
	std::cout << "Matrix A+B: \n";
	matrixC.print();
	std::cout << "_________\n";

	Matrix matrixD;
	matrixD = matrixA - matrixB; //вычитаем матриц только одного размера
	std::cout << "Matrix A-B: \n";
	matrixD.print();
	std::cout << "_________\n";

	Matrix matrixE; //умножаем на число
	matrixE = matrixA * 2;
	std::cout << "Matrix A*2: \n";
	matrixE.print();
	std::cout << "_________\n";

	Matrix matrixF; //количество столбцов 1 матрицы = количеству строк 2
	matrixF = matrixA * matrixB;
	std::cout << "Matrix A* Matrix B: \n";
	matrixF.print();
	std::cout << "_________\n"; 


	
	/*
	std::cout << "Width of matrix A: ";
	matrixA.getWidth("input.txt");

	std::cout << "Height of matrix A: ";
	matrixA.getHeight("input.txt");

	std::cout << "Get [1][1] element: ";
	matrixA.getElement("input.txt", 1, 1);
	std::cout << "_________\n";

	Matrix matrixB;
	matrixB.getMatrixFromFile("input2.txt");
	std::cout << "Matrix B: \n";
	matrixB.print();
	std::cout << "_________\n";

   /* Matrix matrixC; //только одного размера
    matrixC = matrixA + matrixB;
	std::cout << "Matrix A+B: \n";
    matrixC.print();
	std::cout << "_________\n";

	Matrix matrixD; 
	matrixD = matrixA - matrixB;
	std::cout << "Matrix A-B: \n";
	matrixD.print();
	std::cout << "_________\n";


	Matrix matrixE;
	matrixE = matrixA * 2;
	std::cout << "Matrix A*2: \n";
	matrixE.print();
	std::cout << "_________\n";


	Matrix matrixF; //количество столбцов 1 матрицы = количеству строк 2
	matrixF = matrixA * matrixB;
	std::cout << "Matrix A* Matrix B: \n";
	matrixF.print();
	std::cout << "_________\n";*/
	Matrix matrixP;
	matrixP = Conc(matrixA, matrixB);
	matrixP.print();
    return 0;
}
