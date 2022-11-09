#include "speechManager.h"
SpeechManager::SpeechManager()
{
	//��ʼ������
	this->initSpeech();

	//����ѡ��
	this->createSpeaker();

}

void SpeechManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "************* ��ӭ�μ��ݽ����� ************" << endl;
	cout << "************* 1.��ʼ�ݽ����� *************" << endl;
	cout << "************* 2.�鿴�����¼ *************" << endl;
	cout << "************* 3.��ձ�����¼ *************" << endl;
	cout << "************* 0.�˳��������� *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void SpeechManager::initSpeech()
{
	//������֤Ϊ��
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	//��ʼ����������
	this->m_Index = 1;
}
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		Speaker sp;
		sp.m_Name = name;
		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0;
		}
		//12��ѡ�ֱ��
		this->v1.push_back(i + 10001);
		//ѡ�ֱ�� �Լ���Ӧ��ѡ�� ��ŵ�map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}
void SpeechManager::speechDraw()
{
	cout << "�� << " << this->m_Index << " >> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "---------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "---------------------" << endl;
	system("pause");
	cout << endl;
}
void SpeechManager::speechContest()
{
	cout << "------------- ��" << this->m_Index << "����ʽ������ʼ��------------- " << endl;
	multimap<double, int, greater<int>> groupScore; //��ʱ����������key���� value ѡ�ֱ��
	int num = 0; //��¼��Ա����6��Ϊ1��
	vector <int>v_Src; //��������Ա����
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	//�������в���ѡ��
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f; // 600 ~ 1000
			//cout << score << " ";
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>()); //����
		d.pop_front(); //ȥ����߷�
		d.pop_back(); //ȥ����ͷ�
		double sum = accumulate(d.begin(), d.end(), 0.0f); //��ȡ�ܷ�
		double avg = sum / (double)d.size(); //��ȡƽ����
		//ÿ����ƽ����
        //cout << "��ţ� " << *it << " ѡ�֣� " 
		//<< this->m_Speaker[*it].m_Name << " ��ȡƽ��
        //��Ϊ�� " << avg << endl; //��ӡ����
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;
		//6����һ�飬����ʱ��������
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it
				!= groupScore.end(); it++)
			{
				cout << "���: " << it->second << " ������ " 
					<< this->m_Speaker[it->second].m_Name		
					<< " �ɼ��� " << this->m_Speaker[it->second].m_Score[this->m_Index - 1] <<
					endl;
			}
			int count = 0;
			//ȡǰ����
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it
				!= groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}
			groupScore.clear();
			cout << endl;
		}
	}
	cout << "------------- ��" << this->m_Index << "�ֱ������ ------------- " << endl;
	system("pause");
}

//��ʼ����
void SpeechManager::startSpeech()
{
	//��һ�ֱ���
	//1����ǩ
	speechDraw();
	//2������
	speechContest();
	//3����ʾ�������
	//�ڶ��ֱ���
	//1����ǩ
	//2������
	//3����ʾ���ս��
	//4���������
}

SpeechManager::~SpeechManager()
{
}
