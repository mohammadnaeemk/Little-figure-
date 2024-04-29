#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace  std;

class Shape
{
private:
    vector< vector<float>> Points;
public:
virtual float ret_area()=0;

};
class Foursquare:public Shape
{
public:
    float ret_area(){

    }
    float PerimeterCalculator()
    {

    }
    void ShapePainter()
    {

    }
};
class Triangle:public Shape
{
public:
    float PerimeterCalculator()
    {

    }
    float ret_area(){

    }
};

int main() {
    int number;
    cin>>number;
    for (int i = 0; i < number; ++i) {

    }

    return 0;
}
