﻿#include <string.h>
#include <iostream>

// Define the maximum length for the name to use.
// Specify the length of characters in the content (Excluding the terminator).
#define MAX_NAME_LEN 30
#define MAX_TITLE_LEN 50

struct Author
{
	char name[MAX_NAME_LEN + 1];

	void setName(char nameToSet[MAX_NAME_LEN])
	{
		strncpy(name, nameToSet, MAX_NAME_LEN);
		// overwrite the last character
		name[MAX_NAME_LEN] = '\0';
	}

	void print()
	{
		std::cout << name << std::endl;
	}
};

struct Book
{
	int id;
	char title[MAX_TITLE_LEN + 1];

	int numAuthors;
	Author authors[5];

	void addAuthor(Author author)
	{
		// TODO: add an author to the container authors array.
		if (this->numAuthors == 5)
		{
			return;
		}
		for (int i = 0; i < this->numAuthors; i++)
		{
			if (!strcmp(this->authors[i].name, author.name))
				return;
		}
		this->authors[this->numAuthors] = author;
		this->numAuthors++;
	}

	void print()
	{
		std::cout << "Book #" << id << std::endl;
		std::cout << "------" << std::endl;
		std::cout << this->title << std::endl;

		// TODO: add all authors
		std::cout << "Authors: \n";
		for (int i = 0; i < numAuthors; i++)
			this->authors[i].print();
	}
};

void setBookName(Book& book, std::string name)
{
	strncpy_s(book.title, name.c_str(), MAX_TITLE_LEN);
	book.title[MAX_TITLE_LEN] = '\0';
}

int main()
{
	Book book1;
	Book book2;
	Book book3;
	Author author;

	// Load the data into books
	book1.id = 1;
	book1.numAuthors = 0;
	setBookName(book1, u8"The origin of truth (nu există, nu o căutați)");
	author.setName("Gusti");
	book1.addAuthor(author);

	book2.id = 2;
	book2.numAuthors = 0;
	setBookName(book2, "Arhanghelul Raul");
	author.setName("Ovidiu Eftimie");
	book2.addAuthor(author);

	book3.id = 3;
	book3.numAuthors = 0;
	setBookName(book3, "Factfulness");
	author.setName("Hans Rosling");
	book3.addAuthor(author);

	author.setName("Ola Rosling");
	book3.addAuthor(author);
	
	author.setName("Anna Rosling Ronnlund");
	book3.addAuthor(author);

	// Display the books
	book1.print();
	book2.print();
	book3.print();

	//Added book4
	Book book4;
	book4.id = 4;
	book4.numAuthors = 0;
	setBookName(book4, "Clean Architecture: A Craftsman's Guide to Software Structure and Design");
	author.setName("Robert C. Martin Series");
	book4.addAuthor(author);

	book4.print();
	return 0;
}