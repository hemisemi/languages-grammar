#pragma once

#include <string>
#include <vector>
#include <set>

namespace hsm{
namespace lang{

class function;

class type{
public:
	type(const std::string & id);
	~type();

    const std::string & id() const;
	const std::vector<function *> & constructors() const;

	bool operator==(const type &) const;
	bool operator!=(const type &) const;
	bool operator<(const type &) const;

	void add_constructor(function *);

private:
    std::string _id;
	std::vector<function *> _constructors;
};

}
}

std::ostream & operator<<(std::ostream & out, const hsm::lang::type & t);
