// GPA2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class Weapon
{
protected:
	int strength;
	char type;
public:
	int modified;

	int return_strength()
	{
		return strength;
	}

	char return_type()
	{
		return type;
	}

	void setPower(int val)
	{
		strength = val;
		return;
	}
};



class Rock : public Weapon
{

public:
	Rock()
	{
		type = 'r';
	}
	bool battle(Weapon w)
	{
		if (w.return_type() == 'p') {
			if (this->strength / 2 >= w.return_strength()*2)
				return true;

		}
		if (w.return_type() == 's') {
			if(this->strength*2>w.return_strength()/2)
				return true;

		}
		return false;

	}

};

class Paper : public Weapon
{

public:
	Paper()
	{
		type = 'p';
	}
	bool battle(Weapon w)
	{
		if (w.return_type() == 's') {
			if (this->strength / 2 >= w.return_strength() * 2)
				return true;
	
		}
		if (w.return_type() == 'r') {
			if (this->strength * 2>w.return_strength() / 2)
				return true;

		}
		return false;
	}

};

class Scissors : public Weapon
{

public:
	Scissors()
	{
		type = 's';
	}
	bool battle(Weapon w)
	{

		if (w.return_type() == 'r') {
			if (this->strength / 2 >= w.return_strength() * 2)
				return true;

		}
		if (w.return_type() == 'p') {
			if (this->strength * 2>w.return_strength() / 2)
				return true;

		}
		return false;
	}

};


int main()
{
	Rock r;
	Paper p;
	Scissors s;
	r.setPower(5);
	p.setPower(7);
	s.setPower(24);

	cout << r.battle(p) << p.battle(s) << s.battle(r) << '\n';
    return 0;
}

