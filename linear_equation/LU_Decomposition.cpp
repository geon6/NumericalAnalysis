#include <iostream>
#include <Eigen/Dense>
#include <tuple>

std::tuple<Eigen::Matrix3f, Eigen::Matrix3f> LU_Decomposition(Eigen::Matrix3f A);

int main() {
    //       A             L            U
    //   1   2   3     1   0   0     1   2   3
    //   2   5   2     2   1   0     0   1  -4
    //   3   1   5     3  -5   1     0   0 -24
    Eigen::Matrix3f A;
    A << 1.0f, 2.0f, 3.0f,
         2.0f, 5.0f, 2.0f,
         3.0f, 1.0f, 5.0f;
    
    auto [L, U] = LU_Decomposition(A);
    std::cout << L << std::endl << U;
}

std::tuple<Eigen::Matrix3f, Eigen::Matrix3f> LU_Decomposition(Eigen::Matrix3f A) {
    // initialize the L as a Identity, U as a Zero
    Eigen::Matrix3f L = Eigen::Matrix3f::Identity();
    Eigen::Matrix3f U = Eigen::Matrix3f::Zero();
    // compute the first col of L, the first row of U
    for (int i = 0; i < 3; i++) {
        U(0, i) = A(0, i);
    }
    L = Eigen::Matrix3f::Identity();
    for (int j = 1; j < 3; j++) {
        L(j, 0) = A(j, 0) / U(0, 0);
    }
    for (int k = 1; k < 3; k++) {
        // compute U(k, j)
        for (int j = k; j < 3; j++) {
            float sum = 0.0f;
            for (int p = 0; p < k; p++) {
                sum += L(k, p) * U(p, j);
            }
            U(k, j) = A(k, j) - sum;
        }
        // compute L(i, k)
        for (int i = k; i < 3; i++) {
            float sum = 0.0f;
            for (int p = 0; p < k; p++) {
                sum += L(i, p) * U(p, k);
            }
            L(i, k) = (A(i, k) - sum) / U(k, k);
        }
    }
    return { L, U };
}