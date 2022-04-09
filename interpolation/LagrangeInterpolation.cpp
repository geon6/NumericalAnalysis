#include <iostream>
#include <vector>
#include <Eigen/Dense>

#define x(i) points[i].first
#define y(i) points[i].second

typedef float(*func)(float);
// too difficult, i give it up...
// func LagrangeInterpolation(std::vector<std::pair<float, float>>& points);

int main() {
    // a vector of points that the polynomial should fit
    std::vector<std::pair<float, float>> points;
    
}

// func LagrangeInterpolation(std::vector<std::pair<float, float>>& points) {
//     int n = points.size();
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (j == i) continue;
//             auto f = [&](float x) {
//                 return (x - x(j)) / (x(i) - x(j));
//             }       
//         }
//     }
// }