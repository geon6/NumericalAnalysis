#include <Eigen/Dense>
#include <iostream>

// Gauss Elimination solve: Ax = b, A is 3 by 3 Matrix, x,b is 3d Vector
Eigen::Vector3f GaussElimination(Eigen::Matrix3f A, Eigen::Vector3f b); 

int main() {
    //      A       x     b         ans
    //   2  2  2    x1    1        -0.5
    //   3  2  4    x2   0.5         1
    //   1  3  9    x3   2.5         0
    Eigen::Matrix3f A;
    A << 2.0f, 2.0f, 2.0f,
         3.0f, 2.0f, 4.0f,
         1.0f, 3.0f, 9.0f;
    std::cout << "Matrix A: \n" << A << std::endl;
    
    Eigen::Vector3f b;
    b << 1.0f, 0.5f, 2.5f;
    std::cout << "Vector b: \n" << b << std::endl;

    Eigen::Vector3f x = GaussElimination(A, b);
    std::cout << "Solution of Ax = b\n" << "x: \n" << x << std::endl;
}

Eigen::Vector3f GaussElimination(Eigen::Matrix3f A, Eigen::Vector3f b) {
    // elimination process
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            float m = A(j, i) / A(i, i);
            A(j, i) = 0;
            b(j) = b(j) - m * b(i);
            for (int k = i + 1; k < 3; k++) {
                A(j, k) = A(j, k) - m * A(i, k);
            }
        }
    }
    // back substitution process 
    Eigen::Vector3f ans;
    ans(2) = b(2) / A(2, 2);
    for (int i = 1; i >= 0; i--) {
        float sum = 0.0f;
        for (int j = i + 1; j < 3; j++) {
            sum += ans(j) * A(i, j);
        }
        ans(i) = (b(i) - sum) / A(i, i);
    }
    return ans;
}