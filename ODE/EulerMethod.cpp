#include <iostream>

std::tuple<float, float> EulerMethod(float f(float, float), float t0, float T, float u0, float h);

int main() {
    auto f = [](float t, float u) {
        return u - 2.0f * t / u;
    };
    auto [t, u] = EulerMethod(f, 0.0f, 4.0f, 1.0f, 0.0001f);
    std::cout << t << std::endl;
    std::cout << u << std::endl;
}

std::tuple<float, float> EulerMethod(float f(float, float), float t0, float T, float u0, float h) {
    while (t0 <= T) {
        float t1 = t0 + h;
        float u1 = u0 + h * f(t0, u0);
        t0 = t1;
        u0 = u1;
    }
    return { t0, u0 };
}