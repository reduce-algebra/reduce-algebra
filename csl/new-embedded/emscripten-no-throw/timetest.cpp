#include <iostream>


int main()
{   volatile long long int x = 0;
    std::cout << "Starting" << std::endl;
    for (int i=0; i<5000; i++)
        for (int j=0; j<1000000; j++) x++;
    std::cout << "Finishing " << x << std::endl;
    return 0;
}