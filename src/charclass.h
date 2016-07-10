#pragma once

#include <list>
#include "type.h"

namespace hsm{
namespace ulr{

class charclass{
public:
	charclass();

	bool contains(char c) const;

	charclass operator|(const charclass & cc) const;
	charclass operator&(const charclass & cc) const;
	bool operator==(const charclass & cc) const;
	bool operator!=(const charclass & cc) const;

private:
	struct range{
		char first;
		char last;
	};

	std::list<range> _ranges;
};

}
}
