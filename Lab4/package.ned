package lab4;

import ned.IdealChannel;


@license(LGPL);
//
// TODO documentation
//
network Network
{
    @display("bgb=509,255");
    submodules:
        sender: Sender {
            @display("p=133,94");
        }
        receiver: Receiver {
            @display("p=400,105");
        }
    connections:
        sender.sender_out --> IdealChannel --> receiver.receiver_in;
        receiver.receiver_out --> IdealChannel --> sender.sender_in;
}

