#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

class Convert
{
	private:
		const char *input;
		std::string s_input;
		bool error[4];
		char char_value;
		int int_value;
		float float_value;
		char *float_str;
		double double_value;
	public:
		Convert();
		Convert(const char *input);
		Convert(const Convert &copy);
		Convert &operator::=(const Convert &copy);
		~Convert();
		void convert_char();
		void convert_int();
		void convert_float();
		void convert_double();
}



#endif