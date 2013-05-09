//      Copyright Alexander Kondratskiy 2012 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef CL_H_AGYTVCTU
#define CL_H_AGYTVCTU


#define __CL_ENABLE_EXCEPTIONS
#ifdef MAC
#include <OpenCL/cl.hpp>
#else
#include <CL/cl.hpp>
#endif

/**
 * Some missing traits from OpenCL C++ headers
 */
namespace cl
{

    namespace detail
    {

        struct cl_image_info;
        template<>
        struct param_traits<detail::cl_image_info, CL_IMAGE_ARRAY_SIZE>
        {
            enum { value = CL_IMAGE_ARRAY_SIZE };
            typedef ::size_t param_type;
        };

    }

}

#endif /* end of include guard: CL_H_AGYTVCTU */
