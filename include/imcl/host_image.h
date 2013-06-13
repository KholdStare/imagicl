//      Copyright Alexander Kondratskiy 2012 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef HOST_IMAGE_H_6GDNT1UC
#define HOST_IMAGE_H_6GDNT1UC

#include <imcl/image_base.hpp>

namespace imcl
{

    // TODO: have host_image_dynamic (?) to have runtime-specified pixel type.
    // templated host_image could wrap it in a typesafe manner.

    /**
     * An OpenCL image allocated on the host
     */
    template <typename ImageType, typename PixelType> // TODO: maybe pix type shouldn't be compile-time?
    class host_image : public image_base<ImageType, PixelType>
    {
        typedef image_base<ImageType, PixelType> base_type;

        host_image(cl::Context const& context, std::array<std::size_t, base_type::N> const& dims);
        // TODO: another constructor wit PixelType data?
        
        // TODO: when looking into collapsing/expanding dimensions,
        // see if we can "reinterpret" an openCL mem region as another type.
        // May require low-level C opencl calls.
    };


    // =============================
    // Implementations
    
    template <typename ImageType, typename PixelType>
    host_image<ImageType, PixelType>::host_image(
                                        cl::Context const& context,
                                        std::array<std::size_t, base_type::N> const& dims
                                      )
        : base_type(context, dims, CL_MEM_ALLOC_HOST_PTR)
    {

    }

} /* imcl */ 


#endif /* end of include guard: HOST_IMAGE_H_6GDNT1UC */

