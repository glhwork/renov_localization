#include "renov_localization/Trilateration.h"

using Trila::Trilateration;

int main(int argc, char** argv) {

    ros::init(argc, argv, "localizer");
    ros::NodeHandle n;

    std::string data_path = "/home/george/catkin_ws/src/renov_localization/data/uwb_position.txt";
    Trilateration localize(data_path, n);

    ros::Subscriber uwb_sub = n.subscribe("uwb_dis_info", 100, &Trilateration::PosiCalcu, &localize);
    ros::spin();

    return 0;
}
