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
using namespace std;
using namespace rapidxml;
void main() {
	cout << "Comencing parsing document test..." << endl;
	xml_document<> thyDoc;
	string cosa;
	xml_node<> * normal_node;
	ifstream thyText("C:/Users/822/Desktop/IncluyendoLibrerias/Debug/Prueba.xml");
	// cout << thyText.is_open() << endl;
	/*while (getline(thyText, cosa))
	{
		cout << cosa << '\n';
	}
	thyText.close();*/
	vector<char> buffer((istreambuf_iterator<char>(thyText)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	thyDoc.parse<0>(&buffer[0]);
	normal_node = thyDoc.first_node("query");
	cout << normal_node->first_attribute()->value();

	for (xml_node<> * channel_node = normal_node->first_node("query"); channel_node; channel_node = channel_node->next_sibling()) 
		// Probando con el debugger, aca me tira un error en tiempo de ejecucion
	{
		printf("showing data now....");
		printf("here is the page that made us suffer: %s",
			channel_node->first_attribute("xmlns:yahoo")->value());
	}
	cout << endl;
	cout << "parsing succeded" << endl;
	cin.get();
}