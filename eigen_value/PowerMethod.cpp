#include <iostream>
#include <Eigen/Dense>

// get the max eigen value l and its eigen vector q of A 
std::tuple<float, Eigen::Vector3f> PowerMethod(Eigen::Matrix3f A, Eigen::Vector3f q, int times = 50);

int main() {

    Eigen::Matrix3f A;
    A << 1.0f, -1.0f, 0.0f,
        -2.0f, 4.0f, -2.0f,
        0.0f, -1.0f, 1.0f;

    Eigen::Vector3f q0;
    q0 << 1.0f, 0.0f, 0.0f;
    auto [l, q] = PowerMethod(A, q0);
    std::cout << "l: " << l << ", q: " << q.transpose() << std::endl;
}

std::tuple<float, Eigen::Vector3f> PowerMethod(Eigen::Matrix3f A, Eigen::Vector3f q, int times) {
    Eigen::Vector3f y = A * q;
    float l = y.array().abs().maxCoeff();
    Eigen::Vector3f qi = y / l;
    for (int i = 1; i <= times; i++) {
        std::cout << "times " << i << ", l: " << l << ", qi: " << qi.transpose() << std::endl;
        y = A * qi;
        l = y.array().abs().maxCoeff();
        qi = y / l;
    }
    return { l, qi };
}