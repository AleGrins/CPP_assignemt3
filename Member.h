#include <vector>
#pragma once

class Member
{
    private:
        std::vector<int> followers; //list of members following this member
        std::vector<int> following; //list of members this member is following
        int ID; //member's ID for internal use
        
    public:
        Member(); //basic constructor
        int numFollowers(); //returns number of members following this member
        int numFollowing(); //returns number of members this member is following
        static int count(); //returns number of members
        int getID(); //return member's ID
        void follow(Member member); //start following a given member
        void unfollow(Member member); //stop following a given member
        void addToFollowers(int ID); //add a member to "followers"
        void addToFollowing(int ID); //add a member to "following"
        void removeFromFollowers(int index); //remove member at given index from "followers"
        void removeFromFollowing(int index); //remove member at given index from "following"
        int getFollower(int index); //get specific ID from "followers" list
};
