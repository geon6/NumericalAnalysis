#include <iostream>
#include <Eigen/Dense>

Eigen::Vector4f GaussSeidelIteration(Eigen::Matrix4f A, Eigen::Vector4f b, int n = 10, float e = 0.0001f);

int main() {
    Eigen::Matrix4f A;
    A <<    10.0f,   -1.0f,     2.0f,    0.0f,
           -1.0f,     11.0f,   -1.0f,    3.0f,
            2.0f,    -1.0f,    10.0f,   -1.0f,
            0.0f,     3.0f,    -1.0f,    8.0f;
    
    Eigen::Vector4f b;
    b << 6.0f, 25.0f, -11.0f, 15.0f;

    GaussSeidelIteration(A, b, 100, 0.00000000000001f);
}

Eigen::Vector4f GaussSeidelIteration(Eigen::Matrix4f A, Eigen::Vector4f b, int n, float e) {
    Eigen::Vector4f x = Eigen::Vector4f::Zero();
    Eigen::Vector4f p = Eigen::Vector4f::Zero();
    std::cout << "x(0): " << x.transpose() << std::endl;
    for (int k = 0; k < n; k++) {
        float sum[4] = {0};
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (j < i) {
                    sum[i] += x(j) * A(i, j);
                } else if (j > i) {
                    sum[i] += p(j) * A(i, j);
                }
            }
            x(i) = (b(i) - sum[i]) / A(i, i);
        }
        std::cout << "x(" << k + 1 << "): " << x.transpose() << std::endl;
        float norm = (x-p).squaredNorm();
        std::cout << "norm(x-p): " << norm << std::endl;
        if (norm < e) {
            return x;
        }
        p = x;
    }
    std::cout << "iteration over" << std::endl;
    return x;
}