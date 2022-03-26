#include <iostream>
#include <tuple>
#include <Eigen/Dense>

// Cholesky Decomposition is a effcient decomposition method for positive-definite matrix 
Eigen::Matrix3f CholeskyDecomposition(Eigen::Matrix3f A);

int main() {
    //       A                   L
    //   6   7   5     2.4495   0        0
    //   7   13  8     2.8577   2.1985   0
    //   5   8   6     2.0412   0.9856   0.9285
    Eigen::Matrix3f A;
    A <<    6.0f,   7.0f,   5.0f,
            7.0f,   13.0f,  8.0f,
            5.0f,   8.0f,   6.0f;
    
    Eigen::Matrix3f L = CholeskyDecomposition(A);
    Eigen::Matrix3f LT = L.transpose();
    std::cout << "L: \n" << L << std::endl; 
    std::cout << "LT: \n" << LT << std::endl; 
}

Eigen::Matrix3f CholeskyDecomposition(Eigen::Matrix3f A) {
    Eigen::Matrix3f L = Eigen::Matrix3f::Zero();
    L(0, 0) = static_cast<float>(std::sqrt(A(0, 0)));
    for (int i = 1; i < 3; i++) {
        L(i, 0) = A(i, 0) / L(0, 0);
    }
    
    for (int j = 1; j < 3; j++) {
        float sum1 = 0.0f;
        for (int k = 0; k < j; k++) {
            sum1 += L(j, k) * L(j, k);
        }
        L(j, j) = static_cast<float>(std::sqrt(A(j, j) - sum1));
        for (int i = j + 1; i < 3; i++) {
            float sum2 = 0.0f;
            for (int k = 0; k < j; k++) {
                sum2 += L(i, k) * L(j, k);
            }
            L(i, j) = (A(i, j) - sum2) / L(j, j);
        }
    }
    return L;
}