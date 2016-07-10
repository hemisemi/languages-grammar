#pragma once
#include <vector>
#include <string>
#include <map>
#include <ostream>
#include <regex>

#include "function.h"

namespace hsm{
namespace lang{

class type;

class grammar{
public:
    grammar();
    ~grammar();

	const lang::type *type(const std::string &) const;

	const std::map<std::string, const lang::type *> & types() const;
	const std::vector<lang::function *> & functions() const;

	void add_type(const lang::type *);

	lang::type *new_type(const std::string & name);
	lang::type *new_type(const std::string & name, const std::regex & regex);

	void bind();

private:
	std::vector<lang::function*> _functions;
	std::map<std::string, const lang::type*> _types;
};

}
}

std::ostream & operator<<(std::ostream & out, const hsm::lang::grammar & g);
