//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "player2.h"

Define_Module(Player2);

void Player2::initialize()
{
    // TODO - Generated method body
}

void Player2::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(strcmp(msg->getName(),"StartGuessing")==0)
    {
        std::string guessedNumberString=std::to_string(par("guessedNumberPlayer2").intValue());
        char* sentNumber=new char[guessedNumberString.length()+1];
        EV<<"Guessed Number is "<<endl;
        EV<<par("guessedNumberPlayer2").intValue()<<endl;
        strcpy(sentNumber, guessedNumberString.c_str());
        cMessage* msg2=new cMessage(sentNumber);
        send(msg2,"p2_out");
    }else if(strcmp(msg->getName(),"wrong guess")==0){
        std::string guessedNumberString=std::to_string(par("guessedNumberPlayer2").intValue());
        char* sentNumber=new char[guessedNumberString.length()+1];
        EV<<"Guessed Number is "<<endl;
        EV<<par("guessedNumberPlayer2").intValue()<<endl;
        strcpy(sentNumber, guessedNumberString.c_str());
        cMessage* msg1=new cMessage(sentNumber);
        send(msg1,"p2_out");
    }

}
