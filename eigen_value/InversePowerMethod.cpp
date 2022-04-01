#include <iostream>
#include <Eigen/Dense>

// this method is same as Power Method, just use a theorem
// if l is the eigen value of A, 1 / l is the eigen value of inverse(A)
// get the min eigen value and its eigen vector of A
std::tuple<float, Eigen::Vector3f> InversePowerMethod(Eigen::Matrix3f A, Eigen::Vector3f q, int times = 20);

int main() {
    Eigen::Matrix3f A;
    A << 6.0f, 5.0f, -5.0f,
         2.0f, 6.0f, -2.0f,
         2.0f, 5.0f, -1.0f;

    Eigen::Vector3f q0;
    q0 << 3.0f, 7.0f, -13.0f;
    auto [l, q] = InversePowerMethod(A, q0);
    std::cout << "l: " << l << ", q: " << q.transpose() << std::endl;
}

std::tuple<float, Eigen::Vector3f> InversePowerMethod(Eigen::Matrix3f A, Eigen::Vector3f q, int times) {
    Eigen::Matrix3f IA = A.inverse();
    Eigen::Vector3f y = IA * q;
    float l = y.array().abs().maxCoeff();
    Eigen::Vector3f qi = y / l;
    for (int i = 1; i <= times; i++) {
        std::cout << "times " << i << ", l: " << l << ", qi: " << qi.transpose() << std::endl;
        y = IA * qi;
        l = y.array().abs().maxCoeff();
        qi = y / l;
    }
    return { l, qi };
}