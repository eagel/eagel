#ifndef EAGEL_THREADTASK_HH_
#define EAGEL_THREADTASK_HH_

namespace eagel {

class ThreadTask {
public:
	ThreadTask() = default;
	virtual void execute() = 0;
	virtual ~ThreadTask() = default;
};

} /* namespace eagel */

#endif /* EAGEL_THREADTASK_HH_ */
