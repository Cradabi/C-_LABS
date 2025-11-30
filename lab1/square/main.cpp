#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

struct Point {
    double x;
    double y;
};

double calculatePolygonArea(const std::vector<Point>& vertices) {
    int n = vertices.size();
    double area = 0.0;
    
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += vertices[i].x * vertices[j].y;
        area -= vertices[j].x * vertices[i].y;
    }
    
    return std::abs(area) / 2.0;
}

int main() {
    const int VERTICES_COUNT = 5;
    std::vector<Point> polygon(VERTICES_COUNT);

    
    for (int i = 0; i < VERTICES_COUNT; i++) {
        std::cout << "  x" << (i + 1) << " = ";
        std::cin >> polygon[i].x;
        std::cout << "  y" << (i + 1) << " = ";
        std::cin >> polygon[i].y;
    }
    
    double area = calculatePolygonArea(polygon);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << area;
    
    return 0;
}