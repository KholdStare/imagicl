//      Copyright Alexander Kondratskiy 2012 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef CL_cl_image_traits_HPP_NO43KYUP
#define CL_cl_image_traits_HPP_NO43KYUP





namespace imcl
{
    /**
     * Traits to determine types/operations
     * that are possible for an OpenCL image
     */
    template <typename CLImage> struct cl_image_traits;

    template <>
    struct cl_image_traits<cl::Image1D>
    {
        static constexpr std::size_t N = 1;
        static constexpr bool is_array = false;
        static constexpr cl_mem_object_type mem_type = CL_MEM_OBJECT_IMAGE1D;
        typedef cl::Image1D climage_type;

        static constexpr cl_int dim_info[N] =
            { CL_IMAGE_WIDTH };
    };

    template <>
    struct cl_image_traits<cl::Image1DArray>
    {
        static const std::size_t N = 2;
        static const bool is_array = true;
        static const cl_mem_object_type mem_type = CL_MEM_OBJECT_IMAGE1D_ARRAY;
        typedef cl::Image1DArray climage_type;

        static constexpr cl_int dim_info[N] =
            { CL_IMAGE_WIDTH, CL_IMAGE_ARRAY_SIZE };
    };

    template <>
    struct cl_image_traits<cl::Image2D>
    {
        static constexpr std::size_t N = 2;
        static constexpr bool is_array = false;
        static constexpr cl_mem_object_type mem_type = CL_MEM_OBJECT_IMAGE2D;
        typedef cl::Image2D climage_type;

        static constexpr cl_int dim_info[N] =
            { CL_IMAGE_WIDTH, CL_IMAGE_HEIGHT };
    };

    template <>
    struct cl_image_traits<cl::Image2DArray>
    {
        static constexpr std::size_t N = 3;
        static constexpr bool is_array = true;
        static constexpr cl_mem_object_type mem_type = CL_MEM_OBJECT_IMAGE2D_ARRAY;
        typedef cl::Image2DArray climage_type;

        static constexpr cl_int dim_info[N] =
            { CL_IMAGE_WIDTH, CL_IMAGE_HEIGHT, CL_IMAGE_ARRAY_SIZE };
    };

    template <>
    struct cl_image_traits<cl::Image3D>
    {
        static constexpr std::size_t N = 3;
        static constexpr bool is_array = false;
        static constexpr cl_mem_object_type mem_type = CL_MEM_OBJECT_IMAGE3D;
        typedef cl::Image3D climage_type;

        static constexpr cl_int dim_info[N] =
            { CL_IMAGE_WIDTH, CL_IMAGE_HEIGHT, CL_IMAGE_DEPTH };
    };

}

#endif /* end of include guard: CL_IMAGE_TRAITS_HPP_NO43KYUP */
