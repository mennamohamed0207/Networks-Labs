package lab3_req1;

@license(LGPL);
//
// TODO documentation
//
network Star
{
    parameters:
        int N = default(4);
        @display("bgb=397,213");
    submodules:
        nodes[N]: Node;
        hub:Hub;
    connections:
        for i=0..N-1 {
           nodes[i].port++ <--> hub.port_hub++;
        }
}

