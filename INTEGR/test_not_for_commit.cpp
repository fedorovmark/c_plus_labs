#include <iostream>
#include <array>
#include <type_traits>

template <typename RealType, unsigned int N> 
struct nodes;

template <typename RealType> 
struct nodes<RealType, 3> {
    std::array<RealType, 1> p{0.0};
    std::array<RealType, 1> w{2.0};
};

int main() {
    nodes<double, 3> node;
    
    std::cout << node.p.size() << std::endl;
}