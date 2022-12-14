#pragma once
#include <iostream>
#include <iomanip>
#include <limits>
#include "Contact.hpp"

class Phonebook
{
public:
	
	// Constructors & Destructor
	Phonebook();
	~Phonebook();

	// Getters
	Contact getContact(int index) const;
	int		getCount() const;

	// Setters
	void setContact(Contact contact);

private:

	static int		_count;

	Contact _contacts[8];
	int		_index;
};