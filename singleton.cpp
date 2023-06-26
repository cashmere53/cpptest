#include <iostream>

template <typename T>
class Singleton {
public:
    static T& getInstance() {
        if (!instance) {
            Singleton<T>::create();
        }
        return *instance;
    }

    static void create() {
        if (!instance) {
            instance = new T();
        }
    }

    static void create(T* obj) {
        if (!instance) {
            instance = obj;
        }
    }

    static void destroy() {
        delete instance;
        instance = nullptr;
    }

private:
    Singleton(const Singleton&) {}
    Singleton& operator=(const Singleton&);
    Singleton(Singleton&&);
    Singleton& operator=(Singleton&&);

    Singleton() = default;
    ~Singleton() = default;

    static T* instance;
};

template <typename T>
T* Singleton<T>::instance = nullptr;


class Test {
public:
    Test(): val(0) {}
    Test(int a): val(a) {}

    int getA() {return this->val;}
    void inc() {this->val++;}
    void dec() {this->val--;}
private:
    int val;
};

void add5() {
    Singleton<Test>::getInstance().inc();
    Singleton<Test>::getInstance().inc();
    Singleton<Test>::getInstance().inc();
    Singleton<Test>::getInstance().inc();
    Singleton<Test>::getInstance().inc();
}

int main() {
    Singleton<Test>::create();
    Singleton<Test>::getInstance().inc();

    std::cout << Singleton<Test>::getInstance().getA() << std::endl;

    Singleton<Test>::getInstance().inc();
    Singleton<Test>::getInstance().inc();
    Singleton<Test>::getInstance().inc();
    std::cout << Singleton<Test>::getInstance().getA() << std::endl;

    add5();
    Singleton<Test>::getInstance().dec();
    Singleton<Test>::getInstance().dec();
    Singleton<Test>::getInstance().dec();
    Singleton<Test>::getInstance().dec();
    Singleton<Test>::getInstance().dec();
    Singleton<Test>::getInstance().dec();
    std::cout << Singleton<Test>::getInstance().getA() << std::endl;

    return 0;
}
