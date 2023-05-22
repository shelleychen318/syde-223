#include <iostream>
using namespace std;

class ItemClass

{

public:

            ItemClass();

            ItemClass(int newSize, float newCost);

            int getSize();

            float getCost();

            void setSize(int newSize);

            void setCost(float newCost);

private:

            int size;

float cost;

};

int main()
{
    ItemClass myItem;
}