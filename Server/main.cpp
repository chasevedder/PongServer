#include <iostream>
#include <string>
#include <sstream>
#include <enet/enet.h>
#include <stdio.h>
#include <vector>
#include "test.pb.h"

using namespace std;

int main()
{
    ENetAddress address;
    ENetHost* server;
    ENetEvent event;

    if (enet_initialize() != 0)
        cout << "gg" << endl;


    address.host = ENET_HOST_ANY;
    address.port = 1234;

    server = enet_host_create(&address, 32, 2, 0, 0);


    enet_address_set_host(&address, "chasevedder.xyz");

    Test t;

    vector<string> gameList(10);
    gameList.push_back("asdf");
    gameList.push_back("niceeeee");

    cout << "starting server" << endl;
    if (server == NULL)
        cout << "aasdfasdf" << endl;

    t.add_message("asdf");
    t.add_message("im bad");



    while (true) {
        cout << "listening..." << endl;
        while (enet_host_service(server, &event, 1000) > 0) {
            cout << "recieved event" << endl;
            switch (event.type) {
            case ENET_EVENT_TYPE_CONNECT:
                for (int i = 0; i < 5; i++) {
                    cout << "sending packet..." << endl;


                }
                break;
            case ENET_EVENT_TYPE_RECEIVE:
                std::cout << "xDDDD" << std::endl;

                std::string buf;
                t.SerializeToString(&buf);
                //std::cout << buf << std::endl;
                Test t2;
                t2.ParseFromString(buf);
                std::cout << t2.message(1) << std::endl;
                ENetPacket * packet = enet_packet_create (buf.data(), buf.size(), ENET_PACKET_FLAG_RELIABLE);
                enet_peer_send(event.peer, 0, packet);

            }
        }
    }

    return 0;
}

