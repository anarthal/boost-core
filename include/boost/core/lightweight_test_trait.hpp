#ifndef BOOST_CORE_LIGHTWEIGHT_TEST_TRAIT_HPP
#define BOOST_CORE_LIGHTWEIGHT_TEST_TRAIT_HPP

// MS compatible compilers support #pragma once

#if defined(_MSC_VER)
# pragma once
#endif

#if defined(BOOST_USE_MODULES) && !defined(BOOST_CORE_INTERFACE_UNIT)

#include <boost/current_function.hpp>
#include <boost/config.hpp>
#include <boost/core/lightweight_test_trait_macros_impl.hpp>
import boost.core;

#else

// boost/core/lightweight_test_trait.hpp
//
// BOOST_TEST_TRAIT_TRUE, BOOST_TEST_TRAIT_FALSE, BOOST_TEST_TRAIT_SAME
//
// Copyright 2014, 2021 Peter Dimov
//
// Copyright 2019 Glen Joseph Fernandes
// (glenjofe@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#include <boost/core/lightweight_test.hpp>
#include <boost/core/type_name.hpp>
#include <boost/core/detail/is_same.hpp>
#include <boost/core/detail/modules.hpp>
#ifndef BOOST_USE_MODULES
#include <boost/config.hpp>
#endif

namespace boost
{
namespace detail
{

BOOST_CORE_MODULE_EXPORT template< class T > inline void test_trait_impl( char const * trait, void (*)( T ),
  bool expected, char const * file, int line, char const * function )
{
    if( T::value == expected )
    {
        test_results();
    }
    else
    {
        BOOST_LIGHTWEIGHT_TEST_OSTREAM
            << file << "(" << line << "): predicate '" << trait << "' ["
            << boost::core::type_name<T>() << "]"
            << " test failed in function '" << function
            << "' (should have been " << ( expected? "true": "false" ) << ")"
            << std::endl;

        ++test_results().errors();
    }
}

BOOST_CORE_MODULE_EXPORT template<class T> inline bool test_trait_same_impl_( T )
{
    return T::value;
}

BOOST_CORE_MODULE_EXPORT template<class T1, class T2> inline void test_trait_same_impl( char const * types,
  boost::core::detail::is_same<T1, T2> same, char const * file, int line, char const * function )
{
    if( test_trait_same_impl_( same ) )
    {
        test_results();
    }
    else
    {
        BOOST_LIGHTWEIGHT_TEST_OSTREAM
            << file << "(" << line << "): test 'is_same<" << types << ">'"
            << " failed in function '" << function
            << "' ('" << boost::core::type_name<T1>()
            << "' != '" << boost::core::type_name<T2>() << "')"
            << std::endl;

        ++test_results().errors();
    }
}

} // namespace detail
} // namespace boost

#include <boost/core/lightweight_test_trait_macros_impl.hpp>

#endif

#endif // #ifndef BOOST_CORE_LIGHTWEIGHT_TEST_TRAIT_HPP
