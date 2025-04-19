#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void print_num(int num) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Thread " << std::this_thread::get_id() << " prints " << num << std::endl;
}

int main() {
    std::thread t1(print_num, 1);
    std::thread t2(print_num, 2);
    t1.join();
    t2.join();
    return 0;
}