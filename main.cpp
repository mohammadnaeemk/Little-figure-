#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Shape {
protected:
    float A = 0, B = 0, C = 0;
    vector<pair<float, float>> pointsList;
public:
    int counter = 0;

    void AddPointer(float X, float Y) {
        pointsList.push_back(make_pair(X, Y));
        ++counter;
    }

    virtual float retArea() = 0;

    virtual float retPerimeter() = 0;

    virtual string whatIsThis() = 0;

    virtual void ShapePainter() = 0;

    virtual void LengthCalculator() = 0;
};

class Foursquare : public Shape {
public:
    void LengthCalculator() {
        A = sqrt(pow(pointsList[0].first - pointsList[1].first, 2) + pow(pointsList[0].second - pointsList[1].second, 2));
        B = sqrt(pow(pointsList[0].first - pointsList[2].first, 2) + pow(pointsList[0].second - pointsList[2].second, 2));
    }

    string whatIsThis() {
        int Xchecker = 0;
        int Ychecker = 0;
        for (int i = 1; i < 4; ++i) {
            if (pointsList[0].first == pointsList[i].first) {
                ++Xchecker;
            }
        }
        for (int i = 1; i < 4; ++i) {
            if (pointsList[0].second == pointsList[i].second) {
                ++Ychecker;
            }
        }
        if (Ychecker >= 3 || Xchecker >= 3) {
            return "false";
        } else {
            if (A == B) {
                cout << "4" << endl;
            } else
                cout << "5" << endl;

            return "true";
        }
    }

    float retArea() {
        int a = A;
        int b = B;
        return a * b;
    }

    float retPerimeter() {
        int a = A;
        int b = B;
        return (a + b) * 2;
    }

    void ShapePainter() {
        int a = A;
        int b = B;
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                if (i == 0 || i == a - 1 || j == 0 || j == b - 1) {
                    std::cout << "* ";
                } else {
                    std::cout << "  ";
                }
            }
            std::cout << std::endl;
        }
    }
};

class Triangle : public Shape {
public:
    void LengthCalculator() {
        A = sqrt(pow(pointsList[0].first - pointsList[1].first, 2) + pow(pointsList[0].second - pointsList[1].second, 2));
        B = sqrt(pow(pointsList[1].first - pointsList[2].first, 2) + pow(pointsList[1].second - pointsList[2].second, 2));
        C = sqrt(pow(pointsList[0].first - pointsList[2].first, 2) + pow(pointsList[0].second - pointsList[2].second, 2));
    }

    string whatIsThis() {
        if ((pointsList[0].first == pointsList[1].first) && (pointsList[1].first == pointsList[2].first) ||
            (pointsList[0].second == pointsList[1].second) && (pointsList[1].second == pointsList[2].second)) {
            return "false";
        } else {
            if (A == B && B == C) {
                cout << "1" << endl;
            } else if (A == B || B == C || A == C) {
                cout << "2\n";
            } else {
                cout << "3" << endl;
            }
            return "true";
        }
    }

    float retArea() {
        float X = (A + B + C) / 2;
        return sqrt(X * (X - A) * (X - B) * (X - C));
    }

    float retPerimeter() {
        return (A + B + C);
    }

    void ShapePainter() {} //nothing
};

int main() {
    int number;
    cin >> number;
    Shape *shape;
    if (number == 4) {
        shape = new Foursquare;
    } else {
        shape = new Triangle;
    }
    float pointX, pointY;
    for (int i = 0; i < number; ++i) {
        cin >> pointX;
        cin >> pointY;
        shape->AddPointer(pointX, pointY);
    }
    shape->LengthCalculator();
    string str = shape->whatIsThis();
    if (str == "false") {
        cout << "false";
    } else {
        cout << "true" << endl;
        cout << shape->retPerimeter() << " " << shape->retArea() << endl;
        shape->ShapePainter();
    }
    return 0;
}
