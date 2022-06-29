#include "Math/mathUtils.h"
#include "Core/memory.h"
#include <iostream>


using namespace std;

int main()
{
	vl::InitializeMemory();

	cout << "c++ Hoi!\n";
	//cout << math::sqr(9) << endl;
	//cout << math::half(10) << endl;

	// weird and dumb old way of memory allocation
	void* vp = malloc(sizeof(int)); // point at something
	int* ip = (int*)vp; // convert something into an int
	cout << *ip << endl;
	free(vp); // return the memory

	// old c++ of memory allocation (ok for small programs)
	int* p = new int(10);
	*p = 12;
	cout << p << endl;
	cout << *p << endl;
	delete p;

	// cool hip new way of memory allocation (deallocates themselves)
	{
		unique_ptr<float> uf = make_unique<float>(12.5f);
		cout << *uf << endl;
		unique_ptr<float> uf2 = move(uf); // changes ownership to uf2

		shared_ptr<float> sp = make_shared<float>(19.3f);
		shared_ptr<float> sp2 = sp;
		cout << *sp << endl;
		cout << *sp2 << endl;
		
	}
}