#include <AOvector.cpp>

using namespace std;

int main()
{

    AOvector<int> x(8);
    AOvector<int> z(8);
    x.push_back(1);
    x.push_back(5);
    x.push_back(7);
    x.push_back(8);
    x.push_back(9);
    x.push_back(4);
    x.push_back(3);

    z.push_back(1);
    z.push_back(5);
    z.push_back(6);
    z.push_back(8);
    z.push_back(9);
    z.push_back(4);
    z.push_back(3);
    //x.push_back(2);
    cout << z ;
    for(int i = 0 ; i < z.size() ; i++)
    {
        cout << z[i] << " ";
    }
    cout << endl;
    cout << (x == z ) << endl;
    AOvector<int>::iterator z1 = x.begin()+1;
    //AOvector<int>::iterator z2 = x.begin()+2;
    //cout << x.size();
    //x.insert(z1 , 10);
    cout << (x == z) << endl << (x < z);
    //cout << x.size();
    //for(int i = 0 ; i < x.size() ;i++)
    //{
       //cout << x[i] << " ";
    //}
    return 0;
}
