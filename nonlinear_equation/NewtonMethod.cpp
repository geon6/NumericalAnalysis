#include <iostream>

typedef float(*func)(float);
/**
 * @param f: function
 * @param df: derivative of function
 * @param x0: initial point
 * @param times: max iterate times
 * @param e: max error
 */
std::tuple<float, int> NewtonMethod(func f, func df, float x0, float times, float e);

int main() {
    auto f = [](float x) {
        return std::sin(x) - x * x / 4.0f;
    };
    auto df = [](float x) {
        return std::cos(x) - x / 2.0f;
    };
    auto [x, k] = NewtonMethod(f, df, 1.5f, 20, 0.00001f);

    std::cout << "x: " << x << std::endl;
    std::cout << "k: " << k << std::endl;
}

std::tuple<float, int> NewtonMethod(func f, func df, float x0, float times, float e) {
    float x1;
    int k;
    for (k = 0; k < times; k++) {
        x1 = x0 - f(x0) / df(x0);
        x0 = f(x1);
        if (std::abs(x0) < e) {
            break;
        }
        x0 = x1;
    }
    return { x1, k };
}