# QStream
A simple file stream library with basic features written in C++. Contains the Header File and the Dynamic Linked Library file.

Wrote a DLL file for the first time. And yes, Dynamic Linked Libraries are awesome, strong and powerful.

Usage
=====
Download the files "qstream.h" and "qstream.dll" from the "output" directory. Include them in your project, include the header file while you code in C++. Compile them together. Execute your ".exe" file with having the ".dll" file in the same directory of the ".exe" file.

Sample Handler Code
===================
"main.cpp"

//other necessary headers
#include "qstream.h"

using namespace std;

int main() {
    
    oqstream oqs = {"myfile.dat", "wb"};
    char buff[] {"Hello World"};
    oqs.write(buff, strlen(buff) * sizeof(char));
    oqs.put('A');
    oqs.rewind();
    oqs.put('B').put('C');
    oqs.close();
    
    iqstream iqs("myfile.dat", "rb");
    iqs.seekg(-3, SEEK_END);
    char x, y, z;
    x = iqs.get();
    z = iqs.rewind().get(y).get();
    iqs.close();
    cout << x << endl << y << endl << z << endl;
    return 0;
}

==========================================================================

Source Code
===========
You can also check the source code of the library in the "Source" Folder.
