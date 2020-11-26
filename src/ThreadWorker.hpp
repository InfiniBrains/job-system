#include <cstdint>
#include <thread>
#include <string>
#include <future>

class ThreadWorker {
public:
  explicit ThreadWorker(std::string thread_name = "");
  ~ThreadWorker();

  // call only from task's thread
//  void sleep(struct Mutex& cs);
//  void wakeup();
//
//  bool isRunning() const;
//  bool isFinished() const;

  // time used to wait between job fetches
  std::chrono::milliseconds heartbeatTime;

  std::string thread_name;
private:

  bool force_exit;
  bool exited;

  // worker thread
  std::thread handle;

  // Create a std::promise object
  std::promise<void> exitSignal;

};