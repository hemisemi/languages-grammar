#pragma once

#include <string>
#include <regex>
#include "type.h"

namespace hsm{
namespace ulr{

class regex : public ulr::type{
public:
	regex(const std::regex & regex);

private:
	std::string _str;
};

}
}
