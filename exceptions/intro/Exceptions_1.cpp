#include <iostream>

struct my_exception
{
};

void foo()
{
//    throw -1;
    throw my_exception{};
}

int main()
{
    int arr[] = {-1, 2, 4};

    try
    {
//        throw -1;
//        foo();
        throw *arr;
    }
    catch (int e)
    {
        std::cerr << "Error - " << e << '\n';
    } catch (const my_exception &e)
    {
        std::cerr << "my exception\n";
    } catch (int *e)
    {
        std::cerr << "Error - " << e << '\n';
    }

    return 0;
}
