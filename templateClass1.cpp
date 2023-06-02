#include <cstdio>


template <typename T>
class Test {
public:
    Test() : isFirstCall(true) {}
    ~Test() {}

    void run() {
        if (this->isFirstCall) {
            this->firstCallProcess();
            this->isFirstCall = false;
        }

        this->runProcess();
    }

protected:
    virtual void firstCallProcess() = 0;
    virtual void runProcess() = 0;

private:
    bool isFirstCall;
};

class Sample : public Test<Sample> {
public:
    Sample() {}
    ~Sample() {}

    void firstCallProcess() override {
        printf("first call\n");
    }

    void runProcess() override {
        printf("normal process\n");
    }
};

int main() {
    printf("Hello, World\n");

    /**
     * Sample型はTest<Sample>型を継承しており、Sample型内でfirstCallProcess(), runProcess()を
     * オーバーライドしているため、想定した動きとなる。
     * ただ、Test<T>テンプレートのfirstCallProcess(), runProcess()が純粋仮想関数なので、
     * Test<Sample>型のインスタンスは作成できない。
     * 
     * output:
     *   Hello, World
     *   first call
     *   normal process
     *   normal process
     *   normal process
     *   normal process
     *   normal process
    */
    Sample a;
    a.run();
    a.run();
    a.run();
    a.run();
    a.run();

    return 0;
}