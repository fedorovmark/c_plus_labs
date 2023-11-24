#include <vector>
#include <type_traits>

/** класс для работы с трехдиагональной матрицей **/
template<typename Type>
class ThreeDiagonalMatrix {
    /*** Здесь какие-то поля и методы ***/
};

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
};
