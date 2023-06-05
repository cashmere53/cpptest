#include <iostream>
#include <vector>
#include <memory>


template <typename T>
class Filter {
public:
    Filter() = default;
    virtual ~Filter() = default;

    virtual T adapt(T value) = 0;
};


template <typename T>
class SampleFilter : public Filter<T> {
public:
    SampleFilter() : val(1.00) {}
    SampleFilter(double value) : val(value) {}
    ~SampleFilter() {}

    T adapt(T value) override {
        return static_cast<T>(this->val * value);
    }

private:
    double val;
};


template <typename T>
class CombinedFilter {
public:
    CombinedFilter() {}
    ~CombinedFilter() {}

    T adapt(T value) {
        T tmp_value = value;
        for (auto& filter : this->filters) {
            tmp_value = filter->adapt(tmp_value);
        }

        return tmp_value;
    }

    void attach(Filter<T> *filter) {
        std::unique_ptr<Filter<T>> tmp_filter(filter);
        this->filters.push_back(std::move(tmp_filter));
    }

private:
    std::vector<std::unique_ptr<Filter<T>>> filters;
};


int main() {
    // Step1
    // SampleFilter<double> filter(2.0);
    // std::cout << filter.adapt(5) << std::endl;
    // std::cout << filter.adapt(2.3) << std::endl;
    // std::cout << filter.adapt(-1) << std::endl;

    // Step2
    // std::vector<Filter<double>*> filters;
    // filters.push_back(new SampleFilter<double>(2.0));
    // filters.push_back(new SampleFilter<double>(2.0));
    // filters.push_back(new SampleFilter<double>(2.0));
    // double tmp_value = 5;
    // for (auto filter : filters) {
    //     tmp_value = filter->adapt(tmp_value);
    // }
    // std::cout << tmp_value << std::endl;

    // Step3
    // std::vector<std::unique_ptr<Filter<double>>> filters;
    // std::unique_ptr<Filter<double>> filter1(new SampleFilter<double>(2.0));
    // filters.push_back(std::move(filter1));
    // double tmp_value = 5;
    // for (auto const& filter : filters) {
    //     tmp_value = filter->adapt(tmp_value);
    // }
    // std::cout << tmp_value << std::endl;

    // Step4
    CombinedFilter<double> filters;
    // filters.attach(new SampleFilter<double>(2.0));
    // filters.attach(new SampleFilter<double>(5.0));
    // filters.attach(new SampleFilter<double>(12.0));
    std::cout << filters.adapt(5) << std::endl;

    return 0;
}