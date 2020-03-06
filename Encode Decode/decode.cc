//Alexander Smith
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>

using namespace std;

const int BUFFER_SIZE = 80;

struct Decoded
{
	int key;
	char message [BUFFER_SIZE];
};

int main()
{
	int key;
	Decoded decoded_data;
	char input_buffer[BUFFER_SIZE];

	ifstream infile("coded_message.txt", ios::in | ios::binary);

	if (!infile)
	{
		cerr << "Cannot open file."<<endl;
		return 2;
	}
	char c;
	if (infile.is_open())
	{
		while(infile.peek()!=EOF)
		{
			infile.read((char *) &decoded_data,sizeof(decoded_data));
			//cout<<decoded_data.message<<endl;
			for(int i=0; i < BUFFER_SIZE; i++)
			{
				decoded_data.message[i] = decoded_data.message[i]-decoded_data.key-i; //i + key + input_buffer[i];
				//cout<<int(decoded_data.message[i])<<endl;
			}
			cout<<decoded_data.message<<endl;	
		}

		
       
    }   
	infile.close();
	return 0;
}