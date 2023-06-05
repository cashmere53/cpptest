#include <iostream>
#include <vector>
#include <numeric>


template <typename T>
class Filter {
public:
    Filter() = default;
    virtual ~Filter() = default;

    virtual T adapt(T value) = 0;
};


template <typename T, unsigned Size>
class SMAFilter : public Filter<T> {
public:
    SMAFilter() : innerList(Size), count(0) { this->reset(); }

    T adapt(T value) override {
        this->innerList[this->count] = value;

        this->count++;
        if (this->count == Size) {
            this->count = 0;
        }

        T summarize = std::accumulate(this->innerList.begin(), this->innerList.end(), 0);
        return static_cast<T>(summarize / Size);
    }

    void reset(T value = 0) {
        for (auto& item : this->innerList) {
            item = value;
        }
        this->count = 0;
    }

private:
    std::vector<T> innerList;
    uint32_t count;
};


int main() {
    SMAFilter<double, 10> sma;

    std::cout << sma.adapt(1) << std::endl;
    std::cout << sma.adapt(2) << std::endl;
    std::cout << sma.adapt(3) << std::endl;
    std::cout << sma.adapt(4) << std::endl;
    std::cout << sma.adapt(5) << std::endl;
    std::cout << sma.adapt(6) << std::endl;
    std::cout << sma.adapt(7) << std::endl;
    std::cout << sma.adapt(8) << std::endl;
    std::cout << sma.adapt(9) << std::endl;
    std::cout << sma.adapt(10) << std::endl;

    sma.reset();

    std::cout << sma.adapt(1) << std::endl;
    std::cout << sma.adapt(2) << std::endl;
    std::cout << sma.adapt(3) << std::endl;
    std::cout << sma.adapt(4) << std::endl;
    std::cout << sma.adapt(5) << std::endl;
    std::cout << sma.adapt(6) << std::endl;
    std::cout << sma.adapt(7) << std::endl;
    std::cout << sma.adapt(8) << std::endl;
    std::cout << sma.adapt(9) << std::endl;
    std::cout << sma.adapt(10) << std::endl;

    return 0;
}