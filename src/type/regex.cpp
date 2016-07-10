#include "regex.h"

namespace hsm{
namespace lang{

regex::regex(const std::string & exp) : type(exp){
	_str = exp;
}

}
}
