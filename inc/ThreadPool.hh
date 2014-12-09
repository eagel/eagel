#ifndef EAGEL_THREADPOOL_HH_
#define EAGEL_THREADPOOL_HH_

#include <cstddef>
#include <queue>
#include <vector>
#include <thread>

#include "ThreadTask.hh"

namespace eagel {

class ThreadPool {
public:
	ThreadPool() = delete;
	ThreadPool(const ThreadPool &) = delete;
	ThreadPool(size_t size);

	virtual ~ThreadPool();

	ThreadPool & operator=(const ThreadPool &) = delete;

	void execute(ThreadTask *task);

private:
	std::queue<ThreadTask *> tasks;
	std::vector<std::thread *> threads;
};

} /* namespace edb */

#endif /* EAGEL_THREADPOOL_HH_ */
