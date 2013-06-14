//      Copyright Alexander Kondratskiy 2012 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

/**
 * \file Header for all cl related errata and helpers
 */

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

namespace imcl
{
    /**
     * Returns a helpful error message string representing
     * the OpenCL error code
     */
    char const* cl_error_to_str(cl_int err);


    /***************************************************************************
     *                           cl::Vector helpers                            *
     ***************************************************************************/

    namespace detail
    {

        template<typename Vec>
        void vector_constructor_impl(Vec& vec)
        { }

        // only works for non-array arguments
        template<typename Vec, typename U, typename... Us>
        void vector_constructor_impl(Vec& vec, U&& first, Us&&... rest)
        {
            vec.push_back(std::forward<U>(first));
            vector_constructor_impl(vec, std::forward<Us>(rest)...);
        }

    }

    /**
     * Allows inplace construction of cl::vectors,
     * without having to manually push_back values.
     * 
     * For example, to construct a cl::size_t of 3 elements, do:
     *
     *     vector_constructor<size_t>::construct(0, 0, 0)
     *
     */
    template <typename T>
    struct vector_constructor
    {

        template <typename... Ts>
        static cl::vector<T, sizeof...(Ts)>
        construct(Ts&&... args)
        {
            cl::vector<T, sizeof...(Ts)> vec;
            detail::vector_constructor_impl(vec, std::forward<Ts>(args)...);
            return vec;
        }

    };

    /**
     * Specialization for size_t.
     *
     * cl::Vectors for size_t are actually cl::size_t.
     */
    template <>
    struct vector_constructor<typename ::size_t>
    {

        template <typename... Ts>
        static cl::size_t<sizeof...(Ts)>
        construct(Ts&&... args)
        {
            cl::size_t<sizeof...(Ts)> vec;
            detail::vector_constructor_impl(vec, std::forward<Ts>(args)...);
            return vec;
        }

    };

} /* imcl */ 

#endif /* end of include guard: CL_H_AGYTVCTU */
