//      Copyright Alexander Kondratskiy 2012 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef HOST_IMAGE_H_6GDNT1UC
#define HOST_IMAGE_H_6GDNT1UC

#include <array>

#include <imcl/cl.h>

namespace imcl
{

    /**
     * An OpenCL image allocated on the host
     */
    template <typename ImageType, typename PixelType>
    class host_image
    {
        typedef ImageType cl_image_type;
        // TODO: traits to get number of dimensions from cl image type
        static constexpr N = 2;


        cl_image_type image_;

    public:
        host_image(std::array<std::size_t, N> const& dims);
        // TODO: another constructor wit PixelType data?
        
        // TODO: when looking into collapsing/expanding dimensions,
        // see if we can "reinterpret" an openCL mem region as another type.
        // May require low-level C opencl calls.
    };
    
} /* imcl */ 


#endif /* end of include guard: HOST_IMAGE_H_6GDNT1UC */

