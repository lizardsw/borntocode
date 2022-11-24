#include "convert.hpp"

Convert::Convert()
{
}

Convert::Convert(const Convert &copy)
{
}

Convert::Convert(const char *input)
{
	this->input = input;
	this->s_input = std::string(input);
	for(int i = 0; i < 4; i++)
	{
		this->error[i] = false;
	}
}

Convert &Convert::operator=(const Convert &copy)
{
}

Convert::~Convert()
{
}

void Convert::convert_char()
{
	if(this->s_input.length() == 1)
	{
		if(std::isdigit(input[0])) // 한자리수 int
		{	
			int temp = std::atoi(input[0]);
			this->char_value = static_cast<char>(temp);
		}
		else // 한자리수 char
			this->char_value = static_cast<char>(input[0]);
	}
	else
	{
		if (!(s_input.find(".") == std::string::npos)) // double, float
		{
			if (!(s_input.find("f") == std::string::npos)) // float
			{
				float temp = static_cast<float>(std::strtod(this->input, NULL));
				if (temp > 127 || temp < 0)
					this->error[0] = true;
				else
					this->char_value = static_cast<char>(temp);
			}
			else // double
			{
				double temp = std::strtod(this->input, NULL);
				if (temp > 127 || temp < 0)
					this->error[0] = true;
				else
					this->char_value = static_cast<char>(temp);
			}
		}
		else // int
		{
			long temp = std::strtol();
			if (temp > 127 || temp < 0)
				this->error[0] = true;
			else
				this->char_value = static_cast<char>(temp);
		}
	}
}

void Convert::convert_int()
{
	if(this->s_input.length() == 1)
	{
		if(std::isdigit(input[0])) // 한자리수 int
		{	
			int temp = std::atoi(input[0]);
			this->int_value = static_cast<int>(temp);
		}
		else // 한자리수 char
			this->int_value = static_cast<int>(my_string[0]);
	}
	else
	{
		if (!(s_input.find(".") == std::string::npos)) // double, float
		{
			if (!(s_input.find("f") == std::string::npos)) // float
			{
				float temp = static_cast<float>(std::strtod(this->input, NULL));
				if (temp > 127 || temp < 0)
					this->error[1] = true;
				else
					this->int_value = static_cast<char>(temp);
			}
			else // double
			{
				double temp = std::strtod(this->input, NULL);
				if (temp > 127 || temp < 0)
					this->error[1] = true;
				else
					this->int_value = static_cast<char>(temp);
			}
		}
		else // int
		{
			int temp = std::atoi(this->input);
			if (temp > 127 || temp < 0)
				this->error[1] = true;
			else
				this->int_value = static_cast<char>(temp);
		}
	}
}

void Convert::convert_float()
{
	
}

void Convert::convert_double()
{
	
}