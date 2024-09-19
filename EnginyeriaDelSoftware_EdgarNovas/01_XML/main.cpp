#include "dep/inc/xml/rapidxml.hpp"
#include "dep/inc/xml/rapidxml_print.hpp"
#include "dep/inc/xml/rapidxml_utils.hpp"
#include "dep/inc/xml/rapidxml_iterators.hpp"

#include <sstream>

#include <iostream>

int main(){

	//1 Create an XML document to read an XML file

	rapidxml::xml_document<> doc;
	
	//rapidxml::xml_node<> firstnode;
	std::ifstream file("bookstore.xml");


	//2Create a buffer so it wont have to read each character from disk

	std::stringstream buffer;


	//3 Put the file in the buffer (optimization)
	buffer << file.rdbuf();



	//4 The file is inside the buffer, so we can close it

	file.close();


	//5 Construct a string with all the buffer's content (file)

	std::string content(buffer.str());


	//6 

	doc.parse<0>(&content[0]);




	//7 Print the roots name and text

	//rapidxml::xml_node<>* root = doc.first_node();

	//std::cout << "Name: " << root->first_node()->first_node()->name() << std::endl;
	//std::cout << "Value: " << root->first_node()->first_node()->value() << std::endl;

	//PRINT ALL THE BOOK ELEMENTS WITHOUT ATTRIBUTES

	//1) Declare root node

	rapidxml::xml_node<>* pRoot = doc.first_node();

	//2) Iterate through the root's children
	
	for (rapidxml::xml_node<>* pNode = pRoot->first_node("book");
		pNode; //same as pNode is not null
		pNode = pNode->next_sibling())
	{
		std::cout << pNode->name() << ':' << '\n';

		//3) Iterate through the child's children

		for (rapidxml::xml_node<>* pNodeI = pNode->first_node();
			pNodeI; //If this pointer is null we go out of the for
			pNodeI = pNodeI->next_sibling())
		{
			std::cout << pNodeI->name() << ':' << pNodeI->value() << '\n';
		}
		
		std::cout << '\n';

	}




	return 0;

}