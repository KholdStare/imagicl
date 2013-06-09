//      Copyright Alexander Kondratskiy 2012 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <imcl/context.h>

namespace
{

    /* Find a GPU or CPU associated with the first available platform */
    void createDevices(std::vector<cl::Device>& devices)
    {
        std::vector<cl::Platform> platforms;

        /* Identify a platform */
        cl::Platform::get(&platforms);
        cl::Platform platform = platforms[0];

        /* Gather devices */
        try {
            platform.getDevices(CL_DEVICE_TYPE_GPU, &devices);
        }
        catch (cl::Error& e) {
            platform.getDevices(CL_DEVICE_TYPE_CPU, &devices);
        }
    }

    // TODO: actually get best device
    cl::Device getBestDevice()
    {
        std::vector<cl::Device> devices;
        createDevices(devices);

        return devices[0];
    }

}

namespace imcl
{

    compute_context::compute_context()
        : device(getBestDevice()),
          context(device), 
          transfer_q(context, device),
          computation_q(context, device)
    { }

}
