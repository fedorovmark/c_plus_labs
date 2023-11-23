#include <array>
#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

double func(double x){
    return exp(x);
}

template<typename T>
std::vector<T> slice(std::vector<T> const &v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n+1;
 
    std::vector<T> vec(first, last);
    return vec;
}

template<typename T>
double f_for_vect(std::vector<T>& a, int n) {
    if (n == 1) {
        return  func(a[0]);
    } 
    else {
        std::vector<T> b, c;
        b = slice(a, 1, n-1);
        c = slice(a, 0, n-2);
        return (f_for_vect(b, n-1) - f_for_vect(c, n-1)) / (a[n-1] - a[0]);
    }
}

template<typename xType, unsigned int N>
double f(std::array<xType, N> arr, int i) {
    std::vector<xType> vect(arr.begin(), arr.end());
    vect = slice(vect, 0, i);
    return f_for_vect(vect, vect.size());
}

template<typename xType, typename yType, unsigned int N>
class NewtonInterpolator {
    private:
    std::array<xType, N> x_points;
    std::array<yType, N> y_values;
    public:
    NewtonInterpolator(const std::array<xType, N> &points, const std::array<yType, N>& values) noexcept : x_points(points), y_values(values){}
    double interpolate(const xType& x) const noexcept {
        yType D = y_values[0];
        yType el = 1;
        for(auto i = 1; i < N; i++){
            el = 1;
            for(auto j = 1; j <= i; j++){
                el *= (x - x_points[j - 1]);
            }
        
        D += f<xType, N> (x_points, i) * el;
        }
        return D;
    }

    double get_d_N() {
        double D = interpolate(x_points[0] - (x_points[1] - x_points[0]));
        return D;
    }

    double get_d_Ch() {
        double D = interpolate(0);
        return D;
    }
};
// double func(double x){
//     return exp(x);
// }

int main(){
    double left_side = 0.;
    std::vector<double> right_side = {2, 1, 0.5, 0.25, 0.125, 0.0625};

    int N = 3;
    std::ofstream outN3("data_Nu_N3.txt", std::ios::app);
    for (auto i = 0; i <= right_side.size() - 1; i++) {
        double h = (right_side[i] - left_side) / N;
        std::array<double, 3> points = {h, 2*h, 3*h};
        std::array<double, 3> values = {func(h), func(2*h), func(3*h)};
        NewtonInterpolator<double, double, 3> nwp3(points, values);
        double P = nwp3.get_d_N();
        std::cout << std::setprecision(18) << "N = 3 | D("<<  points[0] - h << ") = " << P << " # f(x) = "<< func(points[0] - h) << " || err = " << P - func(points[0] - h) << std::endl;
    outN3 <<  P - func(points[0] - h) << std::endl;
    }
    outN3.close();

    N = 4;
    std::ofstream outN4("data_Nu_N4.txt", std::ios::app);
    for (auto i = 0; i <= right_side.size() - 1; i++) {
        double h = (right_side[i] - left_side) / N;
        std::array<double, 4> points = {h, 2*h, 3*h, 4*h};
        std::array<double, 4> values = {func(h), func(2*h), func(3*h), func(4*h)};
        NewtonInterpolator<double, double, 4> nwp4(points, values);
        double P = nwp4.get_d_N();
        std::cout << std::setprecision(18) << "N = 4 | D("<<  points[0] - h << ") = " << P << " # f(x) = "<< func(points[0] - h) << " || err = " << P - func(points[0] - h) << std::endl;
    outN4 << P - func(points[0] - h) << std::endl;
    }    
    outN4.close();        

    N = 5;
    std::ofstream outN5("data_Nu_N5.txt", std::ios::app);
    for (auto i = 0; i <= right_side.size() - 1; i++) {
        double h = (right_side[i] - left_side) / N;
        std::array<double, 5> points = {h, 2*h, 3*h, 4*h, 5*h};
        std::array<double, 5> values = {func(h), func(2*h), func(3*h), func(4*h), func(5*h)};
        NewtonInterpolator<double, double, 5> nwp5(points, values);
        double P = nwp5.get_d_N();
        std::cout << std::setprecision(18) << "N = 5 | D("<<  points[0] - h << ") = " << P << " # f(x) = "<< func(points[0] - h) << " || err = " << P - func(points[0] - h) << std::endl;
    outN5 << P - func(points[0] - h) << std::endl;
    }
    outN5.close();        



    N = 3;
    std::ofstream outN3c("data_Ch_N3.txt", std::ios::app);
    std::array<double, 3> points_cheb, values_cheb;
    for (auto i = 0; i<= right_side.size() - 1; i++) {
        for (auto j = 1; j <= points_cheb.size(); ++j){
        points_cheb[j-1] = 0.5*(left_side + right_side[i]) + 0.5*(right_side[i] - left_side) * std::cos(M_PI*(2 * j - 1) / (2*N));
        values_cheb[j-1] = func(0.5*(left_side + right_side[i]) + 0.5*(right_side[i] - left_side) * std::cos(M_PI*(2 * j - 1) / (2*N)));
        }

        NewtonInterpolator<double, double, 3> nwp3(points_cheb, values_cheb);
        std::cout << "N = 4 |  D(0) = " << nwp3.get_d_Ch() << " # f(x) = "<< func(left_side) << " || err = " << nwp3.get_d_Ch() - func(left_side) << std::endl;
    outN3c << nwp3.get_d_Ch() - func(left_side) << std::endl;
    }
    outN3c.close(); 

    N = 4;
    std::ofstream outN4c("data_Ch_N4.txt", std::ios::app);
    std::array<double, 4> points_cheb1, values_cheb1;
    for (auto i = 0; i<= right_side.size() -1; i++) {
        for (auto j = 1; j <= points_cheb1.size(); ++j){
        points_cheb1[j-1] = 0.5*(left_side + right_side[i]) + 0.5*(right_side[i] - left_side) * std::cos(M_PI*(2 * j - 1) / (2*N));
        values_cheb1[j-1] = func(0.5*(left_side + right_side[i]) + 0.5*(right_side[i] - left_side) * std::cos(M_PI*(2 * j - 1) / (2*N)));
        }

        NewtonInterpolator<double, double, 4> nwp4(points_cheb1, values_cheb1);
        std::cout << "N = 4 | D(0) = " << nwp4.get_d_Ch() << " # f(x) = "<< func(left_side) << " || err = " << nwp4.get_d_Ch() - func(left_side) << std::endl;
    outN4c << nwp4.get_d_Ch() - func(left_side) << std::endl;
    }
    outN4c.close(); 

    N = 5;
    std::ofstream outN5c("data_Ch_N5.txt", std::ios::app);
    std::array<double, 5> points_cheb2, values_cheb2;
    for (auto i = 0; i<= right_side.size() -1; i++) {
        for (auto j = 1; j <= points_cheb2.size(); ++j){
        points_cheb2[j-1] = 0.5*(left_side + right_side[i]) + 0.5*(right_side[i] - left_side) * std::cos(M_PI*(2 * j - 1) / (2*N));
        values_cheb2[j-1] = func(0.5*(left_side + right_side[i]) + 0.5*(right_side[i] - left_side) * std::cos(M_PI*(2 * j - 1) / (2*N)));
        }

        NewtonInterpolator<double, double, 5> nwp5(points_cheb2, values_cheb2);
        std::cout << "N = 5 | D(0) = " << nwp5.get_d_Ch() << " # f(x) = "<< func(left_side) << " || err = " << nwp5.get_d_Ch()- func(left_side) << std::endl;
    outN5c << nwp5.get_d_Ch() - func(left_side) << std::endl;
    }
    outN5c.close(); 
}

