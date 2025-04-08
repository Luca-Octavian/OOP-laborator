#include <iostream>
using namespace std;
constexpr float operator"" _Kelvin(long double kelvin) {
    return static_cast<float>(kelvin - 273.15);
}
constexpr float operator"" _Fahrenheit(long double fahrenheit) {
    return static_cast<float>((fahrenheit - 32) * 5.0 / 9.0);
}
int main()
{
    {
        float a = 300.0_Kelvin;
        float b = 120.0_Fahrenheit;
        std::cout << "300 Kelvin in Celsius: " << a << "°C\n";
        std::cout << "120 Fahrenheit in Celsius: " << b << "°C\n";
        return 0;
    }
}