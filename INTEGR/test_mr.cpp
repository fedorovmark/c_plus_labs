#include <array>
#include <type_traits>

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
    static constexpr std::array<RealType, 3> p{-0.7745966692, 0, 0.7745966692};
    static constexpr std::array<RealType, 3> w{0.5555555556, 0.8888888889, 0.5555555556};
};

template <typename RealType> 
struct nodes<RealType, 4> {
    static constexpr std::array<RealType, 4> p{-0.8611363116, -0.3399810436, 0.3399810436, 0.8611363116};
    static constexpr std::array<RealType, 4> w{0.3478548451,0.6521451549, 0.6521451549, 0.3478548451};
};

template <typename RealType> 
struct nodes<RealType, 5> {
    static constexpr std::array<RealType, 5> p{-0.9061798459, -0.5384693101, 0.0, 0.5384693101, 0.9061798459};
    static constexpr std::array<RealType, 5> w{0.2369268851, 0.4786286705, 0.5688888889, 0.4786286705, 0.2369268851};
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
template<typename Callable, std::size_t N>
decltype(auto) integrate(   
    const Callable& func,  // Интегрируемая функция
    const typename ArgumentGetter<Callable>::Argument& start,  
    const typename ArgumentGetter<Callable>::Argument& end,
    
                        );

/* Функция производит интегрирование, разбивая отрезок на подотрезки длиной не более dx */
template<typename Callable, std::size_t N>
decltype(auto) integrate(   
    const Callable& func,  // Интегрируемая функция
    const typename ArgumentGetter<Callable>::Argument& start,  // начало отрезка
    const typename ArgumentGetter<Callable>::Argument& end,  // конец отрезка
    const Dif<typename ArgumentGetter<Callable>::Argument>& dx  // Длина подотрезка
                        );
