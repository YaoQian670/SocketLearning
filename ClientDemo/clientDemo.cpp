// clientDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
2016-9-28 12:11:41
@author:CodingMengmeng
language:C;
*/

//Client.
#include <stdio.h>                      //用于输入、输出函数的调用,printf, gets
#include <winsock2.h>                   //socket头文件
#include <Windows.h>                    //为了方便调试，所以加入了等待2秒才进行连接server，这里用到了sleep函数
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32")         //socket库文件

int main()
{
	Sleep(2000);                        //沉睡2秒再连接server
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	sockaddr_in sockaddr;//描述服务器socket地址
	sockaddr.sin_family = PF_INET;
	//sockaddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	InetPton(PF_INET, TEXT("10.140.58.39"), &sockaddr.sin_addr);
	sockaddr.sin_port = htons(9000);
	connect(s, (SOCKADDR*)& sockaddr, sizeof(SOCKADDR));//s:客户端的socket描述字；sockaddr：服务器的socket地址；sizeof(SOCKADDR)：服务器socket地址的长度
	char buffer[MAXBYTE] = { 0 };
	recv(s, buffer, MAXBYTE, NULL);
	printf("***SERVER*** SEND:%s", buffer);
	while (TRUE)
	{
		memset(buffer, 0, sizeof(buffer));
		char* mymsg = new char[100000];
		printf("Say something to Server:\n");
		gets_s(mymsg,100000);//获取屏幕输入
		send(s, mymsg, strlen(mymsg) + sizeof(char), NULL);//发送给服务器

		/*if (mymsg[0] == 'q')
			break;*/
		recv(s, buffer, MAXBYTE, NULL);//接收服务器回传的响应，若未响应，则一直等待。
		printf("***Receive From Server***:    %s\n", buffer);


		/*
		recv函数中的bufferlength参数是可以固定值的
		send函数中的bufferlength参数不能固定值，需要看实际长度，并且考虑到'\0'字符串
		*/
	}
	closesocket(s);        //关闭客户端socket
	WSACleanup();        //卸载
	getchar();
	exit(0);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
