// clientDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
2016-9-28 12:11:41
@author:CodingMengmeng
language:C;
*/

//Client.
#include <stdio.h>                      //�������롢��������ĵ���,printf, gets
#include <winsock2.h>                   //socketͷ�ļ�
#include <Windows.h>                    //Ϊ�˷�����ԣ����Լ����˵ȴ�2��Ž�������server�������õ���sleep����
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32")         //socket���ļ�

int main()
{
	Sleep(2000);                        //��˯2��������server
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	sockaddr_in sockaddr;//����������socket��ַ
	sockaddr.sin_family = PF_INET;
	//sockaddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	InetPton(PF_INET, TEXT("10.140.58.39"), &sockaddr.sin_addr);
	sockaddr.sin_port = htons(9000);
	connect(s, (SOCKADDR*)& sockaddr, sizeof(SOCKADDR));//s:�ͻ��˵�socket�����֣�sockaddr����������socket��ַ��sizeof(SOCKADDR)��������socket��ַ�ĳ���
	char buffer[MAXBYTE] = { 0 };
	recv(s, buffer, MAXBYTE, NULL);
	printf("***SERVER*** SEND:%s", buffer);
	while (TRUE)
	{
		memset(buffer, 0, sizeof(buffer));
		char* mymsg = new char[100000];
		printf("Say something to Server:\n");
		gets_s(mymsg,100000);//��ȡ��Ļ����
		send(s, mymsg, strlen(mymsg) + sizeof(char), NULL);//���͸�������

		/*if (mymsg[0] == 'q')
			break;*/
		recv(s, buffer, MAXBYTE, NULL);//���շ������ش�����Ӧ����δ��Ӧ����һֱ�ȴ���
		printf("***Receive From Server***:    %s\n", buffer);


		/*
		recv�����е�bufferlength�����ǿ��Թ̶�ֵ��
		send�����е�bufferlength�������̶ܹ�ֵ����Ҫ��ʵ�ʳ��ȣ����ҿ��ǵ�'\0'�ַ���
		*/
	}
	closesocket(s);        //�رտͻ���socket
	WSACleanup();        //ж��
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
