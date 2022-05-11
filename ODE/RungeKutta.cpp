#include <iostream>

std::tuple<float, float> RungeKutta(float f(float, float), float t0, float T, float u0, float h);

int main() {
    auto f = [](float t, float u) {
        return u - 2.0f * t / u;
    };
    auto [t, u] = RungeKutta(f, 0.0f, 4.0f, 1.0f, 0.1f);
    std::cout << t << std::endl;
    std::cout << u << std::endl;
}

std::tuple<float, float> RungeKutta(float f(float, float), float t0, float T, float u0, float h) {
    while (t0 <= T) {
        float t1 = t0 + h;
        float k1 = f(t0, u0);
        float k2 = f(t0 + h / 2.0f, u0 + h * k1 / 2.0f);        
        float k3 = f(t0 + h / 2.0f, u0 + h * k2 / 2.0f);
        float k4 = f(t0 + h, u0 + h * k3);
        float u1 = (k1 + 2.0f * k2 + 2.0f * k3 + k4) * h / 6.0f + u0;
        t0 = t1;
        u0 = u1;
    }
    return { t0, u0 };
}