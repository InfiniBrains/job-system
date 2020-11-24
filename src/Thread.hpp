#include <cstdint>
#include <thread>
#include <string>
#include <future>

struct Thread {
public:
  explicit Thread(std::string thread_name = "");
  virtual ~Thread();

  virtual int task() = 0;

  // call only from task's thread
  void sleep(struct Mutex& cs);
  void wakeup();

  bool isRunning() const;
  bool isFinished() const;

  // time used to wait between job fetches
  std::chrono::milliseconds heartbeatTime;

private:
  bool force_exit;
  bool exited;

  // worker thread
  std::thread handle;

  // Create a std::promise object
  std::promise<void> exitSignal;

  std::string thread_name;
};