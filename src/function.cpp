#include "function.h"
#include "grammar.h"
#include "type.h"

namespace ulr{

function::function(const type *red, const std::vector<ref<const type>> & stream) : _params(stream){
	_result = red;
}

const type *function::result() const{
	return _result;
}

const std::vector<ref<const type>> & function::parameters() const{
	return _params;
}

bool function::operator ==(const function & r) const{
	if(_params.size() != r._params.size() || _result != r._result)
        return false;

	for(size_t i = 0; i < _params.size(); ++i){
		if(_params[i] != r._params[i])
            return false;
    }

    return true;
}

bool function::operator !=(const function & r) const{
    return !operator ==(r);
}

}

std::ostream & operator<<(std::ostream & out, const ulr::function & r){
    for(size_t i = 0; i < r.parameters().size(); ++i){
        if(i > 0)
            out << ", ";
        out << r.parameters()[i].id();
    }
    return out;
}
