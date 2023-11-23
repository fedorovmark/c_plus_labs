#include <array>
#include <type_traits>
#include <cmath>
#include <iostream>

template <typename RealType, unsigned int N> 
struct nodes;

template <typename RealType> 
struct nodes<RealType, 1> {
    static constexpr std::array<RealType, 1> p{0.0};
    static constexpr std::array<RealType, 1> w{2.0};
};

template <typename RealType> 
struct nodes<RealType, 2> {
    static constexpr std::array<RealType, 2> p{-0.5773502692, 0.5773502692};
    static constexpr std::array<RealType, 2> w{1.0, 1.0};
};

template <typename RealType> 
struct nodes<RealType, 3> {
    std::array<RealType, 3> p{-0.7745966692, 0, 0.7745966692};
    std::array<RealType, 3> w{0.5555555556, 0.8888888889, 0.5555555556};
};

template <typename RealType> 
struct nodes<RealType, 4> {
    std::array<RealType, 4> p{-0.8611363116, -0.3399810436, 0.3399810436, 0.8611363116};
    std::array<RealType, 4> w{0.3478548451,0.6521451549, 0.6521451549, 0.3478548451};
};

template <typename RealType> 
struct nodes<RealType, 5> {
    std::array<RealType, 5> p{-0.9061798459, -0.5384693101, 0.0, 0.5384693101, 0.9061798459};
    std::array<RealType, 5> w{0.2369268851, 0.4786286705, 0.5688888889, 0.4786286705, 0.2369268851};
};

template<typename A>
struct ArgumentGetter;

template<typename R, typename Arg>
struct ArgumentGetter<R(Arg)> {
    using Argument = Arg;
};

template<typename T>
using Dif = decltype(std::declval<T>() - std::declval<T>());


/* Функция производит интегрирование на одном отрезке */
template<typename Callable, typename RealType, std::size_t N> //работает не везде, приходится использовать unsigned int вместо std::size_t 
decltype(auto) integrate(   
    const Callable& func,  // Интегрируемая функция
    const typename ArgumentGetter<Callable>::Argument& start,  
    const typename ArgumentGetter<Callable>::Argument& end,
    const nodes<RealType, N>& node
                        ) {
                            Dif<RealType> polusum = (end + start) / 2;
                            Dif<RealType> poluraz = (end - start) / 2;
                            RealType gauss_sum = 0.;

                            for (auto i = 0; i < N; i++) {
                                gauss_sum += poluraz * func(polusum + poluraz * node.p[i]) * node.w[i];
                            }

                            return gauss_sum;
                        };



/* Функция производит интегрирование, разбивая отрезок на подотрезки длиной не более dx */
template<typename Callable, typename RealType, std::size_t N>
decltype(auto) integrate(   
    const Callable& func,  // Интегрируемая функция
    const typename ArgumentGetter<Callable>::Argument& start,  // начало отрезка
    const typename ArgumentGetter<Callable>::Argument& end,  // конец отрезка 
    const Dif<typename ArgumentGetter<Callable>::Argument>& dx,  // Длина подотрезка
    const nodes<RealType, N>& node
                        ) {
                            int counter;
                            counter = (end - start) / dx;

                            RealType res = 0.;
                            for (auto i = 0; i < counter; i++) {
                                RealType start2, end2;
                                start2 = start + i * dx;
                                end2 = start2 + dx;
                                res += integrate(func, start2, end2, node);
                            }

                            res += integrate(func, start + counter * dx, end, node);

                            return res;
                        }

double func(double x) {
    return std::sin(x);
}

int main() {
    double res;
    double st = 0.;
    double end[20] = {1, 2,3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    nodes<double, 5> node;
    for (auto i = 0; i < 20; i++) {
        res = integrate(func, st, end[i], 1, node);
        std::cout << end[i]<< "----------" << res << std::endl;
    }
}
