/*  C++ program to Count number of times a function is called  */

#include<iostream>
using namespace std;

class square
{
    private:
        int n,r;
        float n1,r1;
    public:
        void input();
        void calc();
        void display();
        int count;
};

void square::input()
{
    cout<<"Enter an integer:";
    cin>>n;
    cout<<"Enter a float no.:";
    cin>>n1;
    count++;
}

void square::calc()
{
    r=n*n;
    r1=n1*n1;
    count++;
}

void square::display()
{
    cout<<"Square of integer:"<<r;
    cout<<"\nSquare of float:"<<r1;
    count++;
} 

int main()
{
    square s;
    s.count = 0;
    s.input();
    s.calc();
    s.display();
    cout << "\nFunctions were run " << s.count << " times\n";
}