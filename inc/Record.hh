#ifndef EAGEL_RECORD_HH_
#define EAGEL_RECORD_HH_

#include <iostream>

namespace eagel {

class Record {
public:
	Record(const std::string &key, const std::string &value);
	Record(const Record & record);
	Record(const Record && record);
	~Record();

	Record & operator=(const Record & record);
	Record & operator=(const Record && record);

	std::string key();
	std::string value();
private:
	std::string _key;
	std::string _value;
};

} /* namespace eagel */

#endif /* EAGEL_RECORD_HH_ */
