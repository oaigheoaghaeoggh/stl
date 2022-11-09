#pragma once
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <map>
#include "speaker.h"
#include <functional>
#include <numeric>
#include <deque>
#include <string>
#include <fstream>

//�ݽ�������
class SpeechManager
{
public:
	//���캯��
	SpeechManager();

	//չʾ�˵�
	void show_Menu();

	void exitSystem();

	//����ѡ�� ���� 12��
	vector<int>v1;
	//��һ�ֽ������� 6��
	vector<int>v2;
	//ʤ��ǰ�������� 3��
	vector<int>vVictory;
	//��ű�� �Լ���Ӧ�� ����ѡ�� ����
	map<int, Speaker> m_Speaker;
	//��ʼ������
	void initSpeech();
	int m_Index;
	//��ʼ������12��ѡ��
	void createSpeaker();
	void startSpeech();
	//��ǩ
	void speechDraw();
	//����
	void speechContest();//����
	//��������
	~SpeechManager();
};

