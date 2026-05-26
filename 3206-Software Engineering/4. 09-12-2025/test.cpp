#include <iostream>
#include <cassert>  
#include "Calculator.cpp"
using namespace std; 

int main() {
    Calculator calc;

    cout<<"Starting Unit Tests..."<<endl;

    // --- Test 1: Addition ---
    cout<<"Testing Addition... ";
    assert(calc.add(10.5,20)==30.5); 
    assert(calc.add(-5,5)==0);
    cout<<"OK!"<<endl;

    // --- Test 2: Subtraction ---
    cout << "Testing Subtraction... ";
    assert(calc.sub(10,5)==5);
    assert(calc.sub(10,20)==-10);
    cout<<"OK!"<<endl;

    // --- Test 3: Multiplication ---
    cout<<"Testing Multiplication... ";
    assert(calc.mult(5,4)==20);
    assert(calc.mult(10,2)==20);
    cout<<"OK!"<<endl;

    // --- Test 4: Division ---
    cout<<"Testing Division... ";
    assert(calc.div(10,2)==5);
    assert(calc.div(9,3)==3);
    cout<<"OK!"<<endl;

    cout<<"Testing Division by Zero... ";
    bool exceptionCaught=false;
    try 
    {
        calc.div(10,0);
    } 
    catch (string e) 
    {
        exceptionCaught=true;
    }
    assert(exceptionCaught==true); 
    cout<<"OK!"<<endl;

    // --- Test 5: Modulus ---
    cout<<"Testing Modulus... ";
    assert(calc.modulus(10,2)==0);
    assert(calc.modulus(9,7)==2);
    cout<<"OK!"<<endl;

    cout<<"\n---------------------------------"<<endl;
    cout<<"SUCCESS: All tests passed!" <<endl;
    cout<< "---------------------------------"<<endl;

    return 0;
}