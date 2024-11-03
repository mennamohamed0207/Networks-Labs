package lab5;

import ned.IdealChannel;


@license(LGPL);
//
// TODO documentation
//
network Network
{
    @display("bgb=565,380");
    submodules:
        sender: Sender {
            @display("p=125,153");
        }
        receiver: Receiver {
            @display("p=425,153");
        }
    connections:
        sender.sender_out --> IdealChannel --> receiver.receiver_in;
        receiver.receiver_out --> IdealChannel --> sender.sender_in;
}

