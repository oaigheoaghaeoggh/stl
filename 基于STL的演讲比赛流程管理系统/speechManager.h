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

//演讲管理类
class SpeechManager
{
public:
	//构造函数
	SpeechManager();

	//展示菜单
	void show_Menu();

	void exitSystem();

	//比赛选手 容器 12人
	vector<int>v1;
	//第一轮晋级容器 6人
	vector<int>v2;
	//胜利前三名容器 3人
	vector<int>vVictory;
	//存放编号 以及对应的 具体选手 容器
	map<int, Speaker> m_Speaker;
	//初始化属性
	void initSpeech();
	int m_Index;
	//初始化创建12名选手
	void createSpeaker();
	void startSpeech();
	//抽签
	void speechDraw();
	//比赛
	void speechContest();//比赛
	//析构函数
	~SpeechManager();
};

