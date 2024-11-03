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
    EV<<"Enter a message:(if you entered 'end' then it will end simulation)"<<endl;
    scheduleAt(simTime(),new cMessage(""));


}



void Sender::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    std::string input;
    std::cout<<"Enter a message:(if you entered 'end' then it will end simulation) "<<endl;
    EV<<"Enter a message:(if you entered 'end' then it will end simulation)"<<endl;

    std::cin>>input;
    std::cout<<"You Entered : "<<input<<endl;
    std::string finalString=input;
    if (finalString =="end") endSimulation();
    int strSize=finalString.size();
    std::bitset<8>charCount(strSize);
    std::vector<std::bitset<8> > vec;
    vec.push_back(charCount);

    int mayError=uniform(0,2);

    std::bitset<8>parity(0);
    parity=parity^charCount;
    for(int i=0;i<strSize;i++)
     {
        std::bitset<8>character(finalString[i]);
        vec.push_back(character);
        parity=parity^character;
     }
    vec.push_back(parity);
    EV<<"Message "<<finalString<<" Before modification: "<<endl;
    std::cout<<"Message "<<finalString<<" Before modification: "<<endl;

    for(int i=0;i<strSize+2;i++)
      {
          std::cout<<vec[i]<<endl;
          EV<<vec[i]<<endl;
      }
    if (mayError==1)
    {
        int CorruptedByte=uniform(1,strSize+1);

        std::cout<<"There is error at byte number "<<CorruptedByte<<endl;
        EV<<"There is error at byte number "<<CorruptedByte<<endl;
        for(int i=1;i<=strSize+1;i++)
        {
            std::bitset<8>one(1);
            if(i==CorruptedByte)
            {
                int corruptedBit=uniform(0,8);
                vec[CorruptedByte][corruptedBit]=vec[CorruptedByte][corruptedBit] ^ one[0];
                std::cout<<"There is error at bit number "<<corruptedBit<<endl;
                EV<<"There is error at bit number "<<corruptedBit<<endl;


            }


        }
    }else {
        EV<<"There is no error "<<endl;
    }
   std::string transmitedMsg="";
   for(int i=0;i<strSize+2;i++)
   {
       transmitedMsg+=(char)vec[i].to_ulong();
   }
   char* sentMsg=new char[transmitedMsg.length()+1];
   strcpy(sentMsg, transmitedMsg.c_str());
   cMessage* msg2=new cMessage(sentMsg);
   send(msg2,"sender_out");

   scheduleAt(simTime(),new cMessage(""));




}
