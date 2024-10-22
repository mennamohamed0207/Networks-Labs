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

#include "player1.h"

Define_Module(Player1);

void Player1::initialize()
{
    // TODO - Generated method body
    cMessage *msg = new cMessage("StartGuessing");
    send(msg, "p1_out");
    EV<<"The Random Number of Player1 is "<<endl;
    EV<< par("correctNumber").intValue()<<endl;
}

void Player1::handleMessage(cMessage *msg)
{
    // TODO - Generated method body

    int guessedNumber=atoi(msg->getName());
    std::string result="";
    if(guessedNumber == par("correctNumber").intValue())
    {
        EV<<"correct guess"<<endl;
        result="correct guess";


    }else{
        EV <<"wrong guess"<<endl;
        result="wrong guess";
    }

    char *message = new char[result.length() + 1];
    strcpy(message, result.c_str());
    cMessage *Msg = new cMessage(message);


    send(Msg, "p1_out");


}
