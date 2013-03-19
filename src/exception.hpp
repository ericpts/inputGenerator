#ifndef INPUT_GENERATOR_EXCEPTION_HPP_
#define INPUT_GENERATOR_EXCEPTION_HPP_

#include <exception>
#include <string>

namespace inputGenerator {

class Exception: public std::exception {
  public:
    Exception(const char *message): message_(message) {}
    virtual const char* what() const throw() {
        return message_;
    }

    virtual ~Exception() throw() {};
    const char * message_;
};

}

#endif // INPUT_GENERATOR_EXCEPTION_HPP_
