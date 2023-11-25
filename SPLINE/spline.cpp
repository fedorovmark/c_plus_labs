<<<<<<< HEAD
#include <vector>
#include <type_traits>
#include <ostream>
#include <iostream>
/** класс для работы с трехдиагональной матрицей **/
template<typename Type, typename xType>
class ThreeDiagonalMatrix {
private:
	std::vector<std::vector<Type>> matrix;
public:
	ThreeDiagonalMatrix(std::vector<xType> &points) {
		std::vector<Type> h(points.size());
		for (auto i = 1;  i <= points.size() - 1; i++) {
			h[i] = points[i] - points[i-1];
		}
		std::vector<std::vector<Type>> matrix(points.size() - 2, std::vector<Type>(points.size() - 2, 0));
		matrix[0][0] = 2;
		matrix[0][1] = h[2] / (h[1] + h[2]);
		for (auto i = 1; i <= points.size() - 4; i++) {
			matrix[i][i-1] = h[i+1] / (h[i+1] + h[i+2]);
			matrix[i][i] = 2;
			matrix[i][i+1] = h[i+2] / (h[i+1] + h[i+2]);
		}
		matrix[points.size() - 3][points.size() - 4] = h[points.size()-2] / (h[points.size()-2] + h[points.size()-1]);
		matrix[points.size() - 3][points.size() - 3] = 2;

		this->matrix = matrix;
	}

	std::vector<std::vector<Type>> get_matrix() {
		return matrix;
	}
	
};

template<typename Type, typename xType>
std::ostream& operator<<(std::ostream& s, ThreeDiagonalMatrix<Type, xType>& tdm)//реализация метода вывода
{	
	std::vector<std::vector<Type>> matrix;
	matrix = tdm.get_matrix();
	for (int i=0; i<matrix.size(); i++){
		for (int j=0; j<matrix.size(); j++){
			s<<matrix[i][j]<<"           ";
		}
		s<< " " <<std::endl;
	}
	return s;
}


int main() {
    std::vector<double> points = {1, 3, 6, 11, 19, 20};
    ThreeDiagonalMatrix<double, double> tdm(points);
    std::cout << tdm;
}
=======
#include <vector>
#include <type_traits>
#include <ostream>
<<<<<<< HEAD
#include <iostream>
=======
>>>>>>> main
/** класс для работы с трехдиагональной матрицей **/
template<typename Type, typename xType>
class ThreeDiagonalMatrix {
private:
	std::vector<std::vector<Type>> matrix;
public:
	ThreeDiagonalMatrix(std::vector<xType> &points) {
<<<<<<< HEAD
		std::vector<Type> h(points.size());
		for (auto i = 1;  i <= points.size() - 1; i++) {
			h[i] = points[i] - points[i-1];
		}
		std::vector<std::vector<Type>> matrix(points.size() - 2, std::vector<Type>(points.size() - 2, 0));
		matrix[0][0] = 2;
		matrix[0][1] = h[2] / (h[1] + h[2]);
		for (auto i = 1; i <= points.size() - 4; i++) {
=======
		
		std::vector<std::vector<Type>> matrix(points.size(), std::vector<Type>(points.size(), 0));
		matrix[0][0] = 2;
		matrix[0][1] = h[2] / (h[1] + h[2])
		for (auto i = 1; i <= points.size() - 2; i++) {
>>>>>>> main
			matrix[i][i-1] = h[i+1] / (h[i+1] + h[i+2]);
			matrix[i][i] = 2;
			matrix[i][i+1] = h[i+2] / (h[i+1] + h[i+2]);
		}
<<<<<<< HEAD
		matrix[points.size() - 3][points.size() - 4] = h[points.size()-2] / (h[points.size()-2] + h[points.size()-1]);
		matrix[points.size() - 3][points.size() - 3] = 2;
=======
		matrix[points.size() - 1][points.size() - 2] = h[points.size()] / (h[points.size()] + h[points.size() + 1]);
		matrix[points.size() - 1][points.size() - 1] = 2;
>>>>>>> main

		this->matrix = matrix;
	}

	std::vector<std::vector<Type>> get_matrix() {
		return matrix;
	}
	
};

<<<<<<< HEAD
template<typename Type, typename xType>
std::ostream& operator<<(std::ostream& s, ThreeDiagonalMatrix<Type, xType>& tdm)//реализация метода вывода
=======
template<typename Type>
std::ostream& operator<<(std:: ostream& s, const ThreeDiagonalMatrix<Type> tdm)//реализация метода вывода
>>>>>>> main
{	
	std::vector<std::vector<Type>> matrix;
	matrix = tdm.get_matrix();
	for (int i=0; i<matrix.size(); i++){
		for (int j=0; j<matrix.size(); j++){
<<<<<<< HEAD
			s<<matrix[i][j]<<"           ";
=======
			s<<tdm[i][j]<<" ";
>>>>>>> main
		}
		s<< " " <<std::endl;
	}
	return s;
}
<<<<<<< HEAD


int main() {
    std::vector<double> points = {1, 3, 6, 11, 19, 20};
    ThreeDiagonalMatrix<double, double> tdm(points);
    std::cout << tdm;
}
=======

template<typename numeratorType, typename denominatorType>
using DivisType = decltype(std::declval<numeratorType>() / std::declval<denominatorType>());

/** Функция для решения методм  прогонки **/
template<typename mType, typename cType>
std::vector<DivisType<cType, mType>> solve( const ThreeDiagonalMatrix<mType>& matrix,
                                            const std::vector<cType>& column);


/**
* xType - тип аргумента x.
* yType - тип значения функции y
*/
template<typename xType, typename yType>
class CubicSpline {
    /*** Какие-то поля ***/

    public:
    CubicSpline( const std::vector<xType> &points,  // Значения x
                        const std::vector<yType>& values,  // значения y
                        );

    yType interpolate(const xType& x) const noexcept;
i};
>>>>>>> main
>>>>>>> mr
