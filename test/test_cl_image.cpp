//      Copyright Alexander Kondratskiy 2012 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include <imcl/context.h>
#include <imcl/cl_image.h>

BOOST_AUTO_TEST_CASE( construct_image_test )
{
    using namespace std;

    imcl::compute_context c;

    BOOST_REQUIRE( c.context() != nullptr );

    typedef cl::Image2D image_type;

    cl::ImageFormat format(CL_RGBA, CL_FLOAT);
    std::array<std::size_t, 2> dims = {{ 64, 128 }};
    image_type image;
    try
    {
        image = imcl::construct_image<image_type>(
                                c.context(),
                                dims,
                                CL_MEM_ALLOC_HOST_PTR,
                                format);
    }
    catch (cl::Error const& e)
    {
        BOOST_FAIL(imcl::cl_error_to_str(e.err()));
    }
                    
    BOOST_REQUIRE( image() != nullptr );
}

