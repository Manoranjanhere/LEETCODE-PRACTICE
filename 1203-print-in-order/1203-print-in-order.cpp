class Foo {
public:
    mutex m1,m2,m3;
    Foo() {
        m2.lock();
        m3.lock();
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        m1.lock();
        printFirst();
        m2.unlock();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        m2.lock();
        printSecond();
        m3.unlock();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        m3.lock();
        printThird();
    }
};