#include "chatroom.h"

int main()
{
	//acquire user name
	User user;
	cout << "Name: ";// TO BE REMOVED
	char name[20];
	cin >> name;
	if (!user.SetName(name))
	{
		cout << "Name again: ";
		cin >> name;
	}

	//initialize client socket
	user.InitializeClient();
	user.CreateClientSocket();
	user.ConnectClientSocket(); //TO DO : IS SERVER ONLINE? CONNECTION LOST
	
	//threads to input and output logs
	thread InputThread(&User::Input, user);
	thread OutputThread(&User::Output, user);
	InputThread.join();
	OutputThread.join();

	//close client socket
	user.CloseClientSocket();

	return 0;
}