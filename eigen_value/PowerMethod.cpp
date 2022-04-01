#include <iostream>
#include <Eigen/Dense>

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
    Eigen::Vector3f qi = y.normalized();
    float l = 0.0f;
    for (int i = 1; i <= times; i++) {
        std::cout << "times " << i << ", l: " << l << ", qi: " << qi.transpose() << std::endl;
        y = A * qi;
        l = y[0] / qi[0];
        qi = y.normalized();
    }
    return { l, qi };
}