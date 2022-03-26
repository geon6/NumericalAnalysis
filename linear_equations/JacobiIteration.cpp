#include <iostream>
#include <Eigen/Dense>

// jacobi iteration  n is the max iteration times, e is the error that you allow
Eigen::Vector4f JacobiIteration(Eigen::Matrix4f A, Eigen::Vector4f b, int n = 10, float e = 0.001f);

int main() {
    Eigen::Matrix4f A;
    A << 10.0f, -1.0f,  2.0f,  0.0f,
         -1.0f, 11.0f, -1.0f,  3.0f,
          2.0f, -1.0f, 10.0f, -1.0f,
          0.0f, 3.0f,  -1.0f,  8.0f;

    Eigen::Vector4f b;
    b << 6.0f, 25.0f, -11.0f, 15.0f;
    JacobiIteration(A, b, 10, 0.0001f);
}

Eigen::Vector4f JacobiIteration(Eigen::Matrix4f A, Eigen::Vector4f b, int n, float e) {
    // x is ans, p is previous, used to check the norm(x - p) < e
    Eigen::Vector4f x = Eigen::Vector4f::Zero();
    Eigen::Vector4f p = Eigen::Vector4f::Zero();
    std::cout << "x(0): " << x.transpose() << std::endl;
    for (int k = 0; k < n; k++) {
        float sum[4] = {0.0f};
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (j == i) continue;
                sum[i] += A(i, j) * p(j);
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