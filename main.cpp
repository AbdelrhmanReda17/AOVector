#include <AOvector.cpp>

using namespace std;

int main()
{
    AOvector<int> x(4);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    cout << x;
    cout << x.pop_back() <<endl;
    cout << x;

    return 0;
}
