#include <iostream>

using namespace std;


class MyClass
{
    public:
        int hi;
        int bye;
        MyClass()
        {
            this->hi = 1;
            this->bye = 2;
        }
        void hello(void)
        {
            std::cout << "hello" << std::endl;
        }
        void byebye(void)
        {
            std::cout << "bye" << std::endl;
        }

};

int main()
{
    int value = 3;
    int &ref_value = value;

    cout << value << " " << ref_value << endl;
    cout << &value << " " << &ref_value << endl; // 주소 값이 같다...! pointer와는 다른 개념이다.
    ref_value += 3;
    cout << value << " " << ref_value << endl;

    return 0;
}