#include "Store.hh"

namespace eagel {

Store::Store(const std::string path) {
	// TODO Auto-generated constructor stub

}

Store::~Store() {
	// TODO Auto-generated destructor stub
}

void Store::put(const Record & record) {
	// TODO
}

Record Store::get(const std::string & key) {
	// TODO
	return Record(key,"");
}

} /* namespace eagel */
