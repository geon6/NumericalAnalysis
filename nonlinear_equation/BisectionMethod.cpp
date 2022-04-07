#include <iostream>

// assume that function f = 4 + 1/3 * sin(2x), x0 = 4, k_max = 20, e = 1e-7
typedef float(*func) (float);
std::tuple<float, int> BisectionMethod(func f, float a, float b, int times, float e);

int main() {
    auto f = [](float x) {
        // return 4.0f + 1.0f / 3.0f * std::sin(2 * x);
        return std::sin(x) - x * x / 4.0f;
    };
    auto [x, k] = BisectionMethod(f, 1.0f, 3.0f, 200, 0.0000001f);
    std::cout << "x: " << x << std::endl;
    std::cout << "k: " << k << std::endl;
}

std::tuple<float, int> BisectionMethod(func f, float a, float b, int times, float e) {
    int k;
    float c;
    for (k = 0; k < times; k++) {
        c = (a + b) / 2.0f;
        std::cout << c << " ";
        if (abs(c - a) < e) {
            break;
        }
        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return { c, k };
}