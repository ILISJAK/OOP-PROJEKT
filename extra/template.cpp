#include <iostream>
template <typename T>
T maxValue(T x, T y)
{
    return (x > y) ? x : y;
}

template <class T>
class Info
{
public:
    Info(T data) : data(data) {}

    T &operator=(const T &other)
    {
        this->data = other.data;
    }

    void info() { std::cout << typeid(data).name() << std::endl; }

private:
    T data;
};

int main()
{
    std::cout << maxValue<int>(3, 7) << std::endl;
    std::cout << maxValue<double>(3.0, 7.0) << std::endl;
    std::cout << maxValue<char>('g', 'e') << std::endl;
    std::cout << std::endl;

    // zadatak2
    Info<int> i(15);
    i.info();

    Info<int> x(14);

    Info<char> a('a');
    a.info();

    Info<float> b(4.456);
    b.info();

    Info<int> ab = x;
}
