#include <iostream>
#include <Eigen/Dense>

// for sparse matrix, use the Givens transformation
// for dense matrix, use the Householder transformation
// this two transformation make a matrix to be a Hessenberg matrix
std::tuple<Eigen::Matrix4f, Eigen::Matrix4f> Givens(Eigen::Matrix4f A);

int main() {
    Eigen::Matrix4f A;
    A << 1, 2, 3, 4,
         4, 5, 6, 7,
         2, 4, 5, 3, 
         4, 3, 3, 5; 
    auto [q, r] = Givens(A);

    std::cout << q << std::endl;
    std::cout << r << std::endl;
    std::cout << q * r << std::endl;
}

std::tuple<Eigen::Matrix4f, Eigen::Matrix4f> Givens(Eigen::Matrix4f A) {
    Eigen::Matrix4f r = A;
    Eigen::Matrix4f q = Eigen::Matrix4f::Identity();
    Eigen::Matrix4f I = Eigen::Matrix4f::Identity();
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            Eigen::Vector4f v = r.col(i);
            float m = sqrt(v[j] * v[j] + v[i] * v[i]);
            float c = v[i] / m, s = v[j] / m;
            // v[j-1] = v[j-1] * c + v[j] * s;
            // v[j] = 0;
            I(i ,i) = c;
            I(j, j) = c;
            I(j, i) = -s;
            I(i, j) = s;
            r = I * r;
            q = I * q;
            I = Eigen::Matrix4f::Identity();
        }
    }
    return { q.transpose(), r };
}