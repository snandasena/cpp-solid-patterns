#include <iostream>

int main()
{
    try
    {
        throw -1;
    }
    catch (int e)
    {
        std::cerr << e << '\n';
    }

    return 0;
}
