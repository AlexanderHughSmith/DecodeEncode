#include <iostream>
#include <fstream>
#include <string.h>

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
	Decoded encoded_data;
	char input_buffer[BUFFER_SIZE];

	ifstream infile("coded_message.txt");

	if (!infile)
	{
		cerr << "Cannot open file."<<endl;
		return 2;
	}

	cout <<"What do you want to decode: ";
	cin>>key;
	string dm = "";
	char c;
	int i = key * -1;
	int zeros = 0;
	if (infile.is_open())
	{
	
        while(infile.good())
        {
        	i+=1;
            infile.get(c);
            /*
            if((c-i-5)>64 || (c-i-5)<-134 && (c-i-5)>-160 || (c-i-5)==32)
            {
            	cout<<char(c-i-5);
            }
            */
            cout<<"c: "<<c-i-5<<endl;
            cout<<endl;
            cout<<char(c-i-key)<<"-"<<int(c-i-key)<<endl;
            if(int(c-i-key)==0)
            	break;

    	}
    	cout<<endl;
    	cout<<"here"<<endl;
    	cout<<dm<<endl;
	}    
	infile.close();
	return 0;
}