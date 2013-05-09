//      Copyright Alexander Kondratskiy 2012 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef CONTEXT_H_XQMRRUCO
#define CONTEXT_H_XQMRRUCO

#include <imcl/cl.h>

namespace imcl
{

    /**
     * Initializes the necessary handles to run OpenCL computations
     */
    struct compute_context
    {
        cl::Device const device;
        cl::Context const context;
        cl::CommandQueue const queue;

        compute_context();
    };
    
} /* imcl */ 



#endif /* end of include guard: CONTEXT_H_XQMRRUCO */

