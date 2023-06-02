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
    virtual void firstCallProcess() {}
    virtual void runProcess() {}

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
     * Test<Sample>型なので、Test<Sample>型のfirstCallProcess(), runProcess()が呼ばれるため何も表示されない
     * output:
     *   Hello, World
     */
    Test<Sample> a;
    a.run();
    a.run();
    a.run();
    a.run();
    a.run();

    return 0;
}