#include "Thread.hpp"

#include <utility>
#include <future>
#include <iostream>

void threadFunction(std::future<void> futureObj, Thread *t)
{
  std::cout << "Thread Start" << std::endl;

  // while the thread is alive
  while (futureObj.wait_for(std::chrono::milliseconds(0)) == std::future_status::timeout)
  {
    std::cout << "Doing Some Work" << std::endl;
    std::this_thread::sleep_for(t->heartbeatTime);
  }
  std::cout << "Thread End" << std::endl;
}

Thread::Thread(std::string thread_name): thread_name(std::move(thread_name)), exited(false),force_exit(false),is_running(false) {
  //Fetch std::future object associated with promise
  std::future<void> futureObj = exitSignal.get_future();
  // Starting Thread & move the future object in lambda function by reference
  handle = std::thread(&threadFunction, std::move(futureObj), this);
}

Thread::~Thread() {
  // send signal to timeout thread
  exitSignal.set_value();
  // kill it
  handle.join();
}
