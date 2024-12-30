module;

#include <cstdlib>
#include <boost/config.hpp>
#include <boost/config/workaround.hpp>
#include <boost/static_assert.hpp>
#include <boost/assert.hpp>
#include <boost/assert/current_location.hpp>
#include <boost/core/detail/cxxabi.hpp>
#include <boost/core/detail/crtdbg.hpp>
#include <boost/cstdint.hpp>
#if defined(_MSC_VER)
#include <intrin.h>
#endif

export module boost.core;

import std;
import boost.assert;
import boost.throw_exception;

extern "C++" {
#include <boost/core/detail/is_same.hpp>
#include <boost/core/detail/string_view.hpp>
#include <boost/core/demangle.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/core/lightweight_test.hpp>
#include <boost/core/lightweight_test_trait.hpp>
#include <boost/core/type_name.hpp>
#include <boost/core/bit.hpp>
}