#pragma once
#include <cmath>
#define A _matrix_values

/** A 4-dimensional homogenous vector*/
class Vector4D
{
public:
	Vector4D(); //default construct
	Vector4D(float x, float y, float z, float w); //custom construct

	Vector4D(Vector4D& o);	// copy construct
	

	
	/**
	* Performs a dotproduction of two vectors
	* @param vect4 : the 2nd vector used in the dotproduct
	* @return Returns a Scalar 
	*/
	float DotProduct(const Vector4D& vect4);

	/**
	* Performs crossproduct with another vector
	* @param vect4 : the 2nd vector used in the crossproduct
	* @return Returns a new vector 
	*/
	Vector4D CrossProduct(const Vector4D& vect4);

	/**
	* Calculates the lenght of a vector
	* @return Returns the lenght of the vector
	*/
	float LenghtOf();
	 
	/**
	* Normalizes the vector
	* @return Returns a new normalized vector
	*/
	Vector4D Normalize();


	//-----overloading operators-----

	/**
	* Allows Addition between two vectors
	*/
	Vector4D operator+(const Vector4D& other);

	/**
	* Allows Subtraction between two vectors
	*/
	Vector4D operator-(const Vector4D& other);

	/**
	* Allows multiplication with a vector and a number, Scalar
	*/
	Vector4D operator*(const float& other);

	/**
	* Allows assigning a vector with another vector
	*/
	Vector4D& operator=(const Vector4D& other);

	/**
	* Compares a vector with another vector. Checks if the two vectors are the same.
	* @return True or False 
	*/
	bool operator==(const Vector4D& other);

	/**
	* Compares a vector with another vector. Checks if the two vectors are not the same.
	* @return True or False
	*/
	bool operator!=(const Vector4D& other);

	/**
	* Allows access to the vectors private data. Reading the data
	*/
	const float& operator[] (int index) const;

	/**
	* Allows access to the vectors private data. Writing data to the array of data
	*/
	float& operator[] (int index);



private:
	float _vect_values[4];
};

// default construct
Vector4D::Vector4D()
{
	_vect_values[0] = 0;
	_vect_values[1] = 0;
	_vect_values[2] = 0;
	_vect_values[3] = 1;
}
//customconstruct
Vector4D::Vector4D(float x, float y, float z, float w)
{
	this->_vect_values[0] = x;
	this->_vect_values[1] = y;
	this->_vect_values[2] = z;
	this->_vect_values[3] = w;
}
// copy construct
Vector4D::Vector4D(Vector4D& o)
{
	this->_vect_values[0] = o._vect_values[0];
	this->_vect_values[1] = o._vect_values[1];
	this->_vect_values[2] = o._vect_values[2];
	this->_vect_values[3] = o._vect_values[3];
}

Vector4D Vector4D::operator+(const Vector4D& other)
{
	Vector4D new_vect;
	new_vect._vect_values[0] = this->_vect_values[0] + other._vect_values[0];
	new_vect._vect_values[1] = this->_vect_values[1] + other._vect_values[1];
	new_vect._vect_values[2] = this->_vect_values[2] + other._vect_values[2];

	return new_vect;
}

Vector4D Vector4D::operator-(const Vector4D& other)
{
	Vector4D new_vect;
	new_vect._vect_values[0] = this->_vect_values[0] - other._vect_values[0];
	new_vect._vect_values[1] = this->_vect_values[1] - other._vect_values[1];
	new_vect._vect_values[2] = this->_vect_values[2] - other._vect_values[2];

	return new_vect;
}

Vector4D Vector4D::operator*(const float& other)
{
	Vector4D new_vect;
	new_vect._vect_values[0] = this->_vect_values[0] * (other);
	new_vect._vect_values[1] = this->_vect_values[1] * (other);
	new_vect._vect_values[2] = this->_vect_values[2] * (other);

	return new_vect;
}

Vector4D& Vector4D::operator=(const Vector4D& other)
{
	_vect_values[0] = other._vect_values[0];
	_vect_values[1] = other._vect_values[1];
	_vect_values[2] = other._vect_values[2];

	return *this;
}

bool Vector4D::operator==(const Vector4D& v)
{
	return (this->_vect_values[0] == v._vect_values[0] &&
		this->_vect_values[1] == v._vect_values[1]) &&
		this->_vect_values[2] == v._vect_values[2];
}

bool Vector4D::operator!=(const Vector4D& v)
{
	return (this->_vect_values[0] != v._vect_values[0] &&
		this->_vect_values[1] != v._vect_values[1] &&
		this->_vect_values[2] != v._vect_values[2]);
}

const float& Vector4D::operator[] (int index) const
{
	if (index <= 3 && index >= 0)
	{
		return this->_vect_values[index];
	}
	else
	{
		throw "INDEX OUT OF BOUNDS";
	}
}

float& Vector4D::operator[] (int index)
{
	if (index <= 3 && index >= 0)
	{
		return this->_vect_values[index];
	}
	else
	{
		throw "INDEX OUT OF BOUNDS";
	}
}

float Vector4D::DotProduct(const Vector4D& vect2)
{
	float result =
		this->_vect_values[0] * vect2._vect_values[0] +
		this->_vect_values[1] * vect2._vect_values[1] +
		this->_vect_values[2] * vect2._vect_values[2];

	return result;
}

Vector4D Vector4D::CrossProduct(const Vector4D& vect2)
{
	Vector4D result;
	result._vect_values[0] = (this->_vect_values[1] * vect2._vect_values[2]) - (this->_vect_values[2] * vect2._vect_values[1]);
	result._vect_values[1] = -((this->_vect_values[0] * vect2._vect_values[2]) - (this->_vect_values[2] * vect2._vect_values[0]));
	result._vect_values[2] = (this->_vect_values[0] * vect2._vect_values[1]) - (this->_vect_values[1] * vect2._vect_values[0]);


	return result;
}

float Vector4D::LenghtOf()
{
	float lenght = sqrt(pow(this->_vect_values[0], 2) + pow(this->_vect_values[1], 2) + pow(this->_vect_values[2], 2)); // square root of (x^2 + y^2)
	return lenght;
}

Vector4D Vector4D::Normalize()
{
	Vector4D new_vect;
	new_vect._vect_values[0] = this->_vect_values[0] / this->LenghtOf();
	new_vect._vect_values[1] = this->_vect_values[1] / this->LenghtOf();
	new_vect._vect_values[2] = this->_vect_values[2] / this->LenghtOf();

	return new_vect;
}




/** A 4-dimensional homogenous matrix*/
class Matrix4D
{
public:
	Matrix4D();
	
	Matrix4D(float x1, float x2, float x3, float x4,
			float y1, float y2, float y3, float y4,
			float z1, float z2, float z3, float z4,
			float w1, float w2, float w3, float w4);
	/** 4x4 matrix multiplication with a 4x4 matrix
	* @return a new matrix
	*/
	Matrix4D operator*(const Matrix4D& other);

	/** 4x4 matrix multiplication with a 4D vector 
	* @return a new vector
	*/
	Vector4D operator*(const Vector4D& other);

	/** allows access to the matrixs private data, reading */
	float& operator[] (int index);

	/** allows access to the matrixs private data, writing */
	const float& operator[] (int index) const;



private:
	float _matrix_values[16]; /*[ x1 y1 z1 w1 ]
								[ x2 y2 z2 w2 ]
								[ x3 y3 z3 w3 ]
								[ x4 y4 z4 w4 ] 
												*/
};

Matrix4D::Matrix4D()
{
	this->_matrix_values[0] = 1;
	this->_matrix_values[1] = 0;
	this->_matrix_values[2] = 0;
	this->_matrix_values[3] = 0;

	this->_matrix_values[4] = 0;
	this->_matrix_values[5] = 1;
	this->_matrix_values[6] = 0;
	this->_matrix_values[7] = 0;

	this->_matrix_values[8] = 0;
	this->_matrix_values[9] = 0;
	this->_matrix_values[10] = 1;
	this->_matrix_values[11] = 0;

	this->_matrix_values[12] = 0;
	this->_matrix_values[13] = 0;
	this->_matrix_values[14] = 0;
	this->_matrix_values[15] = 1;
}

Matrix4D::Matrix4D(float x1, float x2, float x3, float x4,
					float y1, float y2, float y3, float y4,
					float z1, float z2, float z3, float z4,
					float w1, float w2, float w3, float w4)
{
	_matrix_values[0] = x1;
	_matrix_values[4] = x2;
	_matrix_values[8] = x3;
	_matrix_values[12] = x4;

	_matrix_values[1] = y1;
	_matrix_values[5] = y2;
	_matrix_values[9] = y3;
	_matrix_values[13] = y4;

	_matrix_values[2] = z1;
	_matrix_values[6] = z2;
	_matrix_values[10] = z3;
	_matrix_values[14] = z4;

	_matrix_values[3] = w1;
	_matrix_values[7] = w2;
	_matrix_values[11] = w3;
	_matrix_values[15] = w4;


}

Vector4D Matrix4D::operator*(const Vector4D& other)
{
	Vector4D new_vect;
	new_vect[0] = this->A[0] * other[0] + this->A[1] * other[1] + this->A[2] * other[2] + this->A[3] * other[3]; 
	new_vect[1] = this->A[4] * other[0] + this->A[5] * other[1] + this->A[6] * other[2] + this->A[7] * other[3];
	new_vect[2] = this->A[8] * other[0] + this->A[9] * other[1] + this->A[10] * other[2] + this->A[11] * other[3];
	new_vect[3] = this->A[12] * other[0] + this->A[13] * other[1] + this->A[14] * other[2] + this->A[15] * other[3];

	return new_vect;
}

Matrix4D Matrix4D::operator*(const Matrix4D& other)
{
	Matrix4D new_mat;
	new_mat.A[0] = this->A[0] * other.A[0] + this->A[1] * other.A[4] + this->A[2] * other.A[8] + this->A[3] * other.A[12];
	new_mat.A[1] = this->A[0] * other.A[1] + this->A[1] * other.A[5] + this->A[2] * other.A[9] + this->A[3] * other.A[13];
	new_mat.A[2] = this->A[0] * other.A[2] + this->A[1] * other.A[6] + this->A[2] * other.A[10] + this->A[3] * other.A[14];
	new_mat.A[3] = this->A[0] * other.A[3] + this->A[1] * other.A[7] + this->A[2] * other.A[11] + this->A[3] * other.A[15];

	new_mat.A[4] = this->A[4] * other.A[0] + this->A[5] * other.A[4] + this->A[6] * other.A[8] + this->A[7] * other.A[12];
	new_mat.A[5] = this->A[4] * other.A[1] + this->A[5] * other.A[5] + this->A[6] * other.A[9] + this->A[7] * other.A[13];
	new_mat.A[6] = this->A[4] * other.A[2] + this->A[5] * other.A[6] + this->A[6] * other.A[10] + this->A[7] * other.A[14];
	new_mat.A[7] = this->A[4] * other.A[3] + this->A[5] * other.A[7] + this->A[6] * other.A[11] + this->A[7] * other.A[15];

	new_mat.A[8] = this->A[8] * other.A[0] + this->A[9] * other.A[4] + this->A[10] * other.A[8] + this->A[11] * other.A[12];
	new_mat.A[9] = this->A[8] * other.A[1] + this->A[9] * other.A[5] + this->A[10] * other.A[9] + this->A[11] * other.A[13];
	new_mat.A[10] = this->A[8] * other.A[2] + this->A[9] * other.A[6] + this->A[10] * other.A[10] + this->A[11] * other.A[14];
	new_mat.A[11] = this->A[8] * other.A[3] + this->A[9] * other.A[7] + this->A[10] * other.A[11] + this->A[11] * other.A[15];

	new_mat.A[12] = this->A[12] * other.A[0] + this->A[13] * other.A[4] + this->A[14] * other.A[8] + this->A[15] * other.A[12];
	new_mat.A[13] = this->A[12] * other.A[1] + this->A[13] * other.A[5] + this->A[14] * other.A[9] + this->A[15] * other.A[13];
	new_mat.A[14] = this->A[12] * other.A[2] + this->A[13] * other.A[6] + this->A[14] * other.A[10] + this->A[15] * other.A[14];
	new_mat.A[15] = this->A[12] * other.A[3] + this->A[13] * other.A[7] + this->A[14] * other.A[11] + this->A[15] * other.A[15];

	return new_mat;
}

float& Matrix4D::operator[] (int index)
{
	if (index <= 15 && index >= 0)
	{
		return this->_matrix_values[index];
	}
	else
	{
		throw "INDEX OUT OF BOUNDS";
	}
}

const float& Matrix4D::operator[] (int index) const
{
	if (index <= 15 && index >= 0)
	{
		return this->_matrix_values[index];
	}
	else
	{
		throw "INDEX OUT OF BOUNDS";
	}
}

#undef A