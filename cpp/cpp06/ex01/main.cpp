#include "iostream"

struct Data
{
	int int_mem;
	char char_mem;
};

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main()
{
	Data A;

	A.int_mem = 42;
	A.char_mem = '4';

	std::cout << "data char : " << A.char_mem << std::endl;
	std::cout << "data int : " << A.int_mem << std::endl;

	uintptr_t A_ptr = serialize(&A);
	std::cout << A_ptr << std::endl;
	Data *A_data = deserialize(A_ptr);

	std::cout << "data char : " << A_data->char_mem << std::endl;
	std::cout << "data int : " << A_data->int_mem << std::endl;

	return (0);
}