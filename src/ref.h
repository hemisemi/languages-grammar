#pragma once
#include <string>
#include <map>
#include <list>
#include <algorithm>
#include <iterator>

namespace hsm{
namespace lang{

template<class T>
class ref{
protected:
    static std::list<ref<T>*> _unbound; // must be declared for each type

public:
    ref(const ref<T> & copy) : _id(copy._id), _ptr(copy._ptr){
        if(_ptr == NULL)
            _unbound.push_back(this);
    }

    ref(const T *ptr) : _ptr(ptr){
        if(_ptr == NULL)
            throw;
        _id = _ptr->id();
    }

    ref(const std::string & id) : _id(id), _ptr(NULL){
        _unbound.push_back(this);
    }

    ~ref(){
        std::remove(std::begin(_unbound), std::end(_unbound), this);
    }

    const std::string & id() const{
        return _id;
    }

    const T *pointer() const{
        if(_ptr == NULL)
            throw;
        return _ptr;
    }

    T *pointer(){
        if(_ptr == NULL)
            throw;
        return _ptr;
    }

    const T *operator->() const{
        if(_ptr == NULL)
            throw;
        return _ptr;
    }

    T *operator->(){
        if(_ptr == NULL)
            throw;
        return _ptr;
    }

    const T & operator*() const{
        if(_ptr == NULL)
            throw;
        return *_ptr;
    }

    T & operator*(){
        if(_ptr == NULL)
            throw;
        return *_ptr;
    }

    bool operator==(const ref<T> & other) const{
        return (_id == other._id);
    }

    bool operator!=(const ref<T> & other) const{
        return (_id != other._id);
    }

    bool operator==(const T *other) const{
        return _ptr == other;
    }

    bool operator!=(const T *other) const{
        return _ptr != other;
    }

    operator const T *() const{
        return _ptr;
    }

    operator T *(){
        return _ptr;
    }

    void bind(const std::map<std::string, T*> & bank){
        if(_ptr != NULL){
            typename std::map<std::string, T*>::const_iterator it = bank.find(_id);
            if(it != bank.end()){
                _ptr = it->second;
            }
            if(_ptr == NULL)
                throw; // unresolved symbol
        }
    }

    static void bind_all(const std::map<std::string, T*> & bank){
        for(ref<T> *ref : _unbound){
            ref->bind(bank);
        }
        _unbound.clear();
    }

private:
    std::string _id;
    T *_ptr;
};

}
}
