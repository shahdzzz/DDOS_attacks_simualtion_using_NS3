#include "ns3/core-module.h"

#include "ns3/network-module.h"

#include "ns3/csma-module.h"

#include "ns3/internet-module.h"

#include "ns3/applications-module.h"

#include "ns3/netanim-module.h"

#include "ns3/mobility-module.h"

#include "ns3/point-to-point-module.h"

#include"ns3/internet-stack-helper.h"

#include <ns3/csma-helper.h>

#include "ns3/mobility-module.h"

#include "ns3/nstime.h"

#include "ns3/core-module.h"

#include "ns3/network-module.h"

#include "ns3/ipv4-global-routing-helper.h"

#include "ns3/node-container.h"


#define UDP_SINK_PORT 9001
#define MAX_BULK_BYTES 100000
#define DDOS_RATE "20480kb/s"
#define MAX_SIMULATION_TIME 10.0
#define NUMBER_OF_BOTS 10

NS_LOG_COMPONENT_DEFINE("DDoSAttack");
using namespace ns3;

int main(int argc, char * argv[]) {
    // Create nodes for all entities
    NodeContainer nodes;
    nodes.Create(23); // 31 nodes in total, including users and bots

    // Additional user nodes in residential and commercial areas
    NodeContainer users;
    users.Create(12);

    // Create nodes for bots
    NodeContainer botNodes;
    botNodes.Create(NUMBER_OF_BOTS);

    // PP
    CsmaHelper csmaPP;
    csmaPP.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaPP.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerPP = NodeContainer(nodes.Get(0), nodes.Get(1), nodes.Get(2));
    NetDeviceContainer devicesPP = csmaPP.Install(containerPP);

    CsmaHelper csmaPPSub1;
    csmaPPSub1.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaPPSub1.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerPPSub1 = NodeContainer(nodes.Get(1), nodes.Get(3), nodes.Get(4));
    NetDeviceContainer devicesPPSub1 = csmaPPSub1.Install(containerPPSub1);

    CsmaHelper csmaPPSub2;
    csmaPPSub2.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaPPSub2.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerPPSub2 = NodeContainer(nodes.Get(2), nodes.Get(5), nodes.Get(6));
    NetDeviceContainer devicesPPSub2 = csmaPPSub2.Install(containerPPSub2);

    // Include 5 bots
    CsmaHelper csmaPPSub1R1;
    csmaPPSub1R1.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaPPSub1R1.SetChannelAttribute("Delay", StringValue("2ms"));
NodeContainer containerPPSub1R1;
containerPPSub1R1.Add(nodes.Get(3));
containerPPSub1R1.Add(users.Get(0));
containerPPSub1R1.Add(botNodes.Get(0));
containerPPSub1R1.Add(botNodes.Get(1));
containerPPSub1R1.Add(botNodes.Get(2));
containerPPSub1R1.Add(botNodes.Get(3));
containerPPSub1R1.Add(botNodes.Get(4));
    NetDeviceContainer devicesPPSub1R1 = csmaPPSub1R1.Install(containerPPSub1R1);

    CsmaHelper csmaPPSub1C1;
    csmaPPSub1C1.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaPPSub1C1.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerPPSub1C1 = NodeContainer(nodes.Get(4), users.Get(1));
    NetDeviceContainer devicesPPSub1C1 = csmaPPSub1C1.Install(containerPPSub1C1);

    CsmaHelper csmaPPSub2R2;
    csmaPPSub2R2.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaPPSub2R2.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerPPSub2R2 = NodeContainer(nodes.Get(5), users.Get(2));
    NetDeviceContainer devicesPPSub2R2 = csmaPPSub2R2.Install(containerPPSub2R2);

    CsmaHelper csmaPPSub2C2;
    csmaPPSub2C2.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaPPSub2C2.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerPPSub2C2 = NodeContainer(nodes.Get(6), users.Get(3));
    NetDeviceContainer devicesPPSub2C2 = csmaPPSub2C2.Install(containerPPSub2C2);

    // WTF
    CsmaHelper csmaWTF;
    csmaWTF.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaWTF.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerWTF = NodeContainer(nodes.Get(20), nodes.Get(10), nodes.Get(7));
    NetDeviceContainer devicesWTF = csmaWTF.Install(containerWTF);

    CsmaHelper csmaWTFSub1;
    csmaWTFSub1.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaWTFSub1.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerWTFSub1 = NodeContainer(nodes.Get(7), nodes.Get(8), nodes.Get(9));
    NetDeviceContainer devicesWTFSub1 = csmaWTFSub1.Install(containerWTFSub1);

    CsmaHelper csmaWTFSub2;
    csmaWTFSub2.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaWTFSub2.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerWTFSub2 = NodeContainer(nodes.Get(10), nodes.Get(11), nodes.Get(12));
    NetDeviceContainer devicesWTFSub2 = csmaWTFSub2.Install(containerWTFSub2);

    CsmaHelper csmaWTFSub1HH1;
    csmaWTFSub1HH1.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaWTFSub1HH1.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerWTFSub1HH1 = NodeContainer(nodes.Get(8), users.Get(4));
    NetDeviceContainer devicesWTFSub1HH1 = csmaWTFSub1HH1.Install(containerWTFSub1HH1);

    CsmaHelper csmaWTFSub1H1;
    csmaWTFSub1H1.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaWTFSub1H1.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerWTFSub1H1 = NodeContainer(nodes.Get(9), users.Get(5));
    NetDeviceContainer devicesWTFSub1H1 = csmaWTFSub1H1.Install(containerWTFSub1H1);

    // Include 2 bots
    CsmaHelper csmaWTFSub2HH2;
    csmaWTFSub2HH2.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaWTFSub2HH2.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerWTFSub2HH2 = NodeContainer(nodes.Get(11), users.Get(6), botNodes.Get(5), botNodes.Get(6));
    NetDeviceContainer devicesWTFSub2HH2 = csmaWTFSub2HH2.Install(containerWTFSub2HH2);

    CsmaHelper csmaWTFSub2H2;
    csmaWTFSub2H2.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaWTFSub2H2.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerWTFSub2H2 = NodeContainer(nodes.Get(12), users.Get(7));
    NetDeviceContainer devicesWTFSub2H2 = csmaWTFSub2H2.Install(containerWTFSub2H2);

    // TCS
    CsmaHelper csmaTCS;
    csmaTCS.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaTCS.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerTCS = NodeContainer(nodes.Get(13), nodes.Get(14), nodes.Get(15));
    NetDeviceContainer devicesTCS = csmaTCS.Install(containerTCS);

    CsmaHelper csmaTCSSub1;
    csmaTCSSub1.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaTCSSub1.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerTCSSub1 = NodeContainer(nodes.Get(15), nodes.Get(18), nodes.Get(19));
    NetDeviceContainer devicesTCSSub1 = csmaTCSSub1.Install(containerTCSSub1);

    CsmaHelper csmaTCSSub2;
    csmaTCSSub2.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaTCSSub2.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerTCSSub2 = NodeContainer(nodes.Get(14), nodes.Get(16), nodes.Get(17));
    NetDeviceContainer devicesTCSSub2 = csmaTCSSub2.Install(containerTCSSub2);

    CsmaHelper csmaTCSSub1V1;
    csmaTCSSub1V1.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaTCSSub1V1.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerTCSSub1V1 = NodeContainer(nodes.Get(18), users.Get(8));
    NetDeviceContainer devicesTCSSub1V1 = csmaTCSSub1V1.Install(containerTCSSub1V1);

    CsmaHelper csmaTCSSub1PTM1;
    csmaTCSSub1PTM1.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaTCSSub1PTM1.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerTCSSub1PTM1 = NodeContainer(nodes.Get(19), users.Get(9));
    NetDeviceContainer devicesTCSSub1PTM1 = csmaTCSSub1PTM1.Install(containerTCSSub1PTM1);

    CsmaHelper csmaTCSSub2V2;
    csmaTCSSub2V2.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaTCSSub2V2.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerTCSSub2V2 = NodeContainer(nodes.Get(16), users.Get(10));
    NetDeviceContainer devicesTCSSub2V2 = csmaTCSSub2V2.Install(containerTCSSub2V2);

    // Include last 3 bots
    CsmaHelper csmaTCSSub2PTM2;
    csmaTCSSub2PTM2.SetChannelAttribute("DataRate", StringValue("100Mbps"));
    csmaTCSSub2PTM2.SetChannelAttribute("Delay", StringValue("2ms"));
    NodeContainer containerTCSSub2PTM2 = NodeContainer(nodes.Get(17), users.Get(11), botNodes.Get(7), botNodes.Get(8), botNodes.Get(9));
    NetDeviceContainer devicesTCSSub2PTM2 = csmaTCSSub2PTM2.Install(containerTCSSub2PTM2);

    // CT
    PointToPointHelper mesh;
    mesh.SetDeviceAttribute("DataRate", StringValue("100Mbps"));
    mesh.SetChannelAttribute("Delay", StringValue("2ms"));
    NetDeviceContainer devicesMesh;
    devicesMesh.Add(mesh.Install(nodes.Get(20), nodes.Get(0)));
    devicesMesh.Add(mesh.Install(nodes.Get(20), nodes.Get(21)));
    devicesMesh.Add(mesh.Install(nodes.Get(20), nodes.Get(13)));
    devicesMesh.Add(mesh.Install(nodes.Get(0), nodes.Get(20)));
    devicesMesh.Add(mesh.Install(nodes.Get(0), nodes.Get(21)));
    devicesMesh.Add(mesh.Install(nodes.Get(0), nodes.Get(13)));
    devicesMesh.Add(mesh.Install(nodes.Get(13), nodes.Get(0)));
    devicesMesh.Add(mesh.Install(nodes.Get(13), nodes.Get(20)));
    devicesMesh.Add(mesh.Install(nodes.Get(13), nodes.Get(21)));
    devicesMesh.Add(mesh.Install(nodes.Get(21), nodes.Get(0)));
    devicesMesh.Add(mesh.Install(nodes.Get(21), nodes.Get(20)));
    devicesMesh.Add(mesh.Install(nodes.Get(21), nodes.Get(13)));

    // Server
    PointToPointHelper p2pServer;
    p2pServer.SetDeviceAttribute("DataRate", StringValue("100Mbps"));
    p2pServer.SetChannelAttribute("Delay", StringValue("2ms"));
    NetDeviceContainer devicesServer = p2pServer.Install(nodes.Get(21), nodes.Get(22));

//    PointToPointHelper pp2;
//    pp2.SetDeviceAttribute("DataRate", StringValue("100Mbps"));
//    pp2.SetChannelAttribute("Delay", StringValue("1ms"));

//    NetDeviceContainer botDeviceContainer[NUMBER_OF_BOTS];

//    for (int i = 0; i < NUMBER_OF_BOTS; ++i) {
//        botDeviceContainer[i] = pp2.Install(botNodes.Get(i), nodes.Get(6));
//    }

    // Install Internet stack on all nodes
    InternetStackHelper stack;
    stack.Install(users);
    stack.Install(botNodes);
    stack.Install(nodes);

    // Assign IP addresses to the PP nodes
    Ipv4AddressHelper addressPP, addressPPSub1, addressPPSub2, addressPPSub1R1, addressPPSub1C1, addressPPSub2R2, addressPPSub2C2, addressPPSub1R1C1;
    addressPP.SetBase("10.1.1.0", "255.255.255.0");
    addressPPSub1.SetBase("10.1.2.0", "255.255.255.0");
    addressPPSub2.SetBase("10.1.3.0", "255.255.255.0");
    addressPPSub1R1.SetBase("10.1.4.0", "255.255.255.0");
    addressPPSub1C1.SetBase("10.1.5.0", "255.255.255.0");
    addressPPSub2R2.SetBase("10.1.6.0", "255.255.255.0");
    addressPPSub2C2.SetBase("10.1.7.0", "255.255.255.0");

    // region Bot
    // Assign IP addresses to the botNodes
    //    Ipv4AddressHelper ipv4_bot;
    //    ipv4_bot.SetBase("10.0.0.0", "255.255.255.252");
    //
    //    for (int j = 0; j < NUMBER_OF_BOTS; ++j) {
    //        ipv4_bot.Assign(botDeviceContainer[j]);
    //        ipv4_bot.NewNetwork();
    //    }
    // endregion

    Ipv4InterfaceContainer interfacesPP = addressPP.Assign(devicesPP);
    Ipv4InterfaceContainer interfacesPPSub1 = addressPPSub1.Assign(devicesPPSub1);
    Ipv4InterfaceContainer interfacesPPSub2 = addressPPSub2.Assign(devicesPPSub2);
    Ipv4InterfaceContainer interfacesPPSub1R1 = addressPPSub1R1.Assign(devicesPPSub1R1);
    Ipv4InterfaceContainer interfacesPPSub1C1 = addressPPSub1C1.Assign(devicesPPSub1C1);
    Ipv4InterfaceContainer interfacesPPSub2R2 = addressPPSub2R2.Assign(devicesPPSub2R2);
    Ipv4InterfaceContainer interfacesPPSub2C2 = addressPPSub2C2.Assign(devicesPPSub2C2);

    // Assign IP addresses to the WTF nodes
    Ipv4AddressHelper addressWTF, addressWTFSub1, addressWTFSub2, addressWTFSub1HH1, addressWTFSub1H1, addressWTFSub2HH2, addressWTFSub2H2;
    addressWTF.SetBase("10.2.1.0", "255.255.255.0");
    addressWTFSub1.SetBase("10.2.2.0", "255.255.255.0");
    addressWTFSub2.SetBase("10.2.3.0", "255.255.255.0");
    addressWTFSub1HH1.SetBase("10.2.4.0", "255.255.255.0");
    addressWTFSub1H1.SetBase("10.2.5.0", "255.255.255.0");
    addressWTFSub2HH2.SetBase("10.2.6.0", "255.255.255.0");
    addressWTFSub2H2.SetBase("10.2.7.0", "255.255.255.0");

    Ipv4InterfaceContainer interfacesWTF = addressWTF.Assign(devicesWTF);
    Ipv4InterfaceContainer interfacesWTFSub1 = addressWTFSub1.Assign(devicesWTFSub1);
    Ipv4InterfaceContainer interfacesWTFSub2 = addressWTFSub2.Assign(devicesWTFSub2);
    Ipv4InterfaceContainer interfacesWTFSub1HH1 = addressWTFSub1HH1.Assign(devicesWTFSub1HH1);
    Ipv4InterfaceContainer interfacesWTFSub1H1 = addressWTFSub1H1.Assign(devicesWTFSub1H1);
    Ipv4InterfaceContainer interfacesWTFSub1HH2 = addressWTFSub2HH2.Assign(devicesWTFSub2HH2);
    Ipv4InterfaceContainer interfacesWTFSub1H2 = addressWTFSub2H2.Assign(devicesWTFSub2H2);

    // Assign IP addresses to the TCS nodes
    Ipv4AddressHelper addressTCS, addressTCSSub1, addressTCSSub2, addressTCSSub1V1, addressTCSSub1PTM1, addressTCSSub2V2, addressTCSSub2PTM2;
    addressTCS.SetBase("10.3.1.0", "255.255.255.0");
    addressTCSSub1.SetBase("10.3.2.0", "255.255.255.0");
    addressTCSSub2.SetBase("10.3.3.0", "255.255.255.0");
    addressTCSSub1V1.SetBase("10.3.4.0", "255.255.255.0");
    addressTCSSub1PTM1.SetBase("10.3.5.0", "255.255.255.0");
    addressTCSSub2V2.SetBase("10.3.6.0", "255.255.255.0");
    addressTCSSub2PTM2.SetBase("10.3.7.0", "255.255.255.0");

    Ipv4InterfaceContainer interfacesTCS = addressTCS.Assign(devicesTCS);
    Ipv4InterfaceContainer interfacesTCSSub1 = addressTCSSub1.Assign(devicesTCSSub1);
    Ipv4InterfaceContainer interfacesTCSSub2 = addressTCSSub2.Assign(devicesTCSSub2);
    Ipv4InterfaceContainer interfacesTCSSub1V1 = addressTCSSub1V1.Assign(devicesTCSSub1V1);
    Ipv4InterfaceContainer interfacesTCSSub1PTM1 = addressTCSSub1PTM1.Assign(devicesTCSSub1PTM1);
    Ipv4InterfaceContainer interfacesTCSSub1V2 = addressTCSSub2V2.Assign(devicesTCSSub2V2);
    Ipv4InterfaceContainer interfacesTCSSub1PTM2 = addressTCSSub2PTM2.Assign(devicesTCSSub2PTM2);

    // Assign IP addresses to the CT and server nodes
    Ipv4AddressHelper addressCT, addressServer;
    addressCT.SetBase("10.4.1.0", "255.255.255.0");
    addressServer.SetBase("10.5.1.0", "255.255.255.0");

    Ipv4InterfaceContainer interfacesCT = addressCT.Assign(devicesServer.Get(0)); // node 21
    Ipv4InterfaceContainer interfacesServer = addressServer.Assign(devicesServer.Get(1)); // node 22

    // Add constant mobility to all the nodes
    MobilityHelper mobility;
    mobility.SetPositionAllocator("ns3::GridPositionAllocator",
        "MinX", DoubleValue(0.0),
        "MinY", DoubleValue(0.0),
        "DeltaX", DoubleValue(50.0),
        "DeltaY", DoubleValue(50.0),
        "GridWidth", UintegerValue(6),
        "LayoutType", StringValue("RowFirst"));
    mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    mobility.Install(users);
    mobility.Install(nodes);
    mobility.Install(botNodes);

    // Create the server and client applications
    UdpEchoServerHelper echoServer(9);

    ApplicationContainer serverApps = echoServer.Install(nodes.Get(4));
    serverApps.Start(Seconds(1.0));
    serverApps.Stop(Seconds(10.0));

    UdpEchoClientHelper echoClient(interfacesPP.GetAddress(0), 9);
    echoClient.SetAttribute("MaxPackets", UintegerValue(100));
    echoClient.SetAttribute("Interval", TimeValue(Seconds(1.0)));
    echoClient.SetAttribute("PacketSize", UintegerValue(1024));

    ApplicationContainer clientApps = echoClient.Install(users.Get(5));
    clientApps.Start(Seconds(2.0));
    clientApps.Stop(Seconds(10.0));

    // region Bot
    // Generate Traffic of DDoS Attacks
    OnOffHelper onoff("ns3::UdpSocketFactory", Address(InetSocketAddress(interfacesPPSub2C2.GetAddress(1), UDP_SINK_PORT)));
    onoff.SetConstantRate(DataRate(DDOS_RATE));
    onoff.SetAttribute("OnTime", StringValue("ns3::ConstantRandomVariable[Constant=30]"));
    onoff.SetAttribute("OffTime", StringValue("ns3::ConstantRandomVariable[Constant=0]"));
    ApplicationContainer onOffApp[NUMBER_OF_BOTS];

    //Install application in all bots
    for (int k = 0; k < NUMBER_OF_BOTS; ++k) {
        onOffApp[k] = onoff.Install(botNodes.Get(k));
        onOffApp[k].Start(Seconds(2.0));
        onOffApp[k].Stop(Seconds(MAX_SIMULATION_TIME));
    }

    // Receiver Application (UDP Packet Sink)
    PacketSinkHelper packetSinkHelper("ns3::UdpSocketFactory", InetSocketAddress(interfacesPPSub2C2.GetAddress(1), UDP_SINK_PORT));
    ApplicationContainer packetSinkApp = packetSinkHelper.Install(nodes.Get(1));
    packetSinkApp.Start(Seconds(1.0));
    packetSinkApp.Stop(Seconds(MAX_SIMULATION_TIME));

    // Sender Application (Packets generated by this application are throttled)
    OnOffHelper onoffHelper("ns3::UdpSocketFactory", InetSocketAddress(interfacesPPSub2C2.GetAddress(1), UDP_SINK_PORT));
    onoffHelper.SetAttribute("DataRate", DataRateValue(DataRate("5Mbps"))); // Set the desired data rate for the sender
    onoffHelper.SetAttribute("PacketSize", UintegerValue(1024)); // Set the packet size for the sender
    ApplicationContainer senderApp = onoffHelper.Install(nodes.Get(0));
    senderApp.Start(Seconds(2.0));
    senderApp.Stop(Seconds(MAX_SIMULATION_TIME - 10));
    // endregion

    // Populate the routing tables
    Ipv4GlobalRoutingHelper::PopulateRoutingTables();

    // Enable PCAP Tracing
    csmaPPSub2R2.EnablePcap("ddos", devicesPPSub2R2.Get(0), true);

    // Animation Interface
    AnimationInterface anim("ddos.xml");

    // Label the main nodes
    anim.UpdateNodeDescription(nodes.Get(0), "PP");
    anim.UpdateNodeDescription(nodes.Get(1), "PP_S1");
    anim.UpdateNodeDescription(nodes.Get(2), "PP_S2");
    anim.UpdateNodeDescription(nodes.Get(3), "PP_S1_R1");
    anim.UpdateNodeDescription(nodes.Get(4), "PP_S1_C1");
    anim.UpdateNodeDescription(nodes.Get(5), "PP_S2_R2");
    anim.UpdateNodeDescription(nodes.Get(6), "PP_S2_C2");
    anim.UpdateNodeDescription(nodes.Get(20), "WTF");
    anim.UpdateNodeDescription(nodes.Get(7), "WTF_S1");
    anim.UpdateNodeDescription(nodes.Get(10), "WTF_S2");
    anim.UpdateNodeDescription(nodes.Get(8), "WTF_S1_HH1");
    anim.UpdateNodeDescription(nodes.Get(9), "WTF_S1_H1");
    anim.UpdateNodeDescription(nodes.Get(11), "WTF_S2_HH2");
    anim.UpdateNodeDescription(nodes.Get(12), "WTF_S2_H2");
    anim.UpdateNodeDescription(nodes.Get(13), "TCS");
    anim.UpdateNodeDescription(nodes.Get(15), "TCS_S1");
    anim.UpdateNodeDescription(nodes.Get(14), "TCS_S2");
    anim.UpdateNodeDescription(nodes.Get(18), "TCS_S1_V1");
    anim.UpdateNodeDescription(nodes.Get(19), "TCS_S1_PTM1");
    anim.UpdateNodeDescription(nodes.Get(16), "TCS_S2_V2");
    anim.UpdateNodeDescription(nodes.Get(17), "TCS_S2_PTM2");
    anim.UpdateNodeDescription(nodes.Get(21), "CT");
    anim.UpdateNodeDescription(nodes.Get(22), "Server");
    for (int i = 0; i < 23; i++) {
        anim.UpdateNodeColor(nodes.Get(i), 0, 0, 255);
    }

    // Label the user nodes
    for (int i = 0; i < 12; i++) {
        std::ostringstream oss;
        oss << "User " << i;
        anim.UpdateNodeDescription(users.Get(i), oss.str());
        anim.UpdateNodeColor(users.Get(i), 0, 255, 0);
    }

    // Label the attacker nodes
    for (int i = 0; i < 10; i++) {
        std::ostringstream oss;
        oss << "Bot " << i;
        anim.UpdateNodeDescription(botNodes.Get(i), oss.str());
        anim.UpdateNodeColor(botNodes.Get(i), 255, 0, 0);
    }

    // Change the size of the nodes
    for (int i = 0; i < 45; i++) {
        anim.UpdateNodeSize(i, 10, 10);
    }

    Simulator::Run();
    Simulator::Destroy();
    return 0;
}