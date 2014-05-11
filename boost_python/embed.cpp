//python embed test.
//#pragma comment(lib,"python27.lib")
//#pragma comment(lib,"libboost_python-vc100-mt-1_54.lib")

#define BOOST_PYTHON_STATIC_LIB


#include <boost/python.hpp>
#include <boost/noncopyable.hpp>

#include <iostream>
using namespace boost::python;

class pyinit:boost::noncopyable
{
public:
	pyinit(int initsigs=1)
	{
		assert(initsigs == 0 || initsigs == 1);
		Py_InitializeEx(initsigs);
	}
	~pyinit(){}

	bool isInitialized()
	{
		return Py_IsInitialized();
	}


};

int main(){
	pyinit *p = new pyinit();
	std::cout<<p->isInitialized()<<std::endl;
	return 0;
}

