#include "complexarray.h"
#include <iostream>
#include <complex>

using namespace std;
using namespace ModuleBase;

int main() {
    cout << "========================================" << endl;
    cout << "   ComplexArray Validation Protocol     " << endl;
    cout << "========================================" << endl << endl;

    // Task 1: Default Constructor 
    cout << "--- Task 1: Default Constructor ---" << endl;
    ComplexArray ca1;
    cout << "Size: " << ca1.getSize() << " | Bounds: (" << ca1.getBound1() << "," << ca1.getBound2() << ")" << endl << endl;

    // Task 2: Constructor with Bounds (3, 2) 
    cout << "--- Task 2: Constructor with Bounds ---" << endl;
    ComplexArray ca2(3, 2); 
    cout << "Size: " << ca2.getSize() << " | Bounds: (" << ca2.getBound1() << "," << ca2.getBound2() << ")" << endl << endl;

    // Task 3: create() Method 
    cout << "--- Task 3: create() Method ---" << endl;
    ComplexArray ca3;
    ca3.create(4, 3);
    cout << "Size after create(4,3): " << ca3.getSize() << endl << endl;

    // Task 4: Element Access and Assignment 
    cout << "--- Task 4: Element Access and Assignment ---" << endl;
    ComplexArray ca4(2, 2);
    for(int i=0; i<2; ++i) {
        for(int j=0; j<2; ++j) {
            // Assigning some sample complex values: (i+1) + (j+1)i
            ca4(i, j) = complex<double>(i + 1.0, j + 1.0);
        }
    }
    for(int i=0; i<2; ++i) {
        for(int j=0; j<2; ++j) {
            cout << "ca4(" << i << "," << j << ") = " << ca4(i, j) << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Task 5: zero_out() Method 
    cout << "--- Task 5: zero_out() Method ---" << endl;
    ca4.zero_out();
    cout << "Value at (0,0) after zero_out: " << ca4(0, 0) << endl << endl;

    // Task 6: negate() Method
    cout << "--- Task 6: negate() Method ---" << endl;
    ca4(0, 0) = complex<double>(5.0, -2.0);
    cout << "Original value: " << ca4(0, 0) << endl;
    ca4.negate();
    cout << "After negate(): " << ca4(0, 0) << endl << endl;

    // Task 7: Arithmetic Operators
    cout << "--- Task 7: Arithmetic Operators (+, -, *) ---" << endl;
    ComplexArray A(2, 2), B(2, 2);
    A = complex<double>(1.0, 1.0); // Scalar assignment
    B = complex<double>(2.0, 2.0);
    ComplexArray Sum = A + B;
    ComplexArray Diff = B - A;
    ComplexArray Scaled = A * 2.0;
    cout << "A(0,0) + B(0,0) = " << Sum(0, 0) << endl;
    cout << "B(0,0) - A(0,0) = " << Diff(0, 0) << endl;
    cout << "A(0,0) * 2.0    = " << Scaled(0, 0) << endl << endl;

    // Task 8: Compound Assignment Operators 
    cout << "--- Task 8: Compound Assignment Operators (+=, -=, *=) ---" << endl;
    A += B;
    cout << "A after A += B: " << A(0, 0) << endl;
    A -= B;
    cout << "A after A -= B (back to original): " << A(0, 0) << endl;
    A *= complex<double>(0.0, 1.0); // Multiply by i
    cout << "A after A *= i: " << A(0, 0) << endl << endl;

    // Task 9: dot() Function 
    // The dot product definition in complexarray.h is: sum of cd1(conjugate)[i] * cd2[i]
    cout << "--- Task 9: dot() Function ---" << endl;
    complex<double> dot_prod = dot(A, B);
    cout << "Dot product of A and B: " << dot_prod << endl << endl;

    // Task 10: abs2() Function
    // Sum of absolute squares of all elements
    cout << "--- Task 10: abs2() Function ---" << endl;
    double total_abs2 = abs2(A);
    cout << "Sum of absolute squares of A: " << total_abs2 << endl << endl;

    cout << "Protocol Complete." << endl;
    
    // ========================================
    //   BONUS TASK: VERIFICATION OF SAFETY
    // ========================================
    cout << "--- Bonus Task: Testing Boundary Protection ---" << endl;
    try {
        cout << "Attempting to access ca4(100, 100)..." << endl;
        ca4(100, 100); // This will trigger the 'throw' you wrote
    } catch (const std::out_of_range& e) {
        cout << ">>> SAFETY ALERT: " << e.what() << endl;
        cout << ">>> System state: PROTECTED." << endl;
    }
    cout << "========================================" << endl;
    return 0;
}
