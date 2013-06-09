//      Copyright Alexander Kondratskiy 2012 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TRANSFER_QUEUE_H_PQKXNW7M
#define TRANSFER_QUEUE_H_PQKXNW7M

#include <imcl/cl.h>

namespace imcl
{

    /**
     * A queue used solely for data transfers between host/device
     */
    struct transfer_queue
    {
        cl::CommandQueue const queue;

        transfer_queue(cl::Context const&, cl::Device const&);
    };
    
} /* imcl */ 

#endif /* end of include guard: TRANSFER_QUEUE_H_PQKXNW7M */

