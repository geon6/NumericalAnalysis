#include <iostream>
#include <Eigen/Dense>

// Elimination with Maximal Column Pivoting
Eigen::Vector3f ColumnPivotingElimination(Eigen::Matrix3f A, Eigen::Vector3f b);

int main() {
    //            A              x      b             ans
    //   0.729  0.810  0.900    x1    0.6867        0.2246
    //   1.000  1.000  1.000    x2    0.8338        0.2812
    //   1.331  1.210  1.100    x3    1.0000        0.3280
    Eigen::Matrix3f A;
    A << 0.729f, 0.810f, 0.900f,
         1.000f, 1.000f, 1.000f,
         1.331f, 1.210f, 1.100f;
    
    Eigen::Vector3f b;
    b << 0.6867f, 0.8338f, 1.0000f;

    Eigen::Vector3f x = ColumnPivotingElimination(A, b);
    std::cout << x << std::endl;
}

Eigen::Vector3f ColumnPivotingElimination(Eigen::Matrix3f A, Eigen::Vector3f b) {
    // elimination with column pivoting
    for (int i = 0; i < 2; i++) {
        // choose the pivot
        int pivot_idx = i;
        for (int p = i; p < 3; p++) {
            if (A(p, i) > A(pivot_idx, i)) {
                pivot_idx = p;
            }
        }
        // swap the matrix A and vector b
        A.row(i).swap(A.row(pivot_idx));
        b.row(i).swap(b.row(pivot_idx));
        // elimination
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
            sum += A(i, j) * ans(j);
        }
        ans(i) = (b(i) - sum) / A(i, i);
    } 
    return ans;
}