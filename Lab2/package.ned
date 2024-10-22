package lab2;

import ned.IdealChannel;


@license(LGPL);
//
// TODO documentation
//
network RandomGuessingGame
{
    @display("bgb=561,294");
    submodules:
        player1: Player1 {
            @display("p=84,141");
        }
        player2: Player2 {
            @display("p=442,142");
        }
    connections:
        player1.p1_out --> IdealChannel --> player2.p2_in;
        player2.p2_out --> IdealChannel --> player1.p1_in;
}

