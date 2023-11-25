#include <vector>
#include <type_traits>
#include <ostream>
/** класс для работы с трехдиагональной матрицей **/
template<typename Type>
class ThreeDiagonalMatrix {
private:
	std::vector<std::vector<Type>> matrix;
public:
	ThreeDiagonalMatrix(std::vector<xType> &points) {
		std::vector<std::vector<Type>> matrix(points.size(), std::vector<Type>(points.size(), 0));
		matrix[0][0] = 2;
		matrix[0][1] = h[2] / (h[1] + h[2])
		for (auto i = 1; i <= points.size() - 2; i++) {
			matrix[i][i-1] = h[i+1] / (h[i+1] + h[i+2]);
			matrix[i][i] = 2;
			matrix[i][i+1] = h[i+2] / (h[i+1] + h[i+2]);
		}
		matrix[points.size() - 1][points.size() - 2] = h[points.size()] / (h[points.size()] + h[points.size() + 1]);
		matrix[points.size() - 1][points.size() - 1] = 2;

		this->matrix = matrix;
	}

	std::vector<std::vector<Type>> get_matrix() {
		return matrix;
	}
	
};

template<typename Type>
std::ostream& operator << (std::ostream &os, const ThreeDiagonalMatrix<Type> &threediagonalmatrix)
{
    return os << ;
}

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
