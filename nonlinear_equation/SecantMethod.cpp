#include <iostream>

// i ignore the error
float SecantMethod(float f(float), float x0, float x1, float e, int times);

int main() {
    auto f = [](float x) {
        return x * x - 2;
    };
    float x = SecantMethod(f, 0.0f, 3.0f, 0.00001f, 10);
    std::cout << x << std::endl;
}

float SecantMethod(float f(float), float x0, float x1, float e, int times) {
    float u = f(x0), v = f(x1);
    for (int k = 0; k < times; k++) {
        if (abs(u) < abs(v)) {
            std::swap(u, v);
            std::swap(x0, x1);
        }
        float s = (x1 - x0) / (v - u);
        x0 = x1;
        u = v;
        x1 = x1 - s * v;
        v = f(x1);
        if (abs(x1 - x0) < e) {
            break;
        }
    }
    return x1;
}