#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace  std;

class Shape
{
protected:
    int A = 0 , B = 0 , C = 0 ,D = 0;
 vector<pair<int,int>> Points;
public:

    void AddPointer (int count)
    {
        int X,Y;
        for (int i = 0; i < count; ++i) {
            cin>>X;
            cin>>Y;
            Points[i].first = X;
            Points[i].second = Y;
        }
    }
    virtual float retArea()=0;
    virtual float retPerimeter()=0;
    virtual string whatIsThis()=0;
    virtual  void ShapePainter()=0;
    virtual void LengthCalculator()=0;
};
class Foursquare:public Shape
{
public:
    void LengthCalculator()
    {

    }
    string whatIsThis()
    {

    }
     float retArea()
    {

    }
     float retPerimeter()
    {

    }
    void ShapePainter()
    {

    }
};
class Triangle:public Shape
{
public:
    void LengthCalculator()
    {

    }
    string whatIsThis()
    {

    }
    float retArea()
    {

    }
    float retPerimeter()
    {

    }
    void ShapePainter(){} //nothing
};

int main() {
    int number;
    cin>>number;
    Shape* shape ;
    if(number==4)
    {
      shape = new Foursquare ;
    }
    else
    {
        shape =  new Triangle ;
    }


    return 0;
}
