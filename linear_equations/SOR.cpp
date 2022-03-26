#include <iostream>
#include <Eigen/Dense>

// SOR  w: Relaxation Factor
Eigen::Vector4f SOR(Eigen::Matrix4f A, Eigen::Vector4f b, float w = 1.3f, int n = 10, float e = 0.0001f);

int main() {
    Eigen::Matrix4f A;
    A <<   -4.0f,     1.0f,     1.0f,    1.0f,
            1.0f,    -4.0f,     1.0f,    1.0f,
            1.0f,     1.0f,    -4.0f,    1.0f,
            1.0f,     1.0f,     1.0f,   -4.0f;
    
    Eigen::Vector4f b;
    b << 1.0f, 1.0f, 1.0f, 1.0f;

    SOR(A, b, 1.3f, 10);
}

Eigen::Vector4f SOR(Eigen::Matrix4f A, Eigen::Vector4f b, float w, int n, float e) {
    Eigen::Vector4f x = Eigen::Vector4f::Zero();
    Eigen::Vector4f p = Eigen::Vector4f::Zero();
    std::cout << "x(0): " << x.transpose() << std::endl;
    for (int k = 0; k < n; k++) {
        float sum[4] = {0};
        float error = 0.0f;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (j < i) {
                    sum[i] += x(j) * A(i, j);
                } else if (j > i) {
                    sum[i] += p(j) * A(i, j);
                }
            }
            // why the dx = w ???
            float dx = w / A(i, i) * (b(i) - sum[i]);
            if (std::abs(dx) > error) {
                error = std::abs(dx);
            }
            x(i) = (1 - w) * p(i) + dx;
        }
        std::cout << "x(" << k + 1 << "): " << x.transpose() << std::endl;
        std::cout << "error: " << error << std::endl;
        if (error < e) {
            return x;
        }
        p = x;
    }
    return x;
}