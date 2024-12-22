#ifndef BOOST_CORE_LIGHTWEIGHT_TEST_TRAIT_MACROS_IMPL_HPP
#define BOOST_CORE_LIGHTWEIGHT_TEST_TRAIT_MACROS_IMPL_HPP

#define BOOST_TEST_TRAIT_TRUE(type) ( ::boost::detail::test_trait_impl(#type, (void(*)type)0, true, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION) )
#define BOOST_TEST_TRAIT_FALSE(type) ( ::boost::detail::test_trait_impl(#type, (void(*)type)0, false, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION) )

#if defined(__GNUC__)
// ignoring -Wvariadic-macros with #pragma doesn't work under GCC
# pragma GCC system_header
#endif

#define BOOST_TEST_TRAIT_SAME(...) ( ::boost::detail::test_trait_same_impl(#__VA_ARGS__, ::boost::core::detail::is_same< __VA_ARGS__ >(), __FILE__, __LINE__, BOOST_CURRENT_FUNCTION) )

#endif // #ifndef BOOST_CORE_LIGHTWEIGHT_TEST_TRAIT_MACROS_IMPL_HPP
