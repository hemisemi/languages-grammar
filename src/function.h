#pragma once

#include <string>
#include <vector>
#include <ostream>
#include <list>
#include <string>

#include "typeref.h"

namespace hsm{
namespace lang{

class type;
class grammar;

class function{
public:
	function(const std::string & name, const std::vector<typeref> & params, const type *result_type);

	const std::vector<typeref> & parameters() const;
	const type *result() const;

	bool operator==(const function &) const;
	bool operator!=(const function &) const;

private:
	std::string _name;
	const type *_result;
	std::vector<typeref> _params;
};

}
}

std::ostream & operator<<(std::ostream & out, const hsm::lang::function & r);
