//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTicULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include "Node.h"

Define_Module(Node);

void Node::initialize()
{
    // Check if the node name is "Tic"
    if (strcmp(this->getName(), "Tic") == 0)
    {
        cMessage *msg = new cMessage("Hello from Tic");
        send(msg, "out");
    }
}

int i = 0;

void Node::handleMessage(cMessage *msg)
{
    delete msg;
    if (strcmp(this->getName(), "Toc") == 0&&i==0)
       {
           cMessage *msg = new cMessage("Hello from Toc");
           send(msg, "out");
       }

    // Check if the node name is "Tic"
    if ((strcmp(this->getName(), "Tic") == 0)&&i<8)
    {
        i++;
        std::string messageStr = "Tic_" + std::to_string(i);
        char *message = new char[messageStr.length() + 1];
        strcpy(message, messageStr.c_str());

        cMessage *newMsg = new cMessage(message);
        send(newMsg, "out");

        delete[] message;
    }
    // Check if the node name is "Toc"
    else if (strcmp(this->getName(), "Toc") == 0&&i!=0&&i<=8)
    {
        i++;
        std::string messageStr = "Toc_" + std::to_string(i);
        char *message = new char[messageStr.length() + 1];
        strcpy(message, messageStr.c_str());

        cMessage *newMsg = new cMessage(message);
        send(newMsg, "out");

        delete[] message;
    }
    if(strcmp(this->getName(), "Tic") == 0&&i==8)
    {
        cMessage *newMsg = new cMessage("Goodbye from Tic");
               send(newMsg, "out");
               i++;
    }else if(strcmp(this->getName(), "Toc") == 0&&i==9)
    {
        cMessage *newMsg = new cMessage("Goodbye from Toc");
               send(newMsg, "out");
    }
}
