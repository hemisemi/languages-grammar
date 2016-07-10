#include "function.h"
#include "grammar.h"
#include "type.h"

namespace hsm{
namespace lang{

function::function(const std::string & name, const std::vector<typeref> & params, const type *result_type){
	_name = name;
	_params = params;
	_result = result_type;
}

const type *function::result() const{
	return _result;
}

const std::vector<typeref> & function::parameters() const{
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
}

std::ostream & operator<<(std::ostream & out, const hsm::lang::function & r){
    for(size_t i = 0; i < r.parameters().size(); ++i){
        if(i > 0)
            out << ", ";
        out << r.parameters()[i].id();
    }
    return out;
}
