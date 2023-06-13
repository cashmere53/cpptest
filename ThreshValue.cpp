#include <iostream>

template <typename T>
class ThreshValue {
public:
    ThreshValue(T min, T max) : value(0), min(min), max(max) {}
    ThreshValue(T min, T max, T init) : ThreshValue(min, max), value(init) {}

    void set(T value) {
        if (value > this->max) {
            this->value = this->max;
        } else if (value < this->min) {
            this->value = this->min;
        } else {
            this->value = value;
        }
    }

    T get() { return this->value; }

private:
    T value;
    T min;
    T max;
};

int main() {
    ThreshValue<double> value(0., 100.);

    value.set(5);
    std::cout << value.get() << std::endl;
    value.set(0);
    std::cout << value.get() << std::endl;
    value.set(41234);
    std::cout << value.get() << std::endl;
    value.set(-2134);
    std::cout << value.get() << std::endl;
    value.set(55.2);
    std::cout << value.get() << std::endl;
    value.set(21);
    std::cout << value.get() << std::endl;

    return 0;
}