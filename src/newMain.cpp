

#include <memory>
#include <iostream>
#include <string>
#include "../containers/vector.hpp"


int main(void)
{

	ft::vector<int>		ft_vec;
	ft::vector<int> second (3, 40);                       // four ints with value 100


	// std::allocator<int> alloc;

	// // demonstrating the few directly usable members
	// int* p = alloc.allocate(2);  // space for one int
	

	// for (int i = 0; i <= 2; i++){
	// 	p[i] = i + 1;
	// 	std::cout << p[i] << std::endl;
	// }

	// alloc.destroy(&p[0]);
	// alloc.deallocate(p, 1);      // and it is gone

}