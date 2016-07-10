#include "grammar.h"
#include "type.h"

namespace ulr{

grammar::grammar(){
    //
}

grammar::~grammar(){
    for(std::pair<std::string, const ulr::type*> p : _types)
        delete p.second;
}

void grammar::add_type(const ulr::type *t){
	if(_types.find(t->id()) != _types.end())
        throw; // already defined symbol

	_types[t->id()] = t;
	for(ulr::function *r : t->rules())
        _functions.push_back(r);
}

const std::map<std::string, const ulr::type*> & grammar::types() const{
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
    ref<const ulr::type>::bind_all(_types);
}

}

std::ostream & operator<<(std::ostream & out, const ulr::grammar & g){
    for(std::pair<std::string, const ulr::type*> p : g.types())
        out << *p.second;
    return out;
}
