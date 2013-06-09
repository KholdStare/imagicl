//      Copyright Alexander Kondratskiy 2012 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <imcl/transfer_queue.h>

namespace imcl
{

    struct transfer_queue::transfer_queue(cl::Context const& context, cl::Device const& device)
        : queue(context, device)
    { }
    
} /* imcl */ 
