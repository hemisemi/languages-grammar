#pragma once

#include <string>
#include <vector>
#include <ostream>
#include <list>
#include <string>

#include "ref.h"

namespace ulr{

class type;
class grammar;

class function{
public:
	function(const std::string & name, const std::vector<ref<const type>> & params, const type *result_type);

	const std::vector<ref<const type>> & parameters() const;
	const type *result() const;

	bool operator==(const function &) const;
	bool operator!=(const function &) const;

private:
	const type *_result;
	std::vector<ref<const type>> _params;
};

}

std::ostream & operator<<(std::ostream & out, const ulr::function & r);
