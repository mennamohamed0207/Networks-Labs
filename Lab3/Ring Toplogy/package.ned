package lab3_req2;

@license(LGPL);
//
// TODO documentation
//
network Ring
{
    parameters:
        int N = default(4);
        @display("bgb=474,305");
    submodules:
        nodes[N]: Node;
    connections:
        for i=0..N-1 {
            nodes[i].port++ <--> nodes[i+1].port++ if i< N-1;
            nodes[i].port++ <--> nodes[0].port++ if i == N-1;
        }
}


