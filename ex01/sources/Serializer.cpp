#include "Serializer.hpp"

Serializer::Serializer(void) {
}

Serializer::Serializer(Serializer const &src) {
	(void)src;
}

Serializer &Serializer::operator=(Serializer const &rhs) {
	if (this != &rhs)
		(void)rhs;
	return (*this);
}

Serializer::~Serializer(void) {
}


uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}