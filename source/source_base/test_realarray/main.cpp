#include <iostream>
#include "../realarray.h"

using namespace ModuleBase;

int main() {
    std::cout << "realArray Test Program" << std::endl;
    std::cout << "==================" << std::endl;

    // Test 1: Default Constructor
    std::cout << "\n1. Testing Default Constructor:" << std::endl;
    realArray ra1;
    std::cout << "realArray ra1 (default): size = " << ra1.getSize() << ", dim = " << ra1.getDim() << std::endl;

    // Test 2: 3D Array Constructor
    std::cout << "\n2. Testing 3D Array Constructor:" << std::endl;
    realArray ra2(2, 3, 2);
    std::cout << "realArray ra2 (2, 3, 2): size = " << ra2.getSize() << ", dim = " << ra2.getDim() << std::endl;
    std::cout << "bound1 = " << ra2.getBound1() << ", bound2 = " << ra2.getBound2() << ", bound3 = " << ra2.getBound3() << std::endl;

    // Test 3: 4D Array Constructor
    std::cout << "\n3. Testing 4D Array Constructor:" << std::endl;
    realArray ra3(2, 2, 2, 2);
    std::cout << "realArray ra3 (2, 2, 2, 2): size = " << ra3.getSize() << ", dim = " << ra3.getDim() << std::endl;
    std::cout << "bound1 = " << ra3.getBound1() << ", bound2 = " << ra3.getBound2() << ", bound3 = " << ra3.getBound3() << ", bound4 = " << ra3.getBound4() << std::endl;
    
    // Test 4: create() Method for 3D Array
    std::cout << "\n4. Testing create() Method for 3D Array" << std::endl;
    realArray ra4;
    std::cout << "realArray ra4 before resizing:" << std::endl;
    std::cout << "size = " << ra4.getSize() << ", dim = " << ra4.getDim() << std::endl;
    std::cout << "bound1 = " << ra4.getBound1() << ", bound2 = " << ra4.getBound2() << ", bound3 = " << ra4.getBound3() << std::endl;

    ra4.create(3, 2, 2);
    std::cout << "realArray ra4 after resizing to (3, 2, 2):" << std::endl;
    std::cout << "size = " << ra4.getSize() << ", dim = " << ra4.getDim() << std::endl;
    std::cout << "bound1 = " << ra4.getBound1() << ", bound2 = " << ra4.getBound2() << ", bound3 = " << ra4.getBound3() << std::endl;

    // Test 5: create() Method for 4D Array
    std::cout << "\n5. Testing create() Method for 4D Array" << std::endl;
    realArray ra5;
    std::cout << "realArray ra5 before resizing:" << std::endl;
    std::cout << "size = " << ra5.getSize() << ", dim = " << ra5.getDim() << std::endl;
    std::cout << "bound1 = " << ra5.getBound1() << ", bound2 = " << ra5.getBound2() << ", bound3 = " << ra5.getBound3() << ", bound4 = " << ra5.getBound4() << std::endl;

    ra5.create(2, 2, 2, 2);
    std::cout << "realArray ra5 after resizing to (2, 2, 2, 2):" << std::endl;
    std::cout << "size = " << ra5.getSize() << ", dim = " << ra5.getDim() << std::endl;
    std::cout << "bound1 = " << ra5.getBound1() << ", bound2 = " << ra5.getBound2() << ", bound3 = " << ra5.getBound3() << ", bound4 = " << ra5.getBound4() << std::endl;

    // Test 6: Element Access and Assignment
    std::cout << "\n6. Testing Element Access and Assignment" << std::endl;
    realArray ra6(2, 2, 2);
    std::cout << "We assign ra6(i, j, k) a value of 100*i+10*j+k" << std::endl;
    for(int i = 0; i < ra6.getBound1(); i++){
        for(int j = 0; j < ra6.getBound2(); j++){
            for(int k = 0; k < ra6.getBound3(); k++){
                ra6(i, j, k) = i * 100 + j * 10 + k;
            }
        }
    }
    std::cout << "Print 3D Array ra6:" << std::endl;
    for(int i = 0; i < ra6.getBound1(); i++){
        for(int j = 0; j < ra6.getBound2(); j++){
            for(int k = 0; k < ra6.getBound3(); k++){
                std::cout << "ra6(" << i << "," << j << "," << k << ") = " 
                          << ra6(i, j, k) << std::endl;
            }
        }
    }

    // Test 7: Assignment Operator with Scalar
    std::cout << "\n7. Testing Assignment Operator with Scalar" << std::endl;
    realArray ra7(2, 2, 2);
    ra7 = 5.5;
    std::cout << "We assign ra7(i, j, k) to 5.5" << std::endl;
    std::cout << "Print 3D Array ra7:" << std::endl;
    for(int i = 0; i < ra7.getBound1(); i++){
        for(int j = 0; j < ra7.getBound2(); j++){
            for(int k = 0; k < ra7.getBound3(); k++){
                std::cout << "ra7(" << i << "," << j << "," << k << ") = " 
                          << ra7(i, j, k) << std::endl;
            }
        }
    }


    // Test 8: zero_out() Method
    std::cout << "\n8. Testing zero_out() Method" << std::endl;
    realArray ra8(2, 2, 2);
    std::cout << "We assign ra8(i, j, k) to 1" << std::endl;
    ra8 = 1;
    std::cout << "Print 3D Array ra8:" << std::endl;
    for(int i = 0; i < ra8.getBound1(); i++){
        for(int j = 0; j < ra8.getBound2(); j++){
            for(int k = 0; k < ra8.getBound3(); k++){
                std::cout << "ra8(" << i << "," << j << "," << k << ") = " 
                          << ra8(i, j, k) << std::endl;
            }
        }
    }
    std::cout << "Then we use zero_out to let ra8(i, j, k) all become zero" << std::endl;
    ra8.zero_out();
    std::cout << "Print 3D Array ra8:" << std::endl;
    for(int i = 0; i < ra8.getBound1(); i++){
        for(int j = 0; j < ra8.getBound2(); j++){
            for(int k = 0; k < ra8.getBound3(); k++){
                std::cout << "ra8(" << i << "," << j << "," << k << ") = " 
                          << ra8(i, j, k) << std::endl;
            }
        }
    }

    // Test 9: Copy Constructor
    std::cout << "\n9. Testing Copy Constructor" << std::endl;
    realArray ra9(2, 2, 2);
    std::cout << "We assign ra9(i, j, k) a value of 100*i+10*j+k" << std::endl;
    for(int i = 0; i < ra9.getBound1(); i++){
        for(int j = 0; j < ra9.getBound2(); j++){
            for(int k = 0; k < ra9.getBound3(); k++){
                ra9(i, j, k) = 100 * i + 10 * j + k;
            }
        }
    }
    std::cout << "Print 3D Array ra9:" << std::endl;
    for(int i = 0; i < ra9.getBound1(); i++){
        for(int j = 0; j < ra9.getBound2(); j++){
            for(int k = 0; k < ra9.getBound3(); k++){
                std::cout << "ra9(" << i << "," << j << "," << k << ") = " 
                          << ra9(i, j, k) << std::endl;
            }
        }
    }
    std::cout << "Then we create a new realArray ra9_copy to copy the ra9 constructor" << std::endl;
    realArray ra9_copy = ra9;
    std::cout << "Print 3D Array ra9_copy:" << std::endl;
    for(int i = 0; i < ra9_copy.getBound1(); i++){
        for(int j = 0; j < ra9_copy.getBound2(); j++){
            for(int k = 0; k < ra9_copy.getBound3(); k++){
                std::cout << "ra9_copy(" << i << "," << j << "," << k << ") = " 
                          << ra9_copy(i, j, k) << std::endl;
            }
        }
    }

    // Test 10: 4D Array Operations
    std::cout << "\n10. Tesing 4D Array Operations" << std::endl;
    realArray ra10(2, 2, 2, 2);
    std::cout << "We assign ra10(i, j, k, t) a value of 1000*i+100*j+10*k+t" << std::endl;
    for(int i = 0; i < ra10.getBound1(); i++){
        for(int j = 0; j < ra10.getBound2(); j++){
            for(int k = 0; k < ra10.getBound3(); k++){
                for(int t = 0; t < ra10.getBound4(); t++){
                    ra10(i, j, k, t) = 1000 * i + 100 * j + 10 * k + t;
                }
            }
        }
    }
    std::cout << "Print 4D Array ra10:" << std::endl;
    for(int i = 0; i < ra10.getBound1(); i++){
        for(int j = 0; j < ra10.getBound2(); j++){
            for(int k = 0; k < ra10.getBound3(); k++){
                for(int t = 0; t < ra10.getBound4(); t++){
                    std::cout << "ra10(" << i << "," << j << "," << k << "," << t
                              << ") = " << ra10(i, j, k, t) << std::endl;
                }
            }
        }
    }
    std::cout << "Then we use zero_out() to let ra10(i, j, k, t) all become zero" << std::endl;
    ra10.zero_out();
    std::cout << "Print 4D Array ra10:" << std::endl;
    for(int i = 0; i < ra10.getBound1(); i++){
        for(int j = 0; j < ra10.getBound2(); j++){
            for(int k = 0; k < ra10.getBound3(); k++){
                for(int t = 0; t < ra10.getBound4(); t++){
                    std::cout << "ra10(" << i << "," << j << "," << k << "," << t
                              << ") = " << ra10(i, j, k, t) << std::endl;
                }
            }
        }
    }

    // All tests completed
    std::cout << "\nAll tests completed successfully!" << std::endl;
    return 0;
}