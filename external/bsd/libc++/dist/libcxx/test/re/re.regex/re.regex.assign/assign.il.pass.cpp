//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <regex>

// template <class charT, class traits = regex_traits<charT>> class basic_regex;

// basic_regex&
//    assign(initializer_list<charT> il,
//           flag_type f = regex_constants::ECMAScript);

#include <regex>
#include <cassert>

int main()
{
#ifndef _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
    std::regex r2;
    r2.assign({'(', 'a', '(', '[', 'b', 'c', ']', ')', ')'});
    assert(r2.flags() == std::regex::ECMAScript);
    assert(r2.mark_count() == 2);

    r2.assign({'(', 'a', '(', '[', 'b', 'c', ']', ')', ')'}, std::regex::extended);
    assert(r2.flags() == std::regex::extended);
    assert(r2.mark_count() == 2);
#endif  // _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
}
