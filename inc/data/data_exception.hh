#ifndef EAGEL_DATA_DATA_EXCEPTION_HH_
#define EAGEL_DATA_DATA_EXCEPTION_HH_

#include <exception>
#include <string>

namespace eagel {
namespace data {

class data_exception: public std::exception {
public:
	data_exception(std::string message);
	virtual ~data_exception() noexcept;

	virtual const char* what() const noexcept override;

private:
	std::string message;
};

} /* namespace data */
} /* namespace eagel */

#endif /* EAGEL_DATA_DATA_EXCEPTION_HH_ */
