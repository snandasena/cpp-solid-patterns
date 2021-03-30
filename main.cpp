//
// Created by sajith on 3/30/21.
//


#include <thread>
#include <mutex>
#include <iostream>

int main()
{
//    std::mutex mtx;
//    std::unique_lock<std::mutex> lock(mtx);

    std::this_thread::sleep_for(std::chrono::seconds(10));

//    lock.unlock();

    return 0;
}
