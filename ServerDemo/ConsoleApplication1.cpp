// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//

//#include <iostream>
//using namespace std;
//
//void main() {
//	cout << "meijie" << endl;
//}
//
//#include <memory>
//#include <iostream>
//
//class Bad
//{
//public:
//	std::shared_ptr<Bad> getptr() {
//		return std::shared_ptr<Bad>(this);
//	}
//	~Bad() { std::cout << "Bad::~Bad() called" << std::endl; }
//};
//
//int main()
//{
//	// �����ʾ����ÿ��shared_ptr����Ϊ�Լ��Ƕ�����е�������
//	std::shared_ptr<Bad> bp1(new Bad());
//	std::shared_ptr<Bad> bp2 = bp1->getptr();
//	// ��ӡbp1��bp2�����ü���
//	std::cout << "bp1.use_count() = " << bp1.use_count() << std::endl;
//	std::cout << "bp2.use_count() = " << bp2.use_count() << std::endl;
//}
//
//#include <memory>
//#include <iostream>
//
//struct Good : std::enable_shared_from_this<Good> // ע�⣺�̳�
//{
//public:
//	std::shared_ptr<Good> getptr() {
//		return shared_from_this();
//	}
//	~Good() { std::cout << "Good::~Good() called" << std::endl; }
//};
//
//int main()
//{
//	// ����������������������������ָ�������system("pause")֮ǰ����
//	{
//		std::shared_ptr<Good> gp1(new Good());
//		std::shared_ptr<Good> gp2 = gp1->getptr();
//		// ��ӡgp1��gp2�����ü���
//		std::cout << "gp1.use_count() = " << gp1.use_count() << std::endl;
//		std::cout << "gp2.use_count() = " << gp2.use_count() << std::endl;
//	}
//	system("pause");
//}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
//#include <iostream>
//using namespace std;
//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		int subLength = 0;
//		int currentOrigin = 0, currentEnd = 0, currentLength = 0;
//		for (currentEnd = 0; currentEnd < s.length(); currentEnd++) {
//			if (currentOrigin == currentEnd) {
//				currentLength = 1;
//			}
//			bool isEqual = false;
//			for (int i = currentOrigin; i < currentEnd; i++) {
//				if (s[i] == s[currentEnd]) {
//					isEqual = true;
//					currentOrigin = i + 1;
//					break;
//				}
//			}
//			if (isEqual == false) {
//				currentLength = currentEnd - currentOrigin + 1;
//			}
//			if (subLength < currentLength) {
//				subLength = currentLength;
//			}
//		}
//		return subLength;
//	}
//};
//
//int main() {
//	string s1 = " ";
//	Solution solution1;
//	cout << s1.length() << endl;
//	cout << solution1.lengthOfLongestSubstring(s1) << endl;
//}

//5. Longest Palindromic Substring

//
//char* longestPalindrome(char* s) {
//	int longestLength = 0, subStart = -1, subEnd = -1;
//	for (int i = 0; s[i] != '\0'; i++) {
//		if (i == 0) {
//			longestLength = 1;
//			subStart = 0;
//			subEnd = 0;
//		}
//		else {
//			int currentlongestLength1 = 1, currentsubStart1 = i, currentsubEnd1 = i;
//			int currentlongestLength2 = 1, currentsubStart2 = i, currentsubEnd2 = i;
//			if (s[i] == s[i - 1]) {
//				currentlongestLength1++;
//				currentsubStart1 = i - 1;
//				currentsubEnd1 = i;
//				for (int j = 2; ((i - j) > -1) && (s[i + j - 1] != '\0'); j++) {
//					if (s[i - j] == s[i + j - 1]) {
//						currentlongestLength1 += 2;
//						currentsubStart1 = i - j;
//						currentsubEnd1 = i + j - 1;
//					}
//					else {
//						break;
//					}
//				}
//				if (currentlongestLength1 > longestLength) {
//					longestLength = currentlongestLength1;
//					subStart = currentsubStart1;
//					subEnd = currentsubEnd1;
//				}
//			}
//			if (s[i - 1] == s[i + 1]) {
//				for (int j = 1; ((i - j) > -1) && (s[i + j] != '\0'); j++) {
//					if (s[i - j] == s[i + j]) {
//						currentlongestLength2 += 2;
//						currentsubStart2 = i - j;
//						currentsubEnd2 = i + j;
//					}
//					else {
//						break;
//					}
//				}
//				if (currentlongestLength2 > longestLength) {
//					longestLength = currentlongestLength2;
//					subStart = currentsubStart2;
//					subEnd = currentsubEnd2;
//				}
//			}
//		}
//	}
//	char* charP = (char*)malloc(longestLength + 1);
//	int z = 0;
//	if (charP != NULL) {
//		while (z < longestLength) {
//			charP[z] = s[subStart + z];
//			z++;
//		}
//		charP[z] = '\0';
//	}
//	return charP;
//}

//
//class Solution {
//public:
//	string convert(string s, int numRows) {
//		if (numRows == 1)
//			return s;
//		string *stringArray= new string[numRows];
//		int whichRow = 0;
//		bool downFlag = true;
//		for (int i = 0; i < s.length(); i++) {
//			stringArray[whichRow].push_back(s[i]);
//			if (whichRow == numRows - 1) {
//				downFlag = false;
//			}
//			if (whichRow == 0) {
//				downFlag = true;
//			}
//			if (downFlag) {
//				whichRow++;
//			}
//			else {
//				whichRow--;
//			}
//		}
//		string returnString;
//		for (int i = 0; i < numRows; i++) {
//			returnString = returnString + stringArray[i];
//		}
//		delete[] stringArray;
//		return returnString;
//	}
//};
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//class Partition {
//public:
//	ListNode* partition(ListNode* pHead, int x) {
//		// write code here
//		if (pHead == NULL)
//			return NULL;
//		ListNode* currentNode = pHead;
//		ListNode* leftListHead = NULL, * rightListHead = NULL;
//		ListNode *leftCurrentNode = NULL, * rightCurrentNode = NULL;
//
//		while (currentNode != NULL) {
//			if (currentNode->val < x) {
//				if (leftListHead == NULL) {
//					leftListHead = new ListNode(currentNode->val);
//					leftCurrentNode = leftListHead;
//				}
//				else {
//					leftCurrentNode->next = new ListNode(currentNode->val);
//					leftCurrentNode = leftCurrentNode->next;
//				}
//			}
//			else {
//				if (rightListHead == NULL) {
//					rightListHead = new ListNode(currentNode->val);
//					rightCurrentNode = rightListHead;
//				}
//				else {
//					rightCurrentNode->next = new ListNode(currentNode->val);
//					rightCurrentNode = rightCurrentNode->next;
//				}
//			}
//			currentNode = currentNode->next;
//		}
//		if (leftListHead == NULL)
//			return rightListHead;
//		if (rightListHead ==NULL)
//			return leftListHead;
//		leftCurrentNode->next = rightListHead;
//		return leftListHead;
//	}
//};
//
//class Solution {
//public:
//	vector<int> printMatrix(vector<vector<int> > mat, int n, int m) {
//
//		vector<int> result;
//		
//		if (mat.empty())
//			return result;
//	
//		int left = 0;
//		int right = m - 1;
//		int top = 0;
//		int btm = n - 1;
//		
//		while (left <= right && top <= btm) {             
//			for (int i = left; i <= right; ++i)                
//				result.push_back(mat[top][i]);      
//			
//			if (top < btm)                                
//				for (int i = top + 1; i <= btm; ++i) 
//					result.push_back(mat[i][right]); 
//			
//			if (top < btm && left < right)                 
//				for (int i = right - 1; i >= left; --i)    
//					result.push_back(mat[btm][i]);  
//			if (top + 1 < btm && left < right)            
//				for (int i = btm - 1; i >= top + 1; --i)      
//					result.push_back(mat[i][left]); 
//
//			++left; --right; ++top; --btm;
//		}
//		return result;
//	}
//};
//
//
//class Printer {
//public:
//	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
//		// write code here
//	}
//};
//
//namespace spaceA{
//	string s = "space A";
//}
//
//namespace spaceB {
//	string s = "space A";
//}
//
//void f1(int i) {
//	cout << i;
//}
//void f1(char c) {
//	cout << "hhhh" << c;
//}
//
//
//int main()
//{
//	string inputStr, outputStr;
//	cout << "please enter a sentence: " << endl;
//	getline(cin, inputStr);
//	int len = inputStr.length();
//	int wordLength = 0;
//	int i = 0;
//	for (i = len - 1; i >= 0; i--)
//	{
//		wordLength++;
//		if (' ' == inputStr[i])
//		{
//			outputStr = outputStr + inputStr.substr(i + 1, wordLength - 1) + ' ';
//			wordLength = 0;
//		}
//	}
//	outputStr = outputStr + inputStr.substr(0, wordLength);
//	cout << "the reversed sentence is: " << endl << outputStr;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//template <class T>
//class Node {
//public:
//	T data;
//	Node<T>* left;
//	Node<T>* right;
//};
//
//template <class T>
//void createTreeFromArray(Node<T>*& p, T array[], int start, int end)
//{
//	if (start <= end)
//	{
//		int middle = (start + end) / 2;
//		//p = (node*)malloc(sizeof(node));
//		p = new Node<T>;
//		p->data = array[middle];
//		p->left = NULL;
//		p->right = NULL;
//		createTreeFromArray(p->left, array, start, middle - 1);
//		createTreeFromArray(p->right, array, middle + 1, end);
//	}
//	else
//		return;
//}
//
//
//bool search(Node<int>* root, int va, int vb, Node<int>*& result, Node<int>* parrent)
//{
//	bool left = false, right = false;
//	if (!result && root->left) 
//		left = search(root->left, va, vb, result, root);
//	if (!result && root->right) 
//		right = search(root->right, va, vb, result, root);
//
//	bool mid = false;
//	if (root->data == va || root->data == vb) mid = true;
//	if (!result && int(left + right + mid) == 2) {
//		if (mid) 
//			result = parrent;
//		else 
//			result = root;
//	}
//	return left | mid | right;
//}
//
//template <class T>
//Node<T>* findNearestParentNode(Node<T>* root, T va, T vb)
//{
//	if (root == NULL) 
//		return NULL;
//	Node<T>* result = NULL;
//	search(root, va, vb, result, NULL);
//	return result;
//}
//
//int main() {
//	int a[10] = { 3,10,8,13,2,9 };
//	Node<int>* root = NULL;
//	createTreeFromArray(root, a, 0, sizeof(a) / sizeof(int) - 1);
//	Node<int>* nearestParentNode = findNearestParentNode(root, 3, 10);
//	cout << nearestParentNode->data;
//}
//#include <iostream>
//#include <map>
//#include <vector>
//using namespace std;
//int get_numberpair_count(int* array, size_t size, int N) {
//	vector<int> intVector;
//	int count = 0;
//	for (size_t i = 0; i < size; i++) {
//		intVector.push_back(array[i]);
//	}
//	std::map<int, int> createMap;
//	for (size_t i = 0; i < size; ++i)
//	{
//		std::map<int, int>::const_iterator iter = createMap.find(N + 1 - intVector[i]);
//		if (iter == createMap.end())
//			createMap[intVector[i]] = i;
//		else
//		{
//			cout << intVector[iter->second] << "    " << intVector[i] << endl;
//			count++;
//		}
//	}
//	return count;
//}
//
//int main() {
//	int ar[] = { 1,2,3,4,5,6 };
//	int count = get_numberpair_count(ar, 6, 6);
//	cout << count;
//	return 0;
//}

//#include <iostream>
//#include <pthread.h>
//#include <unistd>

//using namespace std;
//class thread
//{
//public:
//
//	thread();
//
//	~thread();
//
//	void start(void* arg) {
//		this->arg = arg;
//		pthread_create(&threadid, null, thread::run, this);
//		pthread_detach(threadid);
//	}
//
//	void stop() {
//		pthread_cancel(threadid);
//	}
//
//	void run() {
//		cout << "thread run" << arg << endl;
//	}
//
//private:
//	pthread_t threadid;
//	void* arg;
////};
//
//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//HANDLE hMutex = NULL;//������
////�̺߳���
//DWORD WINAPI Fun(LPVOID lpParamter)
//{
//	for (int i = 0; i < 10; i++)
//	{
//		//����һ����������
//		WaitForSingleObject(hMutex, INFINITE);
//		cout << "A Thread Fun Display!" << endl;
//		Sleep(100);
//		//�ͷŻ�������
//		ReleaseMutex(hMutex);
//	}
//	return 0L;//��ʾ���ص���long�͵�0
//
//}
//
//int main()
//{
//	//����һ�����߳�
//	HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
//	hMutex = CreateMutex(NULL, FALSE, "screen");
//	//CloseHandle�ǹر��߳̾��,�����ͷ��߳���Դ��,������ֹ�̵߳ġ�
//	//�ر��߳̾��ֻ���ͷž����Դ���¿����̺߳������������������Ӧ�ùرվ�����ͷ�ϵͳ��Դ��
//	//�ر��߳̾�����̵߳Ľ������û�й�ϵ��������߳�ֻ�봴���̣߳���������֮���ٲ�ѯ�����������ô��ʱ�رվ���Ǹ���ϰ�ߣ���õ�ʱû�أ��Ժ������ˣ�����й©��ϵͳ�ľ����Դ��ϵͳ������������޵ģ���
//	CloseHandle(hThread);
//	//���̵߳�ִ��·��
//	for (int i = 0; i < 10; i++)
//	{
//		//������һ����������
//		WaitForSingleObject(hMutex, INFINITE);
//		cout << "Main Thread Display!" << endl;
//		Sleep(100);
//		//�ͷŻ�������
//		ReleaseMutex(hMutex);
//	}
//	return 0;
//}

/*
2016-9-28 12:09:45
@author:CodingMengmeng
language:C;
*/

//Server.

#include <stdio.h>                   //����printf�Ⱥ����ĵ���
#include <winsock2.h>                //Socket�ĺ������á�
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32")      //C���������������ʱ������.h�ļ��⣬��Ҫ�����Ӧ��lib�ļ��������ͬ��C#��

int main()
{
	/*
		Ϊ����Ӧ�ó����е����κ�һ��Winsock API���������ȵ�һ��������Ǳ���ͨ��WSAStartup������ɶ�Winsock����ĳ�ʼ����
		�����Ҫ����WSAStartup������ʹ��Socket�ĳ�����ʹ��Socket֮ǰ�������WSAStartup������
		�ú����ĵ�һ������ָ����������ʹ�õ�Socket�汾�����и�λ�ֽ�ָ�����汾����λ�ֽ�ָ�����汾��
		����ϵͳ���õڶ����������������Socket�İ汾��Ϣ��
		��һ��Ӧ�ó������WSAStartup����ʱ������ϵͳ���������Socket�汾��������Ӧ��Socket�⣬Ȼ����ҵ���Socket�⵽��Ӧ�ó����С�
		�Ժ�Ӧ�ó���Ϳ��Ե����������Socket���е�����Socket�����ˡ�
----------------------------------------------------------------------------------------------------------------------------------------
		int WSAStartup ( WORD wVersionRequested, LPWSADATA lpWSAData );
		(1)wVersionRequested��һ��WORD��˫�ֽڣ�����ֵ������߰汾��Windows Sockets֧�ֵ�����ʹ�ã��߽��ֽ�ָ��С�汾(�޶���)��,��λ�ֽ�ָ�����汾�š�
		(2)lpWSAData ָ��WSADATA���ݽṹ��ָ�룬��������Windows Sockets ʵ�ֵ�ϸ��
----------------------------------------------------------------------------------------------------------------------------------------
		������������Ӧ�ó����DLL���õĵ�һ��Windows Sockets������
	*/
	WSADATA wsaData;//��������Windows Socketsʵ�ֵ�ϸ��
	WSAStartup(MAKEWORD(2, 2), &wsaData);//��ɶ�Winsock����ĳ�ʼ��
	SOCKET s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);//��ַ���ͣ�AF_INET��socket���ͣ�SOCK_STREAM��Э�����ͣ�TCP
	sockaddr_in sockaddr;//Ҫ�󶨸�sockfd��Э���ַ
	sockaddr.sin_family = PF_INET;//AF_INET�����˵�ַ����Ҫʹ��ipv4��ַ��32λ����˿ںţ�16λ�������
	//sockaddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");   //��Ҫ�󶨵����ص��ĸ�IP��ַ|| 127.0.0.1�ǻ��͵�ַ��ָ���ػ�
	InetPton(PF_INET, TEXT("10.140.58.39"), &sockaddr.sin_addr);
	sockaddr.sin_port = htons(9000);                          //��Ҫ�����Ķ˿�
	bind(s, (SOCKADDR*)& sockaddr, sizeof(SOCKADDR));        //���а󶨶���
	listen(s, 1);                                           //��������
	printf("listening on port [%d].\n", 9000);
	int n;

	SOCKADDR clientAddr;
	int size = sizeof(SOCKADDR);
	SOCKET clientsocket;
	clientsocket = accept(s, &clientAddr, &size);               //������ֱ������tcp�ͻ�������
	printf("***SYS***    New client touched.\n");
	const char* msg = "Hello, my client.\r\n";
	const char* revFlag = "Copy that!\r\n";
	send(clientsocket, msg, strlen(msg) + sizeof(char), NULL);  //����ĵ���������Ҫע�⣬�Ǽ���һ��char���ȵ�
	while (TRUE)
	{
		char buffer[MAXBYTE] = { 0 };
		n = recv(clientsocket, buffer, MAXBYTE, NULL);//һֱ���տͻ���socket��send����
		/*if (buffer[0] == 'q')
			break;*/
		//recvֻ�н��յ����ݲŻ�����ִ�У�����һֱ�ȴ�
		//send(clientsocket, revFlag, strlen(revFlag) + sizeof(char), NULL);
		buffer[n] = '\0';		
		printf("***Receive From Client***:    %s\n", buffer);
		char mymsg[100000] = {0};
		printf("Say something to client:\n");
		gets_s(mymsg, 100000);//��ȡ��Ļ����
		send(clientsocket, mymsg, strlen(mymsg), NULL);
	}

	closesocket(clientsocket);                                //�رտͻ���socket
	closesocket(s);//�رռ���socket

	WSACleanup();                                                //ж��
	getchar();
	exit(0);
}

