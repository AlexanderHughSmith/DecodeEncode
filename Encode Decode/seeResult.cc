#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

const int BUFFER_SIZE = 80;

struct Encoded
{
	int key;
	char message [BUFFER_SIZE];
};

int main()
{
	int key;
	Encoded encoded_data;
	char input_buffer[BUFFER_SIZE];




	cout <<"Enter a positive integer for a key: ";
	cin>>key;

	while (key > 0)
	{
		cout<<"Enter one line of the message: ";
		cin.ignore();
		cin.getline(input_buffer, BUFFER_SIZE);
		cerr<<"Have Message: "<<input_buffer<<endl;
		encoded_data.key = key;
		for (int i=0; i < sizeof(input_buffer); i++)
		{
			encoded_data.message[i] = i + key + input_buffer[i];
			cout<<i<<"i= "<<i<<"key="<<key<<"buffer="<<input_buffer[i]<<"-"<<int(input_buffer[i])<<endl;
			cout<<i<<"total: "<<i + key + input_buffer[i]<<endl;
		}
		cout<<sizeof(encoded_data);
		cout<<"Enter next key (0 to stop): ";
		cin>>key;
		cerr<<"Have Key: "<<key<<endl;
	}
	return 0;
}