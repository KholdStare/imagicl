#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
//#include <boost/test/test_case_template.hpp>
//#include <boost/mpl/list.hpp>
//#include <random>

#include <imcl/context.h>

BOOST_AUTO_TEST_CASE( context_create_test )
{
    using namespace std;

    imcl::compute_context c;

    BOOST_CHECK( c.context() != nullptr );
}
