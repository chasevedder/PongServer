#include <iostream>
#include <string>
#include <sstream>
#include <enet/enet.h>
#include <stdio.h>
#include <vector>

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

    string games[5];
    games[0] = "This";
    games[1] = "is";
    games[2] = "a";
    games[3] = "test";
    games[4] = ".";

    vector<string> *gameList;

    cout << "starting server" << endl;
    if (server == NULL)
        cout << "aasdfasdf" << endl;

    gameList->push_back("asdf");
    gameList->push_back("asdf23");




    while (true) {
        cout << "listening..." << endl;
        while (enet_host_service(server, &event, 1000) > 0) {
            cout << "recieved event" << endl;
            switch (event.type) {
            case ENET_EVENT_TYPE_CONNECT:
                for (int i = 0; i < 5; i++) {
                    cout << "sending packet..." << endl;

                    ENetPacket * packet = enet_packet_create (games[i].c_str(), games[i].length(), ENET_PACKET_FLAG_RELIABLE);
                    enet_peer_send(event.peer, 0, packet);
                }
                break;
            case ENET_EVENT_TYPE_RECEIVE:

                ENetPacket * packet = enet_packet_create (gameList, gameList->size(), ENET_PACKET_FLAG_RELIABLE);
                enet_peer_send(event.peer, 0, packet);

            }
        }
    }

    return 0;
}

