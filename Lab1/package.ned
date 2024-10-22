package lab1;

import ned.IdealChannel;


@license(LGPL);
//
// TODO documentation
//
network lab1
{
    @display("bgb=626,312");
    types:
    submodules:
        Tic: Node {
            @display("p=125,134");
        }
        Toc: Node {
            @display("p=502,134");
        }
    connections:
        Tic.out --> IdealChannel --> Toc.in;
        Toc.out --> IdealChannel --> Tic.in;
}

