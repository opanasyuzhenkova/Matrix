/* ������������ ������ �2. ������������� �.� �����-01-20 1032202457

+ �������� ���� ������
+ ��������� ����� ������� �� ������
+ ������������ ���� ������
+ ��������� ������� �� �����
+ ������ ������� � ��������� ������� (set � get)
+ ������ ������� � ������ � ������ ������� (set � get)
+ ����� ������� (print)
+ �����������, ����������, ����������� �����������

���������� � ����������:

+ ��� ������ ������� ������ ���� ����������. 
+  ������ ������ ���������� � ������������� ����������� ������ ������.
+ ������ ���� ��������� ������������ .h ����, � ������� �������� ����� �� ����� ������������ �������� � ����������,
� ���������� ���� ������� ������ ���� � ��������� .cpp �����.
+ �������� ��������, ���������, ��������� ������ ���� ����������� ����� ���������� ����������� ���������� �+�, �-�, �*�
+ ���������� ������� ������ ���� ������������ �����.
+ ������ ���� ��������� �� ������ ���������� ������.
+ ������ ���� ��������� �������� ������ �� �����.*/

#include "matrix.h"

Matrix::Matrix() 
{
    std::cout<<"Default constructor is called\n";
    width = 0;
    height = 0;
    data = nullptr;
}

Matrix::Matrix(unsigned int w, unsigned int h) //�����������
{
    std::cout<<"Constructor is called\n";
    height = h;
    width = w;
    createMatrix();
}

Matrix::Matrix(const Matrix &other) //����������� �����������
{
    std::cout<<"Copy constructor is called\n";
    width = other.width;
    height = other.height;
    createMatrix();
    for(unsigned int i = 0; i < height; i++)
        for(unsigned int j = 0; j < width; j++)
            data[i][j] = other.data[i][j];
}

Matrix::~Matrix() //���������� 
{
    deleteMatrix();
}



void Matrix::createMatrix() //�������� �������
{
	
		data = new double* [height];
		for (unsigned int i = 0; i < height; i++)
		{
			data[i] = new double[width];
			for (unsigned int j = 0; j < width; j++)
				data[i][j] = 0;
		}
	
}

/*void Matrix::checkMatrix(std::string file_name)
{
	for (unsigned int i = 0; i < height; i++)
	
		for (unsigned int j = 0; j < width; j++)
		{
			char cur = (char(data[i][j]));
			if (cur=='?' || cur == '-' || cur == '*' 
				||cur == '/' ||( cur >= 'A' && cur <='Z')||(cur >='a'&& cur<= 'z'))
			{
				std::cout << "Oops, that input is invalid.  Please try again.\n";
				return;
			}
			else
			{
				std::cout << "Matrix is OK.\n";
				return;
			}
		}
	
	return;

}*/

void Matrix::deleteMatrix() //�������� ��������� �������
{
    for(unsigned int i=0; i < height; i++)
        delete[] data[i];
    delete[] data;
}

void Matrix::print() const //����� �������
{
    if(height != 0 && width != 0)
        for(unsigned int i=0; i < height; i++)
        {
            for(unsigned int j=0; j < width; j++)
                std::cout<<data[i][j]<<" ";
            std::cout<<std::endl;
        }
}

void Matrix::setWidth(unsigned int w) //����� ������� � ������ �������
{

		if (height != 0 && width != 0)
			deleteMatrix();
		width = w;
		if (height != 0 && width != 0)
			createMatrix();
	
}

int Matrix::getWidth() const //����� ������� � ������ �������
{
	if ((height > 0) && (width > 0))
		return width;
	else {
		std::cout << "Matrix is empty" << "\n";
		int c =0;
		return c;
	}
		
}

void Matrix::setHeight(unsigned int h) //����� ������� � ������ �������
{
	if ((h < 0) || (h == 0))
	{
		std::cout << "Error! Correct the dimension of the matrix" << "\n";
		return;
	}
	else
	{
		if (height != 0 && width != 0)
			deleteMatrix();
		height = h;
		if (height != 0 && width != 0)
			createMatrix();
	}
}

int Matrix::getHeight() const //����� ������� � ������ �������
{
	if ((height > 0) && (width > 0))
		return height;
	else
	{
		std::cout << "Matrix is empty" << "\n";
		int c = 0;
		return c;
	}
}



void Matrix::setWidthHeight(unsigned int w, unsigned int h) 
{
	if ((h <= 0) || (w<=0))
	{
		std::cout << "Error! Correct the dimension of the matrix" << "\n";
		return;
	}
	else
	{
		if (height != 0 && width != 0)
			deleteMatrix();
		width = w;
		height = h;
		if (height != 0 && width != 0)
			createMatrix();
	}
}

void Matrix::setElement(unsigned int i, unsigned int j, double value) //set-��������� � �������� ������� 
{
    data[i][j] = value;
}
 
double Matrix::getElement(unsigned int i, unsigned int j) const
{
	
	if (i >= height || j >= width)
	{
		double c = 0 ;
		return c;

	}
	else
	{
		return data[i][j];
	}
}


void Matrix::getMatrixFromFile(std::string file_name) //�������� ������� �� �����
{
    std::ifstream input;
    input.open(file_name);
    if(input.is_open())
    {
        input>>height;
        input>>width;
        createMatrix();
        for(unsigned int i=0; i < height; i++)
            for(unsigned int j=0; j < width; j++)
            {
                if(input.eof())
                {
                    std::cout<<"Error! Reached EOF!\n";
                    input.close();
                    return;
                }
                input>>data[i][j];
            }
        if(!input.eof())
            std::cout<<"Error! All data was loaded, but EOF has not been reached!\n";

    }
    else
    {
        std::cout<<"Error! File is not open!\n";
        return;
    }
    input.close();
}

Matrix Matrix::operator +(const Matrix& other) //�������� ������
{
	Matrix result(width, height);
	if (width == other.width && height == other.height)
	{

		std::cout << "Operator + is called\n";
		for (unsigned int i = 0; i < height; i++)
			for (unsigned int j = 0; j < width; j++)
				result.setElement(i, j, data[i][j] + other.data[i][j]);
		return result;
	}
	else {
		std::cout << "ERROR! Correct the dimension of the matrix\n";
		return result;
	}
}

Matrix Matrix::operator -(const Matrix& other) //��������� ������
{
	Matrix result(width, height);
	if (width == other.width && height == other.height)
	{
		std::cout << "Operator + is called\n";
		Matrix result(width, height);
		for (unsigned int i = 0; i < height; i++)
			for (unsigned int j = 0; j < width; j++)
				result.setElement(i, j, data[i][j] - other.data[i][j]);
		return result;
	}
	else
	{
		std::cout << "ERROR! Correct the dimension of the matrix\n";
		return result;
	}
}


Matrix Matrix::operator *(double value) { //��������� ������� �� �����
	Matrix result(width, height);
	for (unsigned int i = 0; i < height; i++)
		for (unsigned int j = 0; j < width; j++)
			result.setElement(i, j, data[i][j] * value);
	return result;
}

Matrix Matrix::operator *(const Matrix& other) { //������������ ������ - ���������� �������� 1 ������� = ���������� ����� 2

	Matrix result(height, other.width);
	if (width == other.height) {
		

		// ��������� �������������� �������
		// ���� �� ������� ���� ������ �������
		for (unsigned int i = 0; i < height; i++) {
			// ���� �� ������� ������� ������ �������  
			for (unsigned int j = 0; j < other.width; j++) {
				// ��������� ��������� ������������ ���� ��������  
				for (unsigned int k = 0; k < width; k++) {
					result.setElement(i, j, result.data[i][j] + data[i][k] * other.data[k][j]);
				}
			}
		}
		return result;
	}
	else
	{
		std::cout << "ERROR! Correct the dimension of the matrix\n";
		return result;
	}

}


Matrix& Matrix::operator =(const Matrix& other) //�������� ������������
{
    std::cout<<"Operator = is called\n";
    width = other.width;
    height = other.height;
    createMatrix();
    for(unsigned int i=0; i < height; i++)
        for(unsigned int j=0; j < width; j++)
            data[i][j] = other.data[i][j];
    return *this;
}
