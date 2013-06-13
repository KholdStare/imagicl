//      Copyright Alexander Kondratskiy 2012 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include <imcl/context.h>
#include <imcl/cl_image.h>


void create_image_with_flags( cl_mem_flags mem_flags )
{
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
                                mem_flags,
                                format);
    }
    catch (cl::Error const& e)
    {
        BOOST_FAIL(imcl::cl_error_to_str(e.err()));
    }
                    
    BOOST_REQUIRE( image() != nullptr );
}

BOOST_AUTO_TEST_CASE( construct_image_test_on_host )
{
    create_image_with_flags( CL_MEM_ALLOC_HOST_PTR );
}

BOOST_AUTO_TEST_CASE( construct_image_test_on_device )
{
    using namespace std;

    cl_mem_flags flags_array[] =
        {
            CL_MEM_READ_WRITE,
            CL_MEM_READ_ONLY,
            CL_MEM_WRITE_ONLY,
            CL_MEM_HOST_WRITE_ONLY,
            CL_MEM_HOST_READ_ONLY,
            CL_MEM_HOST_NO_ACCESS,
        };

    std::for_each(begin(flags_array), end(flags_array),
        [] (cl_mem_flags flags)
        {
            create_image_with_flags( flags );
        });
}
