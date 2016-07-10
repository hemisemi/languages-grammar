#include "grammar.h"
#include "type.h"

namespace hsm{
namespace lang{

grammar::grammar(){
    //
}

grammar::~grammar(){
	for(std::pair<std::string, const lang::type*> p : _types)
        delete p.second;
}

void grammar::add_type(const lang::type *t){
	if(_types.find(t->id()) != _types.end())
        throw; // already defined symbol

	_types[t->id()] = t;
	for(lang::function *r : t->constructors())
        _functions.push_back(r);
}

const std::map<std::string, const lang::type*> & grammar::types() const{
    return _types;
}

const std::vector<function *> & grammar::functions() const{
    return _functions;
}

const type *grammar::type(const std::string &name) const{
    auto it = _types.find(name);
    if(it != _types.end())
        return it->second;
    return NULL;
}

void grammar::bind(){
	ref<const lang::type>::bind_all(_types);
}

}
}

std::ostream & operator<<(std::ostream & out, const hsm::lang::grammar & g){
	for(std::pair<std::string, const hsm::lang::type*> p : g.types())
        out << *p.second;
    return out;
}
