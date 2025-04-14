#include <iostream>
#include <thread>

#include "HelloWorld.hpp"
#include "HelloWorldPubSubTypes.hpp"

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/topic/Topic.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>

using namespace HelloWorldModule;
using namespace eprosima::fastdds::dds;

int main() {

    // Create DomainParticipant
    DomainParticipantQos participant_qos;
    DomainParticipant* participant = DomainParticipantFactory::get_instance()->create_participant(0, participant_qos);

    // Register the type
    TypeSupport type(new HelloWorldPubSubType());
    participant->register_type(type);

    // Create Topic
    Topic* topic = participant->create_topic("HelloWorldTopic", type->get_name(), TOPIC_QOS_DEFAULT);

    // Create Publisher
    Publisher* publisher = participant->create_publisher(PUBLISHER_QOS_DEFAULT);

    // Create DataWriter
    DataWriter* writer = publisher->create_datawriter(topic, DATAWRITER_QOS_DEFAULT);

    // Publish data
    HelloWorld data;
    data.message("Hello from Fast DDS!");
    while (true) {
        writer->write(&data);
        std::cout << "Published: " << data.message() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}