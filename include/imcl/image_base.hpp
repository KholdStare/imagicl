//      Copyright Alexander Kondratskiy 2012 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef IMAGE_BASE_HPP_M9Z17XQN
#define IMAGE_BASE_HPP_M9Z17XQN

#include <array>

#include <imcl/cl.h>
#include <imcl/traits/cl_image_traits.hpp>

namespace imcl
{

    /**
     * An OpenCL image, with extra compile-time metadata.
     */
    template <typename ImageType, typename PixelType>
    class image_base
    {
        ImageType image_;

    public:
        typedef ImageType cl_image_type;
        static constexpr std::size_t N = cl_image_traits<cl_image_type>::N;

        image_base(cl::Context const& context, std::array<std::size_t, N> const& dims, cl_mem_flags mem_flags);
    };


    template <typename ImageType, typename PixelType>
    image_base<ImageType, PixelType>::image_base(
                cl::Context const& context,
                std::array<std::size_t, N> const& dims,
                cl_mem_flags mem_flags
            )
        : image_(
            construct_image(
                    context,
                    dims,
                    mem_flags,
                    cl::ImageFormat(CL_RGBA, CL_FLOAT) // TODO: make customizable
            )
        )
    {

    }

    
} /* imcl */ 


#endif /* end of include guard: IMAGE_BASE_HPP_M9Z17XQN */

