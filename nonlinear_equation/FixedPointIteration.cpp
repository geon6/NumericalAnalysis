#include <iostream>

// assume that function f = 4 + 1/3 * sin(2x), x0 = 4, k_max = 20, e = 1e-7
typedef float(*func) (float);
std::tuple<float, int, float> FixedPointIteration(func f, float x0, int times, float e);

int main() {
    auto f = [](float x) {
        return 4.0f + 1.0f / 3.0f * std::sin(2 * x);
    };
    auto [x, k, error] = FixedPointIteration(f, 4, 20, 0.0000001f);
    std::cout << "x: " << x << std::endl;
    std::cout << "k: " << k << std::endl;
    std::cout << "error: " << error << std::endl;
}

std::tuple<float, int, float> FixedPointIteration(func f, float x0, int times, float e) {
    float error = e + 1;
    float x = x0;
    int k;
    for (k = 0; k < times; k++) {
        x0 = f(x);
        error = abs(x - x0);
        x = x0;
        if (error < e) {
            break;
        }
    }
    return { x, k, error };
}

