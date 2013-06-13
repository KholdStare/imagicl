//      Copyright Alexander Kondratskiy 2012 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef PIXEL_H_WEB2NYGT
#define PIXEL_H_WEB2NYGT

#include <cstdint>

namespace imcl
{
    template <typename PixelType>
    struct pixel_traits
    /*
    {
        static constexpr cl_channel_order;
        static constexpr cl_channel_type;
    }
    */
    ;

    template <typename PixelType>
    cl::ImageFormat pixel_image_format()
    {
        return cl::ImageFormat(
                    pixel_traits<PixelType>::channel_order, 
                    pixel_traits<PixelType>::channel_type
                );
    }


    template <typename ChannelType>
    union pixel_rgba
    {
        struct
        {
            ChannelType r;
            ChannelType g;
            ChannelType b;
            ChannelType a;
        };
        ChannelType channels[4];
    };

    template <>
    struct pixel_traits<pixel_rgba<float>>
    {
        static constexpr cl_channel_order channel_order = CL_RGBA;
        static constexpr cl_channel_type  channel_type = CL_FLOAT;
    };

    template <>
    struct pixel_traits<pixel_rgba<uint32_t>>
    {
        static constexpr cl_channel_order channel_order = CL_RGBA;
        static constexpr cl_channel_type  channel_type = CL_SIGNED_INT32;
    };

    // TODO: pixel_traits
    // TODO: channel_traits
    
} /* imcl */ 



#endif /* end of include guard: PIXEL_H_WEB2NYGT */

