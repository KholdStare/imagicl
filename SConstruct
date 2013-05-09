import os
import platform

env = Environment()  # Initialize the environment
env.Append(CPPFLAGS = [ '-O3', '-Wall', '-Werror', '-std=c++0x' ])
env.Append(LIBS = [ 'pthread',
            'boost_unit_test_framework',
            'OpenCL', ])

# debugging flags
debugflags = [ '-g', '-pg' ]
env.Append(CPPFLAGS =  debugflags)
env.Append(LINKFLAGS = debugflags)
	
bits = 'x86_64'
if platform.machine() != bits:
    bits = 'x86'

# AMD OpenCL SDK paths
if os.environ['AMDAPPSDKROOT']:
    sdkroot = os.environ['AMDAPPSDKROOT']
    env.Append(CPPPATH = [ sdkroot + '/include' ])
    env.Append(LIBPATH = [ sdkroot + '/lib/' + bits ])

# local include path
env.Append(CPPPATH = [ './include' ])

libSources = Glob('./src/*.cpp')
testSources = Glob('./test/test_*.cpp')

for test in testSources:
    outputName = os.path.basename(test.name)[:-4]
    inputSources = libSources + [test]
    env.Program(outputName, inputSources)
