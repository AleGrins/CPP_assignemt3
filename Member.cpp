#include <vector>
#include "Member.h"
using namespace std;

std::vector<Member*> memberList;
int memberCount = 0;
    
Member::Member(){ //basic constructor
    memberList.push_back(this);
    ID = memberCount;
    memberCount++;
}
        
int Member::numFollowers(){ //returns number of members following this member
    return followers.size();
}
        
int Member::numFollowing(){ //returns number of members this member is following
    return following.size();
}

int Member::count(){ //returns number of members
    return memberCount;
}

void Member::follow(Member member){ //start following a given member
    if(numFollowing() == 0){ //if following list empty
        addToFollowing(member.getID()); //add member ID to "following"
        member.addToFollowers(getID()); //add this ID to member's "followers"
    }  
    else{ //check if already following member, add if not
        bool found = false;
        for(int i=0; i<numFollowing(); i++){ 
            if(following[i] == member.getID()) found = true;
        }
        if(!found){
            addToFollowing(member.getID()); //add member ID to "following"
            member.addToFollowers(getID()); //add this ID to member's "followers"
        } 
    }
}

void Member::unfollow(Member member){ //stop following a given member
    if(numFollowing()!=0){ //if following any members
        int index = -1;
        for(int i =0; i<numFollowing(); i++){ //look for member ID in "following"
            if(following[i] == member.getID()) index = i;
        }
        if(index != -1) removeFromFollowing(index); //if found member ID, delete it
                
        index = -1;
        for(int i =0; i<member.numFollowers(); i++){ //look for this ID in member's "followers"
            if(member.getFollower(i) == getID()) index = i;
        }
        if(index != -1) member.removeFromFollowers(index); //if found this ID, delete it
    }
}

//helper functions

int Member::getID(){ //return member's ID
    return ID;
}

void Member::addToFollowers(int ID){ //add a member ID to "followers"
    if(ID!=getID()) followers.push_back (ID);
}
        
void Member::addToFollowing(int ID){ //add a member ID to "following"
    if(ID!=getID()) following.push_back (ID);
}
        
void Member::removeFromFollowers(int index){ //remove member ID at given index from "followers"
    followers.erase(followers.begin() + index);
}
        
void Member::removeFromFollowing(int index){ //remove member ID at given index from "following"
    following.erase(following.begin() + index);
}

int Member::getFollower(int index){
    return followers[index];
}








