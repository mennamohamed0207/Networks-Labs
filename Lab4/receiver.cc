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

#include "receiver.h"

Define_Module(Receiver);

void Receiver::initialize()
{
    // TODO - Generated method body
}

void Receiver::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    std::string msgreceived=msg->getName();
    std::bitset<8>charCountMsg(msgreceived[0]);
    int charCount=msgreceived[0];
    std::bitset<8>parity(msgreceived[msgreceived.size()-1]);
    std::bitset<8>parity_msg(0);
    parity_msg=parity_msg^charCountMsg;
    std::string OrignalMsg="";
    for(int i=0;i<charCount;i++)
    {
        std::bitset<8>character(msgreceived[i+1]);
        OrignalMsg+=msgreceived[i+1];
        parity_msg=parity_msg^character;

    }
    if(parity_msg==parity)
    {
        EV<<"The Original Message is "<<OrignalMsg<<endl;
    }else {
        EV<<"error message"<<endl;
    }


}
