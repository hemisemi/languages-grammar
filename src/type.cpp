#include "type.h"
#include "function.h"

namespace ulr{

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
    return _rules;
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

std::ostream & operator<<(std::ostream & out, const ulr::type & t){
	if(t.type() == ulr::type::terminal)
        out << "<";
    out << t.id();
	if(t.type() == ulr::type::terminal)
        out << ">";
    return out;
}
