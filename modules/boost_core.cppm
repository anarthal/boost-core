module;

#include <cstdlib>
#include <boost/config.hpp>
#include <boost/config/workaround.hpp>
#include <boost/static_assert.hpp>
#include <boost/assert.hpp>
#include <boost/assert/current_location.hpp>
#include <boost/core/detail/cxxabi.hpp>
#include <boost/core/detail/crtdbg.hpp>

export module boost.core;

import std;
import boost.assert;
import boost.throw_exception;

extern "C++" {
#include <boost/core/detail/is_same.hpp>
#include <boost/core/demangle.hpp>
#include <boost/core/lightweight_test.hpp>
#include <boost/core/lightweight_test_trait.hpp>
#include <boost/core/type_name.hpp>
}