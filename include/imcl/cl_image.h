//      Copyright Alexander Kondratskiy 2012 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef CL_IMAGE_H_ZVFBMIQP
#define CL_IMAGE_H_ZVFBMIQP

#include <imcl/traits/cl_image_traits.hpp>

#include <array>

namespace imcl
{
    
    // TODO: separate into "cl" folder ? for cl specific functionality?
    template <typename CLImage>
    CLImage construct_image(
                cl::Context const& context,
                std::array<size_t, cl_image_traits<CLImage>::N> const& dims,
                cl_mem_flags flags,
                cl::ImageFormat format,
                void* host_ptr = nullptr
            )
    {
        static constexpr size_t N = cl_image_traits<CLImage>::N;
        static_assert( (N >= 1) && (N <= 3), "Image dimensions must be between 1 and 3." );

        cl_image_desc desc = {0,}; // null it out

        desc.image_type = cl_image_traits<CLImage>::mem_type;
        desc.image_width = dims[0];

        desc.image_height = 0;
        if ( N > 1 )
        {
            if (cl_image_traits<CLImage>::is_array
                && N == 2)
            {
                desc.image_array_size = dims[1];
            }
            else 
            {
                desc.image_height = dims[1];
            }
        }

        desc.image_depth = 0;
        if ( N > 2 )
        {
            if (cl_image_traits<CLImage>::is_array
                && N == 3)
            {
                desc.image_array_size = dims[2];
            }
            else 
            {
                desc.image_depth = dims[2];
            }
        }

        cl_int error;

        // pin the host memory
        CLImage hostImage = ::clCreateImage(
            context(), 
            flags,
            &format, 
            &desc, 
            host_ptr, 
            &error);
        ::cl::detail::errHandler(error, "imcl::construct_image");

        return hostImage;
    }

    
} /* imcl */ 


#endif /* end of include guard: CL_IMAGE_H_ZVFBMIQP */

