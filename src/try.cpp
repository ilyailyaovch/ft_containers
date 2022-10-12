

#include <memory>
#include <iostream>
#include <string>


// int main(void)
// {
// 	std::allocator<int> alloc;

// 	// demonstrating the few directly usable members
// 	int* p = alloc.allocate(2);  // space for one int
	

// 	for (int i = 0; i <= 2; i++){
// 		p[i] = i + 1;
// 		std::cout << p[i] << std::endl;
// 	}

// 	alloc.destroy(&p[0]);
// 	alloc.deallocate(p, 1);      // and it is gone

// }