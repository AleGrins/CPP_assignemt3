#include <iostream>
using namespace std;

#include "Member.cpp"

int main() {
	
	Member a;
	cout << "Members following a: " << a.numFollowers() << " Members a is following: " << a.numFollowing() << endl; // 0 0
	cout << "Member count: " << Member::count() << endl; // 1
	
	Member b;
	cout << "Member count: " << Member::count() << endl; // 2
	
	int aID = a.getID();
	int bID = b.getID();
	cout << "ID of a: " << aID << " ID of b: " << bID << endl;
	
	a.follow(b);
	cout << "Members following a: " << a.numFollowers() << " Members a is following: " << a.numFollowing() << endl; // 0 1
	cout << "Members following b: " << b.numFollowers() << " Members b is following: " << b.numFollowing() << endl; // 1 0
	
	a.follow(b); // duplicate follow has no effect
	cout << "Members following a: " << a.numFollowers() << " Members a is following: " << a.numFollowing() << endl; // 0 1
	
	a.unfollow(b);
	cout << "Members following a: " << a.numFollowers() << " Members a is following: " << a.numFollowing() << endl; // 0 1
	
	Member c,d,e;
	cout << "Member count: " << Member::count() << endl; // 5
	
	a.follow(b);
	a.follow(c);
	a.follow(d);
	a.follow(e);
	
	b.follow(a);
	c.follow(a);
	d.follow(a);
	e.follow(a);
	cout << "Members following a: " << a.numFollowers() << " Members a is following: " << a.numFollowing() << endl; // 4 4
	
	a.follow(a); //can't follow yourself
	cout << "Members following a: " << a.numFollowers() << " Members a is following: " << a.numFollowing() << endl; // 4 4
}