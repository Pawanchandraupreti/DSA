// Convex Hull Graham Scan

#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
    int index;
};

long long crossProduct(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convexHull(vector<Point> points) {
    int n = (int)points.size();
    if (n < 3) return points;

    int minIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (points[i].y < points[minIndex].y || (points[i].y == points[minIndex].y && points[i].x < points[minIndex].x)) {
            minIndex = i;
        }
    }
    swap(points[0], points[minIndex]);
    Point pivot = points[0];

    sort(points.begin() + 1, points.end(), [&](const Point& a, const Point& b) {
        long long val = crossProduct(pivot, a, b);
        if (val == 0) {
            return (a.x - pivot.x) * (a.x - pivot.x) + (a.y - pivot.y) * (a.y - pivot.y) < 
                   (b.x - pivot.x) * (b.x - pivot.x) + (b.y - pivot.y) * (b.y - pivot.y);
        }
        return val > 0;
    });

    vector<Point> hull;
    for (int i = 0; i < n; ++i) {
        while (hull.size() > 1 && crossProduct(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    return hull;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
        points[i].index = i;
    }

    vector<Point> hull = convexHull(points);
    for (const Point& p : hull) {
        cout << p.index << ' ';
    }
    return 0;
}


