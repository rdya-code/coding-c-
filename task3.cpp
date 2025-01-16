//#include <iostream>
//using namespace std;
//
//class A {
//public:
//    A() { cout << "A's constructor called\n"; }
//    virtual ~A() { cout << "A's destructor called\n"; }
//    virtual void displayA() { cout << "Message from class A\n"; }
//};
//
//class B : virtual public A { // Virtual inheritance to resolve diamond problem
//public:
//    B() { cout << "B's constructor called\n"; }
//    ~B() { cout << "B's destructor called\n"; }
//    void displayA() override { cout << "Overridden message from class B\n"; }
//    void displayB() { cout << "Message from class B\n"; }
//};
//
//class C : virtual public A { // Virtual inheritance to resolve diamond problem
//public:
//    C() { cout << "C's constructor called\n"; }
//    ~C() { cout << "C's destructor called\n"; }
//    void displayA() override { cout << "Overridden message from class C\n"; }
//    void displayC() { cout << "Message from class C\n"; }
//};
//
//class D : public B, public C {
//public:
//    D() { cout << "D's constructor called\n"; }
//    ~D() { cout << "D's destructor called\n"; }
//    void displayD() { cout << "Message from class D\n"; }
//
//    // Specify which displayA to use to resolve ambiguity
//    void displayA() override { B::displayA(); }
//};
//
//class E : public D, public C {
//public:
//    E() { cout << "E's constructor called\n"; }
//    ~E() { cout << "E's destructor called\n"; }
//    void displayE() { cout << "Message from class E\n"; }
//};
//
//class F : public virtual A, public E {
//public:
//    F() { cout << "F's constructor called\n"; }
//    ~F() { cout << "F's destructor called\n"; }
//    void displayF() { cout << "Message from class F\n"; }
//
//    // Explicitly resolve ambiguity by specifying paths for displayA and displayC
//    void displayA() override { B::displayA(); }
//    void displayC() { C::displayC(); }
//};
//
//int main() {
//    cout << "Creating object of class D:\n";
//    D d;
//    d.displayA();  // Calls B's version of displayA
//    d.displayB();
//    d.displayC();
//    d.displayD();
//
//    cout << "\nCreating object of class F with virtual inheritance:\n";
//    F f;
//    f.displayA();  // Calls B's version of displayA (resolved in F)
//    f.displayB();
//    f.displayC();  // Calls C's displayC explicitly
//    f.displayD();
//    f.displayE();
//    f.displayF();
//
//    return 0;
//}
