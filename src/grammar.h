#pragma once
#include <vector>
#include <string>
#include <map>
#include <ostream>
#include <regex>

#include "function.h"

namespace ulr{

class type;

class grammar{
public:
    grammar();
    ~grammar();

	const ulr::type *type(const std::string &) const;

	const std::map<std::string, const ulr::type *> & types() const;
	const std::vector<ulr::function *> & functions() const;

	void add_type(const ulr::type *);

	ulr::type *new_type(const std::string & name);
	ulr::type *new_type(const std::string & name, const std::regex & regex);

	void bind();

private:
	std::vector<ulr::function*> _functions;
	std::map<std::string, const ulr::type*> _types;
};

}

std::ostream & operator<<(std::ostream & out, const ulr::grammar & g);
