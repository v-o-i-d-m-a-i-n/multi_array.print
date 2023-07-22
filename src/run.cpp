#include "src/algs.hpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // matrix<double> A(extents[3][2]);
    tensor<double,4> A(extents[2][3][3][2]);
    // A = set_value(A, -1.0);
    print_t(cout, A);
    cout<<endl;
    return 0;
}
