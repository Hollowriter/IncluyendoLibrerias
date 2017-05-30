#include<iostream>
#include<cassert>
#include<cstdlib>
#include<new>
#include<exception>
#include<fstream>
#include<vector>
#include<string>
#include"rapidxml.hpp" // intento con XML
#include"rapidxml_print.hpp" // intento con XML
#include"json.hpp"
#include"SFML/Network.hpp"
using namespace std;
using namespace rapidxml;
void main() {
	cout << "Comencing parsing" << endl;
	/*xml_document<> thyDoc;
	xml_node<> * normal_node;
	xml_node<> * results_node;
	xml_node<> * channel_node;
	xml_node<> * item_node;
	xml_node<> * weather_node;*/ // intento con XML
	sf::Http http("http://query.yahooapis.com/");
	sf::Http::Request requesting;
	requesting.setUri("/v1/public/yql?q=select%20item.condition.text%20from%20weather.forecast%20where%20woeid%20in%20(select%20woeid%20from%20geo.places(1)%20where%20text%3D%22buenos%20aires%22)&format=json&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys");
	sf::Http::Response answer = http.sendRequest(requesting);
	nlohmann::json jdata = nlohmann::json::parse(answer.getBody().c_str());
	cout << jdata["query"]["results"]["channel"]["item"]["condition"]["text"] << endl; // finalmente use JSON
	/* ofstream thyText("D:\Desktop\Repo\IncluyendoLibrerias\Prueba.xml");
	cout << thyText.is_open() << endl;
	thyText.open("Prueba.xml", ofstream::in);
	cout << thyText.is_open() << endl;
	thyText << answer.getBody() << endl;
	thyText.close();
	ifstream thyReadings("D:\Desktop\Repo\IncluyendoLibrerias\Debug\Prueba.xml");
	thyReadings.open("Prueba.xml", ifstream::in);
	vector<char> buffer((istreambuf_iterator<char>(thyReadings)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	thyDoc.parse<0>(&buffer[0]);
	normal_node = thyDoc.first_node("query")->first_node("results")->first_node("channel")->first_node("item")->first_node("yweather:condition");
	cout << "the weather is... " << normal_node->last_attribute("text")->value() << endl;
	thyDoc.parse<0>();*/
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
	cout << endl;*/ // intento con XML
	// thyReadings.close();
	cout << "parsing succeded" << endl;
	cin.get();
}