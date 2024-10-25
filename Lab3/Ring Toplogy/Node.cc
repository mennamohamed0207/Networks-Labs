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

#include "Node.h"

Define_Module(Node);

void Node::initialize()
{
    // TODO - Generated method body
    EV<<"Starting Node "<<this->getIndex()<<endl;
    if(this->getIndex()==0)
    {

        cMessage* msg=new cMessage("Exploring");
        msg->setKind(this->getIndex());
        send(msg,"port$o",this->getIndex());
    }
}

void Node::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(this->getIndex()==0)
        {
            EV<<"The number of Nodes is "<<msg->getKind()<<endl;
            endSimulation();
        }
    msg->setKind((this->getIndex())+1);
    send(msg,"port$o",1);

}
