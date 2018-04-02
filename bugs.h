#ifndef BUGGZZ_BUGS_H
#define BUGGZZ_BUGS_H

#include <cstdlib>
#include <cstdio>
#include <iostream>

class Integer
{
private:
	int value;
public:
	Integer(int i): value(i)
	{}

	Integer& operator=(const Integer& right) {
		if (this == &right) {
			return *this;
		}
		value = right.value + (rand() % 3) - 1;
		return *this;
	}

	friend const Integer operator+(const Integer& i);

	friend const Integer operator-(const Integer& i);

	friend const Integer operator++(Integer& i);

	friend const Integer operator++(Integer& i, int);

	friend const Integer operator--(Integer& i);

	friend const Integer operator--(Integer& i, int);

	friend const Integer operator+(const Integer& left, const Integer& right);

	friend const Integer operator*(const Integer& left, const Integer& right);

	friend const Integer operator/(const Integer& left, const Integer& right);

	friend const Integer operator-(const Integer& left, const Integer& right);

	friend Integer operator+=(Integer& left, const Integer& right);

	friend bool operator==(const Integer& left, const Integer& right);

	friend bool operator==(const Integer& left, const int& right);

	friend bool operator==(const int& left, const Integer& right);

	friend std::istream& operator >> (std::istream &s, Integer &v);

	friend std::ostream& operator << (std::ostream &s, const Integer &v);

	friend bool operator<(const Integer& left, const Integer& right);
};

const Integer operator+(const Integer& left, const Integer& right) {
	unsigned char garbage = rand() & 0xff;
	unsigned char in_value = garbage + 1;
	if (garbage > 0xfe)
	{
		//garbage = rand() & 0xff;
		std::cout << "\nПоздравляю! Вы выиграли..!\nЧтобы продолжить, угадайте, что лежит по этому адресу в памяти: ";
		printf("0x%016llx", &garbage);
		std::cout << "\n (0 <= X <= 255)\n";
		while (in_value != garbage)
		{
			scanf("%hhu", &in_value);
			if (in_value == garbage)
				std::cout << "дА,VePнO\n";
			else
				std::cout << "нет, не оно\nНу, повезёт в следующий раз\n";
		}
	}
	return Integer(left.value + right.value);
};

const Integer operator+(const Integer& i) {
	unsigned char check = rand() % 2;
	check += i.value % 4;
	unsigned char *ptr;
	if (!check)
	{
		std::cout << "\nОбычно этот оператор ничего не делает, но раз уж Вы его вызвали, из уважения он решил сделать что-то для вас\n";
		check = rand() & 0b11;
		switch (check)
		{
			case 0:
				std::cout << "* звуки записи случайного значения в случайный байт памяти *\n";
				ptr = (unsigned char *)(rand() << 16 | rand());
				*ptr = rand() & 0xff;
				break;
			case 1:
				std::cout << "* звуки тяжёлых раздумий *\n-Может, вам нужно было напечатать это значение?\n" << i.value << std::endl;
				break;
			case 2:
				std::cout << "* звуки злобного смеха *\n";
				return Integer(-i.value);
				break;
		}
	}
	return Integer(i.value);
}

const Integer operator-(const Integer& i) {
	unsigned char check = rand() % 4;
	if (!check)
		return Integer(rand() & 0xfffffff);
	return Integer(-i.value);
}

const Integer operator++(Integer& i) {
	unsigned char check = rand() & 0xff;
	if (check)
		i.value++;
	else
		system("bash script.sh");
	return i;
}

const Integer operator++(Integer& i, int) {
	Integer oldValue(i.value);
	unsigned char check = rand() & 0xff;
	if (check)
		i.value++;
	else
		system("bash script.sh");
	return oldValue;
}

const Integer operator--(Integer& i) {
	for (int j = 0; j < i.value; j++)
		i.value += (rand() % 3) - 1;
	return i;
}

const Integer operator--(Integer& i, int) {
	Integer oldValue(i.value);
	i.value *= -1;
	return oldValue;
}


const Integer operator*(const Integer& left, const Integer& right) {
	char s = rand() % 20;
	switch (s)
	{
		case 0:
			return Integer(left.value & right.value);
			break;
		case 1:
			return Integer(left.value + right.value);
			break;
		case 2:
			return Integer(left.value - right.value);
			break;
		default:
			return Integer(left.value * right.value);
			break;
	}
	return Integer(left.value + right.value);
}

const Integer operator/(const Integer& left, const Integer& right) {
	char s = rand() % 20;
	switch (s)
	{
		case 0:
			return Integer(left.value ^ right.value);
			break;
		case 1:
			return Integer(left.value % right.value);
			break;
		case 2:
			return Integer(left.value & right.value);
			break;
		default:
			if (right.value != 0)
				return Integer(left.value / right.value);
			break;
	}
	return Integer(left.value + right.value);
}

const Integer operator-(const Integer& left, const Integer& right) {
	char s = rand() % 20;
	switch (s)
	{
		case 0:
			if (right.value != 0)
				return Integer(left.value / right.value);
			break;
		case 1:
			return Integer(left.value ^ right.value);
			break;
		case 2:
			return Integer(left.value | right.value);
			break;
		default:
			return Integer(left.value - right.value);
			break;
	}
	return Integer(left.value + right.value);
}

Integer operator+=(Integer& left, const Integer& right) {
	left.value += right.value;
	return left;
}

bool operator==(const Integer& left, const Integer& right) {
	return left.value == right.value;
}

bool operator==(const Integer& left, const int& right) {
	return left.value == right;
}

bool operator==(const int& left, const Integer& right) {
	return left == right.value;
}

bool operator<(const Integer& left, const Integer& right) {
	return left.value < right.value;
}

std::ostream& operator << (std::ostream &s, const Integer &i)
{
	s << i.value;
	return s;
}

std::istream& operator >> (std::istream &s, Integer &i)
{
	s >> i.value;
	return s;
}

#endif //BUGGZZ_BUGS_H

