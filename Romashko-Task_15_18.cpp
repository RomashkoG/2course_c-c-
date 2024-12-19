#include <iostream>
#include <vector>
#include <cmath>

class Point {
public:
    double x, y;
    double vx, vy;
    double ax, ay;

    Point(double x, double y, double vx, double vy, double ax, double ay)
        : x(x), y(y), vx(vx), vy(vy), ax(ax), ay(ay) {}

    void setVelocity(double vx, double vy) {
        this->vx = vx;
        this->vy = vy;
    }

    void setAcceleration(double ax, double ay) {
        this->ax = ax;
        this->ay = ay;
    }

    void getVelocity(double &vx, double &vy) {
        vx = this->vx;
        vy = this->vy;
    }

    void getAcceleration(double &ax, double &ay) {
        ax = this->ax;
        ay = this->ay;
    }

    void updatePosition(double t) {
        x += vx * t + 0.5 * ax * t * t;
        y += vy * t + 0.5 * ay * t * t;
    }

    static double distance(Point &p1, Point &p2, double t) {
        double x1 = p1.x + p1.vx * t + 0.5 * p1.ax * t * t;
        double y1 = p1.y + p1.vy * t + 0.5 * p1.ay * t * t;
        double x2 = p2.x + p2.vx * t + 0.5 * p2.ax * t * t;
        double y2 = p2.y + p2.vy * t + 0.5 * p2.ay * t * t;
        return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }

    static bool checkIntersection(Point &p1, Point &p2, double t1, double t2) {
        for (double t = t1; t <= t2; t += 0.01) {
            if (distance(p1, p2, t) < 1e-6) {
                return true;
            }
        }
        return false;
    }
};

int countIntersections(std::vector<Point> &points, double t1, double t2) {
    int count = 0;
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            if (Point::checkIntersection(points[i], points[j], t1, t2)) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    std::vector<Point> points = {
        Point(0, 0, 1, 1, 0, 0),
        Point(1, 1, -1, -1, 0, 0)
    };

    double t1 = 0, t2 = 2;
    std::cout << "Number of intersections: " << countIntersections(points, t1, t2) << std::endl;

    return 0;
}