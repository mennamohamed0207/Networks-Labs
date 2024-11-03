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
    MyMessage_Base *mmsg = check_and_cast<MyMessage_Base *>(msg);
    std::bitset<8>charCountMsg(mmsg->getM_Header());
    int charCount=charCountMsg.to_ulong();
    std::bitset<8>parity(mmsg->getM_Trailer());
    std::bitset<8>parity_msg(0);
        parity_msg=parity_msg^charCountMsg;
        std::string payload="";
     for(int i=0;i<charCount;i++)
     {
         payload+=mmsg->getM_Payload(i+1);
     }
     std::cout<<"the payload"<<endl;
     std::cout<<payload<<endl;
        for(int i=0;i<=charCount;i++)
        {
            std::bitset<8>character(payload[i]);
            parity_msg=parity_msg^character;

        }
        MyMessage_Base *mmsgsent=new  MyMessage_Base("Ack or not Ack");
        if(parity_msg==parity)
           {
            mmsgsent->setM_Type(1);
               EV<<"The Original Message is "<<payload<<endl;

           }else {
               EV<<"error message"<<endl;
               mmsgsent->setM_Type(2);

           }

           EV<<"The message parameters "<<endl;
//           EV<<"Header of Message is "<<mmsgsent->getM_Header()<<endl;
           EV<<"Type of Message is "<<mmsgsent->getM_Type()<<endl;
//           EV<<"Tailer of Message is "<<mmsgsent->getM_Trailer()<<endl;
        send(mmsgsent,"receiver_out");


}
