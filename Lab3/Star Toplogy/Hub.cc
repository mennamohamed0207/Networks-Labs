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

#include "Hub.h"

Define_Module(Hub);

void Hub::initialize()
{
    // TODO - Generated method body
    int N= this->getParentModule()->par("N").intValue();
    int startNode=int(uniform(0,N));
    cMessage* startMsg=new cMessage("Hello from the Hub");
    send(startMsg,"port_hub$o",startNode);
}

void Hub::handleMessage(cMessage *msg)
{
    // TODO - Generated method body

    if(msg->isSelfMessage())
    {
        int N= this->getParentModule()->par("N").intValue();
        int chosenNode=int(uniform(0,N));
        cMessage* startMsg=new cMessage("Hello from the Hub");
        send(startMsg,"port_hub$o",chosenNode);
    }else {
        double interval =exponential(2.0);
            EV<<"Scheduled message after "<<interval<<endl;
            scheduleAt(simTime()+interval,new cMessage(""));
    }
}
