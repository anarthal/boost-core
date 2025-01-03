//
//  boost/core/lightweight_test.hpp - lightweight test library
//
//  Copyright (c) 2002, 2009, 2014 Peter Dimov
//  Copyright (2) Beman Dawes 2010, 2011
//  Copyright (3) Ion Gaztanaga 2013
//
//  Copyright 2018 Glen Joseph Fernandes
//  (glenjofe@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//

#ifndef BOOST_CORE_LIGHTWEIGHT_TEST_MACROS_IMPL_HPP
#define BOOST_CORE_LIGHTWEIGHT_TEST_MACROS_IMPL_HPP

// Without includes

#define BOOST_TEST(expr) ( ::boost::detail::test_impl(#expr, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, (expr)? true: false) )
#define BOOST_TEST_NOT(expr) BOOST_TEST(!(expr))

#define BOOST_ERROR(msg) ( ::boost::detail::error_impl(msg, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION) )

#define BOOST_TEST_WITH(expr1,expr2,predicate) ( ::boost::detail::test_with_impl(predicate, #expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )

#define BOOST_TEST_EQ(expr1,expr2) ( ::boost::detail::test_with_impl(::boost::detail::lw_test_eq(), #expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )
#define BOOST_TEST_NE(expr1,expr2) ( ::boost::detail::test_with_impl(::boost::detail::lw_test_ne(), #expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )

#define BOOST_TEST_LT(expr1,expr2) ( ::boost::detail::test_with_impl(::boost::detail::lw_test_lt(), #expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )
#define BOOST_TEST_LE(expr1,expr2) ( ::boost::detail::test_with_impl(::boost::detail::lw_test_le(), #expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )
#define BOOST_TEST_GT(expr1,expr2) ( ::boost::detail::test_with_impl(::boost::detail::lw_test_gt(), #expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )
#define BOOST_TEST_GE(expr1,expr2) ( ::boost::detail::test_with_impl(::boost::detail::lw_test_ge(), #expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )

#define BOOST_TEST_CSTR_EQ(expr1,expr2) ( ::boost::detail::test_cstr_eq_impl(#expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )
#define BOOST_TEST_CSTR_NE(expr1,expr2) ( ::boost::detail::test_cstr_ne_impl(#expr1, #expr2, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expr1, expr2) )

#define BOOST_TEST_ALL_EQ(begin1, end1, begin2, end2) ( ::boost::detail::test_all_eq_impl(BOOST_LIGHTWEIGHT_TEST_OSTREAM, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, begin1, end1, begin2, end2) )
#define BOOST_TEST_ALL_WITH(begin1, end1, begin2, end2, predicate) ( ::boost::detail::test_all_with_impl(BOOST_LIGHTWEIGHT_TEST_OSTREAM, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, begin1, end1, begin2, end2, predicate) )

#ifndef BOOST_NO_EXCEPTIONS
   #define BOOST_TEST_THROWS( EXPR, EXCEP )                           \
      try {                                                           \
         EXPR;                                                        \
         ::boost::detail::throw_failed_impl                           \
         (#EXPR, #EXCEP, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION); \
      }                                                               \
      catch(EXCEP const&) {                                           \
         ::boost::detail::test_results();                             \
      }                                                               \
      catch(...) {                                                    \
         ::boost::detail::throw_failed_impl                           \
         (#EXPR, #EXCEP, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION); \
      }                                                               \
   //
#else
   #define BOOST_TEST_THROWS( EXPR, EXCEP )
#endif

#ifndef BOOST_NO_EXCEPTIONS
#  define BOOST_TEST_NO_THROW(EXPR)                                    \
    try {                                                              \
        EXPR;                                                          \
    } catch (const std::exception& e) {                                \
        ::boost::detail::no_throw_failed_impl                          \
        (#EXPR, e.what(), __FILE__, __LINE__, BOOST_CURRENT_FUNCTION); \
    } catch (...) {                                                    \
        ::boost::detail::no_throw_failed_impl                          \
        (#EXPR, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION);           \
    }
    //
#else
#  define BOOST_TEST_NO_THROW(EXPR) { EXPR; }
#endif

#endif