#pragma once

#include <string>
#include "type.h"

namespace hsm{
namespace lang{

class regex : public lang::type{
public:
	regex(const std::string & regex);

private:
	std::string _str;
};

}
}
