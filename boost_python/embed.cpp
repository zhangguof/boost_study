//python embed test.

#define BOOST_PYTHON_STATIC_LIB //ʹ�þ�̬��,Ĭ��ʹ��dll��
//#define BOOST_PYTHON_SOURCE	//Դ�������Ҫ��


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

