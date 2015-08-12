#ifndef MAIN_HH_
#define MAIN_HH_

#include <list>
#include <string>

class TestCase;

extern std::list<TestCase *> testCases;

class TestException {
public:
	TestException(std::string message) :
			_message(message) {
	}

	std::string message() {
		return _message;
	}
private:
	std::string _message;
};

class TestCase {
public:
	TestCase(std::string name) :
			_message("OK"), _success(true), _name(name) {
		testCases.push_back(this);
	}

	void execute() {
		try {
			run();
		} catch (TestException &e) {
			_success = false;
			_message = e.message();
		}
	}

	virtual ~TestCase() {
	}

	std::string name() {
		return _name;
	}

	std::string message() {
		return _message;
	}

	bool success() {
		return _success;
	}

protected:
	virtual void run() throw (TestException) = 0;

	std::string _message;
	bool _success;

private:
	std::string _name;
};

#define TEST_CASE(case_name)                          \
class case_name: TestCase {                           \
public:                                               \
	case_name(std::string name) :                     \
			TestCase(name) {                          \
	}                                                 \
protected:                                            \
	virtual void run() throw (TestException) override;\
} TestCase_##case_name(#case_name);                   \
void case_name::run()throw (TestException)

#define TEST_CHECK(test_condition)                    \
if(!(test_condition)){                                \
	throw TestException(#test_condition);             \
}

#endif
