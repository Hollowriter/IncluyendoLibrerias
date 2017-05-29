#include<iostream>
#include<cassert>
#include<cstdlib>
#include<new>
#include<exception>
#include<fstream>
#include<vector>
#include<string>
#include"rapidxml.hpp"
#include"rapidxml_print.hpp"
#include"SFML/Network.hpp"
using namespace std;
using namespace rapidxml;
void main() {
	cout << "Comencing parsing document test..." << endl;
	xml_document<> thyDoc;
	xml_node<> * normal_node;
	/*ifstream thyText("D:\Desktop\Repo\IncluyendoLibrerias\Prueba.xml");
	thyText.open("Prueba.xml", ifstream::in);
	cout << thyText.is_open() << endl;
	vector<char> buffer((istreambuf_iterator<char>(thyText)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	thyDoc.parse<0>(&buffer[0]);
	normal_node = thyDoc.first_node("query");
	printf("%s", normal_node->first_attribute("xmlns:yahoo")->value());
	for (xml_node<> * channel_node = normal_node->first_node("results"); channel_node; channel_node = channel_node->next_sibling()){
	}
	cout << endl;*/
	cout << "parsing succeded" << endl;
	cin.get();
}