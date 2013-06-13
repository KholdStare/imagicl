//      Copyright Alexander Kondratskiy 2012 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef IMAGE_BASE_HPP_M9Z17XQN
#define IMAGE_BASE_HPP_M9Z17XQN

#include <array>

#include <imcl/cl.h>
#include <imcl/traits/cl_image_traits.hpp>
#include <imcl/pixel.hpp>

namespace imcl
{

    /**
     * An OpenCL image, with extra compile-time metadata.
     */
    template <typename ImageType, typename PixelType>
    class image_base
    {
    public:
        typedef ImageType cl_image_type;
        static constexpr std::size_t N = cl_image_traits<cl_image_type>::N;

        image_base(cl::Context const& context, std::array<std::size_t, N> const& dims, cl_mem_flags mem_flags);

        cl_image_type image_;
        std::array<std::size_t, N> const dims_;
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
                    pixel_image_format<PixelType>()
            )
        )
        , dims_(dims)
    {

    }

    
} /* imcl */ 


#endif /* end of include guard: IMAGE_BASE_HPP_M9Z17XQN */

