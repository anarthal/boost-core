module;

#include <boost/config.hpp>
#include <boost/config/workaround.hpp>
#include <boost/static_assert.hpp>
#include <boost/assert.hpp>
#include <boost/assert/current_location.hpp>
#include <boost/core/detail/cxxabi.hpp>

export module boost.core;

import std;
import boost.assert;
import boost.throw_exception;

#include <boost/core/demangle.hpp>
#include <boost/core/lightweight_test.hpp>