#include <iostream>
#include <thread>
#include "DoubleBuffer.h"
using namespace std;

void func1()
{

}
int main() {

    DoubleBuffer<int> myBuffer;

    //Be Careful this reference can not be omitted
    auto& ptr = myBuffer.getWriterData();

    ptr = 1;

    myBuffer.swap();

    cout << myBuffer.getReaderData() << endl;
    cout << myBuffer.getWriterData() << endl;

    return 0;
}