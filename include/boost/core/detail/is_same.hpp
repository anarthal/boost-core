#ifndef BOOST_CORE_DETAIL_IS_SAME_HPP_INCLUDED
#define BOOST_CORE_DETAIL_IS_SAME_HPP_INCLUDED

// is_same<T1,T2>::value is true when T1 == T2
//
// Copyright 2014 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#if defined(BOOST_USE_MODULES) && !defined(BOOST_CORE_INTERFACE_UNIT)

import boost.core;

#else

#include <boost/core/detail/modules.hpp>
#ifndef BOOST_USE_MODULES
#include <boost/config.hpp>
#endif

#if defined(BOOST_HAS_PRAGMA_ONCE)
# pragma once
#endif

namespace boost
{
namespace core
{
namespace detail
{

BOOST_CORE_MODULE_EXPORT template< class T1, class T2 > struct is_same
{
    BOOST_STATIC_CONSTANT( bool, value = false );
};

template< class T > struct is_same< T, T >
{
    BOOST_STATIC_CONSTANT( bool, value = true );
};

} // namespace detail
} // namespace core
} // namespace boost

#endif

#endif // #ifndef BOOST_CORE_DETAIL_IS_SAME_HPP_INCLUDED
