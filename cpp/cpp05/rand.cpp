#include <ctime>
#include <cstdlib>
#include <iostream>






int main()
{
	std::cout << (unsigned int)std::time(NULL) << std::endl; 
	std::srand((unsigned int)std::time(NULL));
	for (int i = 0; i < 10; i++)
	{
		std::cout << (unsigned int)std::time(NULL) << std::endl;
		std::cout << std::rand() << std::endl;;
		int temp = std::rand() % 2;
		std::cout << temp << std::endl;
	}

	
    for (int i = 0; i < 20; ++i)
    {
		std::srand((unsigned int)std::time(NULL));
        int num = std::rand();
        printf("난수 : %d\t나머지 : %d\n", num, (int)num % 10);
    }
    system("pause");
	
	return 0;
}