#include<iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point()  // construct by default
    {
        cout << "Construct\n";
        x = y = 0;
    }
    Point(int x1, int y1)   // Construct by 2 param
    {
        cout << "Construct by 2 param\n";
        x = x1;
        y = y1;
    }
    void Init()
    {
        x = rand() % 10;
        y = rand() % 10;
    }
    void Init(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
    void Output()
    {
        cout << "X: " << x << "\tY: " << y << endl;
    }

    Point operator+(Point& b)
    {
        Point temp;
        temp.x = this->x + b.x;
        temp.y = this->y + b.y;
        return temp;
    }
    Point operator+(int a)
    {
        Point temp(x + a, y + a);
        return temp;
    }
    int GetX()
    {
        return x;
    }
    int GetY()
    {
        return y;
    }
    void SetX(int a)
    {
        x = a;
    }
    void SetY(int a)
    {
        y = a;
    }
};

Point operator-(int a, Point b)
{
    Point rez;
    rez.SetX(a - b.GetX());
    rez.SetY(a - b.GetY());
    return rez;
}
Point operator*(Point a, int b)
{
    Point rez;
    rez.SetX(a.GetX() * b);
    rez.SetY(a.GetY() * b);
    return rez;
}
Point operator/(int a, Point b)
{
    Point rez;
    if (b.GetX() != 0 && b.GetY() != 0)
    {
        rez.SetX(a / b.GetX());
        rez.SetY(a / b.GetY());
    }
}
Point operator--(Point& a)
{
    a.SetX(a.GetX() - 1);
    a.SetY(a.GetY() - 1);
    return a;
}
Point operator--(Point& a, int)
{
    Point temp = a;
    a.SetX(a.GetX() - 1);
    a.SetY(a.GetY() - 1);
    return temp;
}
Point& Point::operator+=(int a)
{
    x += a;
    y += a;
    return *this;
}
Point& Point::operator+=(const Point& b)
{
    x += b.x;
    y += b.y;
    return *this;
}

int main()
{
    srand(unsigned(time(0)));

    Point a(1, 2);
    Point b(3, 4);

    Point t = --a;
    t.Output();
    a.Output(); 

    Point d = a--;
    d.Output();
    a.Output();

    a += 10;
    a.Output();

    a += b;
    a.Output();
}
