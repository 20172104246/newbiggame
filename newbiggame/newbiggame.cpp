// game2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
class CWolf;
class CGhost;
class CDragon;
class CCreature
{
protected:
	int nPower; //��������
	int nLifeValue; //��������ֵ
	string name;
public:
	void display()
	{
		cout << "nPower=" << nPower << "  nLifeValue=" << nLifeValue << endl;
	}
	void setvalue(string name_,int p, int l)
	{
		nPower = p;
		nLifeValue = l;
		name = name_;
	}
	void Hurted(int nPower)
	{
		//���������������˶����Ĵ���
		cout << name << "shou shang hai" << endl;
		nLifeValue -= nPower;
	}
	void Attack(CCreature * pobj)
	{
		//���������ֹ��������Ĵ���
		cout << name << "gong ji" << endl;
		pobj->Hurted(nPower);
		pobj->FightBack(this);
	}
	// void Hurted( int nPower);
	void FightBack(CCreature * pobj)
	{
		//�����������ַ��������Ĵ���
		cout << name << "fan ji" << endl;
		pobj->Hurted(nPower / 2);
	}

};
class CDragon :public CCreature
{
public:
	//�����е����Ժͷ���
};
class CWolf :public CCreature
{
public:
	//�����е����Ժͷ���

};
class CGhost :public CCreature
{
public:
	//�������е����Ժͷ���


};
int main()
{
	int x, y;
	cin >> x >> y;
	CDragon oDragon;
	oDragon.setvalue("��",x, y);
	CWolf oWolf;
	oWolf.setvalue("��",x, y);
	CGhost oGhost;
	oGhost.setvalue("����",x, y);
	oDragon.display();
	oWolf.display();
	oGhost.display();
	oDragon.Attack(&oWolf);
	oDragon.Attack(&oWolf);
	oGhost.Attack(&oDragon);
	oDragon.display();
	oWolf.display();
	oGhost.display();
	return 0;
}

