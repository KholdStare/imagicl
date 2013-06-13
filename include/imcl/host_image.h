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
    template <typename ImageType, typename PixelType>
    class host_image : private image_base<ImageType, PixelType> // TODO: composition instead of private inheritance?
    {
        typedef image_base<ImageType, PixelType> base_type;
        typedef typename base_type::cl_image_type cl_image_type;
        static constexpr std::size_t N = base_type::N;

        host_image(cl::Context const& context, std::array<std::size_t, N> const& dims);
        // TODO: another constructor wit PixelType data?
        // TODO: larger context struct?
        
        // TODO: when looking into collapsing/expanding dimensions,
        // see if we can "reinterpret" an openCL mem region as another type.
        // May require low-level C opencl calls.
        

        // TODO: Think about move/copy semantics. Make movable, but not move assignable?
    private:
        // TODO: map/unmap ?
    };


    // =============================
    // Implementations
    
    template <typename ImageType, typename PixelType>
    host_image<ImageType, PixelType>::host_image(
                                        cl::Context const& context,
                                        std::array<std::size_t, N> const& dims
                                      )
        : base_type(context, dims, CL_MEM_ALLOC_HOST_PTR)
    {

    }

} /* imcl */ 


#endif /* end of include guard: HOST_IMAGE_H_6GDNT1UC */

