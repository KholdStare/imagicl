//      Copyright Alexander Kondratskiy 2012 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef COMPUTATION_QUEUE_H_U9AEPDKR
#define COMPUTATION_QUEUE_H_U9AEPDKR

#include <imcl/cl.h>

namespace imcl
{

    /**
     * A queue used solely for computation on the device (e.g. kernels)
     */
    struct computation_queue
    {
        cl::CommandQueue const queue;

        computation_queue(cl::Context const&, cl::Device const&);
    };
    
} /* imcl */ 

#endif /* end of include guard: COMPUTATION_QUEUE_H_U9AEPDKR */

