#include<iostream>
#include<string>
using namespace std;
#include "speechManager.h"
int main() { 

	cout << "v2.2 text" << endl;
	SpeechManager sm;
	int choice = 0; //�����洢�û���ѡ��
	while (true)
	{
		sm.show_Menu();
		cout << "����������ѡ�� " << endl;
		cin >> choice; // �����û���ѡ��
		switch (choice)
		{
		case 1: //��ʼ����
			sm.startSpeech();
			break;
		case 2: //�鿴��¼
			break;
		case 3: //��ռ�¼
			break;
		case 0: //�˳�ϵͳ
			sm.exitSystem();
			break;
		default:
			system("cls"); //����
			break;
		}
	}


	/*for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << it->first
			<< " ������ " << it->second.m_Name
			<< " �ɼ��� " << it->second.m_Score[0] << endl;
	}
*/
	system("pause");
	return 0;
}

