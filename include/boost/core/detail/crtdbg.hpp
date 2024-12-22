#ifndef BOOST_CORE_DETAIL_CRTDBG_HPP_INCLUDED
#define BOOST_CORE_DETAIL_CRTDBG_HPP_INCLUDED

// Conditionally includes crtdbg.h.
// Helpful for the module infrastructure
#if defined(_MSC_VER) && defined(_CPPLIB_VER) && defined(_DEBUG)
# include <crtdbg.h>
#endif

#endif