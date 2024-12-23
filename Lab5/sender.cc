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

#include "sender.h"

Define_Module(Sender);

void Sender::initialize()
{
    // TODO - Generated method body
    EV<<"Sender Intialize"<<endl;
    scheduleAt(simTime(),new cMessage(""));

}
bool distribute=true;
void Sender::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    MyMessage_Base* newMessage=new MyMessage_Base("Name");
    std::string input;
    std::cout<<"Enter a message:(if you entered 'end' then it will end simulation) "<<endl;
        EV<<"Enter a message:(if you entered 'end' then it will end simulation)"<<endl;

        std::cin>>input;
        std::cout<<"You Entered : "<<input<<endl;
        if (input =="end") {
            EV<<"Ending Simulation"<<endl;
            endSimulation();}


    EV<<" Before Modification Message is: "<<input<<endl;
    std::bitset<8>charCount(input.size());
    newMessage->setM_Header((char)charCount.to_ulong());
    newMessage->setM_Type(0);
    int size=0;
    std::bitset<8>parity(0);
    parity=parity^charCount;
    newMessage->setM_PayloadArraySize(input.size()+1);
    int CorruptedByte=uniform(1,input.size()+1);
    int corruptedBit=uniform(0,8);
    if(!distribute)
    {


                std::cout<<"There is error at byte number "<<CorruptedByte<<endl;
                EV<<"There is error at byte number "<<CorruptedByte<<endl;
                EV<<"There is error at bit "<<corruptedBit<<endl;
                EV<<charCount<<endl;

    }else{
        EV<<"There is no error generated "<<endl;
        EV<<charCount<<endl;

    }
    for (int i=0;i<input.size();i++)
    {
        size++;
        std::bitset<8>character(input[i]);
        parity=parity^character;
        if(!distribute&&CorruptedByte==i+1)
        {
            character[corruptedBit]=character[corruptedBit] ^1;
        }
        EV<<character<<endl;
        newMessage->setM_Payload(size,(char)(character.to_ullong()));


    }

    EV<<parity<<endl;
    std::string payload="";
        for(int i=0;i<input.size();i++)
        {
            payload+=newMessage->getM_Payload(i+1);
        }
    newMessage->setM_Trailer((char)parity.to_ulong());
    send(newMessage,"sender_out");
    distribute=!distribute;
    EV<<"The message parameters "<<endl;
    EV<<"Header of Message is "<<newMessage->getM_Header()<<endl;
    EV<<"Payload is "<<payload<<endl;
    EV<<"Type of Message is "<<newMessage->getM_Type()<<endl;
    EV<<"Tailer of Message is "<<newMessage->getM_Trailer()<<endl;

//    scheduleAt(simTime(),new cMessage(""));




}
