#include <iostream>
#include <Eigen/Dense>

// for sparse matrix, use the Givens transformation
// for dense matrix, use the Householder transformation
// this two transformation make a matrix to be a Hessenberg matrix
Eigen::Matrix4f Givens(Eigen::Matrix4f A);

std::tuple<Eigen::Matrix4f, Eigen::Matrix4f> QR_Method(Eigen::Matrix4f A);

int main() {
    Eigen::Matrix4f A;
    A << 1, 2, 3, 4,
         4, 5, 6, 7,
         2, 1, 5, 0, 
         4, 2, 1, 0; 
    Eigen::Matrix4f hessenberg = Givens(A);

    auto [Q, R] = QR_Method(hessenberg);

    std::cout << Q << std::endl;
    std::cout << R << std::endl;
}

Eigen::Matrix4f Givens(Eigen::Matrix4f A) {
    Eigen::Matrix4f g = A;
    for (int i = 0; i < 4 - 2; i++) {
        Eigen::Vector4f v = g.col(i);
        for (int j = 3; j >= 2 + i; j--) {
            if (v[j] == 0 && v[j-1] == 0) continue;
            float m = sqrt(v[j] * v[j] + v[j-1] * v[j-1]);
            float c = v[j-1] / m, s = v[j] / m;
            v[j-1] = v[j-1] * c + v[j] * s;
            v[j] = 0;
        }
        g.col(i) = v;
    }
    return g;
}

std::tuple<Eigen::Matrix4f, Eigen::Matrix4f> QR_Method(Eigen::Matrix4f A) {

}