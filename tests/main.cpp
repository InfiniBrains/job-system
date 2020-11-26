#include <iostream>
#include <thread>
#include <vector>
#include "../src/ThreadWorker.hpp"

int main(){
  unsigned int concurrency = std::thread::hardware_concurrency();
  std::vector<ThreadWorker*> workerPool;
  workerPool.reserve(concurrency);

  std::cout << "Testing Worker Threads, using " << concurrency << " as concurrency level" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  for(int i=0; i<concurrency; i++){
    auto t = new ThreadWorker(std::to_string(concurrency));
    workerPool.push_back( std::ref(t));
  }


  std::this_thread::sleep_for(std::chrono::milliseconds(500));
}