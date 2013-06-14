//      Copyright Alexander Kondratskiy 2012 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <imcl/transfer_queue.h>
#include <imcl/image_base.hpp>

namespace imcl
{

    transfer_queue::transfer_queue(cl::Context const& context, cl::Device const& device)
        : queue(context, device)
    { }

    void transfer_queue::enqueue_write_image(
            cl::Image const& image,
            image_region const& region,
            void* data
            // TODO: some kind of event monad?
        )
    {
        // TODO: make asynchronous
        queue.enqueueWriteImage(
                image,
                CL_BLOCKING,
                region.origin,
                region.dims,
                0,
                0,
                data
            );
    }

    void transfer_queue::enqueue_read_image(
            cl::Image const& image,
            image_region const& region,
            void* data
        )
    {
        // make asynchronous
        queue.enqueueReadImage(
                image,
                CL_BLOCKING,
                region.origin,
                region.dims,
                0,
                0,
                data
            );
    }
    
} /* imcl */ 
