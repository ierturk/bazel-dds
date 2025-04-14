#include "HelloWorldPubSubTypes.h"

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/topic/Topic.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/DataReaderListener.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>
#include <iostream>
#include <thread>


using namespace eprosima::fastdds::dds;
using namespace HelloWorldModule;


class HelloWorldListener : public DataReaderListener {
public:
    void on_data_available(DataReader* reader) override {
        HelloWorldModule::HelloWorld data;
        SampleInfo info;
        if (reader->take_next_sample(&data, &info) == ReturnCode_t::RETCODE_OK) {
            if (info.valid_data) {
                std::cout << "Received: " << data.message() << std::endl;
            }
        }
    }
};

int main() {
    // Create DomainParticipant
    DomainParticipantQos participant_qos;
    DomainParticipant* participant = DomainParticipantFactory::get_instance()->create_participant(0, participant_qos);

    // Register the type
    TypeSupport type(new HelloWorldPubSubType());
    participant->register_type(type);

    // Create Topic
    Topic* topic = participant->create_topic("HelloWorldTopic", "HelloWorld", TOPIC_QOS_DEFAULT);

    // Create Subscriber
    Subscriber* subscriber = participant->create_subscriber(SUBSCRIBER_QOS_DEFAULT);

    // Create DataReader
    HelloWorldListener listener;
    DataReader* reader = subscriber->create_datareader(topic, DATAREADER_QOS_DEFAULT, &listener);

    // Wait for data
    std::cout << "Waiting for data..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));

    return 0;
}