#ifndef BDN_ProgrammingError_H_
#define BDN_ProgrammingError_H_

#include <stdexcept>

namespace bdn
{


/** Indicates a programming error. I.e. the error is a bug in the code, rather than
	something that can legitimately happen at runtime.

	Note that this is actually implemented as a typedef to std::logic_error.
	So ProgrammingError is actually the SAME type as std::logic_error.
	That means that the following will catch both bdn::ProgrammingError AND std::logic_error
	exceptions.

	\code

	try
	{
	...
	}
	catch(ProgrammingError& e)	// will catch std::logic_error as well
	{
	}

	\endcode
*/
#ifdef BDN_GENERATING_DOCS
class ProgrammingError : public std::logic_error
{
public:
	explicit ProgrammingError( const std::string& message );
	explicit ProgrammingError( const char* message );
};

#else

typedef std::logic_error ProgrammingError;

#endif

}


#endif