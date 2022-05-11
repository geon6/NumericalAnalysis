#include <iostream>

std::tuple<float, float> PredictorCorrectorMethod(float f(float, float), float t0, float T, float u0, float h);

int main() {
    auto f = [](float t, float u) {
        return u - 2.0f * t / u;
    };
    auto [t, u] = PredictorCorrectorMethod(f, 0.0f, 4.0f, 1.0f, 0.0001f);
    std::cout << t << std::endl;
    std::cout << u << std::endl;
}

std::tuple<float, float> PredictorCorrectorMethod(float f(float, float), float t0, float T, float u0, float h) {
    while (t0 <= T) {
        float t1 = t0 + h;
        float k1 = f(t0, u0);
        float k2 = f(t1, u0 + h * k1);        
        float u1 = u0 + (k1 + k2) * h / 2.0f;
        t0 = t1;
        u0 = u1;
    }
    return { t0, u0 };
}