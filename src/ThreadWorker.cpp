#include "ThreadWorker.hpp"

#include <utility>
#include <future>
#include <iostream>

void threadFunction(std::future<void> futureObj, ThreadWorker *t)
{
  std::cout << "Thread Start" << std::endl;

  // while the thread is alive
  while (futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout) {
    std::cout << "Doing Some Work at Thread " << t->thread_name << std::endl;
    std::this_thread::sleep_for(t->heartbeatTime);
  }
  std::cout << "Thread End" << std::endl;
}

ThreadWorker::ThreadWorker(std::string thread_name): thread_name(std::move(thread_name)), exited(false), force_exit(false) {
  std::cout << thread_name << std::endl;
  //Fetch std::future object associated with promise
  std::future<void> futureObj = exitSignal.get_future();
  // Starting Thread & move the future object in lambda function by reference
  handle = std::thread(&threadFunction, std::move(futureObj), this);
}

ThreadWorker::~ThreadWorker() {
  // send signal to timeout thread
  exitSignal.set_value();
  // kill it
  handle.join();
}
