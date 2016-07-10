#include "type.h"
#include "function.h"

namespace hsm{
namespace lang{

template<>
std::list<ref<const type>*> ref<const type>::_unbound = std::list<ref<const type>*>();

type::type(const std::string &name) : _id(name){
    //
}

type::~type(){
    //
}

const std::string & type::id() const{
    return _id;
}

const std::vector<function *> & type::constructors() const{
	return _constructors;
}

void type::add_constructor(function *f){
	_constructors.push_back(f);
}

bool type::operator ==(const type & t) const{
    return _id == t._id;
}

bool type::operator !=(const type & t) const{
    return _id != t._id;
}

bool type::operator <(const type & t) const{
    return _id < t._id;
}

}
}

std::ostream & operator<<(std::ostream & out, const hsm::lang::type & t){
    out << t.id();
    return out;
}
